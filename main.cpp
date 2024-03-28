#include <iostream>
#include "MonitorController.h"

int main(int argc, char *argv[]) {
    MonitorController mon;
    std::map<int, std::vector<int>> res = mon.getSupportedResolutions();
    for (auto const& [xKey, yVector] : res) {
        for (int i : yVector) {
            std::cout << xKey << "x" << i << std::endl;
        }
    }
//    HMONITOR hMonitor = mon.getMonitor();
//    MONITORINFOEX monitorInfo = mon.getMonitorInfo(hMonitor);
//    DEVMODE devMode = mon.getDeviceMode(monitorInfo);
//    auto cxLogical = monitorInfo.rcMonitor.right - monitorInfo.rcMonitor.left;
//    auto cyLogical = monitorInfo.rcMonitor.bottom - monitorInfo.rcMonitor.top;
//
//    std::cout << "Logical width: " << cxLogical << std::endl;
//    std::cout << "Logical height: " << cyLogical << std::endl;
//
//    auto horizontalScale = static_cast<double>(devMode.dmPelsWidth) / cxLogical;
//    auto verticalScale = static_cast<double>(devMode.dmPelsHeight) / cyLogical;
//
//    std::cout << horizontalScale << " x " << verticalScale << std::endl;
//
//    devMode.dmPelsWidth = cxLogical;
//    devMode.dmPelsHeight = cyLogical;
//
//    LONG result = ChangeDisplaySettingsEx(monitorInfo.szDevice, &devMode, nullptr, 0, nullptr);
    return 0;
}
