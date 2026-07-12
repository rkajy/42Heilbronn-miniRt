#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
#include "error.h"
#include "libft.h"
}

class ParseLightFixture : public ::testing::Test
{
protected:
    t_scene scene{};
    t_rt_error error;

    void TearDown() override
    {
         destroy_scene(&scene);
    }
};

TEST_F(ParseLightFixture, AcceptValidLight)
{

    char *tokens[] = {
        (char *)"L",
        (char *)"-40,50,0",
        (char *)"0.6",
        (char *)"255,255,255",
        NULL
    };

	EXPECT_EQ(parse_light(tokens, &this->scene, &this->error), RT_ERR_OK);
	EXPECT_EQ(ft_lstsize(this->scene.lights), 1);
	t_light *light = (t_light *)this->scene.lights->content;
    EXPECT_DOUBLE_EQ(light->position.x, -40);
    EXPECT_DOUBLE_EQ(light->position.y, 50);
    EXPECT_DOUBLE_EQ(light->position.z, 0);

    EXPECT_DOUBLE_EQ(light->brightness, 0.6);

    EXPECT_EQ(light->material.color.r, 255);
	EXPECT_EQ(light->material.color.g, 255);
	EXPECT_EQ(light->material.color.b, 255);
}

TEST_F(ParseLightFixture, NotAcceptMultipleLights)
{

	char *light1[] = {
		(char *)"L",
		(char *)"0,0,0",
		(char *)"0.5",
		(char *)"255,255,255",
		NULL
	};

	char *light2[] = {
		(char *)"L",
		(char *)"10,20,30",
		(char *)"1.0",
		(char *)"255,0,0",
		NULL
	};

	EXPECT_DOUBLE_EQ(parse_light(light1, &this->scene, &this->error), RT_ERR_OK);
	EXPECT_DOUBLE_EQ(parse_light(light2, &this->scene, &this->error), RT_ERR_DUPLICATE_LIGHT);

	EXPECT_EQ(ft_lstsize(this->scene.lights), 1);
}

TEST_F(ParseLightFixture, RejectWrongTokenCount)
{	
    char *tokens[] = {
		(char *)"L",
		(char *)"0,0,0",
		NULL
	};

	EXPECT_EQ(parse_light(tokens, &this->scene, &this->error), RT_ERR_TRAILING_DATA);

	EXPECT_EQ(this->scene.lights, nullptr);
}

TEST_F(ParseLightFixture, RejectInvalidPosition)
{
	char *tokens[] = {
		(char *)"L",
		(char *)"abc",
		(char *)"0.5",
		(char *)"255,255,255",
		NULL
	};
	EXPECT_EQ(parse_light(tokens, &this->scene, &this->error), RT_ERR_TRAILING_DATA);
}

TEST_F(ParseLightFixture, RejectNegativeBrightness)
{
	char *tokens[] = {
		(char *)"L",
		(char *)"0,0,0",
		(char *)"-0.1",
		(char *)"255,255,255",
		NULL
	};
	EXPECT_EQ(parse_light(tokens, &this->scene, &this->error), RT_ERR_OUT_OF_RANGE);

}
TEST_F(ParseLightFixture, RejectBrightnessGreaterThanOneBrightness)
{
	char *tokens[] = {
		(char *)"L",
		(char *)"0,0,0",
		(char *)"1.5",
		(char *)"255,255,255",
		NULL
	};
	EXPECT_EQ(parse_light(tokens, &this->scene, &this->error), RT_ERR_OUT_OF_RANGE);
}

TEST_F(ParseLightFixture, RejectInvalidColor)
{
	char *tokens[] = {
		(char *)"L",
		(char *)"0,0,0",
		(char *)"0.5",
		(char *)"300,255,255",
		NULL
	};
	EXPECT_EQ(parse_light(tokens, &this->scene, &this->error), RT_ERR_OUT_OF_RANGE);
}