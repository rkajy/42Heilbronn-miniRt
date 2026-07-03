#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
#include "error.h"
}

TEST(ParseColor, ValidColor)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color("255,0,128", &color, &error),
        RT_ERR_OK
    );
    EXPECT_EQ(color.r, 255);
    EXPECT_EQ(color.g, 0);
    EXPECT_EQ(color.b, 128);
}

TEST(ParseColor, RejectAbove255)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color("256,0,0", &color, &error),
        RT_ERR_OUT_OF_RANGE
    );
}

TEST(ParseColor, RejectNegative)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color("-1,0,0", &color, &error),
        RT_ERR_INVALID_NUMBER
    );
}

TEST(ParseColor, ParseGreen)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color("0,255,0", &color, &error),
        RT_ERR_OK
    );

    EXPECT_EQ(color.r, 0);
    EXPECT_EQ(color.g, 255);
    EXPECT_EQ(color.b, 0);
}

TEST(ParseColor, RejectMalformedNotEnouthValues)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color(
            "255,0,",
            &color,
            &error
        ),
        RT_ERR_TRAILING_DATA
    );
}

TEST(ParseColor, RejectMalformedTooMuchValues)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color(
            "255,0,0,1,",
            &color,
            &error
        ),
        RT_ERR_TRAILING_DATA
    );
}

TEST(ParseColor, RejectMalformedEmptyField)
{
    t_color color;
    t_rt_error error;

    EXPECT_EQ(
        parse_color(
            "255,,1",
            &color,
            &error
        ),
        RT_ERR_TRAILING_DATA
    );
}

TEST(ParseColor, RejectMalformedLetter)
{
    t_color color;
    t_rt_error error;

        EXPECT_EQ(
        parse_color(
            "a,b,c",
            &color,
            &error
        ),
        RT_ERR_INVALID_NUMBER
    );
}