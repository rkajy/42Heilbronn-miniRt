#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
#include "error.h"
#include "libft.h"
}

class ParseAmbientFixture : public ::testing::Test
{
protected:
    t_scene scene{};

    void TearDown() override
    {
         destroy_scene(&scene);
    }
};

TEST_F(ParseAmbientFixture, ValidAmbient)
{
    t_color color_expected;
    t_rt_error error;
    t_ambient *result;
    double ratio_expected;

    const char *tokens[] = {
        "A",
        "0.2",
        "255,255,255",
        NULL
    };
    parse_color(tokens[2], &color_expected, &error);

    EXPECT_EQ(
        parse_ambient(tokens, &scene, &error),
        RT_ERR_OK
    );

    parse_double(tokens[1], &ratio_expected, &error);

    result = (t_ambient*)scene.ambients->content;
    EXPECT_EQ(color_expected.r, result->color.r);
    EXPECT_EQ(color_expected.g, result->color.g);
    EXPECT_EQ(color_expected.b, result->color.b);
    EXPECT_EQ(ratio_expected, result->ratio);
    EXPECT_EQ(ft_lstsize(scene.ambients), 1);
}

TEST_F(ParseAmbientFixture, OutOfRangePositiveRatioAmbient)
{
    t_color color_expected;
    t_rt_error error;
    t_ambient *result;
    double ratio_expected;

    const char *tokens[] = {
        "A",
        "9",
        "255,255,255",
        NULL
    };
    parse_color(tokens[2], &color_expected, &error);

    EXPECT_EQ(
        parse_ambient(tokens, &scene, &error),
        RT_ERR_OUT_OF_RANGE
    );

    parse_double(tokens[1], &ratio_expected, &error);

    result = (t_ambient*)scene.ambients->content;
    EXPECT_EQ(color_expected.r, result->color.r);
    EXPECT_EQ(color_expected.g, result->color.g);
    EXPECT_EQ(color_expected.b, result->color.b);
    EXPECT_EQ(ratio_expected, result->ratio);
    EXPECT_EQ(ft_lstsize(scene.ambients), 1);
}

TEST_F(ParseAmbientFixture, OutOfRangeNegativeRatioAmbient)
{
    t_color color_expected;
    t_rt_error error;
    t_ambient *result;
    double ratio_expected;

    const char *tokens[] = {
        "A",
        "-19",
        "255,255,255",
        NULL
    };
    parse_color(tokens[2], &color_expected, &error);

    EXPECT_EQ(
        parse_ambient(tokens, &scene, &error),
        RT_ERR_OUT_OF_RANGE
    );

    parse_double(tokens[1], &ratio_expected, &error);

    result = (t_ambient*)scene.ambients->content;
    EXPECT_EQ(color_expected.r, result->color.r);
    EXPECT_EQ(color_expected.g, result->color.g);
    EXPECT_EQ(color_expected.b, result->color.b);
    EXPECT_EQ(ratio_expected, result->ratio);
    EXPECT_EQ(ft_lstsize(scene.ambients), 1);
}

// test for 2 ambients
TEST_F(ParseAmbientFixture, DuplicateAmbient)
{
    t_rt_error error;

    const char *tokens[] = {
        "A",
        "0.2",
        "255,255,255",
        NULL
    };

    EXPECT_EQ(
        parse_ambient(tokens, &scene, &error),
        RT_ERR_OK
    );

    EXPECT_EQ(ft_lstsize(scene.ambients), 1);

    // add a second scene should return an error
    EXPECT_EQ(
        parse_ambient(tokens, &scene, &error),
        RT_ERR_DUPLICATE_AMBIENT
    );
}