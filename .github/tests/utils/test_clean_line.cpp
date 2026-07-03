#include <gtest/gtest.h>
#include <string>

extern "C" {
#include "utils.h"
}

TEST(CleanLine, RemoveLeadingSpacesAndNewLine)
{
    char line[] = "      sp 0,0,20 20 255,0,0\n";
    char *clean = clean_line(line);

    ASSERT_STREQ(clean, "sp 0,0,20 20 255,0,0");
}

TEST(CleanLine, Comment)
{
	char line[] = "	# hello";
	char *result = clean_line(line);
	EXPECT_STREQ(result, "# hello");
}

TEST(CleanLine, EmptyLine)
{
	char line[] = "";
	char *result = clean_line(line);
	EXPECT_STREQ(result, "");
}



