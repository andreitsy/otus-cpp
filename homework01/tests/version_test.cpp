#include <gtest/gtest.h>
#include "../lib.h"
using namespace std::string_literals;

TEST(VersionTest, BasicAssertions) {
  // Expect two strings not to be equal since version is not 0
  EXPECT_TRUE(version() != "0.0.0"s);
}

TEST(HelloTest, BasicAssertions) {
  EXPECT_TRUE(hello_world() == "Hello, World!"s);
}
