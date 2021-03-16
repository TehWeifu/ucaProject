//#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include <WinSock2.h>
#include <iphlpapi.h>
#include <IcmpAPI.h>


#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#include "IlumMonitor.h"

void IlumMonitor::menu(const int& failed) {
    int option = 0;

    while (option != 3) {

        system("cls");

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                                                  *" << std::endl;
        std::cout << "*                  ILUM-MONITOR                    *" << std::endl;
        std::cout << "*                                                  *" << std::endl;
        std::cout << "*  Menu:                                           *" << std::endl;
        std::cout << "*    1. Run                                        *" << std::endl;
        std::cout << "*    2. Edit                                       *" << std::endl;
        std::cout << "*    3. Exit                                       *" << std::endl;
        std::cout << "*                                                  *" << std::endl;
        std::cout << "****************************************************" << std::endl;

        if (failed) { std::cout << "Error, invalid input. "; }

        std::cout << "Select an option: ";
        std::cin >> option;


        if (option > 3 || option < 1) menu(-1);

        switch (option) {
            case 1:
                run();
                break;
            case 2:
                edit_menu();
                break;
            default:
                break;
        }
    }

    export_devices();

    system("cls");
    std::cout << "****************************************************" << std::endl;
    std::cout << "*      Thank you for using ILUM-MONITOR. Bye!      *" << std::endl;
    std::cout << "****************************************************" << std::endl;
    Sleep(5000);
}

int IlumMonitor::export_devices() {

    std::ofstream outDevicesFile{ "devices.txt", std::ios::out };

    if (!outDevicesFile) { return 0; }

    for (const auto& pc : devices) {
        outDevicesFile << pc.first << ' ' << pc.second << std::endl;
    }

    outDevicesFile.close();
    return 1;
}

int IlumMonitor::load() {
    std::string tmpName;
    std::string tmpIp;

    std::ifstream inDevicesFile{ "devices.txt", std::ios::in };

    if (!inDevicesFile) { return 0; }

    while (inDevicesFile >> tmpName >> tmpIp) {
        devices.insert({ tmpName, tmpIp });
    }

    inDevicesFile.close();
    return 1;
}

int IlumMonitor::run() {

    HANDLE hIcmpFile;
    unsigned long ipaddr{ INADDR_NONE };
    DWORD dw_ret_val{ 0 };
    char send_data[32]{ "Data Buffer" };
    LPVOID reply_buffer{ nullptr };
    DWORD reply_size{ 0 };

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
        std::cout << "Unable to open handle." << std::endl;
        std::cout << "ImcpCreateFile returned error: " << GetLastError() << std::endl;
        return 1;
    }

    reply_size = sizeof(ICMP_ECHO_REPLY) + sizeof(send_data);
    reply_buffer = (VOID*)malloc(reply_size);
    if (reply_buffer == nullptr) {
        std::cout << "Unable to allocate memory" << std::endl;
        return 1;
    }

    while (true) {
        std::string res;

        for (const auto& map : devices) {

            ipaddr = inet_addr(map.second.c_str());
            dw_ret_val = IcmpSendEcho(hIcmpFile, ipaddr, send_data, sizeof(send_data),
                                      nullptr, reply_buffer, reply_size, 100);


            if (dw_ret_val != 0) {
                auto* const pEchoReply = (PICMP_ECHO_REPLY)reply_buffer;
                struct in_addr reply_addr {};
                reply_addr.S_un.S_addr = pEchoReply->Address;
            }
            else {
                res += "Device " + map.first + " (IP " + map.second + ") is currently: OFFLINE \n";
            }
        }

        system("CLS");
        std::cout << "Last update: ";
        system("time /t");
        std::cout << std::endl;

        std::cout << res;
        Sleep(300'000);
    }
}

void IlumMonitor::edit_menu(const int& failed) {
    int option = 0;

    while (option != 5) {

        system("cls");

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                                                  *" << std::endl;
        std::cout << "*   Edit:                                          *" << std::endl;
        std::cout << "*     1. Add device                                *" << std::endl;
        std::cout << "*     2. Remove device                             *" << std::endl;
        std::cout << "*     3. Change device name                        *" << std::endl;
        std::cout << "*     4. Change device IP                          *" << std::endl;
        std::cout << "*     5. Go back to main menu                      *" << std::endl;
        std::cout << "*                                                  *" << std::endl;
        std::cout << "****************************************************" << std::endl;

        if (failed) { std::cout << "Error, invalid input. "; }

        std::cout << "Select an option: ";
        std::cin >> option;


        if (option > 5 || option < 1) edit_menu(-1);


        switch (option) {
            case 1:
                add_device();
                break;
            case 2:
                remove_device();
                break;
            case 3:
                change_name();
                break;
            case 4:
                change_ip();
                break;
            default:
                break;
        }
    }
}

void IlumMonitor::add_device() {
    std::string tmp_name;
    std::string tmp_ip;

    std::cout << "Input the name of the device: ";
    std::cin >> tmp_name;

    std::cout << "Input the IP of the device: ";
    std::cin >> tmp_ip;

    if (devices.find(tmp_name) == devices.end()) {
        devices.insert({ tmp_name, tmp_ip });
    }
    else {
        std::cout << "Error. This device already exists." << std::endl;
    }
}

void IlumMonitor::remove_device() {
    std::string tmp_name;

    std::cout << "Input the name of the device: ";
    std::cin >> tmp_name;

    auto it = devices.find(tmp_name);

    if (it == devices.end()) {
        std::cout << "Error. This device does not exist." << std::endl;
    }
    else {
        devices.erase(it);
    }
}

void IlumMonitor::change_name() {
    std::string tmp_name;
    std::string tmp_new_name;
    std::string tmp_ip;

    std::cout << "Input the name of the device: ";
    std::cin >> tmp_name;

    std::cout << "Input the new name of the device: ";
    std::cin >> tmp_new_name;

    auto it = devices.find(tmp_name);

    if (it == devices.end()) {
        std::cout << "Error. This device does not exist." << std::endl;
    }
    else
    {
        tmp_ip = devices[tmp_name];
        devices.insert({ tmp_new_name, tmp_ip });
        devices.erase(it);
    }
}

void IlumMonitor::change_ip() {
    std::string tmp_name;
    std::string tmp_ip;

    std::cout << "Input the name of the device: ";
    std::cin >> tmp_name;

    std::cout << "Input the new IP of the device: ";
    std::cin >> tmp_ip;

    if (devices.find(tmp_name) == devices.end()) {
        std::cout << "Error. This device does not exist." << std::endl;
    }
    else {
        devices[tmp_name] = tmp_ip;
    }
}
