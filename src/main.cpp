#include "include/Environment.hpp"
#include "include/Agent.hpp"
#include "include/Utility.hpp"
#include "include/InputGenerator.hpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    GenerateInputData();
    try {
        Environment environment("dataset/input.data");
        Agent agent(environment);
        std::vector<std::string> actions_log;
        const int max_moves = 20;

        ExecuteAgent(environment, agent, actions_log, max_moves);

        std::cout << "Execução finalizada. Verifique os arquivos de saída." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Ocorreu um erro: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
