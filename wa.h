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

#endif // WA_H_
