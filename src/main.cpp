#include "include/Utility.hpp"

int main() {
    try {
        std::string inputFilePath = "dataset/input.data";
        int maxMoves = 20;
        ExecuteSimulation(inputFilePath, maxMoves);
        std::cout << "Simulação completa. Verifique os arquivos de saída para resultados." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
