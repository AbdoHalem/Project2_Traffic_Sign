/* 
 * File:   application.c
 * Author: Abdo Halem
 *
 * Created on September 10, 2023, 5:11 PM
 */

#include "application.h"

volatile uint8 traffic_sign_counter = 1;
volatile uint8 sign_counter = 1;

void Timer0_Default_Interrupt_Handler(void){
    traffic_sign_counter++;
    sign_counter++;
}

int main(){
    Std_Return_Type ret = E_OK;
    ret &= seven_segment_initialize(&seg1);
    ret &= seven_segment_initialize(&seg2);
    ret &= gpio_pin_initialize(&buzzer);
    ret &= led_initialize(&green_led);
    ret &= led_initialize(&yellow_led);
    ret &= led_initialize(&red_led);
    ret &= timer0_init(&timer0_obj);
    ret &= gpio_pin_initialize(&buzzer);
    while(1){
        ret &= seven_segment_write_number(&seg1, sign_counter/10);
        ret &= seven_segment_write_number(&seg2, sign_counter%10);
        if(traffic_sign_counter == 1){
            ret &= led_turn_on(&green_led);
            ret &= gpio_pin_write_logic(&buzzer, GPIO_LOW);
        }
        else if(traffic_sign_counter == 30){
            sign_counter = 1;
            ret &= led_turn_off(&green_led);
            ret &= led_turn_on(&yellow_led); 
        }
        else if(traffic_sign_counter == 35){
            sign_counter = 1;
            ret &= led_turn_off(&yellow_led);
            ret &= led_turn_on(&red_led); 
        }
        else if(traffic_sign_counter == 44){
            ret &= gpio_pin_write_logic(&buzzer, GPIO_HIGH);
        }
        else if(traffic_sign_counter == 45){
            sign_counter = 1; traffic_sign_counter = 1;
            ret &= led_turn_off(&red_led);
            ret &= led_turn_on(&green_led);
        }
        else{/* Nothing */}
    }
    return (EXIT_SUCCESS);
}

