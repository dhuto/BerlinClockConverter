#include <iostream>

#include "BerlinClock.h"
#include "TimeValidator.h"

const size_t HOURS_START = 0;
const size_t HOURS_LENGTH = 2;
const size_t MINUTES_START = 3;
const size_t MINUTES_LENGTH = 2;
const size_t SECONDS_START = 6;
const size_t SECONDS_LENGTH = 2;

int main() {
  std::cout << "Enter time in HH:MM:SS format: ";
  std::string time;
  std::getline(std::cin, time);

  TimeValidator validator;
  if (validator.isEmptyOrWhitespace(time)) {
    std::cerr << "Time string is empty or contains only whitespace."
              << std::endl;
    return 1;
  }

  if (!validator.isValidTime(time)) {
    std::cerr << "Invalid time format." << std::endl;
    return 1;
  }

  BerlinClock clock;
  int hours = std::stoi(time.substr(HOURS_START, HOURS_LENGTH));
  int minutes = std::stoi(time.substr(MINUTES_START, MINUTES_LENGTH));
  int seconds = std::stoi(time.substr(SECONDS_START, SECONDS_LENGTH));

  std::string result = clock.convertToBerlinClock(hours, minutes, seconds);
  std::cout << "\nBerlin Clock Representation:\n" << result << std::endl;

  return 0;
}
