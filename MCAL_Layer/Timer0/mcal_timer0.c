/* 
 * File:   mcal_timer0.c
 * Author: Abdo Halem
 *
 * Created on September 18, 2023, 12:59 PM
 */

#include "mcal_timer0.h"

static inline Std_Return_Type timer0_prescaler_configuration(const timer0_t *timer);
static inline Std_Return_Type timer0_mode_select(const timer0_t *timer);
static inline Std_Return_Type timer0_resolution_configuration(const timer0_t *timer);

static uint16 timer0_preload_value = ZERO_INIT;

#if TIMER0_INTERRUPT_ENABLED == INTERRUPT_FEATURE_ENABLE
static void (*Timer0_Interrupt_Handler)(void) = NULL;
#endif

/**
 * Initialize Timer0 Module
 * @param timer
 * @return 
 */
Std_Return_Type timer0_init(const timer0_t *timer){
    Std_Return_Type ret = E_OK;
    if(NULL == timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_DISABLE();
        timer0_resolution_configuration(timer);
        timer0_mode_select(timer);
        timer0_prescaler_configuration(timer);
#if TIMER0_INTERRUPT_ENABLED == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_FLAG_CLEAR();
        Timer0_Interrupt_Handler = timer->Timer0_Interrupt_Handler;
#if INERRUPT_PRIORITY_ENABLED == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORITY_ENABLE();
        if(INTERRUPT_LOW_PRIORITY == timer->priority){
            INTERRUPT_GLOBAL_INTERRUPT_LOW_ENABLE();
            TIMER0_INTERRUPT_LOW_PRIORITY_SET();
        }
        else{
            INTERRUPT_GLOBAL_INTERRUPT_HIGH_ENABLE();
            TIMER0_INTERRUPT_HIGH_PRIORITY_SET();
        }
        else{/* Nothing */}
#else
        INTERRUPT_GLOBAL_INTERRUPT_ENABLE();
        INTERRUPT_PERIPHERAL_INTERRUPT_ENABLE();
#endif
#endif
        TMR0H = (uint8)((timer->preload_value) >> 8);
        TMR0L = (uint8)(timer->preload_value);
        timer0_preload_value = timer->preload_value;
        TIMER0_ENABLE();
    }
    return ret;
}

/**
 * Deinitialize Timer0 Module
 * @param timer
 * @return 
 */
Std_Return_Type timer0_Deinit(const timer0_t *timer){
    Std_Return_Type ret = E_OK;
    if(NULL == timer){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_DISABLE();
#if TIMER0_INTERRUPT_ENABLED == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_DISABLE();
#endif
    }
    return ret;
}

/**
 * Write a value in timer0 register in Timer0 Module
 * @param timer
 * @return 
 */
Std_Return_Type timer0_write_value(const timer0_t *timer, uint16 value){
    Std_Return_Type ret = E_OK;
    if(NULL == timer){
        ret = E_NOT_OK;
    }
    else{
        TMR0H = (uint8)(value >> 8);
        TMR0L = (uint8)(value);
    }
    return ret;
}

/**
 * Read a value in timer0 register in Timer0 Module
 * @param timer
 * @return 
 */
Std_Return_Type timer0_read_value(const timer0_t *timer, uint16 *value){
    Std_Return_Type ret = E_OK;
    if((NULL == timer) || (NULL == value)){
        ret = E_NOT_OK;
    }
    else{
        *value = (uint16)((TMR0H << 8) + TMR0L);
    }
    return ret;
}

void TIMER0_ISR(){
    TIMER0_INTERRUPT_FLAG_CLEAR();
    TMR0H = (uint8)(timer0_preload_value >> 8);
    TMR0L = (uint8)(timer0_preload_value);
    if(Timer0_Interrupt_Handler){
        Timer0_Interrupt_Handler();
    }
}

static inline Std_Return_Type timer0_prescaler_configuration(const timer0_t *timer){
    Std_Return_Type ret = E_OK;
    if(TIMER0_PRESCALER_ENABLE_CFG == timer->prescaler_enable){
            TIMER0_PRESCALER_ENABLE();
            T0CONbits.T0PS = timer->prescaler_value;
        }
    else if(TIMER0_PRESCALER_DISABLE_CFG == timer->prescaler_enable){
        TIMER0_PRESCALER_DISABLE();
    }
    else{
        ret = E_NOT_OK;
    }
    return ret;
}

static inline Std_Return_Type timer0_mode_select(const timer0_t *timer){
    Std_Return_Type ret = E_OK;
    if(TIMER0_TIMER_MODE == timer->timer0_mode){
        TIMER0_TIMER_MODE_ENABLE();
    }
    else if(TIMER0_COUNTER_MODE == timer->timer0_mode){
        TIMER0_COUNTER_MODE_ENABLE();
        switch(timer->timer0_counter_edge){
            case TIMER0_COUNTER_RISING_EDGE_CFG :
                TIMER0_COUNTER_MODE_RISING_EDGE(); break;
            case TIMER0_COUNTER_FALLING_EDGE_CFG :
                TIMER0_COUNTER_MODE_FALLING_EDGE(); break;
            default :
                ret = E_NOT_OK; break;
        }
    }
    else{
        ret = E_NOT_OK;
    }
    return ret;
}

static inline Std_Return_Type timer0_resolution_configuration(const timer0_t *timer){
    Std_Return_Type ret = E_OK;
    if(TIMER0_8BIT_REGISTER_MODE == timer->timer0_resolution){
        TIMER0_8BIT_RESOLUTION();
    }
    else if(TIMER0_16BIT_REGISTER_MODE == timer->timer0_resolution){
        TIMER0_16BIT_RESOLUTION();
    }
    else{
        ret = E_NOT_OK;
    }
    return ret;
}