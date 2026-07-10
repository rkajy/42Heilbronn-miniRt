#include <gtest/gtest.h>

extern "C" {
#include "math_rt.h"
#include "parse.h"
#include "utils.h"
}

TEST(ParseDemo, CheckRtExtensionFile)
{
	EXPECT_EQ(is_file_extension_valid("scene.rt", ".rt"), 1);
	EXPECT_EQ(is_file_extension_valid("scene.txt", ".rt"), 0);
	EXPECT_EQ(is_file_extension_valid(NULL, ".rt"), 0);
	EXPECT_EQ(is_file_extension_valid(".rt", ".rt"), 0);
}

TEST(ParseDemo, CheckInputValidation)
{
	char	*valid_argv[] = {(char *)"./miniRT", (char *)"assets/simple.rt", NULL};
	char	*invalid_argv[] = {(char *)"./miniRT", (char *)"assets/simple.txt", NULL};

	EXPECT_EQ(is_input_valid(2, valid_argv), 1);
	EXPECT_EQ(is_input_valid(2, invalid_argv), 0);
	EXPECT_EQ(is_input_valid(1, valid_argv), 0);
}
