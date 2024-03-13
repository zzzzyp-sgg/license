/// @brief  test file

#include "include/licenseLib.h"

int main(int argc, char* argv[])
{
    char* filename = "./license.lic";
    char *uid = "TEST01";

    // online function
    // getAccessOn(filename, uid);
    // offline function
    // getAccessOff(filename);
    // frontend function
    bool test = getAccessFrontend(uid);
    printf("test: %d\n", test);

    return 0;
}