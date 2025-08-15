/******************************************************************************
 * @brief timer_service.c
 *****************************************************************************/
#include <stdio.h>
#include "timer_service.h"

static TimerContextStructType s_stTimerControl[MAX_TIMER_ID_AVAILABLE];

void TimerServiceRegisterCallBack(TimerIdEnumType f_enTimerId, void (*f_pCallBack)(void))
{
  s_stTimerControl[f_enTimerId].TimerCallBackFunc = f_pCallBack;
  s_stTimerControl[f_enTimerId].m_enTimerStatus = TIMER_STOPED;
}

void TimerServiceStart(TimerIdEnumType f_enTimerId, uint32_t f_uiElapsedTime)
{
  s_stTimerControl[f_enTimerId].m_uiTimerElapsedTime = 0;
  s_stTimerControl[f_enTimerId].m_enTimerStatus = TIMER_START;  
  s_stTimerControl[f_enTimerId].m_uiTimerRequestedTime = f_uiElapsedTime;
}

void TimerServiceStopped(TimerIdEnumType f_enTimerId)
{
  s_stTimerControl[f_enTimerId].m_uiTimerElapsedTime= 0;
  s_stTimerControl[f_enTimerId].m_uiTimerRequestedTime = 0;
  s_stTimerControl[f_enTimerId].m_enTimerStatus = TIMER_STOPED;  
}

void TimerServiceInEveryMs(void)
{
  for(TimerIdEnumType l_enTimerId = SET_RESET_CONTROL_TIMER_ID; l_enTimerId < MAX_TIMER_ID_AVAILABLE; ++l_enTimerId)
  {
    if (s_stTimerControl[l_enTimerId].m_enTimerStatus == TIMER_START)
    {
      s_stTimerControl[l_enTimerId].m_uiTimerElapsedTime++;
      if (s_stTimerControl[l_enTimerId].m_uiTimerElapsedTime >= s_stTimerControl[l_enTimerId].m_uiTimerRequestedTime)
      {
        s_stTimerControl[l_enTimerId].m_uiTimerElapsedTime = 0;        
        if (s_stTimerControl[l_enTimerId].TimerCallBackFunc != NULL)
        {
              s_stTimerControl[l_enTimerId].TimerCallBackFunc();
        }
      }
    }
  }
}