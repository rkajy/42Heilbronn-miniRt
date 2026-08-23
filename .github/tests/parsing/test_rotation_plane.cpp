#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse_functions.h"
#include "error.h"
#include "libft.h"
}

class RotationPlaneFixture : public ::testing::Test
{
  protected:
    t_scene scene{};
    void TearDown() override
    {
        destroy_scene(&scene);
    }
};

TEST_F(RotationPlaneFixture, basicCase)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"pl",
		(char *)"0,0,0", //point
		(char *)"0,1,0", //normal <---
		(char *)"255,255,255",
        (char *)"R",
        (char *)"90,0,0",
		NULL
	};


	EXPECT_EQ(parse_plane(tokens, &scene, &error),RT_ERR_OK );

    t_plane *plane = (t_plane *)scene.planes->content;

    // Trigonometric calculations may produce tiny floating-point errors,
    // such as 6.12e-17 instead of exact zero, so compare with a tolerance.
    // 1 × 10⁻⁶ = 0,000001 <=> 1e-6
    EXPECT_NEAR(plane->normal.x, 0, 1e-6);
	EXPECT_NEAR(plane->normal.y, 0, 1e-6);
	EXPECT_NEAR(plane->normal.z, 1, 1e-6);
}

TEST_F(RotationPlaneFixture, NegativeCase)
{
    t_rt_error error;

	char *tokens[] = {
		(char *)"pl",
		(char *)"0,0,0", //point
		(char *)"0,1,0", //normal <---
		(char *)"255,255,255",
        (char *)"R",
        (char *)"-90,0,0",
		NULL
	};


	EXPECT_EQ(parse_plane(tokens, &scene, &error),RT_ERR_OK );

    t_plane *plane = (t_plane *)scene.planes->content;

    // Trigonometric calculations may produce tiny floating-point errors,
    // such as 6.12e-17 instead of exact zero, so compare with a tolerance.
    // 1 × 10⁻⁶ = 0,000001 <=> 1e-6
    EXPECT_NEAR(plane->normal.x, 0, 1e-6);
	EXPECT_NEAR(plane->normal.y, 0, 1e-6);
	EXPECT_NEAR(plane->normal.z, -1, 1e-6);
}
