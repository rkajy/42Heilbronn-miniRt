#include <gtest/gtest.h>

extern "C"
{
#include "error.h"
#include "libft.h"
#include "math_rt.h"
#include "parse.h"
#include "parse_functions.h"

}

static int	test_normalize_vector(t_vec3 vec, t_rt_error *error)
{
	return (normalize_vector(&vec, error));
}

TEST(validateRatio, validateRatioCheck)
{
	t_rt_error	error;

	// valid cases
	EXPECT_EQ(RT_ERR_OK, validate_ratio(0, &error));
	EXPECT_EQ(RT_ERR_OK, validate_ratio(1, &error));
	EXPECT_EQ(RT_ERR_OK, validate_ratio(0.0, &error));
	EXPECT_EQ(RT_ERR_OK, validate_ratio(0.2, &error));
	EXPECT_EQ(RT_ERR_OK, validate_ratio(0.5, &error));
	EXPECT_EQ(RT_ERR_OK, validate_ratio(1.0, &error));
	// invalid cases
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(-50, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(90, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(1.1, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(-0.1, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(-1, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(1.1, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_ratio(2, &error));
}

TEST(validatePositive, validatePositiveCheck)
{
	t_rt_error	error;

	// valid cases
	EXPECT_EQ(RT_ERR_OK, validate_positive(0.0001, &error));
	EXPECT_EQ(RT_ERR_OK, validate_positive(1, &error));
	EXPECT_EQ(RT_ERR_OK, validate_positive(42.5, &error));
	// invalid cases
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_positive(0, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_positive(-1, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_positive(-0.001, &error));
}

TEST(validateFov, validateFovCheck)
{
	t_rt_error	error;

	// valid cases
	EXPECT_EQ(RT_ERR_OK, validate_fov(0, &error));
	EXPECT_EQ(RT_ERR_OK, validate_fov(45, &error));
	EXPECT_EQ(RT_ERR_OK, validate_fov(90, &error));
	EXPECT_EQ(RT_ERR_OK, validate_fov(180, &error));
	// invalid cases
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_fov(-1, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_fov(181, &error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, validate_fov(500, &error));
}

TEST(validate_normalized_vector, validate_normalized_vector_check)
{
	t_rt_error error;

	// cas passant
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({1, 0, 0}, &error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({0, 1, 0}, &error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({0, 0, 1}, &error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({0, -1, 0}, &error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({0.707106, 0.707106, 0},
			&error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({0.577350269, 0.577350269,
			0.577350269}, &error));
	// invlid case
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, test_normalize_vector({2, 0, 0},
			&error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, test_normalize_vector({0, -2, 0},
			&error));
	EXPECT_EQ(RT_ERR_OUT_OF_RANGE, test_normalize_vector({0, 0, 5},
			&error));
	EXPECT_EQ(RT_ERR_INVALID_VECTOR, test_normalize_vector({0,0,0},
			&error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({1,1,1},
			&error));
	EXPECT_EQ(RT_ERR_OK, test_normalize_vector({0.5,0.5,0.5},
			&error));
}
