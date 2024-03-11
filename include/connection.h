/// @details http request
/// @author  zyp
/// @date    2024-03-11

#ifndef CONNECTION_H
#define CONNECTION_H

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define HOST "cloud.navfirst.com"
#define PATH "/iot-asset/frontend/verify"

char* getIP();

char* sendRequest(char* _uid);

#endif