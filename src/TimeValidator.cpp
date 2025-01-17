#include "TimeValidator.h"

/**
 * @brief Validates a time string.
 *
 * This method checks if the given time string matches the format HH:MM:SS.
 *
 * @param time The time string to validate.
 * @return True if the time string is valid, false otherwise.
 */
bool TimeValidator::isValidTime(const std::string& time) const {
  std::regex timePattern(R"((2[0-3]|[01]?[0-9]):([0-5]?[0-9]):([0-5]?[0-9]))");
  return std::regex_match(time, timePattern);
}

/**
 * @brief Checks if a time string is empty or contains only whitespace.
 *
 * @param time The time string to check.
 * @return True if the time string is empty or contains only whitespace, false
 * otherwise.
 */
bool TimeValidator::isEmptyOrWhitespace(const std::string& time) const {
  return time.empty() || time.find_first_not_of(' ') == std::string::npos;
}
