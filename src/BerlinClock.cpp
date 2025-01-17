#include "BerlinClock.h"

/**
 * @brief Converts standard time to Berlin Clock format.
 *
 * @param hours The hours part of the time.
 * @param minutes The minutes part of the time.
 * @param seconds The seconds part of the time.
 * @return A string representing the time in Berlin Clock format.
 */
std::string BerlinClock::convertToBerlinClock(int hours, int minutes,
                                              int seconds) {
  std::string berlinClock;
  berlinClock +=
      (seconds % 2 == 0) ? "O\n" : "Y\n";  // Seconds lamp (odd on, even off)

  berlinClock += generateRow(hours / 5, 4, 'R');  // Top row for hours
  berlinClock += generateRow(hours % 5, 4, 'R');  // Bottom row for hours
  berlinClock +=
      generateRow(minutes / 5, 11, 'Y', true);      // Top row for minutes
  berlinClock += generateRow(minutes % 5, 4, 'Y');  // Bottom row for minutes

  return berlinClock;
}
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
std::string BerlinClock::generateRow(int litLights, int totalLights,
                                     char lightSymbol, bool isMinuteRow) {
  std::string row;
  const int redMinutePositions[] = {2, 5, 8};
  const int redMinutePositionsCount =
      sizeof(redMinutePositions) / sizeof(redMinutePositions[0]);

  for (int i = 0; i < totalLights; ++i) {
    if (i < litLights) {
      bool isRedMinutePosition = false;
      if (isMinuteRow) {
        for (int j = 0; j < redMinutePositionsCount; ++j) {
          if (i == redMinutePositions[j]) {
            isRedMinutePosition = true;
            break;
          }
        }
      }
      if (isRedMinutePosition) {
        row += 'R';  // Red lights for specific positions in minute row
      } else {
        row += lightSymbol;
      }
    } else {
      row += 'O';
    }
  }
  row += '\n';
  return row;
}
