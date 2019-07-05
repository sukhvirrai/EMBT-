/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"

#include "pin_mux.h"
#include <stdbool.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_BOARD_TEST_LED_PORT 1U
#define APP_BOARD_TEST_LED_PIN 10U

#define SPEED1_TEST_LED_PORT 1U
#define SPEED1_TEST_LED_PIN 0U
#define SPEED2_TEST_LED_PORT 1U
#define SPEED2_TEST_LED_PIN 14U
#define DIRECTION1_TEST_LED_PORT 1U
#define DIRECTION1_TEST_LED_PIN 13U
#define DIRECTION2_TEST_LED_PORT 1U
#define DIRECTION2_TEST_LED_PIN 12U

#define APP_SW_PORT BOARD_SW1_GPIO_PORT
#define APP_SW_PIN  BOARD_SW1_GPIO_PIN


/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief delay a while.
 */
void delay(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
void delay(void)
{
    volatile uint32_t i = 0;
    for (i = 0; i < 100000; ++i)
    {
        __asm("NOP"); /* delay */
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    uint32_t port_state = 0;

    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput, 0,
    };

    /* Board pin, clock, debug console init */
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    /* enable clock for GPIO*/
    CLOCK_EnableClock(kCLOCK_Gpio0);
    CLOCK_EnableClock(kCLOCK_Gpio1);

    BOARD_InitPins();
    BOARD_BootClockFROHF48M();
    BOARD_InitDebugConsole();

    /* Print a note to terminal. */
    PRINTF("\r\n direction 1");
    PRINTF("\r\n speed 1.\r\n");

    /* Init SW GPIO PORT. */

    GPIO_PortInit(GPIO, SPEED1_TEST_LED_PORT);

    GPIO_PortInit(GPIO, SPEED2_TEST_LED_PORT);

    GPIO_PortInit(GPIO, DIRECTION1_TEST_LED_PORT);

    GPIO_PortInit(GPIO, DIRECTION2_TEST_LED_PORT);



    /* Init output LED GPIO. */
    GPIO_PortInit(GPIO,BOARD_INITPINS_SWITCH1_PORT);
    GPIO_PinInit(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, &led_config);
    GPIO_PinWrite(GPIO, APP_BOARD_TEST_LED_PORT, APP_BOARD_TEST_LED_PIN, 1);



    /* Port masking */
    GPIO_PortMaskedSet(GPIO, APP_BOARD_TEST_LED_PORT, 0x0000FFFF);
    GPIO_PortMaskedWrite(GPIO, APP_BOARD_TEST_LED_PORT, 0xFFFFFFFF);
    port_state_MK1 = GPIO_PortRead(GPIO,SPEED1_TEST_LED_PORT);
    port_state_MK2 = GPIO_PortRead(GPIO,SPEED2_TEST_LED_PORT);
    port_state_MK3 = GPIO_PortRead(GPIO,DIRECTION1_TEST_LED_PORT);
    port_state_MK4 = GPIO_PortRead(GPIO,DIRECTION2_TEST_LED_PORT);
    PRINTF("\r\n Standard port read: %x\r\n", port_state);
    PRINTF("\r\n PRESS SWITCH1: %x\r\n", port_state_MK1);
        PRINTF("\r\n PRESS SWITCH2: %x\r\n", port_state_MK2);
        PRINTF("\r\n PRESS SWITCH3: %x\r\n", port_state_MK3);
        PRINTF("\r\n PRESS SWITCH4: %x\r\n", port_state_MK4);
    port_state = GPIO_PortMaskedRead(GPIO, APP_SW_PORT);
    port_state_MK1 = GPIO_PortMaskedRead(GPIO,SPEED1_TEST_LED_PORT);
        port_state_MK2 = GPIO_PortMaskedRead(GPIO,SPEED2_TEST_LED_PORT);
        port_state_MK3 = GPIO_PortMaskedRead(GPIO,DIRECTION1_TEST_LED_PORT);
        port_state_MK4 = GPIO_PortMaskedRead(GPIO,DIRECTION2_TEST_LED_PORT);
    PRINTF("\r\n Masked port read: %x\r\n", port_state);




    while (1)
    {

    	port_state = GPIO_PortRead(GPIO, APP_SW_PORT);



    	if (!(port_state & (1 << APP_SW_PIN)))
        {
            PRINTF("\r\n Port state: %x\r\n", port_state);
            PRINTF("\r\n Port state:");
            GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
        }
        port_state_MK1 = GPIO_PortRead(GPIO,SPEED1_TEST_LED_PORT );


             if (!(port_state_MK1 & (1 << SPEED1_TEST_LED_PORT)))
             {
            	 PRINTF("\r\n Port state: %x\r\n", port_state);
            	 PRINTF("\r\n SPEED1 FOR M1");
            	 GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
             }
             port_state_MK2 = GPIO_PortRead(GPIO,SPEED2_TEST_LED_PORT );


                  if (!(port_state & (1 << SPEED2_TEST_LED_PORT)))
                  {
                	  PRINTF("\r\n Port state: %x\r\n", port_state);
                	  PRINTF("\r\n SPEED2 FOR M2");
                	  GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
                  }

                port_state = GPIO_PortRead(GPIO, SPEED2_TEST_LED_PORT);



                  if (!(port_state & (1 << DIRECTION1_TEST_LED_PORT)))
                  {
                	  PRINTF("\r\n Port state: %x\r\n", port_state);
                	  PRINTF("\r\n DIRECTION1 FOR M1");
                	  GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
                  }

                 port_state = GPIO_PortRead(GPIO, DIRECTION1_TEST_LED_PORT);


                 if (!(port_state & (1 << DIRECTION2_TEST_LED_PORT)))
                 {
                     PRINTF("\r\n Port state: %x\r\n", port_state);
                     PRINTF("\r\n DIRECTION2 FOR M2");
                     GPIO_PortToggle(GPIO, APP_BOARD_TEST_LED_PORT, 1u << APP_BOARD_TEST_LED_PIN);
                  }

                 port_state = GPIO_PortRead(GPIO, DIRECTION2_TEST_LED_PORT);
                 }
      delay();
    }
}
