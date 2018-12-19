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

#include "dbcomm.h"

void printMySQLError(const char *msg) {
    if (msg)
        printf("%s: %s\n", msg, mysql_error(g_conn));
    else
        puts(mysql_error(g_conn));
}

int execSQL(const char *sql) {
    if (mysql_real_query(g_conn, sql, strlen(sql))){
        printf("Failed to execute SQL!\n");
        return -1;
    }
    return 0;
}

int initMySQL() {
    g_conn = mysql_init(NULL);
    printf("Try to get connection with database...\n");

    if(!mysql_real_connect(g_conn, g_host_name, g_user_name, g_password, g_db_name, g_db_port, NULL, 0)){
        printf("Failed to connect...\n");
        return -1;
    }

    if (execSQL("set names utf8")){
        printf("Failed to initialize...\n");
        return -1;
    }

    printf("Successfully get connection with database!\n");
    return 0;
}

int closeMySQL() {
    mysql_close(g_conn);
    printf("Quit from database...\n");
    return 0;
}

int genTempOrHumOrPhSQL(char *sql, float data, int sensorType, int dataType, unsigned char addr) {
    if (sensorType == IS_SOIL_SENSOR) {
        if (dataType == IS_TEMP) {
            //sprintf(sql, "INSERT INTO soil_temp VALUES (null, %d, %f, \'%s\')", dev_id, data, time_str);
            sprintf(sql, "INSERT INTO env_trace (factory_num, temp_soil) values (%d, %f)", FACTORY_NUM, data);
        } else if (dataType == IS_HUM) {
            //sprintf(sql, "INSERT INTO soil_hum VALUES (null, %d, %f, \'%s\')", dev_id, data, time_str);
            sprintf(sql, "INSERT INTO env_trace (factory_num, hum_soil) values (%d, %f)", FACTORY_NUM, data);
        } else {
            printf("Wrong data type!\n");
            return -1;
        }
    } else if (sensorType == IS_AIR_SENSOR) {
        if (dataType == IS_TEMP) {
            //sprintf(sql, "INSERT INTO air_temp VALUES (null, %d, %f, \'%s\')", dev_id, data, time_str);
            sprintf(sql, "INSERT INTO env_trace (factory_num, temp_indoor) values (%d, %f)", FACTORY_NUM, data);
        } else if (dataType == IS_HUM) {
            //sprintf(sql, "INSERT INTO air_hum VALUES (null, %d, %f, \'%s\')", dev_id, data, time_str);
            sprintf(sql, "INSERT INTO env_trace (factory_num, hum_indoor) values (%d, %f)", FACTORY_NUM, data);
        } else {
            printf("Wrong data type!\n");
            return -1;
        }
    } else if (sensorType == IS_PH_SENSOR) {
        if (dataType == IS_PH) {
            //sprintf(sql, "INSERT INTO water_ph VALUES (null, %d, %f, \'%s\')", dev_id, data, time_str);
            sprintf(sql, "INSERT INTO env_trace (factory_num, temp_water) values (%d, %f)", FACTORY_NUM, data);
        } else if (dataType == IS_TEMP) {
            //sprintf(sql, "INSERT INTO water_temp VALUES (null, %d, %f, \'%s\')", dev_id, data, time_str);
            sprintf(sql, "INSERT INTO env_trace (factory_num, ph) values (%d, %f)", FACTORY_NUM, data);
        } else {
            printf("Wrong data type!\n");
            return -1;
        }
    } else {
        printf("Wrong sensor type!\n");
        return -1;
    }
    return 0;
}

int genPMOrNH3SQL(char *sql, int data, int sensorType, int dataType, unsigned char addr) {
    if (sensorType == IS_PM_SENSOR) {
        if (dataType == IS_PM1) {//TODO: REVISE IF NEEDED
            sprintf(sql, "INSERT INTO env_trace (factory_num, pm) values (%d, %d)", FACTORY_NUM, data);
        } else if (dataType == IS_PM2_5) {
            sprintf(sql, "INSERT INTO env_trace (factory_num, pm) values (%d, %d)", FACTORY_NUM, data);
        } else if (dataType == IS_PM10) {//TODO: REVISE IF NEEDED
            sprintf(sql, "INSERT INTO env_trace (factory_num, pm) values (%d, %d)", FACTORY_NUM, data);
        } else {
            printf("Wrong data type!\n");
            return -1;
        }
    } else if (sensorType == IS_NH3_SENSOR) {
        if(dataType == IS_NH3) {
            sprintf(sql, "INSERT INTO env_trace (factory_num, nh3) values (%d, %d)", FACTORY_NUM, data);
        } else {
            printf("Wrong data type!\n");
            return -1;
        }
    } else {
        printf("Wrong sensor type!\n");
        return -1;
    }
    return 0;
}
