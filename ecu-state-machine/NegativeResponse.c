/******************************************/
/*Module Name: CAN State Machine          */
/*Author: Philopatear Ashraf              */
/*                                        */
/*Purpose: Final Project                  */
/******************************************/

#include "NegativeResponse.h"

extern uint32_t Read_ID;
extern uint32_t Write_ID;

void Negative_Response_Read(void)
{
    UARTprintf("Read Only\n");
    Send_Session(Read_ID,0); /*Negative response: ID 0x22, data 0*/
    Check_Err();
}

void Negative_Response_Write(void)
{
    UARTprintf("Write Only\n");
    Send_Session(Write_ID,1); /*Negative response: ID 0x2E, data 1*/
    Check_Err();
}



