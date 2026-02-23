/*
 * TCA9548.c
 *
 *  Created on: Feb 23, 2026
 *      Author: Bacnk
 */
#include "TCA9548.h"
HAL_StatusTypeDef TCA9548A_Init(TCA9548A_HandleTypeDef *htca, I2C_HandleTypeDef *hi2c, uint8_t a2, uint8_t a1, uint8_t a0)
{
    if (htca == NULL || hi2c == NULL)
    {
        return HAL_ERROR;
    }
    htca->hi2c = hi2c;
    htca->address = TCA9548A_ADDR(a2, a1, a0);
    return HAL_OK;
}
HAL_StatusTypeDef  TCA9548A_WriteByte(TCA9548A_HandleTypeDef *htca, uint8_t data)
{
    if (htca == NULL)
    {
        return HAL_ERROR;
    }
    return HAL_I2C_Master_Transmit(htca->hi2c, htca->address, &data, 1, 100);
}
HAL_StatusTypeDef TCA9548A_ReadByte(TCA9548A_HandleTypeDef *htca, uint8_t *data)
{
    if (htca == NULL || data == NULL)
    {
        return HAL_ERROR;
    }
    return HAL_I2C_Master_Receive(htca->hi2c, htca->address, data, 1, 100);
}
HAL_StatusTypeDef TCA9548A_SelectChannel(TCA9548A_HandleTypeDef *htca, uint8_t channel)
{
    if (htca == NULL)
    {
        return HAL_ERROR;
    }
    channel = channel-1;
    uint8_t buff = 0x00;
    buff = 1 << channel;
    return TCA9548A_WriteByte(htca, buff);
}
HAL_StatusTypeDef TCA9548A_DisableAllChannels(TCA9548A_HandleTypeDef *htca)
{
    if (htca == NULL)
    {
        return HAL_ERROR;
    }
    return TCA9548A_WriteByte(htca, 0x00);
}
HAL_StatusTypeDef TCA9548A_OpenAllChannels(TCA9548A_HandleTypeDef *htca)
{
    if (htca == NULL)
    {
        return HAL_ERROR;
    }
    return TCA9548A_WriteByte(htca, 0xFF);
}
HAL_StatusTypeDef TCA9548A_DisableChannel(TCA9548A_HandleTypeDef *htca, uint8_t channel)
{
    if (htca == NULL)
    {
        return HAL_ERROR;
    }
    uint8_t buff;
    if (TCA9548A_ReadByte(htca, &buff) != HAL_OK)
    {
        return HAL_ERROR;
    }
    channel = channel-1;
    buff &= ~(1 << channel);
    return TCA9548A_WriteByte(htca, buff);
}
