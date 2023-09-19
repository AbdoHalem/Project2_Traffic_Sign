/* 
 * File:   seven_segment.h
 * Author: Abdo Halem
 *
 * Created on September 11, 2023, 9:21 PM
 */

#include "seven_segment.h"

Std_Return_Type seven_segment_initialize(const seven_segment_t *sev_seg){
    Std_Return_Type ret = E_OK;
    uint8 pins_counter = 0;
    if(NULL == sev_seg){
        ret = E_NOT_OK;
    }
    else{
        for(pins_counter = 0; pins_counter < 4; pins_counter++){
            ret = gpio_pin_initialize(&(sev_seg->seven_seg_4_pins[pins_counter]));
        }
    }
    return ret;
}

Std_Return_Type seven_segment_write_number(const seven_segment_t *sev_seg, uint8 bcd_number){
    Std_Return_Type ret = E_OK;
    uint8 pins_counter = 0;
    if(NULL == sev_seg){
        ret = E_NOT_OK;
    }
    else{
        for(pins_counter = 0; pins_counter < 4; pins_counter++){
            ret = gpio_pin_write_logic(&(sev_seg->seven_seg_4_pins[pins_counter]), READ_BIT(bcd_number, pins_counter));
        }
    }
    return ret;
}

