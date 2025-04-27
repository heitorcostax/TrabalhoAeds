#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include <string>
#include <vector>
#include "Floresta.hpp"
#include "Animal.hpp"
#include "Config.hpp"

class Gerenciador {
public:
    Gerenciador();
    ~Gerenciador();

    void executarSimulacao();
    void imprimirResultados();
    void salvarResultados(const std::string& nomeArquivo);

private:
    int n, m, k;
    bool influenciaVento;
    bool ventoCima, ventoBaixo, ventoEsquerda, ventoDireita;
    bool debug;

    Floresta floresta;
    Animal animal;
    Config config;
    int iteracaoAtual;
    bool simulacaoConcluida;
    std::vector<std::vector<int>> matrizFogo;
};

#endif