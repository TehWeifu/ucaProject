#include "source/IlumMonitor.h"

//#include <fstream>
//#include <cstdlib>
//#include <string>

//void fill_uca();
//void generateDevices(std::map<std::string, std::string> &);


int main() {
    //fill_uca();
    auto uca = IlumMonitor();
    return 0;
}

//void fill_uca() {
//	std::string tmpName;
//	std::string tmpIp;
//
//	std::ofstream outDevicesFile{ "devices.txt", std::ios::out };
//
//
//	for (int i = 1; i < 10; ++i) {
//		tmpName = "CK0" + std::to_string(i);
//		tmpIp = "192.168.211." + std::to_string(i);
//
//		outDevicesFile << tmpName << ' ' << tmpIp << std::endl;
//	}
//
//	for (int i = 10; i < 63; ++i) {
//		tmpName = "CK" + std::to_string(i);
//		tmpIp = "192.168.211." + std::to_string(i);
//
//		outDevicesFile << tmpName << ' ' << tmpIp << std::endl;
//	}
//
//
//	outDevicesFile << "GTTG" << ' ' << "192.168.211.119" << std::endl;
//	outDevicesFile << "GT1A" << ' ' << "192.168.211.120" << std::endl;
//	outDevicesFile << "GT1B" << ' ' << "192.168.211.121" << std::endl;
//
//	for (int i = 2; i < 10; ++i) {
//		tmpName = "GT0" + std::to_string(i);
//		tmpIp = "192.168.211." + std::to_string(120 + i);
//
//		outDevicesFile << tmpName << ' ' << tmpIp << std::endl;
//	}
//
//	for (int i = 10; i < 23; ++i) {
//		tmpName = "GT" + std::to_string(i);
//		tmpIp = "192.168.211." + std::to_string(120 + i);
//
//		outDevicesFile << tmpName << ' ' << tmpIp << std::endl;
//	}
//
//}


//void generateDevices(std::map<std::string, std::string> &map) {
//    std::string tmpName;
//    std::string tmpIp;
//
//    for (int i = 1; i <= 62; ++i) {
//        tmpName = "CK" + std::to_string(i);
//        tmpIp = "192.168.211." + std::to_string(i);
//
//        map.insert({tmpName, tmpIp});
//    }
//
//    for (int i = 0; i <= 22; ++i) {
//        tmpName = "GT" + std::to_string(i);
//        tmpIp = "192.168.211." + std::to_string(120 + i);
//
//        map.insert({tmpName, tmpIp});
//    }
//}
