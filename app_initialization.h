/* 
 * File:   app_initialization.h
 * Author: Abdo Halem
 *
 * Created on September 19, 2023, 12:21 AM
 */

#ifndef APP_INITIALIZATION_H
#define	APP_INITIALIZATION_H

/* Section: Includes*/
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/7_Segment/seven_segment.h"
#include "MCAL_Layer/Interrupt/mcal_internal_interrupt.h"
#include "MCAL_Layer/Timer0/mcal_timer0.h"

/* Section: Macro Declarations*/


/* Section: Macro Function Declarations*/


/* Section: Data Type Declarations*/


/* Section: Software Interfaces Declarations*/
void Timer0_Default_Interrupt_Handler(void);


#endif	/* APP_INITIALIZATION_H */

