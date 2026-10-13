/********************************/
/*Module Name : TimeOut.c       */
/*Author : Philopatear Ashraf   */
/*                              */
/*Purpose : Final Project       */
/********************************/
#include "TimeOut.h"
#pragma CHECK_MISRA("none")
#include <stdbool.h>
#pragma RESET_MISRA("all")
extern volatile bool one  ;
extern volatile bool zero ;
void TimeOut (void)
{
    UARTprintf("Time Out\n");
    g_bRXFlag = zero ;
}
