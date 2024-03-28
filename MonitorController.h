#ifndef MONITORCHANGER_MONITORCONTROLLER_H
#define MONITORCHANGER_MONITORCONTROLLER_H
#include <windows.h>
#include <map>
#include <vector>

class MonitorController {
private:
    std::map<int, std::vector<int>> resolutions;
    HMONITOR hMonitor = nullptr;
    MONITORINFOEX monitorInfoEx{};
    DEVMODE devMode{0};
    DEVMODE devModeRest{0};
public:
    MonitorController();
    HMONITOR getMonitor();
    MONITORINFOEX getMonitorInfo();
    DEVMODE getDeviceMode();
    std::map<int, std::vector<int>> getSupportedResolutions();
    void resetChanges();
};

#endif // MONITORCHANGER_MONITORCONTROLLER_H
