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

TEST(ParseColor, RejectAbove255)
{
    t_color color;

    EXPECT_FALSE(
        parse_color("256,0,0", &color));
}

TEST(ParseColor, RejectNegative)
{
    t_color color;

    EXPECT_FALSE(
        parse_color("-1,0,0", &color));
}

TEST(ParseColor, ParseGreen)
{
    t_color color;

    EXPECT_TRUE(
        parse_color("0,255,0", &color));

    EXPECT_EQ(color.r, 0);
    EXPECT_EQ(color.g, 255);
    EXPECT_EQ(color.b, 0);
}

TEST(ParseColor, RejectMalformedNotEnouthValues)
{
    t_color color;

    EXPECT_FALSE(
        parse_color(
            "255,0,",
            &color)
    );
}

TEST(ParseColor, RejectMalformedTooMuchValues)
{
    t_color color;

    EXPECT_FALSE(
        parse_color(
            "255,0,0,1,",
            &color
        )
    );
}

TEST(ParseColor, RejectMalformedEmptyField)
{
    t_color color;

    EXPECT_FALSE(
        parse_color(
            "255,,1",
            &color
        )
    );
}

TEST(ParseColor, RejectMalformedLetter)
{
    t_color color;

        EXPECT_FALSE(
        parse_color(
            "a,b,c",
            &color
        )
    );
}