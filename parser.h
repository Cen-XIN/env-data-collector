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
