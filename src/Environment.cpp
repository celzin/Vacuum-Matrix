// Environment.cpp
#include "include/Environment.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <random>

Environment::Environment(int size) : size(size), grid(size, std::vector<int>(size, 0)) {}

void Environment::LoadFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Não foi possível abrir o arquivo de entrada.");
    }

    file >> size; // Ler o tamanho do ambiente

    grid.resize(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> grid[i][j];
        }
    }
}

std::pair<int, int> Environment::GetRandomStartPosition() {
    std::random_device rd; // Obtém um número aleatório do dispositivo de hardware se disponível
    std::mt19937 gen(rd()); // Padrão mersenne_twister_engine
    std::uniform_int_distribution<> dis(0, size - 1); // Distribuição que gera números entre 0 e size - 1

    int x = dis(gen);
    int y = dis(gen);
    return { x, y }; // Retorna uma posição aleatória válida dentro da matriz
}

bool Environment::IsDirty(int x, int y) const {
    return grid[x][y] == 1;
}

void Environment::Clean(int x, int y) {
    if (IsWithinBounds(x, y) && IsDirty(x, y)) {
        grid[x][y] = 0;
    }
}

bool Environment::IsWithinBounds(int x, int y) const {
    return x >= 0 && x < size && y >= 0 && y < size;
}

int Environment::GetSize() const {
    return size;
}

void Environment::Print() const {
    for (const auto &row : grid) {
        for (int cell : row) {
            std::cout << (cell ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }
}
