#include <iostream>
#include "MonitorController.h"

int main(int argc, char *argv[]) {
    MonitorController mon;
    std::map<int, std::vector<int>> res = mon.getSupportedResolutions();

    if (argc < 3) {
        std::cout << "Supported Resolutions:" << std::endl;
        for (auto const& [xKey, yVector] : res) {
            for (int i : yVector) {
                std::cout << xKey << "x" << i << std::endl;
            }
        }
        std::cout << "Usage: ./exe [x] [y]" << std::endl;
        return 0;
    }

    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);
    long changeCode = mon.setResolution(x, y);
    if (changeCode != 0) {
        if (mon.codes.count(changeCode) == 0) {
            std::cout << "Error code " << changeCode << " not recognized" << std::endl;
            return 0;
        }
        std::cout << mon.codes[changeCode] << std::endl;
        return 0;
    }

    std::cout << "Keep resolution?" << std::endl;
    int key;
    std::cin >> key;
    if ((int)key == 1) return 0;
    mon.resetChanges();
    return 0;
}