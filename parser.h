/*
 * Version 1.0 (2018-06-20)
 * Copyright (c) Cen XIN
 */

#ifndef ENVDATACOLLECTOR_PARSER_H
#define ENVDATACOLLECTOR_PARSER_H

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include "devinfo.h"

/**
 * Parse the temperature and humidity datagram received from UART
 * @param datagram
 * @param result
 * @return 0 for succeed | -1 for error
 */
int parseTempAndHum(unsigned char *datagram, float *result);

/**
 * Parse the PM1/PM2.5/PM10 datagram received from UART
 * @param datagram
 * @param result
 * @return 0 for succeed | -1 for error
 */
int parsePM(unsigned char *datagram, int *result);

/**
 * Parse the Ph and temperature datagram received from UART
 * @param datagram
 * @param result
 * @return 0 for succeed | -1 for error
 */
int parsePhAndTemp(unsigned char *datagram, float *result);

/**
 * Parse the NH3 datagram received from UART
 * @param datagram
 * @param result
 * @return 0 for succeed | -1 for error
 */
int parseNH3(unsigned char *datagram, int *result);

#endif //ENVDATACOLLECTOR_PARSER_H
