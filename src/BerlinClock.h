#ifndef BERLINCLOCK_H
#define BERLINCLOCK_H

#include <string>

/**
 * @class BerlinClock
 * @brief A class to convert standard time to Berlin Clock format.
 */
class BerlinClock {
 public:
  /**
   * @brief Converts standard time to Berlin Clock format.
   *
   * @param hours The hours part of the time.
   * @param minutes The minutes part of the time.
   * @param seconds The seconds part of the time.
   * @return A string representing the time in Berlin Clock format.
   */
  std::string convertToBerlinClock(int hours, int minutes, int seconds);

 private:
  /**
   * @brief Generates a row of lights for the Berlin Clock.
   *
   * @param litLights The number of lights that should be lit.
   * @param totalLights The total number of lights in the row.
   * @param lightSymbol The symbol representing a lit light.
   * @param isMinuteRow A flag indicating if the row is a minute row (default is
   * false).
   * @return A string representing the row of lights.
   */
  std::string generateRow(int litLights, int totalLights, char lightSymbol,
                          bool isMinuteRow = false);
};

#endif  // BERLINCLOCK_H