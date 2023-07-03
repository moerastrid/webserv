#include <gtest/gtest.h>

#include "hello-world.hpp"

TEST(hello_world, basic)
{
	EXPECT_EQ(hello_world(), "Hello, World!");
}
