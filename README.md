<div align="center" style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div>

#

<!-- <h1 align="center">
    <a>
        <img alt="Banner" title="#Banner" style="object-fit: fill; height:200px;" src="imgs/github-header-image.png" />
    </a>
</h1> -->

# 📌 Sumário

>1. [⚠️ Apresentação do Problema ](#%EF%B8%8F-apresentação-do-problema)
>2. [💡 Solução do Problema ](#-solu%C3%A7%C3%A3o-do-problema)
>		* 
>4. [🔬 Experimentação](#-experimenta%C3%A7%C3%A3o)
>5. [🎯 Conclusão](#-conclus%C3%A3o)
>6. [🔄 Compilação e execução](#-compila%C3%A7%C3%A3o-e-execu%C3%A7%C3%A3o)
>7. [📞 Contato](#-contato)

# ⚠️ Apresentação do Problema 

<p align="center">
<img src="imgs/main2.png" width="450"/> 
</p>
<p align="center">
<em>Imagem 1: Imagem ilustrativa do agente reativo simples que será implementado. </em>
</p>

<div align="justify">
Implemente um agente inteligente para o mundo do aspirador de pó no qual o agente possui um sensor de sujeira e um método `suck`. Considerações: 
    
  1. O agente implementado será avaliado em um abiente de matriz NxN, inicialmente 4x4, porém o tamanho do ambiente e deve ser flexível para uso em outras dimensões.
  
  2. O agente não sabe a disposição da sujeira nem mesmo o tamanho do ambiente.
  
  3. O agente é iniciado em um local aleatório a cada experimento.
  
  4. O agente pode se movimentar para direita, esquerda, cima e para baixo.
  
  5. O agente pode armazenar o estado de até 3 movimentos realizados. No entanto, ele não pode armazenar sua localização.
  
  6. Após ser realizada a limpeza, o ambiente não volta a ficar sujo.

  7. Se bater na parede o agente deve fazer um movimento pseudo-aleatório. Ele pode usar as informações dos estados anteriores para fazer esse movimento.
  
  8. A disposição do local de sujeira deve ser gerada de forma aleatória antes de iniciar o agente. Porém, as configurações de quantidade serão as seguintes:
    - Configurações: 16 quadrados sujos, 12 quadrados sujos, 8 quadrados sujos e 4 quadrados sujos.
  
  9. Registre a pontuação do Aspirador:
      - ganha 3 pontos para cada ambiente limpo;
      - perde 1 ponto para cada movimento;
      - perde 20 pontos para cada quadrado sujo remanescente após o término da limpeza;

  10. O Critério de parada do agente deve ser definido pelo aluno.

  11. Para experimentação, deve-se executar 10 repetições de cada configuração e apresentar o melhor resultado, o pior, a média e o desvio padrão.
  
A intenção global do problema não é encontrar uma saída, mas sim, tentar deixar o ambiente limpo e obter uma pontuação razoável ou "morrer tentando".
</div>

# 💡 Solução do Problema 

<div align="justify">

O agente inteligente é projetado para operar em um ambiente simulado, enfrentando desafios de navegação e limpeza com uma abordagem que mescla aleatoriedade e memória de curto prazo. Abaixo, será discutida a descrição dessa estratégia.

</div>

## Componentes Principais

- **`Agent`**: Opera com lógica reativa para navegar e limpar o ambiente baseado em sua percepção imediata e uma memória curta de ações passadas.
- **`Environment`**: Define o espaço de atuação do agente, gerando configurações aleatórias de sujeira em uma matriz NxN.
- **`Utility`**: Fornece suporte para execução do agente e geração de relatórios, simplificando o fluxo principal de atividades.

## Estratégias Implementadas

- **Posicionamento Aleatório e Ação Inicial**: O agente é colocado aleatoriamente no ambiente e imediatamente verifica e age sobre sujeira na posição inicial.
- **Movimentação no meio da matriz:** O agente se move de forma aleatória, escolhendo entre quatro direções: cima, baixo, esquerda e direita. Essa abordagem visa cobrir o ambiente de maneira eficaz, evitando padrões previsíveis.
- **Após colidir com uma parede:** O agente recorda seus últimos três movimentos para evitar repetições imediatas, especialmente útil após colidir com uma parede. Essa memória ajuda a diversificar a exploração sem cair em ciclos.

# 🔬 Experimentação 

<div align="justify">

Para uma análise abrangente, a experimentação seguiu os seguintes passos:

- **Configurações Testadas**: As execuções foram divididas em quatro configurações de sujeira dentro do ambiente, especificamente com 16, 12, 8 e 4 quadrados sujos, respectivamente

- **Repetições**: Para cada uma dessas configurações, realizou-se 10 repetições, garantindo que os resultados refletissem a variabilidade do comportamento do agente devido à sua inicialização e movimentos aleatórios.

</div>


## Análise dos Resultados

<div align="justify">

A tabela a seguir resume os resultados obtidos após 10 repetições com critério de parada de 32 movimentos para cada configuração de sujeira no ambiente:

</div>


<div align="center">

| Configuração de Sujeira | Pior Resultado | Melhor Resultado | Média  | Desvio Padrão |
|-------------------------|------------------|----------------|--------|---------------|
| 25% Sujos                | -112             | -54            | -79.3  | 15.7          |
| 50% Sujos                | -192             | -100           | -138.4 | 26.9          |
| 75% Sujos                | -249             | -88            | -163.9 | 55.2          |
| 100% Sujos               | -260             | 191            | -166.0 | 134.7         |

</div>

<div align="justify">

Os resultados destacam a variação na performance do agente com diferentes níveis de sujeira no ambiente. Aumentos na quantidade de sujeira tendem a dificultar a tarefa do agente, refletido nos valores de pontuação mais baixos e na maior variação (desvio padrão) entre os resultados.

</div>

<!-- <p align="center">
<img src="imgs/teoria.png" width="600"/> 
</p>
<p align="center">
<em>Imagem 1: Parte do `output.data` gerado a partir das entradas para análise. </em>
</p> -->

# 🎯 Conclusão 

<div align="justify">

A solução alcançou o objetivo de criar um agente capaz de limpar o ambiente de certa forma eficiente, porém com suas devidas limitações. Observa-se que o agente tem desempenhos variáveis, refletidos nas pontuações obtidas.

- **Variação no Desempenho**: O agente mostrou capacidade de lidar com ambientes variados, mas os resultados indicam uma clara variação no desempenho. O aumento da complexidade do ambiente, com mais sujeira, leva a pontuações mais baixas, demonstrando os desafios adicionais que o agente enfrenta.

- **Desafios e Limitações**: A estratégia de movimento do agente, embora efetiva em certas situações, encontra limitações conforme a complexidade do ambiente aumenta. Isso é evidenciado pelos resultados mais baixos (mais negativos) em ambientes com maior percentual de sujeira.

- **Oportunidades para Melhorias**: Os experimentos sugerem áreas para futuras melhorias, especialmente na otimização da estratégia de movimento e na eficiência da limpeza em ambientes mais desafiadores.

Em suma, a experimentação revelou tanto o potencial quanto as limitações da abordagem atual. Embora o agente demonstre uma capacidade básica de navegação e limpeza, há uma certa necessidade de aprimoramento, visando aumentar a eficiência e adaptabilidade em diversos cenários de limpeza.
</div>

# 🔄 Compilação e Execução 

## 1. Arquivo de Entrada - 'Matriz de Percurso' (`input.data`)

<div align="justify">

É essencial que o usuário inclua um arquivo denominado `input.data` (dentre a coleção de textos inserida na pasta (`dataset`), contendo uma _'matriz de percurso'_.

```C++
4 4

0 0 0 1 
1 1 1 0 
0 1 0 1 
0 0 1 1 
```

Contendo em sua primeira linha os valores `NxN` do tamanho da matriz e em seguida a matriz, onde `0` representam quadrados limpos e `1` os quadrados sujos.
</div>

## 3. Arquivo de saída (`output.data`)
<div align="justify">

Ao final de sua execução, o programa gera um arquivo (`output.data`) dentro da pasta (`dataset`), o qual contém as estruturas propostas na apresentação do problema. Certifique-se de verificá-lo ao final da compilação.

</div>

## 4. Execução

<div align="justify">

Por fim, esse programa possui um arquivo (`Makefile`) e um (`CMakeLists`), os quais realizam todo o procedimento de compilação e execução. Para tanto, cabe ao usuário escolher o de sua preferência, porém se atente ao fato de que para cada um temos as seguintes diretrizes de execução:

</div>

### Makefile

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td>make clean</td>
    <td>Apaga a última compilação realizada contida na pasta build</td>
  </tr>
  <tr>
    <td>make</td>
    <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td>make run</td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>
	
### CMake

<table align="center">
  <tr>
    <th>Comando</th>
    <th>Função</th>
  </tr>
  <tr>
    <td>cmake -B ./build</td>
    <td>Cria as instâncias da pasta build necessárias para execução do programa</td>
  </tr>
  <tr>
    <td>cmake --build ./build</td>
    <td>Executa a compilação do programa utilizando o cmake, e o resultado vai para a pasta build</td>
  </tr>
  <tr>
    <td>./build/app</td>
    <td>Executa o programa da pasta build após a realização da compilação</td>
  </tr>
</table>

# 📞 Contato

<table align="center">
  <tr>
    <th>Participante</th>
    <th>Contato</th>
  </tr>
  <tr>
    <td>Celso</td>
    <td><a href="https://t.me/celso_vsf"><img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> </td>
  </tr>
</table>