#include "wa.h"
#include <gtest/gtest.h>

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
