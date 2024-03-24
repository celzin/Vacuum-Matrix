#include "include/InputGenerator.hpp"

const int N = 4; // Tamanho da matriz NxN
const float DIRT_PERCENTAGE = 1.0; // 50% dos quadrados sujos

void GenerateInputData() {
    int totalSquares = N * N;
    int dirtySquares = static_cast<int>(totalSquares * DIRT_PERCENTAGE);

    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));

    std::srand(std::time(nullptr)); // Seed para geração de números aleatórios

    // Preenchendo a matriz com sujeira de forma aleatória
    while (dirtySquares > 0) {
        int x = std::rand() % N;
        int y = std::rand() % N;

        if (matrix[x][y] == 0) {
            matrix[x][y] = 1;
            dirtySquares--;
        }
    }

    // Salvando a configuração no arquivo input.data
    std::ofstream outputFile("dataset/input.data");
    outputFile << N << " " << N << std::endl;

    for (const auto &row : matrix) {
        for (const auto &cell : row) {
            outputFile << cell << " ";
        }
        outputFile << std::endl;
    }

    outputFile.close();
}