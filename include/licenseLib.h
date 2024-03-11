/// @details  this file contains the license library interface
/// @author   zyp
/// @date     2024-03-11

#ifndef LICENSELIB_H
#define LICENSELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#ifndef WIN32
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#ifdef WIN_DLL
#define EXPORT __declspec(dllexport) /* for Windows DLL */
#elif defined(WIN32)
#define EXPORT
#else
#define EXPORT
#endif

#ifdef WIN32
/* --- Online license function --- */
EXPORT __declspec(dllexport) bool getAccessOn(char* _filename, char* _uid);
/* --- Offline license function --- */
EXPORT __declspec(dllexport) bool getAccessOff(char* _filename);
#else
EXPORT bool getAccessOn(char* _filename, char* _uid);
EXPORT bool getAccessOff(char* _filename);
/* --- License function for frontend(just linux) --- */

#define HOST "cloud.navfirst.com"
#define PATH "/iot-asset/frontend/verify"
#define PORT 80

EXPORT bool getAccessFrontend(char* _uid);
char* httpPost(const char *_postData);
#endif

#endif