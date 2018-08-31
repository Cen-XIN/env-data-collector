/*
 * Version 1.0 (2018-06-20)
 * Copyright (c) Cen XIN
 */

#ifndef ENVDATACOLLECTOR_INST_H
#define ENVDATACOLLECTOR_INST_H

/**
 * Instruction for temperature & humidity sensor of soil (underground)
 */
unsigned char soil_temp_hum_inq[8] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0xc4, 0x0b};

/**
 * Instruction for temperature & humidity sensor of air (indoor)
 */
unsigned char air_temp_hum_inq[8] = {0x02, 0x03, 0x00, 0x00, 0x00, 0x02, 0xc4, 0x38};

/**
 * Instruction for PM1, PM2.5, PM10 sensor (outdoor)
 */
unsigned char pm_inq[8] = {0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x04, 0x29};

/**
 * Instruction for pH sensor (in liquid)
 */
unsigned char ph_temp_inq[8] = {0x04, 0x03, 0x00, 0x00, 0x00, 0x02, 0xc4, 0x5e};

/**
 * Instruction for NH3 (wastes)
 */
unsigned char nh3_inq[8] = {0x05, 0x03, 0x00, 0x00, 0x00, 0x01, 0x85, 0x8E};

#endif //ENVDATACOLLECTOR_INST_H
