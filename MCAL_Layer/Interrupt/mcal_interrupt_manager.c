/* 
 * File:   mcal_interrupt_manager.h
 * Author: Abdo Halem
 *
 * Created on September 17, 2023, 7:19 PM
 */

#include "mcal_interrupt_manager.h"

#if INERRUPT_PRIORITY_ENABLED == INTERRUPT_FEATURE_ENABLE
void __interrupt() interrupt_manager_high(){
    
}

void __interrupt(low_priority) interrupt_manager_low(){
    
}
#else
void __interrupt() interrupt_manager(){
    if((INTERRUPT_ENABLED == INTCONbits.TMR0IE) && (INTERRUPT_OCCURED == INTCONbits.TMR0IF)){
        TIMER0_ISR();
    }
}
#endif