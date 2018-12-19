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

#ifndef ENVDATACOLLECTOR_DBCOMM_H
#define ENVDATACOLLECTOR_DBCOMM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <mysql/mysql.h>
#include "devinfo.h"

#define MAX_SQL_SIZE    1024    //the maximum size of SQL (FOR ALL!)

MYSQL *g_conn;
MYSQL_RES *g_res;
MYSQL_ROW g_row;

static char *g_host_name = "*****";
static char *g_user_name = "*****";
static char *g_password = "*****";
static char *g_db_name = "*****";
static unsigned int g_db_port = 3306;

/**
 * Print MySQL error message
 * @param msg
 */
void printMySQLError(const char *msg);

/**
 * Execute SQL
 * @param sql
 * @return 0 for succeed | -1 for failed
 */
int execSQL(const char *sql);

/**
 * Initialize MySQL
 * @return 0 for succeed | -1 for failed
 */
int initMySQL();

/**
 * Disconnect with MySQL
 * @return 0
 */
int closeMySQL();

/**
 * Generate a SQL with temperature, humidity or pH data
 * @param sql
 * @param data
 * @param sensorType
 * @param dataType
 * @param addr
 * @return 0 for succeed | -1 for wrong type
 */
int genTempOrHumOrPhSQL(char *sql, float data, int sensorType, int dataType, unsigned char addr);

/**
 * Generate a SQL with PM1, PM2.5, PM10 or NH3 data
 * @param sql
 * @param data
 * @param sensorType
 * @param dataType
 * @param addr
 * @return 0 for succeed | -1 for wrong type
 */
int genPMOrNH3SQL(char *sql, int data, int sensorType, int dataType, unsigned char addr);

#endif //ENVDATACOLLECTOR_DBCOMM_H
