#ifndef AGENT_HPP
#define AGENT_HPP

#include "Environment.hpp"
#include <array>

class Agent {
public:
    Agent(Environment &env);

    void Act(std::vector<std::string> &log);
    void UpdatePosition(int x, int y);
    void UpdateMemory(int dx, int dy); // Nova
    void CleanCurrentPosition();
    void UpdateScore(int points);
    int GetCurrentX() const;
    int GetCurrentY() const;
    int GetScore() const;
    std::string LogCurrentState() const; // Novo método

private:
    Environment &environment;
    int current_x, current_y;
    int score; // Pontuação do agente
    std::array<std::pair<int, int>, 3> memory; // Memória dos últimos 3 movimentos
};

#endif 