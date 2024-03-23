#include "include/Environment.hpp"
#include "include/Agent.hpp"
#include "include/Utility.hpp"
#include "include/InputGenerator.hpp"
#include <vector>
#include <string>

int main() {
    // GenerateInputData(); // Gera o arquivo input.data com a configuração desejada

    try {
        Environment environment("dataset/input.data");
        Agent agent(environment);
        std::vector<std::string> actions_log;

        ExecuteAgent(environment, agent, actions_log, 20);

        std::cout << "Execução finalizada. Verifique os arquivos de saída." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Ocorreu um erro: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}