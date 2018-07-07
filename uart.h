/*
 * Version 1.0 (2018-06-20)
 * Copyright (c) Cen XIN
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
