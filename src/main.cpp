#include "include/Environment.hpp"
#include "include/Agent.hpp"
#include "include/Utility.hpp"
#include "include/InputGenerator.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Gera dados de entrada (matriz de ambiente)
    GenerateInputData();  // Caso queira testar com a mesma matriz,comente esta função
    try {
        Environment environment("dataset/input.data");
        Agent agent(environment);
        std::vector<std::string> actions_log;
        // Define o critério de parada, exemplo 32 movimentos
        const int max_moves = 32;
        // Executa o agente no ambiente, registrando suas ações
        ExecuteAgent(environment, agent, actions_log, max_moves);
        std::cout << "Execução finalizada. Verifique os arquivos de saída." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Ocorreu um erro: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
