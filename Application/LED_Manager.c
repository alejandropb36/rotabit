/*
 * LED_Manager.c
 *
 *  Created on: 13/03/2019
 *      Author: Alejandro
 */

#include "stdtypes.h"
#include "stdint.h"
#include "LED_Manager.h"
#include "MKL25Z4.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "fsl_gpio.h"




void Led_On_PortB(uint32_t numPort)
{
	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortB);

	//PIN mux
	port_pin_config_t ls_LedPinMux;
	ls_LedPinMux.mux = kPORT_MuxAsGpio;
	//ls_LedGreenPinMux.pullSelect = kPORT_PullDisable;
	PORT_SetPinConfig(PORTB, numPort, &ls_LedPinMux);

	gpio_pin_config_t ls_LedPinCfg;
	gpio_pin_config_t* lps_LedPinCfg;

	lps_LedPinCfg = &ls_LedPinCfg;

	ls_LedPinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedPinCfg.outputLogic = TRUE;

	//PIN Initialization
	GPIO_PinInit(GPIOB, numPort, lps_LedPinCfg);
}

void Led_Off_PortB(uint32_t numPort)
{
	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortB);

	//PIN mux
	port_pin_config_t ls_LedPinMux;
	ls_LedPinMux.mux = kPORT_PinDisabledOrAnalog;
	//ls_LedPinMux.mux = kPORT_MuxAsGpio;
	//ls_LedGreenPinMux.pullSelect = kPORT_PullDisable;
	PORT_SetPinConfig(PORTB, numPort, &ls_LedPinMux);

	gpio_pin_config_t ls_LedPinCfg;
	gpio_pin_config_t* lps_LedPinCfg;

	lps_LedPinCfg = &ls_LedPinCfg;

	ls_LedPinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedPinCfg.outputLogic = TRUE;

	//PIN Initialization
	GPIO_PinInit(GPIOB, numPort, lps_LedPinCfg);
}

void sleep(uint32_t time)
{
	for(uint32_t i = 0; i < time; i++){}
}

void Buthon_interrump(void)
{
	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortB);

	//PIN mux
	port_pin_config_t ls_LedPinMux;
	ls_LedPinMux.mux = kPORT_PinDisabledOrAnalog;
	//ls_LedPinMux.mux = kPORT_MuxAsGpio;
	//ls_LedGreenPinMux.pullSelect = kPORT_PullDisable;
	PORT_SetPinConfig(PORTB, numPort, &ls_LedPinMux);

	gpio_pin_config_t ls_LedPinCfg;
	gpio_pin_config_t* lps_LedPinCfg;

	lps_LedPinCfg = &ls_LedPinCfg;

	ls_LedPinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedPinCfg.outputLogic = TRUE;

	//PIN Initialization
	GPIO_PinInit(GPIOB, numPort, lps_LedPinCfg);
}

void RotaBit(void)
{
	Led_On_PortB(LED_PIN_0);
	sleep(MAX_TIME);
	Led_Off_PortB(LED_PIN_0);

	sleep(MAX_TIME);
	Led_On_PortB(LED_PIN_1);
	sleep(MAX_TIME);
	Led_Off_PortB(LED_PIN_1);

	sleep(MAX_TIME);
	Led_On_PortB(LED_PIN_2);
	sleep(MAX_TIME);
	Led_Off_PortB(LED_PIN_2);

	sleep(MAX_TIME);
	Led_On_PortB(LED_PIN_3);
	sleep(MAX_TIME);
	Led_Off_PortB(LED_PIN_3);
	sleep(MAX_TIME);
}

/*
void LED_Manager_Task(void)
{
	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortB);

	//PIN mux
	port_pin_config_t ls_LedGreenPinMux;
	ls_LedGreenPinMux.mux = kPORT_MuxAsGpio;
	//ls_LedGreenPinMux.pullSelect = kPORT_PullDisable;
	PORT_SetPinConfig(PORTB, LED_GREEN_PIN_NUMBER, &ls_LedGreenPinMux);

	gpio_pin_config_t ls_LedGreenPinCfg;
	gpio_pin_config_t* lps_LedGreenPinCfg;

	lps_LedGreenPinCfg = &ls_LedGreenPinCfg;

	ls_LedGreenPinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedGreenPinCfg.outputLogic = TRUE;

	//PIN Initialization
	GPIO_PinInit(GPIOB, LED_GREEN_PIN_NUMBER, lps_LedGreenPinCfg);



	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortB);

	//PIN mux
	port_pin_config_t ls_LedRedPinMux;
	ls_LedRedPinMux.mux = kPORT_MuxAsGpio;
	//ls_LedGreenPinMux.pullSelect = kPORT_PullDisable;
	PORT_SetPinConfig(PORTB, LED_RED_PIN_NUMBER, &ls_LedRedPinMux);

	gpio_pin_config_t ls_LedRedPinCfg;
	gpio_pin_config_t* lps_LedRedPinCfg;

	lps_LedRedPinCfg = &ls_LedRedPinCfg;

	ls_LedRedPinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedRedPinCfg.outputLogic = TRUE;

	//PIN Initialization
	GPIO_PinInit(GPIOB, LED_RED_PIN_NUMBER, lps_LedRedPinCfg);


	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortD);

	//PIN mux
	port_pin_config_t ls_LedBluePinMux;
	ls_LedBluePinMux.mux = kPORT_MuxAsGpio;
	//ls_LedGreenPinMux.pullSelect = kPORT_PullDisable;
	PORT_SetPinConfig(PORTD, LED_BLUE_PIN_NUMBER, &ls_LedBluePinMux);

	gpio_pin_config_t ls_LedBluePinCfg;
	gpio_pin_config_t* lps_LedBluePinCfg;

	lps_LedBluePinCfg = &ls_LedBluePinCfg;

	ls_LedBluePinCfg.pinDirection = kGPIO_DigitalOutput;
	ls_LedBluePinCfg.outputLogic = FALSE;

	//PIN Initialization
	GPIO_PinInit(GPIOD, LED_BLUE_PIN_NUMBER, lps_LedRedPinCfg);

	return;
}
*/

