// Utility.cpp
#include "include/Utility.hpp"
#include <fstream>
#include <stdexcept>

namespace Utility {

    void SaveTravessia(const std::string &filename, const std::vector<std::pair<int, int>> &travessia) {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Não foi possível abrir o arquivo de travessia para escrita.");
        }
        for (const auto &pos : travessia) {
            file << pos.first << " " << pos.second << std::endl;
        }
    }

    void SaveRelatorio(const std::string &filename, int score, int cleanedCount, int percorridas, int naoExploradas) {
        std::ofstream file(filename);
        if (!file) {
            throw std::runtime_error("Não foi possível abrir o arquivo de relatório para escrita.");
        }
        file << "Pontos ganhos: " << score << std::endl;
        file << "Quantidades limpas: " << cleanedCount << std::endl;
        file << "Casas percorridas: " << percorridas << std::endl;
        file << "Casas não exploradas: " << naoExploradas << std::endl;
        file << "Pontuação Final: " << score - (percorridas - cleanedCount) - (naoExploradas * 20) << std::endl;
    }

}

// ... Mais funções conforme necessário ...
