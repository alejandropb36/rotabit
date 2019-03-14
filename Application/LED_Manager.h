/*
 * LED_Manager.h
 *
 *  Created on: 13/03/2019
 *      Author: Alejandro
 */

#ifndef LED_MANAGER_H_
#define LED_MANAGER_H_

/*Defines*/
#define LED_GREEN_PIN_NUMBER ((uint32_t)19U)
#define LED_RED_PIN_NUMBER ((uint32_t)18U)
#define LED_BLUE_PIN_NUMBER ((uint32_t)13U)

#define LED_PIN_0 ((uint32_t)0U)
#define LED_PIN_1 ((uint32_t)1U)
#define LED_PIN_2 ((uint32_t)2U)
#define LED_PIN_3 ((uint32_t)3U)

#define OUT_PIN_PWR ((uint32_t)8U)
#define INT_PIN ((uint32_t)9U)

#define MAX_TIME ((uint32_t)1000000)

/*Protypes*/
extern void LED_Manager_Task(void);
extern void Led_On_PortB(uint32_t numPort);
extern void Led_Off_PortB(uint32_t numPort);
extern void sleep(uint32_t time);
extern void Buthon_interrump(void);
extern void RotaBit(void);

#endif /* LED_MANAGER_H_ */
