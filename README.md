<div align="center" style="display: inline_block">
  <img align="center" alt="VS" src="https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white" />
  <img align="center" alt="Linux" src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" />
  <img align="center" alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
</div>

<!--
<h1 align="center">
    <a>
        <img alt="Banner" title="#Banner" style="object-fit: fill; height:200px;" src="imgs/header-image.png" />
    </a>
</h1>
-->

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
    - +3 pontos para cada ambiente limpo;
    - -1 ponto para cada movimento;
    - -20 pontos para cada quadrado sujo remanescente após o término da limpeza;

  10. O Critério de parada do agente deve ser definido pelo aluno.

  11. Para experimentação, deve-se executar 10 repetições de cada configuração e apresentar o melhor resultado, o pior, a média e o desvio padrão.
  
A intenção global do problema não é encontrar uma saída, mas sim, tentar deixar o ambiente limpo e obter uma pontuação razoável ou "morrer tentando".
</div>

# 💡 Solução do Problema 

<div align="justify">
	


</div>

**Política de Balanceamento**:


# 🔬 Experimentação 

<div align="justify">

- ...

- ...

</div>

<p align="center">
<img src="imgs/teoria.png" width="600"/> 
</p>
<p align="center">
<em>Imagem 1: Parte do `output.data` gerado a partir das entradas para análise. </em>
</p>

# 🎯 Conclusão 

<div align="justify">

...

</div>

## Desfecho e Custos

<div align="justify">
	


</div>

# 🔄 Compilação e Execução 

## 1. Arquivo de Entrada - 'Matriz de Percurso' (`input.data`)

<div align="justify">

É também essencial que o usuário inclua um arquivo denominado `input.data` (dentre a coleção de textos inserida na pasta (`dataset`), contendo uma _'matriz de percurso'_.

 - ...
 
 - ...

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