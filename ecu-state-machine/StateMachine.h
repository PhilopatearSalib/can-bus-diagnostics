/******************************************/
/*Module Name: StateMachine.c             */
/*Author: Philopatear Ashraf              */
/*                                        */
/*Purpose: Final Project                  */
/******************************************/

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "LEDs.h"
#include "Delay.h"

/*****************************************************/
/*Function Name: CounterClockwise_StateMachine       */
/*Inputs: Previous LED state (*prev_LED) and State   */
/*        Machine Direction (*CW)                    */
/*Outputs: void                                      */
/*Reentrant: Reentrant                               */
/*Synchronous: Synchronous                           */
/*Description: Sets direction to counter clockwise   */
/*             and moves the LED one step.           */
/*             *prev_LED is a pointer to previous LED*/
/*             color on State Machine.               */
/*             *CW is a pointer to State Machine     */
/*             Direction.                            */
/*****************************************************/
extern void CounterClockwise_StateMachine (int* prev_LED, uint8_t* CW);

/*****************************************************/
/*Function Name: Clockwise_StateMachine              */
/*Inputs: Previous LED state (*prev_LED) and State   */
/*        Machine Direction (*CW)                    */
/*Outputs: void                                      */
/*Reentrant: Reentrant                               */
/*Synchronous: Synchronous                           */
/*Description: Sets direction to clockwise and       */
/*             moves the LED one step.               */
/*             *prev_LED is a pointer to previous LED*/
/*             color on State Machine.               */
/*             *CW is a pointer to State Machine     */
/*             Direction.                            */
/*****************************************************/
extern void Clockwise_StateMachine (int* prev_LED, uint8_t* CW);

#endif /* STATEMACHINE_H_ */
