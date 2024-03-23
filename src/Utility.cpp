#include "include/Utility.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

void ExecuteSimulation(const std::string &inputFilePath, int maxMoves) {
    Environment environment(inputFilePath);
    Agent agent(environment);
    std::vector<std::string> actions_log;
    std::vector<std::vector<bool>> explored(environment.GetSize(), std::vector<bool>(environment.GetSize(), false));
    int total_moves = 0;
    int cleaned_squares = 0;
    int squares_explored = 0;

    for (int step = 0; step < maxMoves; ++step) {
        agent.Act(actions_log);
        total_moves++;

        // Logica para atualizar o estado explorado e a contagem de sujeira
        int current_x = agent.GetCurrentX();
        int current_y = agent.GetCurrentY();
        if (!explored[current_x][current_y]) {
            squares_explored++;
            explored[current_x][current_y] = true;
            if (environment.IsDirty(current_x, current_y)) {
                cleaned_squares++;
                std::cout << cleaned_squares << std::endl;
                environment.Clean(current_x, current_y);
                agent.UpdateScore(3); // Ganha 3 pontos para cada ambiente limpo
            }
        }
        agent.UpdateScore(-1); // Perde 1 ponto para cada movimento
        actions_log.push_back(agent.LogCurrentState()); // Estado atual após ação
    }

    GenerateReports(actions_log, total_moves, cleaned_squares, squares_explored, environment);
}

void GenerateReports(const std::vector<std::string> &actions_log, const int total_moves, const int cleaned_squares, const int squares_explored, const Environment &environment) {
    std::ofstream output_file("dataset/output.data");
    for (const auto &action : actions_log) {
        output_file << action << "\n";
    }
    output_file.close();

    int remaining_dirty_squares = environment.CountRemainingDirtySquares();
    int environment_size = environment.GetSize() * environment.GetSize();
    int points_lost_due_to_moves = total_moves;
    int points_lost_due_to_dirt = remaining_dirty_squares * 20;
    int clean_score = cleaned_squares * 3;
    int final_score = clean_score - points_lost_due_to_moves - points_lost_due_to_dirt;

    std::ofstream report_file("dataset/relatorio.data");
    report_file << "A) Casas percorridas: " << squares_explored << "\n";
    report_file << "B) Casas não exploradas: " << environment_size - squares_explored << "\n";
    report_file << "C) Sujeiras limpas: " << cleaned_squares << "\n";
    report_file << "D) Pontos ganhos: " << clean_score << "\n";
    report_file << "E) Penalidades por movimento: " << points_lost_due_to_moves << "\n";
    report_file << "F) Penalidades por sujeira remanescente: " << points_lost_due_to_dirt << "\n";
    report_file << "G) Pontuação Final: " << final_score << "\n";
    report_file.close();

    // std::cout << "Execução finalizada. Verifique os arquivos de saída." << std::endl;
}