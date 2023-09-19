/* 
 * File:   app_initialization.c
 * Author: Abdo Halem
 *
 * Created on September 19, 2023, 12:21 AM
 */

#include "app_initialization.h"

seven_segment_t seg1 = {
    .seven_seg_4_pins[0].port = PORTC_INDEX, .seven_seg_4_pins[0].pin = PIN0,
    .seven_seg_4_pins[0].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[0].logic = GPIO_HIGH,
    .seven_seg_4_pins[1].port = PORTC_INDEX, .seven_seg_4_pins[1].pin = PIN1,
    .seven_seg_4_pins[1].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[1].logic = GPIO_HIGH,
    .seven_seg_4_pins[2].port = PORTC_INDEX, .seven_seg_4_pins[2].pin = PIN2,
    .seven_seg_4_pins[2].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[2].logic = GPIO_HIGH,
    .seven_seg_4_pins[3].port = PORTC_INDEX, .seven_seg_4_pins[3].pin = PIN3,
    .seven_seg_4_pins[3].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[3].logic = GPIO_HIGH,
};

seven_segment_t seg2 = {
    .seven_seg_4_pins[0].port = PORTC_INDEX, .seven_seg_4_pins[0].pin = PIN4,
    .seven_seg_4_pins[0].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[0].logic = GPIO_HIGH,
    .seven_seg_4_pins[1].port = PORTC_INDEX, .seven_seg_4_pins[1].pin = PIN5,
    .seven_seg_4_pins[1].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[1].logic = GPIO_HIGH,
    .seven_seg_4_pins[2].port = PORTC_INDEX, .seven_seg_4_pins[2].pin = PIN6,
    .seven_seg_4_pins[2].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[2].logic = GPIO_HIGH,
    .seven_seg_4_pins[3].port = PORTC_INDEX, .seven_seg_4_pins[3].pin = PIN7,
    .seven_seg_4_pins[3].direction = GPIO_DIRECTION_OUTPUT, .seven_seg_4_pins[3].logic = GPIO_HIGH,
};

led_t green_led = {
    .led_config.port = PORTD_INDEX, .led_config.pin = PIN0,
    .led_config.direction = GPIO_DIRECTION_OUTPUT, .led_config.logic = GPIO_LOW
};

led_t yellow_led = {
    .led_config.port = PORTD_INDEX, .led_config.pin = PIN1,
    .led_config.direction = GPIO_DIRECTION_OUTPUT, .led_config.logic = GPIO_LOW
};

led_t red_led = {
    .led_config.port = PORTD_INDEX, .led_config.pin = PIN2,
    .led_config.direction = GPIO_DIRECTION_OUTPUT, .led_config.logic = GPIO_LOW
};

timer0_t timer0_obj = {
    .Timer0_Interrupt_Handler = Timer0_Default_Interrupt_Handler,
    .prescaler_enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_PRESCALER_DIV_BY_16,
    .preload_value = 3036,
    .timer0_resolution = TIMER0_16BIT_REGISTER_MODE,
    .timer0_mode = TIMER0_TIMER_MODE
};

pin_config_t buzzer = {
    .port = PORTD_INDEX, .pin = PIN3,
    .direction = GPIO_DIRECTION_OUTPUT, .logic = GPIO_LOW
};