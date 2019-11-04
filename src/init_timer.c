/*
 * File:   init_timer.c
 * Author: M91406.LA
 *
 * Created on November 2, 2019, 1:44 PM
 */


#include <xc.h>
#include <stdint.h>

/*!ConfigureSystemTimer()
 * *********************************************************************************
 * Summary: Initialize standard 16-bit timer
 * 
 * Description:
 * This timer is used to create a deterministic state machine base clock.
 * This base clock period and related state machine call time step will help
 * to organize and manage control step intervals for soft-start, fault-handling
 * and auto-recovery of the power supply.
 * 
 * ********************************************************************************/

volatile uint16_t ConfigureSystemTimer(void) {
    
    T1CONbits.TON = 0; // Timer1 = disabled
    T1CONbits.TSIDL = 0; // Timer1 Stop in Idle Mode = Continues module operation in Idle mode
    T1CONbits.TGATE = 0; // Timer1 Gated Time Accumulation Enable = Gated time accumulation is disabled
    T1CONbits.TCKPS = 0b00; // Timer1 Input Clock Prescale Select = 1:1
    T1CONbits.TSYNC = 0; // Timer1 External Clock Input Synchronization Selection = Does not synchronize external clock input
    T1CONbits.TCS = 0; // Timer1 Clock Source Selection = Internal clock (FP)
    
    PR1 = 9999; // Timer is set up for 100 usec period
            
    _T1IP = 1;
    _T1IF = 0;
    _T1IE = 0;
    
    T1CONbits.TON = 1; // Timer1 = enabled
    
    return (1);
}
