#include "../include/macAddress.h"

char* getMacAddress() {
#if _WIN32
    char* macAddress = NULL;
    ULONG ulOutBufLen = 0;
    PIP_ADAPTER_INFO pAdapterInfo = NULL;

    // GetAdaptersInfo
    ULONG outBufLen = 0;
    PIP_ADAPTER_ADDRESSES pAddresses = NULL, pCurrAddresses = NULL;

    // Get the required buffer size
    if (GetAdaptersAddresses(AF_UNSPEC, 0, NULL, pAddresses, &outBufLen) == ERROR_BUFFER_OVERFLOW) {
        // 分配内存
        pAddresses = (PIP_ADAPTER_ADDRESSES) malloc(outBufLen);
        if (pAddresses == NULL) {
            fprintf(stderr, "memory failed!\n");
            return NULL;
        }

        // Getting Adapter Information
        if (GetAdaptersAddresses(AF_UNSPEC, 0, NULL, pAddresses, &outBufLen) == NO_ERROR) {
            // Iterate over all adapters
            pCurrAddresses = pAddresses;
            while (pCurrAddresses) {
                if (pCurrAddresses->OperStatus == IfOperStatusUp) {
                    macAddress = (char*)malloc(18); // address format --- XX:XX:XX:XX:XX:XX
                    if (macAddress != NULL) {
                        sprintf(macAddress, "%02X:%02X:%02X:%02X:%02X:%02X",
                            pCurrAddresses->PhysicalAddress[0], pCurrAddresses->PhysicalAddress[1],
                            pCurrAddresses->PhysicalAddress[2], pCurrAddresses->PhysicalAddress[3],
                            pCurrAddresses->PhysicalAddress[4], pCurrAddresses->PhysicalAddress[5]);
                        break;  // Just find the first adapter that is connected
                    }
                }
                pCurrAddresses = pCurrAddresses->Next;
            }
        }
        free(pAddresses);
    }

    return macAddress;
#else
    struct ifreq ifr;
    struct ifconf ifc;
    char buf[1024];
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(0);
    }
    
    ifc.ifc_len = sizeof(buf);
    ifc.ifc_buf = buf;
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl");
        close(sock);
        exit(EXIT_FAILURE);
    }

    struct ifreq* it = ifc.ifc_req;
    const struct ifreq* const end = it + (ifc.ifc_len / sizeof(struct ifreq));

    for (; it != end; ++it) {
        strcpy(ifr.ifr_name, it->ifr_name);
        if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
            if (! (ifr.ifr_flags & IFF_LOOPBACK)) {
                if (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0) {
                    close(sock);
                    char* mac = (char*)malloc(18);
                    sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X",
                            (unsigned char)ifr.ifr_hwaddr.sa_data[0],
                            (unsigned char)ifr.ifr_hwaddr.sa_data[1],
                            (unsigned char)ifr.ifr_hwaddr.sa_data[2],
                            (unsigned char)ifr.ifr_hwaddr.sa_data[3],
                            (unsigned char)ifr.ifr_hwaddr.sa_data[4],
                            (unsigned char)ifr.ifr_hwaddr.sa_data[5]);
                    return mac;
                }
            }
        } else {
            perror("ioctl");
            close(sock);
            exit(EXIT_FAILURE);
        }
    }

    close(sock);
    return NULL;
#endif
}