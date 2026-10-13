/******************************************/
/*Module Name: PositiveResponse.h         */
/*Author: Philopatear Salib               */
/*                                        */
/*Purpose: Final Project                  */
/******************************************/

/*
 * RECONSTRUCTED (2026): the original PositiveResponse.h was missing from
 * the 2019 project archive. This file was rebuilt from PositiveResponse.c
 * and the API descriptions in docs/Final_Project_Report.pdf. It only
 * declares the three functions defined in PositiveResponse.c and includes
 * the headers that file depends on.
 */

#ifndef POSITIVERESPONSE_H_
#define POSITIVERESPONSE_H_

#include "LEDs.h"
#include "CAN0.h"

/*****************************************************/
/*Function Name: Positive_Responses_Read             */
/*Inputs: Requested data (data) and State Machine    */
/*        Direction (*CW)                            */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Responds to Read Commands from        */
/*             Diagnostic tool if allowed.           */
/*             data can be 1 to read LED state or 2  */
/*             to read State Machine direction.      */
/*             *CW is a pointer to State Machine     */
/*             Direction.                            */
/*****************************************************/
extern void Positive_Responses_Read(uint8_t data, const uint8_t* CW);

/*****************************************************/
/*Function Name: Positive_Response_Write             */
/*Inputs: Data to be written (data) and State        */
/*        Machine Direction (*CW)                    */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Responds to Write Commands from       */
/*             Diagnostic tool if allowed.           */
/*             data can be 1 (red), 2 (blue),        */
/*             3 (green), 4 (clockwise) or           */
/*             5 (counter clockwise).                */
/*             *CW is a pointer to State Machine     */
/*             Direction.                            */
/*****************************************************/
extern void Positive_Response_Write(uint8_t data, uint8_t* CW);

/*****************************************************/
/*Function Name: Positive_Responses_SessionControl   */
/*Inputs: Requested session (data) and Session       */
/*        Control (*Ctrl)                            */
/*Outputs: void                                      */
/*Reentrant: Non-Reentrant                           */
/*Synchronous: Synchronous                           */
/*Description: Responds to Session Control Commands  */
/*             from Diagnostic tool.                 */
/*             data can be 0 for Default Session or  */
/*             1 for Extended Session.               */
/*             *Ctrl is a pointer to Session Control.*/
/*****************************************************/
extern void Positive_Responses_SessionControl(uint8_t data, uint8_t* Ctrl);

#endif /* POSITIVERESPONSE_H_ */
