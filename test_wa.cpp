#include "wa.h"
#include <gtest/gtest.h>
#include <utility>

TEST(Numeric, Gcd) {
    EXPECT_EQ(gcd(1, 0), 1);
    EXPECT_EQ(gcd(0, 1), 1);
    EXPECT_EQ(gcd(-1, 0), 1);
    EXPECT_EQ(gcd(0, -1), 1);

    EXPECT_EQ(gcd(4, 6), 2);
    EXPECT_EQ(gcd(4, -6), 2);
    EXPECT_EQ(gcd(-4, 6), 2);
    EXPECT_EQ(gcd(-4, -6), 2);
}

TEST(UniquePointer, Creation) {
    UniquePointer<int> p;
}

TEST(UniquePointer, BooleanConversion) {
    UniquePointer<int> p;
    EXPECT_FALSE(p);

    UniquePointer<int> q{new int{0}};
    EXPECT_TRUE(q);
}

TEST(UniquePointer, Assignment) {
    UniquePointer<int> p{new int{0}};
    UniquePointer<int> q{new int{1}};

    p = std::move(q);
    EXPECT_TRUE(p);
    EXPECT_FALSE(q);
    EXPECT_EQ(*p, 1);
}

TEST(UniquePointer, Reset) {
    UniquePointer<int> p;
    EXPECT_FALSE(p);

    p.reset(new int{1});
    EXPECT_TRUE(p);
    EXPECT_EQ(*p, 1);

    p.reset();
    EXPECT_FALSE(p);
}

TEST(UniquePointer, Release) {
    UniquePointer<int> p{new int{1}};
    EXPECT_TRUE(p);

    int *q = p.release();
    EXPECT_FALSE(p);
    EXPECT_EQ(*q, 1);

    delete q;
}
