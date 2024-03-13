/// @details  get device's MAC address
/// @author   zyp
/// @date     2024-03-11

#ifndef MACADDRESS_H
#define MACADDRESS_H

#if _WIN32
#include <winsock2.h>
#include <windows.h>
#include <iphlpapi.h>
#else
#define _GNU_SOURCE
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>        //for struct ifreq
#endif

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./base64.h"

char* getMacAddress();

#endif