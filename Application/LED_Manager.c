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

/*
uint32_t Buthon_interrump(uint_T numPort)
{
	uint32_t result = 1;
	//PORTB Clock Source enable
	CLOCK_EnableClock(kCLOCK_PortB);

	//PIN mux
	port_pin_config_t ls_LedPinMux;
	ls_LedPinMux.mux = kPORT_PinDisabledOrAnalog;

	PORT_SetPinConfig(PORTB, numPort, &ls_LedPinMux);

	gpio_pin_config_t ls_LedPinCfg;
	gpio_pin_config_t* lps_LedPinCfg;

	lps_LedPinCfg = &ls_LedPinCfg;

	ls_LedPinCfg.pinDirection = kGPIO_DigitalInput;
	ls_LedPinCfg.outputLogic = FALSE;

	//PIN Initialization
	GPIO_PinInit(GPIOB, numPort, lps_LedPinCfg);

	if(lps_LedPinCfg->outputLogic == 0)
	{
		result = 0;
	}


	return result;
}
*/
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


