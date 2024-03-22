// main.cpp

#include "include/Environment.hpp"
#include "include/Agent.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>

int main() {
    try {
        Environment environment("dataset/input.data");
        Agent agent(environment);

        std::vector<std::string> actions_log;
        const int max_moves = 20;
        int total_moves = 0;
        int cleaned_squares = 0;
        int squares_explored = 0;
        std::vector<std::vector<bool>> explored(environment.GetSize(), std::vector<bool>(environment.GetSize(), false));

        // Executa até que o número máximo de movimentos seja atingido
        for (int step = 0; step < max_moves; ++step) {
            agent.Act(); // Agente executa uma ação
            total_moves++;

            int current_x = agent.GetCurrentX();
            int current_y = agent.GetCurrentY();

            // Atualiza a contagem de quadrados limpos
            if (!explored[current_x][current_y]) {
                squares_explored++;
                explored[current_x][current_y] = true;

                if (environment.IsDirty(current_x, current_y)) {
                    cleaned_squares++;
                    agent.UpdateScore(3); // ganha 3 pontos para cada ambiente limpo
                }
            }

            agent.UpdateScore(-1); // perde 1 ponto para cada movimento

            // Log da ação atual
            actions_log.push_back("Move " + std::to_string(total_moves) + ": (" + std::to_string(current_x) + ", " + std::to_string(current_y) + ")");
        }

        // Calcula as sujeiras remanescentes usando o método apropriado da classe Environment
        int remaining_dirty_squares = environment.CountRemainingDirtySquares();

        // Calcula os pontos perdidos devido a movimentos e sujeiras remanescentes
        int points_lost = total_moves + (remaining_dirty_squares * 20); // Calcula apenas uma vez
        int final_score = agent.GetScore() - points_lost; // Calcula apenas uma vez

        // Geração do arquivo output.data com o log das ações do agente
        std::ofstream output_file("dataset/output.data");
        for (const auto &action : actions_log) {
            output_file << action << "\n";
        }
        output_file.close();

        // Cálculo da pontuação final e geração do arquivo relatorio.data
        std::ofstream report_file("relatorio.data");
        report_file << "A) Casas percorridas: " << squares_explored << "\n";
        report_file << "B) Casas não exploradas: " << (environment.GetSize() * environment.GetSize()) - squares_explored << "\n";
        report_file << "C) Sujeiras limpas: " << cleaned_squares << "\n";
        report_file << "D) Pontos ganhos: " << agent.GetScore() << "\n";
        report_file << "E) Pontos perdidos: " << points_lost << "\n";
        report_file << "F) Pontuação Final: " << final_score << "\n";
        report_file.close();

        std::cout << "Execução finalizada. Verifique os arquivos de saída." << std::endl;

    }
    catch (const std::exception &e) {
        std::cerr << "Ocorreu um erro: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}