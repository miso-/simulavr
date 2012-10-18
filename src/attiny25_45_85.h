/*
 ****************************************************************************
 *
 * simulavr - A simulator for the Atmel AVR family of microcontrollers.
 * Copyright (C) 2001, 2002, 2003   Klaus Rudolph       
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 ****************************************************************************
 *
 *  $Id$
 */

#ifndef ATTINY25
#define ATTINY25

#include "avrdevice.h"
#include "hardware.h"
#include "rwmem.h"
#include "hwtimer/timerprescaler.h"
#include "hwtimer/timerirq.h"
#include "hwtimer/hwtimer.h"
#include "externalirq.h"
#include "hwuart.h"

//! AVRDevice class for ATTiny25/45/85
class AvrDevice_attinyX5: public AvrDevice {
    
    public:
        HWPort *portb;                  //!< port B (only 6 bit)

        GPIORegister *gpior0_reg;       //!< GPIOR0 Register
        GPIORegister *gpior1_reg;       //!< GPIOR1 Register
        GPIORegister *gpior2_reg;       //!< GPIOR2 Register

        IOSpecialReg      *gtccr_reg;   //!< GTCCR IO register
        HWPrescaler       *prescaler0;  //!< prescaler unit for timer 0 (10 bit w. reset/sync and only sys clock)
        HWTimer8_2C*      timer0;       //!< timer 0 unit
        TimerIRQRegister* timer01irq;   //!< timer interrupt unit for timer 0 and 1

        /*! Creates the device for ATMega48/88/168/328
          @param ram_bytes how much SRAM does the device own
          @param flash_bytes how much flash memory does the device own
          @param ee_bytes how much EEPROM space does the device own */
        AvrDevice_attinyX5(unsigned ram_bytes,
                           unsigned flash_bytes,
                           unsigned ee_bytes);
        ~AvrDevice_attinyX5(); 
};

//! AVR device class for ATTiny25, see AvrDevice_attinyX5.
class AvrDevice_attiny25: public AvrDevice_attinyX5 {
    public:
        //! Creates the device for ATTiny25, see AvrDevice_attinyX5.
        AvrDevice_attiny25() : AvrDevice_attinyX5(128, 2 * 1024, 128) {}
};

//! AVR device class for ATTiny45, see AvrDevice_attinyX5.
class AvrDevice_attiny45: public AvrDevice_attinyX5 {
    public:
        //! Creates the device for ATTiny45, see AvrDevice_attinyX5.
        AvrDevice_attiny45() : AvrDevice_attinyX5(256, 4 * 1024, 256) {}
};

//! AVR device class for ATTiny85, see AvrDevice_attinyX5.
class AvrDevice_attiny85: public AvrDevice_attinyX5 {
    public:
        //! Creates the device for ATTiny85, see AvrDevice_attinyX5.
        AvrDevice_attiny85() : AvrDevice_attinyX5(512, 8 * 1024, 512) {}
};

#endif
