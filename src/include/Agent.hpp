// agent.hpp

#ifndef AGENT_HPP
#define AGENT_HPP

#include "Environment.hpp"
#include <array>

class Agent {
public:
    Agent(Environment &env);

    void Act();
    void UpdatePosition(int x, int y);
    void CleanCurrentPosition();
    int GetCurrentX() const;
    int GetCurrentY() const;
    int GetScore() const;
    void UpdateScore(int points);

private:
    Environment &environment;
    int current_x, current_y;
    int score; // Pontuação do agente
    std::array<std::pair<int, int>, 3> memory; // Memória dos últimos 3 movimentos
};

#endif // AGENT_HPP