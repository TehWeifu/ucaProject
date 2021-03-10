#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#include <cstdio>

#include <iostream>
#include <map>
#include <string>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

void generateDevices(std::map<std::string, std::string>&);


int main() {
    // Declare and initialize variables

    HANDLE hIcmpFile;
    unsigned long ipaddr{INADDR_NONE};
    DWORD dwRetVal{0};
    char SendData[32]{"Data Buffer"};
    LPVOID ReplyBuffer{nullptr};
    DWORD ReplySize{0};

    std::map<std::string, std::string> devices;
    generateDevices(devices);
//    devices.insert({"myPC", "192.168.1.14"});

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
        printf("\tUnable to open handle.\n");
        printf("IcmpCreateFile returned error: %ld\n", GetLastError());
        return 1;
    }

    ReplySize = sizeof(ICMP_ECHO_REPLY) + sizeof(SendData);
    ReplyBuffer = (VOID *) malloc(ReplySize);
    if (ReplyBuffer == nullptr) {
        printf("\tUnable to allocate memory\n");
        return 1;
    }

    for (const auto& map : devices) {

        ipaddr = inet_addr(map.second.c_str());
        dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr, SendData, sizeof(SendData),
                                nullptr, ReplyBuffer, ReplySize, 1000);

        std::cout << "Ping to " << map.first << "(IP " << map.second << ")" << ":";

        if (dwRetVal != 0) {
            auto pEchoReply = (PICMP_ECHO_REPLY) ReplyBuffer;
            struct in_addr ReplyAddr{};
            ReplyAddr.S_un.S_addr = pEchoReply->Address;
            std::cout << " SUCCESS";
        } else {
            std::cout << " FAILED";
        }
        std::cout << std::endl;
    }
    return 0;
}

void generateDevices(std::map<std::string, std::string>& map) {
    std::string tmpName;
    std::string tmpIp;

    for (int i = 1; i <= 62; ++i) {
        tmpName = "CK" + std::to_string(i);
        tmpIp = "192.168.211." + std::to_string(i);

        map.insert({tmpName, tmpIp});
    }

    for (int i = 0; i <= 22; ++i) {
        tmpName = "GT" + std::to_string(i);
        tmpIp = "192.168.211." + std::to_string(120 + i);

        map.insert({tmpName, tmpIp});
    }
}
