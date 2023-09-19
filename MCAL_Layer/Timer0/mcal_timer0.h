/* 
 * File:   mcal_timer0.h
 * Author: Abdo Halem
 *
 * Created on September 18, 2023, 12:59 PM
 */

#ifndef MCAL_TIMER0_H
#define	MCAL_TIMER0_H

/* Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "../../MCAL_Layer/Interrupt/mcal_internal_interrupt.h"

/* Section: Macro Declarations*/
#define TIMER0_PRESCALER_ENABLE_CFG  0
#define TIMER0_PRESCALER_DISABLE_CFG 1

#define TIMER0_COUNTER_RISING_EDGE_CFG  0
#define TIMER0_COUNTER_FALLING_EDGE_CFG 1

#define TIMER0_TIMER_MODE  0
#define TIMER0_COUNTER_MODE 1

#define TIMER0_8BIT_REGISTER_MODE  1
#define TIMER0_16BIT_REGISTER_MODE 0

#define ZERO_INIT 0

/* Section: Macro Function Declarations*/
#define TIMER0_ENABLE()  (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE() (T0CONbits.TMR0ON = 0)

#define TIMER0_8BIT_RESOLUTION()  (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_RESOLUTION() (T0CONbits.T08BIT = 0)

#define TIMER0_TIMER_MODE_ENABLE()   (T0CONbits.T0CS = 0)
#define TIMER0_COUNTER_MODE_ENABLE() (T0CONbits.T0CS = 1)

#define TIMER0_COUNTER_MODE_RISING_EDGE()  (T0CONbits.T0SE = 0)
#define TIMER0_COUNTER_MODE_FALLING_EDGE() (T0CONbits.T0SE = 1)

#define TIMER0_PRESCALER_ENABLE()  (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE() (T0CONbits.PSA = 1)

/* Section: Data Type Declarations*/
typedef enum{
    TIMER0_PRESCALER_DIV_BY_2 = 0,
    TIMER0_PRESCALER_DIV_BY_4,
    TIMER0_PRESCALER_DIV_BY_8,
    TIMER0_PRESCALER_DIV_BY_16,
    TIMER0_PRESCALER_DIV_BY_32,
    TIMER0_PRESCALER_DIV_BY_64,
    TIMER0_PRESCALER_DIV_BY_128,
    TIMER0_PRESCALER_DIV_BY_256
}timer0_prescaler_values_t;

typedef struct{
#if TIMER0_INTERRUPT_ENABLED == INTERRUPT_FEATURE_ENABLE
    void (*Timer0_Interrupt_Handler)(void);
#if INERRUPT_PRIORITY_ENABLED == INTERRUPT_FEATURE_ENABLE
    interrupt_priority_t priority;
#endif
#endif
    timer0_prescaler_values_t prescaler_value;
    uint16 preload_value;
    uint8 timer0_mode : 1;
    uint8 prescaler_enable : 1;
    uint8 timer0_resolution : 1;
    uint8 timer0_counter_edge : 1;
    uint8  : 4;
}timer0_t;

/* Section: Software Interfaces Declarations*/
Std_Return_Type timer0_init(const timer0_t *timer);
Std_Return_Type timer0_Deinit(const timer0_t *timer);
Std_Return_Type timer0_write_value(const timer0_t *timer, uint16 value);
Std_Return_Type timer0_read_value(const timer0_t *timer, uint16 *value);

#endif	/* MCAL_TIMER0_H */

