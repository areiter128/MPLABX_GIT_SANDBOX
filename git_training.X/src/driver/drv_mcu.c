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
// @date 2019-08-16
// @author M52409
//
//=======================================================================================================
#include "driver/drv_mcu.h"
#include <xc.h>
// 16-bit peripheral library for access to delay_ms() function

//=======================================================================================================
// permanent configuration of the microcontroller with "fuses"
//-------------------------------------------------------------------------------------------------------
// FSEC
#pragma config BWRP = OFF           // Boot Segment Write-Protect bit (Boot Segment may be written)
#pragma config BSS = DISABLED       // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSEN = OFF           // Boot Segment Control bit (No Boot Segment)
#pragma config GWRP = OFF           // General Segment Write-Protect bit (General Segment may be written)
#pragma config GSS = DISABLED       // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF           // Configuration Segment Write-Protect bit (Configuration Segment may be written)
#pragma config CSS = DISABLED       // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = OFF        // Alternate Interrupt Vector Table bit (Disabled AIVT)
//-------------------------------------------------------------------------------------------------------
// FBSLIM
#pragma config BSLIM = 0x1FFF       // Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address  limit)
//-------------------------------------------------------------------------------------------------------
// FOSCSEL
#pragma config FNOSC = FRC          // Oscillator Source Selection (Internal Fast RC (FRC))
#pragma config IESO = OFF           // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)
//-------------------------------------------------------------------------------------------------------
// FOSC
//#pragma config POSCMD = XT          // Primary Oscillator Mode Select bits (Primary oscillator = external Crytal)
#pragma config POSCMD = EC          // Primary Oscillator Mode Select bits (Primary oscillator = External Clock)
#pragma config OSCIOFNC = ON        // OSC2 Pin Function bit (OSC2 is general purpose digital I/O pin)
#pragma config FCKSM = CSECMD       // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
//#pragma config XTCFG = G1           // XT Config (8-16 MHz crystals)
#pragma config XTCFG = G3           // XT Config (24-32 MHz crystals)
#pragma config XTBST = ENABLE       // XT Boost (Boost the kick-start)
//-------------------------------------------------------------------------------------------------------
// FWDT
#pragma config RWDTPS = PS1048576   // Run Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config RCLKSEL = LPRC       // Watchdog Timer Clock Select bits (Always use LPRC)
//#pragma config WINDIS = ON          // Watchdog Timer Window Enable bit (Watchdog Timer operates in Non-Window mode)
#pragma config WINDIS = OFF         // Watchdog Timer Window Enable bit (Watchdog Timer operates in Window mode)
#pragma config WDTWIN = WIN25       // Watchdog Timer Window Select bits (WDT Window is 25% of WDT period)
#pragma config SWDTPS = PS1048576   // Sleep Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config FWDTEN = ON_SW       // Watchdog Timer Enable bit (WDT controlled via SW, use WDTCON.ON bit)
//-------------------------------------------------------------------------------------------------------
// FICD
#pragma config ICS = PGD2           // ICD Communication Channel Select bits (Communicate on PGC3 and PGD3)
#pragma config JTAGEN = OFF         // JTAG Enable bit (JTAG is disabled)
#pragma config NOBTSWP = DISABLED   // BOOTSWP instruction disable bit->BOOTSWP instruction is disabled
//-------------------------------------------------------------------------------------------------------
// FDMT
#pragma config DMTIVTL = 0xFFFF     // Dead Man Timer Interval low word (Lower 16 bits of 32 bitDMT window interval (0-0xFFFF))
#pragma config DMTIVTH = 0xFFFF     // Dead Man Timer Interval high word (Uper 16 bits of 32 bitDMT window interval (0-0xFFFF))
#pragma config DMTCNTL = 0xFFFF     // Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF) (Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF))
#pragma config DMTCNTH = 0xFFFF     // Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF) (Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF))
#pragma config DMTDIS = OFF         // Dead Man Timer Disable bit (Dead Man Timer is Disabled and can be enabled by software)
//-------------------------------------------------------------------------------------------------------
// FDEVOPT
#pragma config ALTI2C1 = OFF        // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config ALTI2C2 = ON         // Alternate I2C2 Pin bit (I2C2 mapped to SDA2/SCL2 pins)
#pragma config SMBEN = SMBUS        // SM Bus Enable (SMBus input threshold is enabled)
#pragma config SPI2PIN = DEDICATED  // SPI2 uses dedicated I/O pins
//-------------------------------------------------------------------------------------------------------
// FALTREG
#pragma config CTXT1 = OFF          // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (Not Assigned)
#pragma config CTXT2 = OFF          // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)
#pragma config CTXT3 = OFF          // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits (Not Assigned)
#pragma config CTXT4 = OFF          // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits (Not Assigned)
//=======================================================================================================


