/********************************/
/*Module Name : Receive.h       */
/*Author : Philopatear Ashraf   */
/*                              */
/*Purpose : Final Project       */
/********************************/
#ifndef RECEIVE_H_
#define RECEIVE_H_
#include "CAN0.h"
#include "UART_Init.h"
extern void Receive(uint32_t MsgID);
/*****************************************************/
/*Function Name: Receive                             */
/*Inputs:uint32_t MsgID                              */
/*Outputs: void                                      */
/*Reentrancy: Non-Reentrant                          */
/*Synchronous: Synchronous                           */
/*Description: Decodes the response from Node 2      */
/*             (MsgID and data) and prints it:       */
/*             positive, negative or session         */
/*             control response. Does not change     */
/*             the active session.                   */
/*****************************************************/
#endif /* RECEIVE_H_ */
