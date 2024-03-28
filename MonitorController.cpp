//
// Created by Pierce on 3/27/2024.
//
#include "MonitorController.h"

MonitorController::MonitorController() {
    POINT cursorPos;
    GetCursorPos(&cursorPos);
    hMonitor = MonitorFromPoint(cursorPos, MONITOR_DEFAULTTONEAREST);
    monitorInfoEx.cbSize = sizeof(MONITORINFOEX);
    GetMonitorInfo(hMonitor, &monitorInfoEx);
    devMode.dmSize = sizeof(devMode);
    EnumDisplaySettings(monitorInfoEx.szDevice, ENUM_CURRENT_SETTINGS, &devMode);
    devModeRest = devMode;
    DEVMODE dm = { 0 };
    dm.dmSize = sizeof(dm);
    for(int mode = 0; EnumDisplaySettings(monitorInfoEx.szDevice, mode, &dm ) != 0; mode++) {
        int key = (int) dm.dmPelsWidth;
        if (resolutions.count(key)) continue;
        resolutions[key];
        resolutions[key].push_back((int) dm.dmPelsHeight);
    }
}

HMONITOR MonitorController::getMonitor() {
    return hMonitor;
}

MONITORINFOEX MonitorController::getMonitorInfo() {
    return monitorInfoEx;
}

DEVMODE MonitorController::getDeviceMode() {
    return devMode;
}

std::map<int, std::vector<int>> MonitorController::getSupportedResolutions() {
    return resolutions;
}

void MonitorController::resetChanges() {
    ChangeDisplaySettingsEx(monitorInfoEx.szDevice, &devModeRest, nullptr, 0, nullptr);
}
