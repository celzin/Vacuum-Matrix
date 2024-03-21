=// main.cpp
#include "include/Environment.hpp"
#include "include/Agent.hpp"
#include "include/Utility.hpp"
#include <iostream>
#include <string>

int main() {
    try {
        // Criar ambiente e agente
        Environment environment;
        Agent agent(environment);

        // Carregar ambiente a partir do arquivo
        environment.LoadFromFile("input.data");

        // Executar o agente
        agent.Run();

        // Salvar os resultados em arquivos
        Utility::SaveTravessia("dataset/output.data", agent.GetTravessia());
        Utility::SaveRelatorio("relatorio.data", agent.GetScore(), agent.GetCleanedCount(),
            environment.GetPercorridas(), environment.GetNaoExploradas());

        std::cout << "Simulação concluída. Resultados salvos em 'dataset/output.data' e 'relatorio.data'." << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
