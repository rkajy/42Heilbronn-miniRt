#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
#include "error.h"
#include "libft.h"
}

class ParseCameraFixture : public ::testing::Test
{
protected:
    t_scene scene{};
    void TearDown() override
    {
        destroy_scene(&scene);
    }
};

TEST_F(ParseCameraFixture, ValidCamera)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"-50,0,20",
		(char *)"0,0,1",
		(char *)"70",
		NULL
	};

	EXPECT_EQ(parse_camera(tokens, &scene, &error),RT_ERR_OK );
	EXPECT_EQ(ft_lstsize(scene.cameras), 1);

	t_camera *camera = (t_camera *)scene.cameras->content;

	EXPECT_DOUBLE_EQ(camera->position.x, -50);
	EXPECT_DOUBLE_EQ(camera->position.y, 0);
	EXPECT_DOUBLE_EQ(camera->position.z, 20);

	EXPECT_DOUBLE_EQ(camera->orientation.x, 0);
	EXPECT_DOUBLE_EQ(camera->orientation.y, 0);
	EXPECT_DOUBLE_EQ(camera->orientation.z, 1);

	EXPECT_DOUBLE_EQ(camera->fov, 70);
}

TEST_F(ParseCameraFixture, RejectSecondCamera)
{
	t_scene	scene = {};
    t_rt_error error;

	char *camera1[] = {
		(char *)"C",
		(char *)"0,0,0",
		(char *)"0,0,1",
		(char *)"70",
		NULL
	};

	char *camera2[] = {
		(char *)"C",
		(char *)"10,0,0",
		(char *)"1,0,0",
		(char *)"60",
		NULL
	};

	EXPECT_EQ(parse_camera(camera1, &scene, &error), RT_ERR_OK);

	EXPECT_EQ(parse_camera(camera2, &scene, &error), RT_ERR_DUPLICATE_AMBIENT);

	EXPECT_EQ(ft_lstsize(scene.cameras), 1);
}

TEST_F(ParseCameraFixture, RejectWrongTokenCount)
{
	t_scene	scene = {};
    t_rt_error error;

	char *tokens[] = {
		(char *)"C",
		(char *)"0,0,0",
		NULL
	};

	EXPECT_EQ(parse_camera(tokens, &scene, &error), RT_ERR_TRAILING_DATA);

	EXPECT_EQ(scene.cameras, nullptr);
}