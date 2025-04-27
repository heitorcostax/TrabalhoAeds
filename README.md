
<div align="center">

#  Simulador de Propagação de Incêndio na Floresta

</div>

## 💭 Introdução

O programa se trata de um sistema de simulação da propagação de incêndio em uma floresta e o comportamento de um animal em busca de sobrevivência nesse ambiente hostil. Devido ao cenário de incêndio florestal, o sistema monitora como o fogo se espalha ao longo do tempo, considerando fatores como a influência do vento, e acompanha a movimentação do animal enquanto ele tenta encontrar água (célula segura) e sobreviver. O projeto atende à necessidade de simular e analisar de forma eficiente os padrões de propagação de incêndios florestais e o comportamento adaptativo de animais em situações de risco ambiental.

## 🎯 Objetivos

- Simular o avanço de um incêndio em uma matriz que representa uma floresta.
- Modelar um animal que tenta se deslocar pela floresta, com decisões automáticas.
- Incorporar a influência de vento na propagação do fogo.
- Gerar arquivos de saída com os resultados e trilha do animal.

## 🖥️ Ambiente de Desenvolvimento

- **Linguagem:** C++
- **Compilador:** GCC 11.4.0
- **IDE Recomendada:** Visual Studio Code
- **SO Testado:** Windows version 10
- **Scripts/executáveis auxiliares:** Makefile, scripts shell (opcional)

## 📂 Estrutura dos Arquivos


