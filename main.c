/*
 * Version 1.0 (2018-06-20)
 * Copyright (c) Cen XIN
 */

#include "inst.h"
#include "devinfo.h"
#include "uart.h"
#include "dbcomm.h"
#include "parser.h"

#define MAX_RECV_BUF 16


int main() {
    pid_t p;

    float soil_data[2];
    float air_data[2];
    int pm_data[3];
    float ph_data[2];
    char sql[MAX_SQL_SIZE];
    unsigned char recv_uart_buf[MAX_RECV_BUF];
    char cmd_line;

    if ((p = fork()) == -1) {
        perror("fork");
        return EXIT_FAILURE;
    } else if (p == 0) {
        initMySQL();
        while(1) {

            bzero(recv_uart_buf, MAX_RECV_BUF);
            openUart(dev);
            initUart();
            sendToUart(soil_temp_hum_inq, UART_SEND_LEN);
            recvFromUart(recv_uart_buf, SOIL_RECV_LEN);
            closeUart();
            bzero(soil_data, 2);
            parseTempAndHum(recv_uart_buf, soil_data);
            printf("[Soil Data] Temp = %.1f\'C, Hum = %.1f%%\n\n", soil_data[1], soil_data[0]);
/*          TODO: UNCOMMENT THIS SEGMENT TO ACTIVATE THE SQL
            bzero(sql, MAX_SQL_SIZE);
            genTempOrHumOrPhSQL(sql, soil_data[1], IS_SOIL_SENSOR, IS_TEMP, SOIL_TEMP_HUM_SENSOR_ADDR);
            execSQL(sql);
            bzero(sql, MAX_SQL_SIZE);
            genTempOrHumOrPhSQL(sql, soil_data[0], IS_SOIL_SENSOR, IS_HUM, SOIL_TEMP_HUM_SENSOR_ADDR);
            execSQL(sql);
*/
            sleep(5);

            bzero(recv_uart_buf, MAX_RECV_BUF);
            openUart(dev);
            initUart();
            sendToUart(air_temp_hum_inq, UART_SEND_LEN);
            recvFromUart(recv_uart_buf, AIR_RECV_LEN);
            closeUart();
            bzero(air_data, 2);
            parseTempAndHum(recv_uart_buf, air_data);
            printf("[Air Data] Temp = %.1f\'C, Hum = %.1f%%\n\n", air_data[1], air_data[0]);
/*          TODO: UNCOMMENT THIS SEGMENT TO ACTIVATE THE SQL
            bzero(sql, MAX_SQL_SIZE);
            genTempOrHumOrPhSQL(sql, air_data[1], IS_AIR_SENSOR, IS_TEMP, AIR_TEMP_HUM_SENSOR_ADDR);
            execSQL(sql);
            bzero(sql, MAX_SQL_SIZE);
            genTempOrHumOrPhSQL(sql, air_data[0], IS_AIR_SENSOR, IS_HUM, AIR_TEMP_HUM_SENSOR_ADDR);
            execSQL(sql);
*/
            sleep(5);

            bzero(recv_uart_buf, MAX_RECV_BUF);
            openUart(dev);
            initUart();
            sendToUart(pm_inq, UART_SEND_LEN);
            recvFromUart(recv_uart_buf, PM_RECV_LEN);
            closeUart();
            bzero(pm_data, 3);
            parsePM(recv_uart_buf, pm_data);
            printf("[PM Data] PM1 = %d ppm, PM2.5 = %d ppm, PM10 = %d ppm\n\n", pm_data[0], pm_data[1], pm_data[2]);

            //bzero(sql, MAX_SQL_SIZE);
            //genPMOrNH3SQL(sql, pm_data[0], IS_PM_SENSOR, IS_PM1, PM1_PM2_5_PM10_SENSOR_ADDR);
            //execSQL(sql);
/*          TODO: UNCOMMENT THIS SEGMENT TO ACTIVATE THE SQL
            bzero(sql, MAX_SQL_SIZE);
            genPMOrNH3SQL(sql, pm_data[1], IS_PM_SENSOR, IS_PM2_5, PM1_PM2_5_PM10_SENSOR_ADDR);
            execSQL(sql);
*/
            //bzero(sql, MAX_SQL_SIZE);
            //genPMOrNH3SQL(sql, pm_data[2], IS_PM_SENSOR, IS_PM10, PM1_PM2_5_PM10_SENSOR_ADDR);
            //execSQL(sql);

            sleep(5);

            bzero(recv_uart_buf, MAX_RECV_BUF);
            openUart(dev);
            initUart();
            sendToUart(ph_temp_inq, UART_SEND_LEN);
            recvFromUart(recv_uart_buf, AIR_RECV_LEN);
            closeUart();
            bzero(ph_data, 2);
            parsePhAndTemp(recv_uart_buf, ph_data);
            printf("[Water Data] Temp = %.1f\'C, pH = %.1f\n\n", ph_data[0], ph_data[1]);
/*          TODO: UNCOMMENT THIS SEGMENT TO ACTIVATE THE SQL
            bzero(sql, MAX_SQL_SIZE);
            genTempOrHumOrPhSQL(sql, ph_data[0], IS_PH_SENSOR, IS_TEMP, PH_TEMP_SENSOR_ADDR);
            execSQL(sql);
            bzero(sql, MAX_SQL_SIZE);
            genTempOrHumOrPhSQL(sql, ph_data[1], IS_PH_SENSOR, IS_PH, PH_TEMP_SENSOR_ADDR);
            execSQL(sql);
*/
            sleep(5);
        }
    } else {
        while (1) {
            scanf("%c", &cmd_line);
            if (cmd_line == 'q') {
                kill(0, SIGKILL);
                break;
            }
        }
    }
    return 0;
}