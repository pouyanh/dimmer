/* 
 * File:   addr_space.h
 * Author: Pouyan Heyratpour
 *
 * Created on August 28, 2017, 00:44
 */

#ifndef ADDR_SPACE_H
#define	ADDR_SPACE_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ADDR_ADC	0x0400 // 1K
#define ADDR_KEYPAD	0x0800 // 2K
#define ADDR_7SEG1	0x0C00 // 3K
#define ADDR_7SEG2	0x1000 // 4K
#define ADDR_7SEG3	0x1400 // 5K
#define ADDR_7SEG4	0x1800 // 6K
#define ADDR_STMOTOR	0x1C00 // 7K
#define ADDR_MATRIX_LED	0x2000 // 8K
#define ADDR_LED_ARRAY	0x2400 // 9K
#define ADDR_SRAM	0x8000 // 32K

#ifdef	__cplusplus
}
#endif

#endif	/* ADDR_SPACE_H */
