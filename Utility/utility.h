/******************************************************************************
 * @brief utility.h
 *****************************************************************************/

#ifndef UTILITY_H
#define UTILITY_H

#include <stdint.h>

void DebounceCheckLogic(uint8_t f_uiPinStatus);
void DetectSetResetOfPin(uint8_t f_uiPinCurrentStatus);

#endif // UTILITY_H