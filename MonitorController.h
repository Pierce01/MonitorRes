#ifndef MONITORRESCHANGER_MONITORCONTROLLER_H
#define MONITORRESCHANGER_MONITORCONTROLLER_H
#include <windows.h>
#include <map>
#include <vector>
#include <string>

class MonitorController {
private:
    std::map<int, std::vector<int>> resolutions;
    HMONITOR hMonitor = nullptr;
    MONITORINFOEX monitorInfoEx{};
    DEVMODE devMode{};
    DEVMODE devModeRest{};
public:
    MonitorController();
    HMONITOR getMonitor();
    MONITORINFOEX getMonitorInfo();
    DEVMODE getDeviceMode();
    std::map<int, std::vector<int>> getSupportedResolutions();
    void resetChanges();
    long setResolution(int x, int y);
    std::map<long, std::string> codes = {
            {DISP_CHANGE_SUCCESSFUL, "The settings change was successful."},
            {DISP_CHANGE_BADDUALVIEW, "The settings change was unsuccessful because the system is DualView capable."},
            {DISP_CHANGE_BADFLAGS, "An invalid set of flags was passed in."},
            {DISP_CHANGE_BADMODE, "The graphics mode is not supported."},
            {DISP_CHANGE_BADPARAM, "An invalid parameter was passed in. This can include an"
                                   " invalid flag or combination of flags."},
            {DISP_CHANGE_FAILED, "The display driver failed the specified graphics mode."},
            {DISP_CHANGE_NOTUPDATED, "Unable to write settings to the registry."},
            {DISP_CHANGE_RESTART, "The computer must be restarted for the graphics mode to work."},
            {-90, "Resolution not supported."}
    };
};

#endif // MONITORRESCHANGER_MONITORCONTROLLER_H
