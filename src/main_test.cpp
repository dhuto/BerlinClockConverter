// src/main_test.cpp
#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
  // Expect two strings to be equal.
  EXPECT_EQ(std::string("hello"), std::string("hello"));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}