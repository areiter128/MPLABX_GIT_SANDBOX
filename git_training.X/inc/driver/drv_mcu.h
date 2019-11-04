//=======================================================================================================
// Copyright(c) 2018 Microchip Technology Inc. and its subsidiaries.
// Subject to your compliance with these terms, you may use Microchip software and any derivatives
// exclusively with Microchip products. It is your responsibility to comply with third party license
// terms applicable to your use of third-party software (including open source software) that may
// accompany Microchip software.
// THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
// APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND
// FITNESS FOR A PARTICULAR PURPOSE.
// IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
// LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF
// MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT
// ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT
// EXCEED THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
//=======================================================================================================

//=======================================================================================================
// @file drv_mcu.c
//
// @brief contains the functions for configuration and initializing the microcontroller
//
// @version v1.0
// @date 2019-11-04
// @author M52409
//
//=======================================================================================================
#ifndef _DRV_MCU_H_
#define _DRV_MCU_H_


#ifndef FCY
#define FCY     100000000ULL  // 100 MHz - Define instruction rate for delay routine
                        // __delay_ms(x);
                        // __delay_us(x);
                        // along with: #include <libpic30.h>  // Needed for delay function
#endif

// FVCO = FPLLI * M / N1 / N2 / N3
// FOSC = FVCO/2, when NOSC = S1/S3
// FCY = FOSC/2, , when DOZEN = 0 OR DOZE = 0
// FCY = FPLLI * M / N1 / N2 / N3 / 2UL / 2UL

#define FOSC        FCY * 2UL

#define N1          1UL       // PLLPRE
#define N2          2UL       // POST1DIV
#define N3          2UL       // POST2DIV
#define PLLVCODIV   0         // 0:/4, 1:/3, 2:/2, 3:/1 

#define POSC_FREQ   8000000UL
#ifdef POSC_FREQ
#define FPLLI       POSC_FREQ
#else
#define FPLLI       8000000UL      // FRC = 8MHz
#endif

// PLLFBDIV
// Calculate PLL multiplier based on FCY
#define M   FCY * N1 * N2 * N3 * 2UL * 2UL / FPLLI

#define AFPLLO      500000000ULL  // 500 MHz - Aux PLL Output

// AFPLLO = AFPLLI * AuxM / AuxN1 / AuxN2 / AuxN3

#define AuxN1       1UL       // APLLPRE
#define AuxN2       2UL       // APOST1DIV
#define AuxN3       1UL       // APOST2DIV
#define AuxDIV      0         // 0:/4, 1:/3, 2:/2, 3:/1 

#ifdef POSC_FREQ
#define AFPLLI      POSC_FREQ
#else
#define AFPLLI      8000000UL      // FRC = 8MHz
#endif

// APLLFBDIV
// Calculate PLL multiplier based on AFPLLO
#define AuxM   AFPLLO * AuxN1 * AuxN2 * AuxN3 / AFPLLI

//=======================================================================================================
//  @brief  Initializes the clock
//  @note   Call this as the first function in main.c
//=======================================================================================================
void Drv_MCU_InitClock(void);



#endif  // _DRV_MCU_H_
