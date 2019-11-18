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
// @file project_setting.h
//
// @brief contains some project specific settings regarding the operating system parts and application
//
// @version v1.0
// @date 2019-08-22
// @author M52409
//
//=======================================================================================================

#ifndef _PROJECT_SETTINGS_H_
#define	_PROJECT_SETTINGS_H_

//some parts of the software is being used in different projects, so we make some board defines

#define PROJECT_SETTINGS_BOARD_MPA13_CK 1       // MPA13_CK has a single core dsPic33CK on board

#define PROJECT_SETTINGS_BOARD_EXPANDER_CK 0    // BOARD_EXPANDER_CK single core dsPic33CK for testing basic stuff

#define PROJECT_SETTINGS_BOARD_MPA9_CH  0       // MPA9_CH has a dual core dsPic33CH on board

#define PROJECT_SETTINGS_BOARD_MPA_9_CK  0      // MPA_9_CK is a dsPIC33CK256MP206 single core board for a customer


//=======================================================================================================
//  OS Settings for the OS_Scheduler
//
//  Decide which timing precision you need for your project and choose the right scheduler
//-------------------------------------------------------------------------------------------------------
#define OS_USE_SCHEDULER_100us 1
#define OS_USE_SCHEDULER_1ms   0
//=======================================================================================================


//=======================================================================================================
//  OS Settings for the OS_Scheduler
//
//  Decide if you want to use OS_Systime in your project
//-------------------------------------------------------------------------------------------------------
    #define OS_USE_SYSTIME 0
//=======================================================================================================


//=======================================================================================================
//  OS Settings for OS_Timer
//-------------------------------------------------------------------------------------------------------
    #define OS_TIMER_NUMBER_OF_TIMERS       0
//-------------------------------------------------------------------------------------------------------
//  Application specific Timers:
    #define OS_TIMER_COUNTDOWN_COILSWITCH   0
//=======================================================================================================





#endif	//_PROJECT_SETTINGS_H_

