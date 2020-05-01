/**
 ******************************************************************************
 * @file    utilities.h
 * @brief   Contains helper code
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

#pragma once

#include <stdio.h>
#include <stdint.h>

/** Enable debug prints */
#define DBUG_EN 1
/** Enable information prints */
#define INFO_EN 1
/** Enable warning prints */
#define WARN_EN 1
/** Enable error prints */
#define ERRR_EN 1

#if defined(SEMIHOSTING) || defined(__x86_64__)
extern void initialise_monitor_handles(void);
// TODO: Handle printf if not semihosting
/** Print as debug output */
#define DBUG(fmt...) if(DBUG_EN){printf("[DBUG] " fmt); printf("\n");}
/** Print as information output */
#define INFO(fmt...) if(INFO_EN){printf("[INFO] " fmt); printf("\n");}
/** Print as warning output */
#define WARN(fmt...) if(WARN_EN){printf("[WARN] " fmt); printf("\n");}
/** Print as error output */
#define ERRR(fmt...) if(ERRR_EN){printf("[ERRR] " fmt); printf("\n");}

/** Print start part of the debug output. This is used for printing in loops */
#define DBUG_CUST_S(fmt...) if(DBUG_EN){printf("[DBUG] " fmt);}
#define DBUG_CUST_C(fmt...) if(DBUG_EN){printf(fmt);}
#define DBUG_CUST_E(fmt...) if(DBUG_EN){printf(fmt "\n");}

/** Print start part of information output. This is used for printing in loops. */
#define INFO_CUST_S(fmt...) if(INFO_EN){printf("[INFO] " fmt);}
#define INFO_CUST_C(fmt...) if(INFO_EN){printf(fmt);}
#define INFO_CUST_E(fmt...) if(INFO_EN){printf(fmt "\n");}
#endif /* SEMIHOSTING */

// Exception handling
/** Error_Handler is called by STM32 HAL */
#define Error_Handler    FaultHandler
/** @brief Automating exception analysis
 *         https://interrupt.memfault.com/blog/cortex-m-fault-debug#automating-the-analysis
 */
void FaultHandler();
typedef struct __attribute__((packed)) context_state_frame {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t return_address;
    uint32_t xpsr;

} sContextStateFrame;


#define DUMMY_SYS_ADDR 0xA5A5A5A5
