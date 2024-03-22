#include "include/Utility.hpp"
#include <fstream>
#include <iostream>

void ExecuteAgent(Environment &environment, Agent &agent, std::vector<std::string> &actions_log, int max_moves) {
    int total_moves = 0;
    int cleaned_squares = 0;
    int squares_explored = 0;
    std::vector<std::vector<bool>> explored(environment.GetSize(), std::vector<bool>(environment.GetSize(), false));

    for (int step = 0; step < max_moves; ++step) {
        agent.Act(actions_log);
        total_moves++;

        // Incluir aqui o restante do loop de execução baseado no código original...
    }

    GenerateReports(actions_log, environment, agent);
}

void GenerateReports(const std::vector<std::string> &actions_log, const Environment &environment, const Agent &agent) {
    // Implementar a lógica para gerar 'output.data' e 'relatorio.data' baseado no código original...
}