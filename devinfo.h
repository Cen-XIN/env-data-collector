/*
 * Version 1.0 (2018-06-20)
 * Copyright (c) Cen XIN
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
