#include "include/Utility.hpp"
#include <fstream>
#include <iostream>

void ExecuteAgent(Environment &environment, Agent &agent, std::vector<std::string> &actions_log, int max_moves) {
    int total_moves = 0;
    int cleaned_squares = 0;
    int squares_explored = 0;
    // Inicializa contadores e registra a ação inicial se o agente começar em um quadrado sujo
    std::vector<std::vector<bool>> explored(environment.GetSize(), std::vector<bool>(environment.GetSize(), false));

    // Verifica e contabiliza a limpeza inicial se o agente começar em uma posição suja
    if (environment.IsDirty(agent.GetCurrentX(), agent.GetCurrentY())) {
        cleaned_squares++;
    }

    for (int step = 0; step < max_moves; ++step) {
        agent.Act(actions_log); // Executa uma ação do agente
        total_moves++;

        int current_x = agent.GetCurrentX();
        int current_y = agent.GetCurrentY();
        std::string currentState = agent.LogCurrentState();
        actions_log.push_back(currentState);

        // Atualiza contadores e registra a ação
        if (!explored[current_x][current_y]) {
            squares_explored++;
            explored[current_x][current_y] = true;

            if (environment.IsDirty(current_x, current_y)) {
                cleaned_squares++;
                agent.UpdateScore(3);
            }
        }
        // Atualiza a pontuação do agente por movimento
        agent.UpdateScore(-1);
        // actions_log.push_back("Mov Atual " + std::to_string(total_moves) + ": (" + std::to_string(current_x) + ", " + std::to_string(current_y) + ")");
    }

    GenerateReports(actions_log, environment, agent, total_moves, cleaned_squares, squares_explored);
}

// Cria o relatorio a partir das informações fornecidas pela função de execução do agente
void GenerateReports(const std::vector<std::string> &actions_log, const Environment &environment, const Agent &agent, int total_moves, int cleaned_squares, int squares_explored) {
    std::ofstream output_file("dataset/output.data");
    for (const auto &action : actions_log) {
        output_file << action << "\n";
    }
    output_file.close();

    int remaining_dirty_squares = environment.CountRemainingDirtySquares();
    int points_lost_due_to_moves = total_moves;
    int points_lost_due_to_dirt = remaining_dirty_squares * 20;
    int clean_score = cleaned_squares * 3;
    int final_score = clean_score - points_lost_due_to_moves - points_lost_due_to_dirt;

    std::ofstream report_file("dataset/relatorio.data");
    report_file << "A) Casas percorridas: " << squares_explored << "\n";
    report_file << "B) Casas não exploradas: " << (environment.GetSize() * environment.GetSize()) - squares_explored << "\n";
    report_file << "C) Sujeiras limpas: " << cleaned_squares << "\n";
    report_file << "D) Pontos ganhos: " << clean_score << "\n";
    report_file << "E) Penalidades por movimento: " << points_lost_due_to_moves << "\n";
    report_file << "F) Penalidades por sujeira remanescente: " << points_lost_due_to_dirt << "\n";
    report_file << "G) Pontuação Final: " << final_score << "\n";
    report_file.close();
}
