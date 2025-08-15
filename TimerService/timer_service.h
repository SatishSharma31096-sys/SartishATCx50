/******************************************************************************
 * @brief timer_service.h
 *****************************************************************************/

#ifndef TIMER_SERVICE_H
#define TIMER_SERVICE_H

#include <stdint.h>

typedef enum
{
  SET_RESET_CONTROL_TIMER_ID,
  DEBOUNCE_CONTROL_TIMER_ID,
  MAX_TIMER_ID_AVAILABLE,
} TimerIdEnumType;

typedef enum
{
  TIMER_STOPED,
  TIMER_START,
  TIMER_INVALID_STATE
} TimerRunStatusEnumType;

typedef struct
{
  uint32_t m_uiTimerElapsedTime;
  uint32_t m_uiTimerRequestedTime;
  void (*TimerCallBackFunc)(void);  
  TimerRunStatusEnumType m_enTimerStatus;  
} TimerContextStructType;

#endif // TIMER_SERVICE_H