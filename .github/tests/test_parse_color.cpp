#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
}

TEST(ParseColor, ValidColor)
{
    t_color color;

    EXPECT_TRUE(
        parse_color("255,0,128", &color)
    );
    EXPECT_EQ(color.r, 255);
    EXPECT_EQ(color.g, 0);
    EXPECT_EQ(color.b, 128);
}