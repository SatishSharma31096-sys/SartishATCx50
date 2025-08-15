/******************************************************************************
 * @brief timer_service.h
 *****************************************************************************/

#ifndef TIMER_SERVICE_H
#define TIMER_SERVICE_H

typedef enum
{
  SET_RESET_CONTROL_TIMER_ID,
  DEBOUNCE_CONTROL_TIMER_ID,
  MAX_TIMER_ID_AVAILABLE,
} TimerIdEnumType;

typedef enum
{
  TIMER_STOPED,
  TIMER_START
} TimerRunStatusEnumType;

typedef struct
{
  void (*TimerCallBackFunc)(void);
  TimerIdEnumType m_enTimerId,
  uint32_t m_uiTimerElapsedTime;
  TimerRunStatusEnumType m_enTimerStatus;  
} TimerContextStructType;

#endif // TIMER_SERVICE_H