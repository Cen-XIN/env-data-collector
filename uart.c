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

#include "uart.h"

int openUart(char *dev) {
    uartfd = open(dev, O_RDWR | O_NOCTTY | O_NDELAY);
    if(uartfd < 0){
        perror("open");
        return -1;
    }
    printf("Successfully opened %s\n", dev);
    return 0;
}

int initUart() {
    struct termios opt;
    tcgetattr(uartfd, &opt);
    opt.c_cflag |= (CLOCAL | CREAD);
    opt.c_cflag &= ~CSIZE;
    opt.c_cflag &= ~CRTSCTS;
    opt.c_cflag |= CS8;
    opt.c_cflag &= ~CSTOPB;
    opt.c_iflag |= IGNPAR;
    opt.c_oflag = 0;
    opt.c_lflag = 0;
    opt.c_iflag &= ~(ICRNL | IXON);
    cfsetospeed(&opt, B9600);
    cfsetispeed(&opt, B9600);
    tcflush(uartfd, TCIFLUSH);
    tcsetattr(uartfd, TCSANOW, &opt);

    printf("Successfully initialized UART!\n");
    return 0;
}

int closeUart() {
    close(uartfd);
    printf("UART fd closed...\n");
    return 0;
}

int recvFromUart(unsigned char *data, int datalen) {
    int len = 0, ret = 0;
    fd_set fs_read;
    struct timeval tv_timeout;

    FD_ZERO(&fs_read);
    FD_SET(uartfd, &fs_read);
    tv_timeout.tv_sec = (10 * 20 / 115200 + 2);
    tv_timeout.tv_usec = 0;

    ret = select(uartfd + 1, &fs_read, NULL, NULL, &tv_timeout);
    printf("ret = %d\n", ret);

    if(FD_ISSET(uartfd, &fs_read)) {
        len = read(uartfd, data, datalen);
        printf("len = %d\n", len);
        tcflush(uartfd, TCIFLUSH);
        return len;
    } else{
        perror("select");
        return -1;
    }
}

int sendToUart(unsigned char *data, int datalen) {
    int len = 0;
    len = write(uartfd, data, datalen);
    if(len == datalen){
        return len;
    }else{
        tcflush(uartfd, TCOFLUSH);
        return -1;
    }
}