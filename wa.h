#ifndef WA_H_
#define WA_H_

template <typename T>
T abs(T n) {
    return (n >= 0) ? n : -n;
}

template <typename T, typename U>
auto gcd(T m, U n) -> decltype(T{} + U{}) {
    using V = decltype(T{} + U{});
    V a = abs(static_cast<V>(m));
    V b = abs(static_cast<V>(n));
    while (b != 0) {
        V c = a % b;
        a = b;
        b = c;
    }
    return a;
}

template <typename T>
class UniquePointer {
  public:
    using element_type = T;
    using pointer = T *;

    UniquePointer() : p_{nullptr} {}
    explicit UniquePointer(pointer p) : p_{p} {}
    UniquePointer(const UniquePointer &other) = delete;
    UniquePointer(UniquePointer &&other) : p_{other.p_} { other.p_ = nullptr; }
    UniquePointer &operator=(const UniquePointer &other) = delete;
    UniquePointer &operator=(UniquePointer &&other) {
        delete p_;
        p_ = other.p_;
        other.p_ = nullptr;
        return *this;
    }
    ~UniquePointer() { delete p_; }

    pointer get() const { return p_; }
    element_type &operator*() const { return *p_; }
    pointer operator->() const { return p_; }
    explicit operator bool() const { return p_ != nullptr; }

    void reset(pointer p = pointer{}) { p_ = p; }
    pointer release() {
        pointer p = p_;
        p_ = nullptr;
        return p;
    }

  private:
    T *p_;
};

#endif // WA_H_
