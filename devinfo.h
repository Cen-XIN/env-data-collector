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

#ifndef ENVDATACOLLECTOR_DEVINFO_H
#define ENVDATACOLLECTOR_DEVINFO_H

#define FACTORY_NUM 1 //TODO: TO BE REVISED AS FILE-READ MOD IF NEEDED

#define SOIL_TEMP_HUM_SENSOR_ADDR   0x01
#define AIR_TEMP_HUM_SENSOR_ADDR    0x02
#define PM1_PM2_5_PM10_SENSOR_ADDR  0x03
#define PH_TEMP_SENSOR_ADDR         0x04
#define NH3_SENSOR_ADDR             0x05

#define IS_SOIL_SENSOR  1
#define IS_AIR_SENSOR   2
#define IS_PH_SENSOR    3
#define IS_PM_SENSOR    4
#define IS_NH3_SENSOR   5

#define IS_TEMP     1
#define IS_HUM      2
#define IS_PH       3
#define IS_PM1      4
#define IS_PM2_5    5
#define IS_PM10     6
#define IS_NH3      7

#define SOIL_RECV_LEN   9
#define AIR_RECV_LEN    9
#define PM_RECV_LEN     11
#define PH_RECV_LEN     9
#define NH3_RECV_LEN    8

#define UART_SEND_LEN       8

static char *dev = "/dev/ttyUSB0";

#endif //ENVDATACOLLECTOR_DEVINFO_H
