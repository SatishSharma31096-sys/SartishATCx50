/******************************************************************************
 * @brief utility.c
 *****************************************************************************/
#include <stdio.h>
#include <stdint.h>

void DebounceCheckLogic(uint8_t f_uiPinStatus)
{
  uint8_t l_uiORImage = 0;
  uint8_t l_uiANDImage = 0;
  uint8_t l_uiPinStatus = 0;  
  static uint8_t s_uiPinStatus[4] = {0};
  static uint8_t s_uiPinStatusIndex = 0;  
  
  s_uiPinStatus[s_uiPinStatusIndex++] = f_uiPinStatus;  
  for (uint8_t l_uiIndex = 0; l_uiIndex < 4; ++l_uiIndex)
  {
    l_uiANDImage = s_uiPinStatus[0] & s_uiPinStatus[l_uiIndex]; // To get 4 times ones
    l_uiORImage = s_uiPinStatus[0] | s_uiPinStatus[l_uiIndex]; // To get 4 times zero
  }
  l_uiPinStatus = l_uiANDImage;
  l_uiPinStatus &= l_uiORImage;
  
  if (s_uiPinStatusIndex >= 4)
  {
    s_uiPinStatusIndex = 0;
  }
}

void DetectSetResetOfPin(uint8_t f_uiPinCurrentStatus)
{
  uint8_t l_uiSetPin = 0;
  uint8_t l_uiResetPin = 0;
  uint8_t l_uiPinStatus = 0;
  static uint8_t s_uiPinPreviousStatus = 0;
  l_uiPinStatus = f_uiPinCurrentStatus ^ s_uiPinPreviousStatus;
  
  l_uiSetPin = l_uiPinStatus & (~s_uiPinPreviousStatus); // changes from 0 -> 1
  l_uiResetPin = l_uiPinStatus & s_uiPinPreviousStatus; // changes from 1 -> 0
}