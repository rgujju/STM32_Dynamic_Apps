/**
 ******************************************************************************
 * @file    main.c
 * @brief   Main file
 *          Load the app and also turn on a LED
 ******************************************************************************
 * @attention
 *
 * LICENSE
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Rohit Gujarathi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <drivers/gpio.h>

#include "utilities.h"
#include "sys_module/syscall.h"
#include "app_loader/app_loader.h"

// Add the app
#include "blinky_tinf.h"

int main ( void ) {
#if SEMIHOSTING
    //initialise_monitor_handles();
    //setbuf(stdout, NULL);
    //~ setvbuf(stdout, NULL, _IONBF, 0);
    INFO("Main program start");
#endif
	
	initLeds();
    // Load the app defined in blinky_tinf.h
    if(LoadApp(app)<0){
		while(1){
		}
	}

    uint8_t led_ret = sys.SetLed(0, LED_ON);
	DBUG("Return value of SetLed = %d", led_ret);
    
    while (1) {
    }
    return 0;
}