![estrutura](https://github.com/user-attachments/assets/9b8f4c6f-4a44-4125-92ba-08f6f30c810c)

O programa foi implementando seguindo as classes acima, sendo elas -> Animal; Config; Floresta; Gerenciador e a main (todos com hpp e gpp).

## 💡 Principais Classes e Funções

### `Animal`

- **Responsável por:** Instanciar e modelar o animal na floresta. Nessa classe é possivel: gerenciar a posição, a movimentação,  os passos dados, se a água foi encontrada, e se ele está vivo.
- **Principais métodos:**
  - `mover(Floresta&)`: Move o animal pela matriz, preferencialmente para a direita.
  - `foiAtingidoPeloFogo(Floresta&)`: Verifica se o animal foi atingido pelo fogo e define sua morte.
  - Getters e setters para linha, coluna, total de passos, água encontrada, status de vida/morte e iteração de morte.

### `Floresta`

- **Responsável por:** Armazenar e definir a matriz/mapa da floresta, ler e gravar os arquivos de entrada e saída e manipular células.
- **Principais métodos:**
  - `carregarDoArquivo()`, `salvarNoArquivo()`
  - `imprimirComAnimal()`, `salvarTrilhaAnimal()`
  - `getCelula()`, `definirCelula()`
  - `existeFogo()`
  - Métodos para acessar e modificar a matriz internamente.

### `Config`

- **Responsável por:** Lógica de propagação do fogo, considerando ou não a influência do vento (em cada direção).
- **Principais métodos:**
  - `propagar(Floresta&, ...)`: Propaga o fogo na matriz dada conforme as regras e condições do vento.

### `Gerenciador`

- **Responsável por:** Controlar o ciclo completo da simulação (setup, execução, estatísticas, saída), sendo a principal classe do programa.
- **Principais métodos:**
  - `executarSimulacao()`
  - `imprimirResultados()`
  - `salvarResultados()`
- **Extras:** Inicializa floresta, animal, lê do arquivo de entrada, escreve nos arquivos de saída, mede tempo de execução, controla ciclos e termina condições da simulação.

### `main.cpp`

- Inicia a simulação e chama o `Gerenciador::executarSimulacao()`.

---

## 📥 Como Executar

### 1. Preparar o ambiente

- Instale um compilador C++ (ex.: GCC).
- Garanta que o arquivo de entrada esteja em um diretório chamado inputs e que seu nome seja input.dat ( `inputs/input.dat`) e que tenha a seguinte estrutura:
    ```
    <n> <m>
    <linha_animal> <coluna_animal>
    <linha 1 da matriz>
    <linha 2 da matriz>
    ...
    ```



### 2. Compilação e Execução

No diretório raiz do projeto, utilize o comando:


| Comando                |  Função                                                                                               |                     
| -----------------------| ------------------------------------------------------------------------------------------------------|
|  make clean          | Apaga a última compilação realizada contida na pasta build                                            |
|  make                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build               |
|  make run            | Executa o programa da pasta build após a realização da compilação                                     |
|make r| Faz os três processos descritos acima em apenas um comando|



### 3. Execução

Após compilar e executar com o comando acima, o programa irá ler o arquivo de entrada `inputs/input.dat` e gerar os arquivos de saída na pasta `outputs/`, como nesse exemplo onde o usuário insere uma matriz 5x5 no arquivo de entrada e o programa soluciona o problema de forma bem efieciente e clara devolvendo essa solução nos dois tipos de arquivo de saída:

### Arquivo de Entrada (inputs/input.dat)

![priaiaiai](https://github.com/user-attachments/assets/47fdc8eb-281d-4b05-9ca2-23b864eb88ae)



### Arquivo da Saída Final da Floresta (outputs/output.dat // outputs/outpult_com_animal.dat)

**Sem animal**

![print saidaaa](https://github.com/user-attachments/assets/389a15d7-1467-487d-97bd-aef385a47940)


**Com animal**

![print](https://github.com/user-attachments/assets/b0357ced-b9be-4da5-b4b0-09984ef0a652)




### Resultados da Simulação (outputs/resultados.txt)

![resultado](https://github.com/user-attachments/assets/e559bcff-a3b0-458b-a02c-947b06ad7e67)



Os arquivos de saída detalham o resultado da simulação:

- **output.dat:**  
  Matriz final da floresta

- **output_com_animal.dat:**  
  Estado da matriz a cada iteração com a posição do animal ('A')

- **resultados.txt:**  
  Resumo estatístico da execução
---

## 🛠️ Como Personalizar e Expandir o Projeto

- **Experimente com diferentes cenários:**  
  Altere o arquivo de entrada (`inputs/input.dat`) para criar florestas de tamanhos variados, posicione o animal em diferentes locais e insira obstáculos (água/vazio) em posições estratégicas. Teste situações com mais ou menos focos de incêndio e diferentes distribuições das árvores.

- **Controle a duração da simulação:**  
  Ajuste o número máximo de iterações diretamente no construtor da classe `Gerenciador` (ou como um parâmetro configurável). Isso permite simular incêndios mais longos ou limitar o tempo de sobrevivência do animal.

- **Personalize a propagação do fogo e adicione eventos climáticos:**  
  Modifique as regras de propagação considerando, por exemplo, umidade do solo, intensidade e direção variável do vento por iteração.

---


## ✔️ Conclusão

O programa de simulação de incêndio florestal cumpre com eficiência seu objetivo principal: modelar tanto a propagação do fogo quanto a sobrevivência animal em um ambiente hostil. A implementação em C++ utiliza uma estrutura orientada a objetos bem definida, com quatro classes que encapsulam as responsabilidades específicas de representar a floresta, o comportamento do fogo, as ações do animal e a coordenação geral da simulação.


A simulação funciona conforme esperado, processando iterativamente as mudanças no ambiente florestal e registrando detalhadamente o percurso e destino do animal. A representação da matriz da floresta e os algoritmos de propagação capturam de forma simplificada, porém efetiva, a dinâmica real de um incêndio florestal, considerando inclusive fatores como a influência do vento.


O sistema produz um relatório claro que possibilita ao usuário/cliente a análise dos resultados de forma precisa, tornando-o uma ferramenta valiosa para estudos educacionais sobre incêndios florestais e comportamento animal em situações de emergência.


---

## 📪 Contato

Em caso de dúvidas, sugestões ou interesse em contribuir:

- Email: [heitorfrancisco2005@hotmail.com](heitorfrancisco2005@hotmail.com)
- GitHub: [heitorcostax](https://github.com/heitorcostax)

