// agent.cpp

#include "include/Agent.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream> // Necessário para usar o stringstream

Agent::Agent(Environment &env)
    : environment(env), current_x(0), current_y(0) {
    // Inicializa o gerador de números aleatórios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define a posição inicial aleatória do agente
    current_x = std::rand() % environment.GetSize();
    current_y = std::rand() % environment.GetSize();
}

int Agent::GetCurrentX() const {
    return current_x;
}

int Agent::GetCurrentY() const {
    return current_y;
}

int Agent::GetScore() const {
    return score;
}

void Agent::UpdateScore(int points) {
    score += points;
}

void Agent::Act(std::vector<std::string> &log) {
    std::stringstream logEntry;
    if (environment.IsDirty(current_x, current_y)) {
        CleanCurrentPosition();
        logEntry << "Limpou em (" << current_x << ", " << current_y << ")";
        log.push_back(logEntry.str());
    } else {
        bool moved = false;
        for (int attempts = 0; attempts < 4 && !moved; ++attempts) {
            int dir = std::rand() % 4; // Escolhe direção aleatória
            int new_x = current_x, new_y = current_y;

            // Atualiza new_x e new_y com base na direção
            switch (dir) {
            case 0: new_x--; break; // Cima
            case 1: new_y++; break; // Direita
            case 2: new_x++; break; // Baixo
            case 3: new_y--; break; // Esquerda
            }

            // Checa se o novo movimento é válido
            if (new_x >= 0 && new_x < environment.GetSize() && new_y >= 0 && new_y < environment.GetSize()) {
                UpdatePosition(new_x, new_y);
                moved = true;
                logEntry << "Move para (" << new_x << ", " << new_y << ")";
                log.push_back(logEntry.str());
            } else {
                logEntry.str(""); // Limpa o stringstream
                logEntry << "Colisão com parede ao tentar mover para (" << new_x << ", " << new_y << ")";
                log.push_back(logEntry.str());
            }
        }

        if (!moved) {
            log.push_back("Agent preso, sem movimentos válidos.");
        }
    }
}

void Agent::UpdatePosition(int x, int y) {
    // Atualiza a memória do agente com o movimento mais recente
    memory[2] = memory[1];
    memory[1] = memory[0];
    memory[0] = { current_x, current_y };

    // Atualiza a posição atual do agente
    current_x = x;
    current_y = y;
}

void Agent::CleanCurrentPosition() {
    environment.Clean(current_x, current_y);
}

std::string Agent::LogCurrentState() const {
    std::stringstream ss;
    for (int i = 0; i < environment.GetSize(); ++i) {
        for (int j = 0; j < environment.GetSize(); ++j) {
            if (i == current_x && j == current_y) {
                ss << "X "; // Marca a posição do agente
            } else {
                ss << environment.GetValueAt(i, j) << " "; // Usa GetValueAt para obter o valor
            }
        }
        ss << "\n";
    }
    ss << "\n"; // Espaço extra entre estados para melhor visualização
    return ss.str();
}
