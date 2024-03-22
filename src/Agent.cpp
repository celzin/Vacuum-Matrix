// agent.cpp

#include "include/Agent.hpp"
#include <cstdlib>
#include <ctime>

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

void Agent::Act() {
    // Se a posição atual estiver suja, limpe
    if (environment.IsDirty(current_x, current_y)) {
        CleanCurrentPosition();
    } else {
        // Escolha um movimento pseudo-aleatório que não seja contra a parede
        int new_x = current_x;
        int new_y = current_y;
        bool move_valid = false;

        while (!move_valid) {
            int move_direction = std::rand() % 4; // Gera um número entre 0 e 3
            switch (move_direction) {
            case 0: new_x = (current_x > 0) ? current_x - 1 : current_x; break; // Movimento para cima
            case 1: new_y = (current_y < environment.GetSize() - 1) ? current_y + 1 : current_y; break; // Movimento para a direita
            case 2: new_x = (current_x < environment.GetSize() - 1) ? current_x + 1 : current_x; break; // Movimento para baixo
            case 3: new_y = (current_y > 0) ? current_y - 1 : current_y; break; // Movimento para a esquerda
            }

            // Verifica se o movimento é válido
            move_valid = (new_x != current_x || new_y != current_y);
        }

        UpdatePosition(new_x, new_y);
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
