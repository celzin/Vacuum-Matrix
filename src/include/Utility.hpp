// Utility.hpp
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <vector>
#include <utility>

namespace Utility {
    void SaveTravessia(const std::string &filename, const std::vector<std::pair<int, int>> &travessia);
    void SaveRelatorio(const std::string &filename, int score, int cleanedCount, int percorridas, int naoExploradas);
}

#endif // UTILITY_HPP