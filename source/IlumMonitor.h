#pragma once

#include <map>
#include <string>

class IlumMonitor {
public:
    IlumMonitor() {
        load();
        menu(0);
    }

    void menu(const int& = 0);
    int load();
    int export_devices();
    int run();

    void edit_menu(const int& = 0);
    void add_device();
    void remove_device();
    void change_name();
    void change_ip();

private:
    std::map<std::string, std::string> devices;
};
