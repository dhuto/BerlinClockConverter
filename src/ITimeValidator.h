/**
 * @file ITimeValidator.h
 * @brief Interface for validating time strings.
 *
 * This file contains the declaration of the ITimeValidator interface,
 * which provides a method to validate time strings.
 */

#pragma once

#include <string>

/**
 * @class ITimeValidator
 * @brief Interface for time validation.
 *
 * The ITimeValidator interface declares a method for validating
 * time strings. Implementations of this interface should provide
 * the logic to determine whether a given time string is valid.
 */
class ITimeValidator {
 public:
  virtual ~ITimeValidator() = default;
  virtual bool isValidTime(const std::string& time) const = 0;
  virtual bool isEmptyOrWhitespace(const std::string& time) const = 0;
};
