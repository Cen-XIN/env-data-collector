/*
 * Version 1.1 (2018-08-31)
 * Author: Cen XIN
 *
 * This file is a part of EnvDataConllector.
 *
 * EnvDataConllector is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EnvDataConllector is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EnvDataConllector. If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef ENVDATACOLLECTOR_UART_H
#define ENVDATACOLLECTOR_UART_H

#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <termios.h>

int uartfd;//UART fd

/**
 * Open UART
 * @param dev absolute or relative directory of the target device
 * @return 0 for succeed | -1 for error
 */
int openUart(char *dev);

/**
 * Initialize UART optioins
 * For the safety, just use a fixed option set (9600, 8, N, 1)
 * @return 0
 */
int initUart();

/**
 * Close UART
 * @return 0
 */
int closeUart();

/**
 * Receive data from UART
 * @param data receive buffer
 * @param datalen fixed data length
 * @return len for successfully received length | -1 for failed
 */
int recvFromUart(unsigned char *data, int datalen);

/**
 * Send data to UART
 * @param data send buffer
 * @param datalen fixed data length
 * @return len for successfully sent length | -1 for failed
 */
int sendToUart(unsigned char *data, int datalen);

#endif //ENVDATACOLLECTOR_UART_H
