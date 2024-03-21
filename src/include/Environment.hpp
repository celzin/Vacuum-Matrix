// Environment.hpp
#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <string>

class Environment {
public:
    Environment(int size); // Construtor que inicializa o ambiente com um tamanho especificado
    void LoadFromFile(const std::string &filename); // Carrega o ambiente do arquivo
    bool IsDirty(int x, int y) const; // Verifica se a posição (x, y) está suja
    void Clean(int x, int y); // Limpa a posição (x, y)
    bool IsWithinBounds(int x, int y) const; // Verifica se a posição está dentro dos limites do ambiente
    int GetSize() const; // Retorna o tamanho do ambiente
    void Print() const; // Imprime o estado atual do ambiente para depuração
    std::pair<int, int> GetRandomStartPosition(); // Método para obter uma posição inicial aleatória

private:
    std::vector<std::vector<int>> grid; // Representação do ambiente como uma grade NxN
    int size; // Tamanho da grade
};

#endif // ENVIRONMENT_HPP
