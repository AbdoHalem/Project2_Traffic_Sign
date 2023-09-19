/* 
 * File:   seven_segment.h
 * Author: Abdo Halem
 *
 * Created on September 11, 2023, 9:21 PM
 */

#ifndef SEVEN_SEGMENT_H
#define	SEVEN_SEGMENT_H

/* Section: Includes*/
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macro Declarations*/
#define SEVEN_SEGMENT_DISPLAY_ON_0 0b0000
#define SEVEN_SEGMENT_DISPLAY_ON_1 0b0001
#define SEVEN_SEGMENT_DISPLAY_ON_2 0b0010
#define SEVEN_SEGMENT_DISPLAY_ON_3 0b0011
#define SEVEN_SEGMENT_DISPLAY_ON_4 0b0100
#define SEVEN_SEGMENT_DISPLAY_ON_5 0b0101
#define SEVEN_SEGMENT_DISPLAY_ON_6 0b0110
#define SEVEN_SEGMENT_DISPLAY_ON_7 0b0111
#define SEVEN_SEGMENT_DISPLAY_ON_8 0b1000
#define SEVEN_SEGMENT_DISPLAY_ON_9 0b1001
#define SEVEN_SEGMENT_DISPLAY_OFF  0b1111

/* Section: Macro Function Declarations*/


/* Section: Data Type Declarations*/
typedef struct{
    pin_config_t seven_seg_4_pins[4];
}seven_segment_t;

/* Section: Software Interfaces Declarations*/
Std_Return_Type seven_segment_initialize(const seven_segment_t *sev_seg);
Std_Return_Type seven_segment_write_number(const seven_segment_t *sev_seg, uint8 bcd_number);

#endif	/* SEVEN_SEGMENT_H */

