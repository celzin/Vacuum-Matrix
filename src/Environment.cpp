#include "include/Environment.hpp"

Environment::Environment(const std::string &file_path) {
    LoadFromFile(file_path);
}

void Environment::LoadFromFile(const std::string &file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open the file: " + file_path);
    }

    int sizeX, sizeY; // Variáveis para ler as dimensões da matriz
    file >> sizeX >> sizeY; // Lê ambas as dimensões da matriz
    size = sizeX; // Assume uma matriz quadrada NxN

    grid.resize(size, std::vector<int>(size)); // Redimensiona a matriz de acordo com o tamanho

    // Preenche a matriz com os dados lidos do arquivo
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> grid[i][j];
        }
    }
}

void Environment::Print() const {
    for (const auto &row : grid) {
        for (int val : row) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
}

bool Environment::IsDirty(int x, int y) const {
    return grid[x][y] == 1; // Retorna verdadeiro se o quadrado estiver sujo
}

void Environment::Clean(int x, int y) {
    if (IsDirty(x, y)) {
        grid[x][y] = 0; // Limpa o quadrado se estiver sujo
    }
}

int Environment::GetSize() const {
    return size;
}

int Environment::CountRemainingDirtySquares() const {
    int count = 0;
    for (const auto &row : grid) {
        count += std::count(row.begin(), row.end(), 1);
    }
    return count;
}

int Environment::GetValueAt(int x, int y) const {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        return grid[x][y];
    } else {
        return -1; // Retorna -1 ou outro valor de erro se as coordenadas estiverem fora dos limites
    }
}