#define CALC_FCY    FPLLI * M / N1 / N2 / N3 / 2UL / 2UL
#if (CALC_FCY != FCY)
#warning "Calculated FCY and defined FCY don't match"
#endif

#define CALC_AFPLLO    AFPLLI * AuxM / AuxN1 / AuxN2 / AuxN3
#if (CALC_AFPLLO != AFPLLO)
#warning "Calculated AFPLLO and defined AFPLLO don't match"
#endif


//=======================================================================================================
//  @brief  Initializes the clock
//  @note   Call this as the first function in main.c
//=======================================================================================================
void Drv_MCU_InitClock(void)
{
    //Switch to FRC (no divider, no PLL), assuming we aren't already running from that.
    if(OSCCONbits.COSC != 0b000)
    {
        __builtin_write_OSCCONH(0x00);  //NOSC = 0b000 = FRC without divider or PLL
        __builtin_write_OSCCONL((OSCCON & 0x7E) | 0x01);  //Clear CLKLOCK and assert OSWEN = 1 to initiate switchover
        //Wait for switch over to complete.
        while(OSCCONbits.COSC != OSCCONbits.NOSC);
    }

    // Configure PLL prescaler, both PLL postscalers, and PLL feedback divider
    CLKDIVbits.PLLPRE   = N1;       // 1
    PLLFBDbits.PLLFBDIV = M;        // 200
    PLLDIVbits.POST1DIV = N2;       // 2
    PLLDIVbits.POST2DIV = N3;       // 2
    // Initiate Clock Switch to POSC with PLL (NOSC = 0b011)
    __builtin_write_OSCCONH(0x03);
    if(OSCCONbits.COSC != OSCCONbits.NOSC)
    {
        __builtin_write_OSCCONL((OSCCON & 0x7F) | 0x01);    //Assert OSWEN and make sure CLKLOCK is clear, to initiate the switching operation
        // Wait for clock switch to finish
        while(OSCCONbits.COSC != OSCCONbits.NOSC);
    }
    

    // Configure AUX PLL
    // The auxiliary clock is needed as a base for the PWMs
    // Attention: at 500 MHz there could be some race conditions in the silicon that can be avoided when
    // turning down the frequency to 400 MHz
    // TODO: check, if we need to turn down the frequency
    
// AFPLLO = AFPLLI * AuxM / AuxN1 / AuxN2 / AuxN3
// AuxN1 1
// AuxN2 2
// AuxN3 1
// AuxDIV      0         // 0:/4, 1:/3, 2:/2, 3:/1 
// AFPLLO = AFPLLI * AuxM / AuxN1 / AuxN2 / AuxN3

    ACLKCON1 = 0x0001;      //APLLPRE = 1:1 mode, POSC as input, PLL off
    ACLKCON1bits.APLLPRE = AuxN1;
    APLLDIV1bits.APOST1DIV = AuxN2;
    APLLDIV1bits.APOST2DIV = AuxN3;
    APLLFBD1 = AuxM;
    APLLDIV1bits.AVCODIV   = 0; 	// default AVCO divider MUX output=  AVCO/4
    ACLKCON1bits.APLLEN = 1;        // Enable the AUX PLL now
}
