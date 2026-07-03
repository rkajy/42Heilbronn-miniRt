#include <gtest/gtest.h>

extern "C" {
#include "parse_functions.h"
#include "error.h"
}

TEST(ParseDouble, ValidValue)
{
	double value;
	t_rt_error error;

	EXPECT_EQ(parse_double((char *)"45.25", &value, &error), RT_ERR_OK);
	EXPECT_DOUBLE_EQ(value, 45.25);
}

TEST(ParseDouble, RejectTrailingData)
{
	double value;
	t_rt_error error;

	EXPECT_EQ(parse_double((char *)"45.25abc", &value, &error), RT_ERR_TRAILING_DATA);
}