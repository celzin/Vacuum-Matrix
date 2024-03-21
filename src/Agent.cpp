// Agent.cpp
#include "include/Agent.hpp"
#include <random>
#include <algorithm>
#include <ctime>

Agent::Agent(Environment &env)
    : environment(env), score(0), cleanedCount(0), currentPosition({ env.GetRandomStartPosition() }) {
    lastPositions.fill(currentPosition); // Inicializa as últimas posições com a posição inicial
}

void Agent::Run() {
    int moveCount = 0; // Contador de movimentos
    while (true) {
        if (environment.IsDirty(currentPosition.first, currentPosition.second)) {
            Clean();
        } else {
            std::pair<int, int> nextMove = ChooseNextMove();
            Move(nextMove.first, nextMove.second);
            moveCount++;
            score--; // Perde ponto por movimento

            // Atualiza a memória de curto prazo com a posição atual
            std::rotate(lastPositions.begin(), lastPositions.begin() + 1, lastPositions.end());
            lastPositions.back() = currentPosition;

            // Critério de parada: nenhum movimento nos últimos 'X' passos ou limite de movimentos alcançado
            if (moveCount > environment.GetSize() * environment.GetSize() * 4) {
                break; // Limite superior de movimentos como critério de parada
            }
        }
    }
}

void Agent::Move(int dx, int dy) {
    std::pair<int, int> newPos = { currentPosition.first + dx, currentPosition.second + dy };

    if (environment.IsWithinBounds(newPos.first, newPos.second) && !HasVisited(newPos.first, newPos.second)) {
        currentPosition = newPos; // Move se a nova posição for válida e não visitada recentemente
    } else {
        // Se bater na parede ou em uma posição já visitada, escolhe um movimento pseudo-aleatório
        currentPosition = ChooseNextMove();
    }
}

bool Agent::HasVisited(int x, int y) const {
    return std::find(lastPositions.begin(), lastPositions.end(), std::make_pair(x, y)) != lastPositions.end();
}

std::pair<int, int> Agent::ChooseNextMove() {
    // Retorna um movimento pseudo-aleatório que não esteja nas últimas posições visitadas
    // e que não faça o agente bater em paredes
    std::pair<int, int> nextMove;
    do {
        // Gerador de números pseudo-aleatórios
        std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));
        std::uniform_int_distribution<int> dist(-1, 1);

        nextMove.first = currentPosition.first + dist(rng);
        nextMove.second = currentPosition.second + dist(rng);
    } while (!environment.IsWithinBounds(nextMove.first, nextMove.second) || HasVisited(nextMove.first, nextMove.second));

    return nextMove;
}
