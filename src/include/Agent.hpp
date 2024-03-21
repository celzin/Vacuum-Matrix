// Agent.hpp
#ifndef AGENT_HPP
#define AGENT_HPP

#include "Environment.hpp"
#include <array>

class Agent {
public:
    Agent(Environment &env);

    void Run(); // Método que executa o comportamento do agente
    int GetScore() const; // Retorna a pontuação atual do agente
    int GetCleanedCount() const; // Retorna o número de quadrados limpos pelo agente

private:
    Environment &environment; // Referência para o ambiente onde o agente está atuando
    std::array<std::pair<int, int>, 3> lastPositions; // Armazena as últimas posições visitadas pelo agente
    int score; // Pontuação do agente
    int cleanedCount; // Contagem de quantas vezes o agente limpou
    std::pair<int, int> currentPosition; // Posição atual do agente

    void Move(int dx, int dy); // Move o agente na direção (dx, dy)
    void Clean(); // Limpa o quadrado atual
    bool HasVisited(int x, int y) const; // Verifica se o agente já visitou a posição (x, y)
    std::pair<int, int> ChooseNextMove(); // Escolhe o próximo movimento baseado na percepção atual
};

#endif // AGENT_HPP
