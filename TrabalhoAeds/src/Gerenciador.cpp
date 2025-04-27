#include "Gerenciador.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib> // Para usar system()
#include <chrono>  // Para medir o tempo de execução
#include <sys/stat.h> // Para verificar a existência do diretório

using namespace std;

bool diretorioExiste(const std::string& nomeDiretorio) {
    struct stat info;
    if (stat(nomeDiretorio.c_str(), &info) != 0) {
        // Diretório não existe
        return false;
    }
    return (info.st_mode & S_IFDIR) != 0; // Verifica se é um diretório
}

void criarDiretorioOutputs() {
    if (!diretorioExiste("outputs")) {
        system("mkdir outputs >nul 2>&1"); // No Windows
        // system("mkdir -p outputs"); // No Linux/Mac
    }
}

Gerenciador::Gerenciador() :
    n(10), m(10), k(100),
    influenciaVento(false),
    ventoCima(false), ventoBaixo(false), ventoEsquerda(false), ventoDireita(false),
    debug(false),
    floresta(n, m),
    animal(0, 0),
    config(),
    iteracaoAtual(0),
    simulacaoConcluida(false)
{
    criarDiretorioOutputs(); // Cria o diretório "outputs" se não existir

    int linhaAnimal = 0, colunaAnimal = 0;
    floresta = Floresta(n, m);
    floresta.carregarDoArquivo("inputs/input.dat", linhaAnimal, colunaAnimal);
    animal = Animal(linhaAnimal, colunaAnimal);

    matrizFogo = floresta.acessarMatriz();
}

Gerenciador::~Gerenciador() {}

void Gerenciador::executarSimulacao() {
    iteracaoAtual = 0;
    simulacaoConcluida = false;

    // Limpar o arquivo "output_com_animal.dat" no diretório "outputs"
    ofstream limpar("outputs/output_com_animal.dat", ios::trunc);
    limpar.close();

    if (debug) {
        cout << "Parametros:" << endl;
        cout << "Floresta: " << floresta.getN() << "x" << floresta.getM() << endl;
        cout << "Iteracoes: " << k << endl;
        cout << "Vento: " << (influenciaVento ? "Sim" : "Nao") << endl;
    }

    auto inicio = chrono::high_resolution_clock::now();

    matrizFogo = floresta.acessarMatriz();
    Floresta florestaFogo = floresta;

    std::vector<std::vector<int>> ultimaMatrizAnimal;

    while (iteracaoAtual < k && floresta.existeFogo() && animal.estaVivo()) {
        if (debug) {
            cout << "\nIteracao " << iteracaoAtual + 1 << ":" << endl;
            floresta.imprimir();
            cout << "Animal: (" << animal.getLinha() << ", " << animal.getColuna() << ")" << endl;
        }

        animal.mover(floresta);

        // Salvar a trilha do animal no arquivo "output_com_animal.dat" no diretório "outputs"
        floresta.salvarTrilhaAnimal("outputs/output_com_animal.dat", animal.getLinha(), animal.getColuna(), iteracaoAtual);

        ultimaMatrizAnimal = floresta.acessarMatriz();

        config.propagar(floresta, influenciaVento, ventoCima, ventoBaixo, ventoEsquerda, ventoDireita);
        config.propagar(florestaFogo, influenciaVento, ventoCima, ventoBaixo, ventoEsquerda, ventoDireita);

        matrizFogo = florestaFogo.acessarMatriz();

        if (animal.foiAtingidoPeloFogo(floresta)) {
            animal.mover(floresta);
            if (animal.foiAtingidoPeloFogo(floresta)) {
                animal.definirIteracaoMorte(iteracaoAtual);
                if (debug)
                    cout << "Animal atingido pelo fogo!" << endl;
            }
        }
        iteracaoAtual++;
    }

    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::milliseconds>(fim - inicio).count();

    // Salvar o estado final da floresta no arquivo "output.dat" no diretório "outputs"
    std::ofstream arquivo("outputs/output.dat");
    if (arquivo.is_open()) {
        for (int i = 0; i < floresta.getN(); ++i) {
            for (int j = 0; j < floresta.getM(); ++j) {
                arquivo << ultimaMatrizAnimal[i][j];
                if (j < floresta.getM() - 1) arquivo << " ";
            }
            arquivo << "\n";
        }
        arquivo.close();
    }

    if (debug) {
        cout << "Concluido em " << duracao << " ms, " << iteracaoAtual << " iteracoes." << endl;
    }
    simulacaoConcluida = true;
    imprimirResultados();
    salvarResultados("resultados.txt");
}

void Gerenciador::imprimirResultados() {
    if (!simulacaoConcluida) {
        cout << "Simulacao nao concluida. Rode 'executarSimulacao()' primeiro." << endl;
        return;
    }
    cout << "\n====== RESULTADOS DA SIMULACAO ======" << endl;
    cout << "Iteracoes realizadas: " << iteracaoAtual << endl;
    cout << "Posição final do animal: (" << animal.getLinha() << ", " << animal.getColuna() << ")" << endl;
    cout << "Passos dados pelo animal: " << animal.getTotalPassos() << endl;
    cout << "Água encontrada pelo animal: " << animal.getAguaEncontrada() << endl;
    if (!animal.estaVivo())
        cout << "Animal NÃO sobreviveu. Iteracao da morte: " << animal.getIteracaoMorte() + 1 << "." << endl;
    else
        cout << "Animal sobreviveu!" << endl;
    cout << "=====================================" << endl;
}

void Gerenciador::salvarResultados(const std::string& nomeArquivo) {
    std::ofstream arquivo("outputs/" + nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar os resultados no arquivo: outputs/" << nomeArquivo << std::endl;
        return;
    }

    arquivo << "====== RESULTADOS DA SIMULACAO ======" << std::endl;
    arquivo << "Iteracoes realizadas: " << iteracaoAtual << std::endl;
    arquivo << "Posição final do animal: (" << animal.getLinha() << ", " << animal.getColuna() << ")" << std::endl;
    arquivo << "Passos dados pelo animal: " << animal.getTotalPassos() << std::endl;
    arquivo << "Água encontrada pelo animal: " << animal.getAguaEncontrada() << std::endl;
    if (!animal.estaVivo())
        arquivo << "Animal NÃO sobreviveu. Iteracao da morte: " << animal.getIteracaoMorte() + 1 << "." << std::endl;
    else
        arquivo << "Animal sobreviveu!" << std::endl;
    arquivo << "=====================================" << std::endl;

    arquivo.close();
}