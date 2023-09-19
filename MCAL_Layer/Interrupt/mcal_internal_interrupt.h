/* 
 * File:   mcal_internal_interrupt.h
 * Author: Abdo Halem
 *
 * Created on September 17, 2023, 3:44 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* Section: Includes*/
#include "mcal_interrupt_config.h"

/* Section: Macro Declarations*/


/* Section: Macro Function Declarations*/
#if TIMER0_INTERRUPT_ENABLED == INTERRUPT_FEATURE_ENABLE
/* Enable, Disable the Timer0 interrupt and clear the interrupt flag */
#define TIMER0_INTERRUPT_ENABLE()     (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_DISABLE()    (INTCONbits.TMR0IE = 1)
#define TIMER0_INTERRUPT_FLAG_CLEAR() (INTCONbits.TMR0IF = 0)

#if INERRUPT_PRIORITY_ENABLED == INTERRUPT_FEATURE_ENABLE
#define TIMER0_INTERRUPT_HIGH_PRIORITY_SET() (INTCON2bits.TMR0IP = 1)
#define TIMER0_INTERRUPT_LOW_PRIORITY_SET()  (INTCON2bits.TMR0IP = 0)
#endif
#endif

/* Section: Data Type Declarations*/


/* Section: Software Interfaces Declarations*/


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

