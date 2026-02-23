/*
 * TCA9548.h
 *
 *  Created on: Feb 23, 2026
 *      Author: Bacnk
 */
#include "main.h"

#ifndef SRC_TCA9548_H_
#define SRC_TCA9548_H_
#define TCA95487_CHANNEL_0 0x01
#define TCA95487_CHANNEL_1 0x02
#define TCA95487_CHANNEL_2 0x04
#define TCA95487_CHANNEL_3 0x08
#define TCA95487_CHANNEL_4 0x10
#define TCA95487_CHANNEL_5 0x20
#define TCA95487_CHANNEL_6 0x40
#define TCA95487_CHANNEL_7 0x80

#define TCA9548A_BASE_ADDR     0x70


#define TCA9548A_ADDR(a2, a1, a0) \
    (TCA9548A_BASE_ADDR | ((a2 & 0x01) << 2) | ((a1 & 0x01) << 1) | (a0 & 0x01))
typedef struct {
    I2C_HandleTypeDef* hi2c;
    uint8_t address;
} TCA9548A_HandleTypeDef;
HAL_StatusTypeDef TCA9548A_Init(TCA9548A_HandleTypeDef* htca, I2C_HandleTypeDef* hi2c, uint8_t a2, uint8_t a1, uint8_t a0);
HAL_StatusTypeDef TCA9548A_SelectChannel(TCA9548A_HandleTypeDef* htca, uint8_t channel);
HAL_StatusTypeDef TCA9548A_DisableAllChannels(TCA9548A_HandleTypeDef* htca);
HAL_StatusTypeDef TCA9548A_OpenAllChannels(TCA9548A_HandleTypeDef* htca);
HAL_StatusTypeDef TCA9548A_DisableChannel(TCA9548A_HandleTypeDef* htca, uint8_t channel);
HAL_StatusTypeDef TCA9548A_WriteByte(TCA9548A_HandleTypeDef* htca, uint8_t data);
HAL_StatusTypeDef TCA9548A_ReadByte(TCA9548A_HandleTypeDef* htca, uint8_t* data);
#endif /* SRC_TCA9548_H_ */
