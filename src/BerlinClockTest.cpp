#include <gtest/gtest.h>

#include "BerlinClock.h"

TEST(BerlinClockTest, ConvertToBerlinClock) {
  // Arrange
  BerlinClock clock;

  // Act and Assert
  // Test seconds lamp
  EXPECT_EQ(clock.convertToBerlinClock(0, 0, 0).substr(0, 2), "O\n");
  EXPECT_EQ(clock.convertToBerlinClock(0, 0, 1).substr(0, 2), "Y\n");

  // Test hours top row
  EXPECT_EQ(clock.convertToBerlinClock(8, 0, 0).substr(2, 5), "ROOO\n");
  EXPECT_EQ(clock.convertToBerlinClock(16, 0, 0).substr(2, 5), "RRRO\n");

  // Test hours bottom row
  EXPECT_EQ(clock.convertToBerlinClock(8, 0, 0).substr(7, 5), "RRRO\n");
  EXPECT_EQ(clock.convertToBerlinClock(16, 0, 0).substr(7, 5), "ROOO\n");

  // Test minutes top row
  EXPECT_EQ(clock.convertToBerlinClock(0, 17, 0).substr(12, 12),
            "YYROOOOOOOO\n");
  EXPECT_EQ(clock.convertToBerlinClock(0, 59, 0).substr(12, 12),
            "YYRYYRYYRYY\n");

  // Test minutes bottom row
  EXPECT_EQ(clock.convertToBerlinClock(0, 17, 0).substr(24, 5), "YYOO\n");
  EXPECT_EQ(clock.convertToBerlinClock(0, 59, 0).substr(24, 5), "YYYY\n");
}

TEST(BerlinClockTest, ConvertToBerlinClock_HappyFlow) {
  // Arrange
  BerlinClock clock;

  // Act
  std::string result = clock.convertToBerlinClock(8, 28, 59);

  // Assert
  EXPECT_EQ(result.substr(0, 2), "Y\n");              // Seconds lamp
  EXPECT_EQ(result.substr(2, 5), "ROOO\n");           // Hours top row
  EXPECT_EQ(result.substr(7, 5), "RRRO\n");           // Hours bottom row
  EXPECT_EQ(result.substr(12, 12), "YYRYYOOOOOO\n");  // Minutes top row
  EXPECT_EQ(result.substr(24, 5), "YYYO\n");          // Minutes bottom row
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
