/*
 * Version 1.0 (2018-06-20)
 * Copyright (c) Cen XIN
 */

#include "parser.h"

int parseTempAndHum(unsigned char *datagram, float *result) {
    unsigned short tempRaw, humRaw;
    float tempRes, humRes;

    if(datagram[0] != SOIL_TEMP_HUM_SENSOR_ADDR && datagram[0] != AIR_TEMP_HUM_SENSOR_ADDR) {
        printf("Wrong address!\n");
        return -1;
    }

    tempRaw = 0x0000;
    humRaw = 0x0000;

    humRaw |= datagram[3] << 8;
    humRaw |= datagram[4];
    tempRaw |= datagram[5] << 8;
    tempRaw |= datagram[6];

    humRes = (float)(((short)humRaw) / 10.0);
    tempRes = (float)(((short)tempRaw) / 10.0);

    result[0] = humRes;
    result[1] = tempRes;

    if(result[0] <= 0 || result[1] >= 100) {
        printf("Failed to parse temp & hum datagram!\n");
        return -1;
    }
    else {
        printf("Successfully parsed temp & hum datagram!\n");
        return 0;
    }
}

int parsePM(unsigned char *datagram, int *result) {
    unsigned short pm1Raw, pm2_5Raw, pm10Raw;

    if(datagram[0] != PM1_PM2_5_PM10_SENSOR_ADDR) {
        printf("Wrong address!\n");
        return -1;
    }

    pm1Raw = 0x0000;
    pm2_5Raw = 0x0000;
    pm10Raw = 0x0000;

    pm1Raw |= datagram[3] << 8;
    pm1Raw |= datagram[4];
    pm2_5Raw |= datagram[5] << 8;
    pm2_5Raw |= datagram[6];
    pm10Raw |= datagram[7] << 8;
    pm10Raw |= datagram[8];

    result[0] = (int)pm1Raw;
    result[1] = (int)pm2_5Raw;
    result[2] = (int)pm10Raw;

    if(result[0] == 0 && result[1] == 0 && result[2] == 0) {
        printf("Failed to parse PM1, PM2.5, PM10 datagram!\n");
        return -1;
    }else {
        printf("Successfully parsed PM1, PM2.5, PM10 datagram!\n");
        return 0;
    }
}

int parsePhAndTemp(unsigned char *datagram, float *result) {
    unsigned short tempRaw, phRaw;
    float tempRes, phRes;

    if(datagram[0] != PH_TEMP_SENSOR_ADDR) {
        printf("Wrong address!\n");
        return -1;
    }

    tempRaw = 0x0000;
    phRaw = 0x0000;

    tempRaw |= datagram[3] << 8;
    tempRaw |= datagram[4];
    phRaw |= datagram[5] << 8;
    phRaw |= datagram[6];

    tempRes = (float)(((short)tempRaw) / 10.0);
    phRes = (float)(((short)phRaw) / 10.0);

    result[0] = tempRes;
    result[1] = phRes;

    if(result[0] >= 100 || result[1] < 0 || result[1] > 14) {
        printf("Failed to parse pH & temp datagram!\n");
        return -1;
    }else {
        printf("Successfully parsed pH & temp datagram!\n");
        return 0;
    }
}

