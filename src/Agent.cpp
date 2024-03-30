#include "include/Agent.hpp"
#include <cstdlib>
#include <ctime>
#include <sstream>

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

// Define o comportamento do agente em cada movimento
void Agent::Act(std::vector<std::string> &log) {
    std::stringstream logEntry;
    // Se a posição atual está suja, o agente limpa
    if (environment.IsDirty(current_x, current_y)) {
        CleanCurrentPosition();
        logEntry << "Limpou em (" << current_x << ", " << current_y << ")";
        log.push_back(logEntry.str());
        UpdateMemory(0, 0); // Representa ação de limpeza sem deslocamento
    } else {
        std::vector<std::pair<int, int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // Cima, Direita, Baixo, Esquerda
        std::random_shuffle(directions.begin(), directions.end()); // Mistura as direções para aleatoriedade

        bool moved = false;
        for (auto &dir : directions) {
            int dx = dir.first, dy = dir.second;

            // Verifica se este deslocamento foi realizado recentemente
            if (std::find(memory.begin(), memory.end(), std::make_pair(dx, dy)) != memory.end()) {
                continue; // Pula este deslocamento se foi um dos últimos três realizados
            }

            int new_x = current_x + dx;
            int new_y = current_y + dy;

            // Checa se o novo movimento é válido e não resulta em colisão com a parede
            if (new_x >= 0 && new_x < environment.GetSize() && new_y >= 0 && new_y < environment.GetSize()) {
                UpdatePosition(dx, dy); // Atualiza a posição baseada no deslocamento
                moved = true;
                logEntry.str(""); // Limpa o stringstream
                logEntry << "Move para (" << new_x << ", " << new_y << ")";
                log.push_back(logEntry.str());
                break; // Sai do loop após um movimento bem-sucedido
            } else {
                // Registra a tentativa de movimento que resultaria em colisão
                UpdateMemory(dx, dy); // Atualiza a memória com o deslocamento tentado
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

void Agent::UpdatePosition(int dx, int dy) {
    // Atualiza a posição atual do agente
    current_x += dx;
    current_y += dy;

    // Atualiza a memória do agente com o movimento mais recente como deslocamento
    std::rotate(memory.rbegin(), memory.rbegin() + 1, memory.rend());
    memory[0] = { dx, dy };
}

void Agent::UpdateMemory(int dx, int dy) {
    // Semelhante à lógica em UpdatePosition, mas sem alterar as coordenadas do agente
    std::rotate(memory.rbegin(), memory.rbegin() + 1, memory.rend());
    memory[0] = { dx, dy };
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
    ss << "\n";
    return ss.str();
}
