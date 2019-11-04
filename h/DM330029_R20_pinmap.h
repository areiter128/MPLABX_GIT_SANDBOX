/*LICENSE ********************************************************************
 * Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 * ***************************************************************************/
/*@@board_pinmap.h
 * ***************************************************************************
 * File:   00142_expander_board_pinmap.h
 * Author: M91406
 * 
 * Summary:
 * Global declarations of specific board pin names and peripherals
 * 
 * Description:
 * Global declarations are used to associate board signals, LEDs and other 
 * peripherals with device pins and special function registers.
 * 
 * History:
 * 07/28/2017	File created
 * ***************************************************************************/

#ifndef HAL_DP_DEVELOPMENT_BOARD_PINMAP_H
#define	HAL_DP_DEVELOPMENT_BOARD_PINMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#include <stdbool.h>

// Generic defines
#ifndef PINDIR_INPUT
#define PINDIR_INPUT    1
#endif
#ifndef PINDIR_OUTPUT
#define PINDIR_OUTPUT   0
#endif
#ifndef PINSTATE_HIGH
#define PINSTATE_HIGH   1
#endif
#ifndef PINSTATE_LOW
#define PINSTATE_LOW    0
#endif

// LEDs and Debug Pins
#ifndef BRD_LED_ON
  #define BRD_LED_ON    1
#endif
#ifndef BRD_LED_OFF
  #define BRD_LED_OFF   0    
#endif
#ifndef LED_OUTPUT
  #define LED_OUTPUT    0
#endif
#ifndef LED_INPUT
  #define LED_INPUT     1
#endif
    
#define LED_RD_TRIS     TP52_TRIS
#define LED_RD_WR       TP52_WR
#define LED_RD_RD       TP52_RD
#define LED_RD_INIT_OUTPUT TP52_INIT_OUTPUT   // Initializine the LED pin as output
#define LED_RD_INIT_INPUT  TP52_INIT_INPUT   // Initializine the LED pin as input
#define LED_RD_SET      TP52_SET
#define LED_RD_CLEAR    TP52_CLEAR
#define LED_RD_TOGGLE   TP52_TOGGLE
    
#define LED_GN_TRIS     TP54_TRIS
#define LED_GN_WR       TP54_WR
#define LED_GN_RD       TP54_RD
#define LED_GN_INIT_OUTPUT TP54_INIT_OUTPUT   // Initializine the LED pin as output
#define LED_GN_INIT_INPUT  TP54_INIT_INPUT   // Initializine the LED pin as input
#define LED_GN_SET      TP54_SET
#define LED_GN_CLEAR    TP54_CLEAR
#define LED_GN_TOGGLE   TP54_TOGGLE

#define CLKOUT_TRIS     TP39_TRIS
#define CLKOUT_WR       TP39_WR
#define CLKOUT_RD       TP39_RD
#define CLKOUT_INIT_OUTPUT   TP39_INIT_OUTPUT   // Initializine the clockout pin as output
#define CLKOUT_INIT_INPUT    TP39_INIT_INPUT   // Initializine the clockout pin as input
#define CLKOUT_SET      TP39_SET
#define CLKOUT_CLEAR    TP39_CLEAR
#define CLKOUT_TOGGLE   TP39_TOGGLE

#define SWITCH_CLOSED   0
#define SWITCH_OPEN     1
#define SWITCH_TRIS     TP27_TRIS    
#define SWITCH_WR       TP27_WR
#define SWITCH_RD       TP27_RD    
#define SWITCH_INIT_OUTPUT   TP27_INIT_OUTPUT   // Initializine the switch as output
#define SWITCH_INIT_INPUT    TP27_INIT_INPUT   // Initializine the switch as input
#define SWITCH_SET      TP27_SET
#define SWITCH_CLEAR    TP27_CLEAR
#define SWITCH_TOGGLE   TP27_TOGGLE
    
#define PWM1H_TRIS     TP45_TRIS    
#define PWM1H_WR       TP45_WR
#define PWM1H_RD       TP45_RD    
#define PWM1H_INIT_OUTPUT   TP45_INIT_OUTPUT   // Initializine the PWM pin as output
#define PWM1H_INIT_INPUT    TP45_INIT_INPUT   // Initializine the PWM pin as input
#define PWM1H_SET      TP45_SET
#define PWM1H_CLEAR    TP45_CLEAR
#define PWM1H_TOGGLE   TP45_TOGGLE

#define PWM1L_TRIS     TP47_TRIS    
#define PWM1L_WR       TP47_WR
#define PWM1L_RD       TP47_RD    
#define PWM1L_INIT_OUTPUT   TP47_INIT_OUTPUT   // Initializine the PWM pin as output
#define PWM1L_INIT_INPUT    TP47_INIT_INPUT   // Initializine the PWM pin as input
#define PWM1L_SET      TP47_SET
#define PWM1L_CLEAR    TP47_CLEAR
#define PWM1L_TOGGLE   TP47_TOGGLE

/* DECLARE ANALOG INPUTS */
    
#define ANIN_TP03_TRIS     TP03_TRIS
#define ANIN_WR       TP03_WR
#define ANIN_RD       TP03_RD
#define ANIN__ANSEL    _ANSELB2 // analog/digital pin configuration register bit
#define ANIN_INIT_ANALOG  {VSNS_DCSUP_ANSEL = 1; VSNS_DCSUP_WR = PINSTATE_HIGH; VSNS_DCSUP_TRIS = PINDIR_INPUT;} // initialization macro for analog input
#define ANIN_INIT_OUTPUT  {VSNS_DCSUP_ANSEL = 0; VSNS_DCSUP_WR = PINSTATE_LOW; VSNS_DCSUP_TRIS = PINDIR_OUTPUT;} // initialization macro for digital output
#define ANIN_INIT_INPUT   {VSNS_DCSUP_ANSEL = 0; VSNS_DCSUP_WR = PINSTATE_HIGH; VSNS_DCSUP_TRIS = PINDIR_INPUT;} // initialization macro for digital input
#define ANIN_SET     { asm volatile ("bset _LATA, #0 \n"); }
#define ANIN_CLEAR   { asm volatile ("bclr _LATA, #0 \n"); }
#define ANIN_TOGGLE  { asm volatile ("btg  _LATA, #0 \n"); }
#define ANIN_ADCCORE  0   // index starts from zero, last index indicated shared adC core
#define ANIN_IS_SHARED_CORE 1   // index indicating if ACD core is dedicated or shared
#define ANIN_ADC_AN_INPUT 0   // ANx input pin number
#define ANIN_ADCBUF   ADCBUF0 // ADC buffer register for this input
#define ANIN_ADC_ANIE ADIELbits.IE0
#define ANIN_ADC_ANEIE ADEIELbits.EIEN0
#define ANIN_ADC_IF   _ADCAN0IF // interrupt flag bit
#define ANIN_ADC_IE   _ADCAN0IE // interrupt enable bit
#define ANIN_ADC_IP   _ADCAN0IP // interrupt priority for this analog input
#define ANIN_ADC_RDY  _AN0RDY // ADC buffer ready bit
#define ANIN_ADC_Interrupt _ADCAN0Interrupt 

    
#ifdef	__cplusplus
}
#endif

#endif	/* HAL_BOARD_PINMAP_H */

// EOF
