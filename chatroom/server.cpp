//
// Created by Reeb Deve on 2022/1/5.
//
#define _GNU_SOURCE 1
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>

const USER_LIMIT = 5;       // 最大用户数量
const BUFFER_SIZE = 64;     // 读缓冲区的大小
const FD_LIMIT = 65535;     // 文件描述符数量限制

/* 客户数据：客户端socket地址，待写入到客户端到数据到位置，从客户端读入的数据 */
struct client_data
{
    sockaddr_in address;
    char* write_buf;
    char buf[BUFFER_SIZE];
};


