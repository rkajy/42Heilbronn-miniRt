#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
#include "error.h"
#include "libft.h"
}

class TranslationCameraFixture : public ::testing::Test
{
  protected:
    t_scene scene{};
    void TearDown() override
    {
        destroy_scene(&scene);
    }
};

TEST_F(TranslationCameraFixture, PositiveTranslationXYZ)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20", //position <---
		(char *)"0,0,1", //orientation
		(char *)"70", //fov
        (char *)"T",
        (char *)"1,2,3",
		NULL
	};


	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );

    t_camera *camera = (t_camera *)scene.cameras->content;

    EXPECT_DOUBLE_EQ(camera->position.x, -49);
	EXPECT_DOUBLE_EQ(camera->position.y, 2);
	EXPECT_DOUBLE_EQ(camera->position.z, 23);
}

TEST_F(TranslationCameraFixture, NegativeTranslationXYZ)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20", //position <---
		(char *)"0,0,1", //orientation
		(char *)"70", //fov
        (char *)"T",
        (char *)"-1,-2,-3",
		NULL
	};


	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );

    t_camera *camera = (t_camera *)scene.cameras->content;

    EXPECT_DOUBLE_EQ(camera->position.x, -51);
	EXPECT_DOUBLE_EQ(camera->position.y, -2);
	EXPECT_DOUBLE_EQ(camera->position.z, 17);
}

TEST_F(TranslationCameraFixture, ZeroTranslationXYZ)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20", //position <---
		(char *)"0,0,1", //orientation
		(char *)"70", //fov
        (char *)"T",
        (char *)"0,0,0",
		NULL
	};


	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );

    t_camera *camera = (t_camera *)scene.cameras->content;

    EXPECT_DOUBLE_EQ(camera->position.x, -50);
	EXPECT_DOUBLE_EQ(camera->position.y, 0);
	EXPECT_DOUBLE_EQ(camera->position.z, 20);
}

TEST_F(TranslationCameraFixture, XTranslationOnly)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20", //position <---
		(char *)"0,0,1", //orientation
		(char *)"70", //fov
        (char *)"T",
        (char *)"5,0,0",
		NULL
	};


	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );

    t_camera *camera = (t_camera *)scene.cameras->content;

    EXPECT_DOUBLE_EQ(camera->position.x, -45);
	EXPECT_DOUBLE_EQ(camera->position.y, 0);
	EXPECT_DOUBLE_EQ(camera->position.z, 20);
}

TEST_F(TranslationCameraFixture, YTranslationOnly)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20", //position <---
		(char *)"0,0,1", //orientation
		(char *)"70", //fov
        (char *)"T",
        (char *)"0,5,0",
		NULL
	};


	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );

    t_camera *camera = (t_camera *)scene.cameras->content;

    EXPECT_DOUBLE_EQ(camera->position.x, -50);
	EXPECT_DOUBLE_EQ(camera->position.y, 5);
	EXPECT_DOUBLE_EQ(camera->position.z, 20);
}

TEST_F(TranslationCameraFixture, ZTranslationOnly)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20", //position <---
		(char *)"0,0,1", //orientation
		(char *)"70", //fov
        (char *)"T",
        (char *)"0,0,5",
		NULL
	};


	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );

    t_camera *camera = (t_camera *)scene.cameras->content;

    EXPECT_DOUBLE_EQ(camera->position.x, -50);
	EXPECT_DOUBLE_EQ(camera->position.y, 0);
	EXPECT_DOUBLE_EQ(camera->position.z, 25);
}