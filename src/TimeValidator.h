/**
 * @file TimeValidator.h
 * @brief Header file for the TimeValidator class.
 *
 * This file contains the declaration of the TimeValidator class, which
 * implements the ITimeValidator interface to validate time strings.
 */

#pragma once

#include <regex>

#include "ITimeValidator.h"

/**
 * @class TimeValidator
 * @brief A class to validate time strings.
 *
 * The TimeValidator class provides a method to validate time strings
 * in the format HH:MM:SS, where HH is the hour (00-23), MM is the minute
 * (00-59), and SS is the second (00-59).
 */
class TimeValidator : public ITimeValidator {
 public:
  /**
   * @brief Validates a time string.
   *
   * This method checks if the given time string matches the format HH:MM:SS.
   *
   * @param time The time string to validate.
   * @return True if the time string is valid, false otherwise.
   */
  bool isValidTime(const std::string& time) const override;

  /**
   * @brief Checks if a time string is empty or contains only whitespace.
   *
   * @param time The time string to check.
   * @return True if the time string is empty or contains only whitespace, false
   * otherwise.
   */
  bool isEmptyOrWhitespace(const std::string& time) const override;
};
