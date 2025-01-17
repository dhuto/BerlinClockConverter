#include <gtest/gtest.h>

#include "TimeValidator.h"

TEST(TimeValidatorTest, ValidTimeFormat) {
  // Arrange
  TimeValidator validator;

  // Act & Assert
  EXPECT_TRUE(validator.isValidTime("08:28:59"));
  EXPECT_TRUE(validator.isValidTime("00:00:00"));
  EXPECT_TRUE(validator.isValidTime("23:59:59"));
}

TEST(TimeValidatorTest, InvalidTimeFormat) {
  // Arrange
  TimeValidator validator;

  // Act & Assert
  EXPECT_FALSE(validator.isValidTime("24:00:00"));    // Invalid hour
  EXPECT_FALSE(validator.isValidTime("12:60:00"));    // Invalid minute
  EXPECT_FALSE(validator.isValidTime("12:00:60"));    // Invalid second
  EXPECT_FALSE(validator.isValidTime("not_a_time"));  // Invalid string
}

TEST(TimeValidatorTest, IllegalOrBadlyFormattedInput) {
  // Arrange
  TimeValidator validator;

  // Act & Assert
  EXPECT_FALSE(validator.isValidTime(""));             // Empty string
  EXPECT_FALSE(validator.isValidTime("12:34"));        // Missing seconds
  EXPECT_FALSE(validator.isValidTime("123456"));       // No colons
  EXPECT_FALSE(validator.isValidTime("12:34:56:78"));  // Too many colons
  EXPECT_FALSE(validator.isValidTime("12:34:5a"));     // Non-numeric characters
  EXPECT_FALSE(validator.isValidTime("12:34:"));       // Trailing colon
  EXPECT_FALSE(validator.isValidTime("::"));           // Only colons
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
