#include "Floresta.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Floresta::Floresta(int n, int m)
    : n(n), m(m), matriz(n, vector<int>(m, 1)) {}

Floresta::~Floresta() {}

void Floresta::carregarDoArquivo(const string& nomeArquivo, int& linhaAnimal, int& colunaAnimal) {
    ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }
    arquivo >> n >> m;
    arquivo >> linhaAnimal >> colunaAnimal;
    matriz.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arquivo >> matriz[i][j];
        }
    }
    arquivo.close();
}

void Floresta::salvarNoArquivo(const string& nomeArquivo) const {
    ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar no arquivo: " << nomeArquivo << endl;
        return;
    }
    arquivo << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arquivo << matriz[i][j];
            if (j < m - 1) {
                arquivo << " ";
            }
        }
        arquivo << endl;
    }
    arquivo.close();
}

void Floresta::imprimirComAnimal(int linhaAnimal, int colunaAnimal) const {
    cout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == linhaAnimal && j == colunaAnimal) {
                cout << 'A';
            } else {
                cout << matriz[i][j];
            }
            if (j < m - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Floresta::salvarTrilhaAnimal(const std::string& nomeArquivo, int linhaAnimal, int colunaAnimal, int iteracao) const {
    ofstream arquivo(nomeArquivo, ios::app);
    if (!arquivo.is_open()) {
        cerr << "Erro ao salvar no arquivo: " << nomeArquivo << endl;
        return;
    }
    arquivo << "Iteracao " << iteracao << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == linhaAnimal && j == colunaAnimal)
                arquivo << 'A';
            else
                arquivo << matriz[i][j];
            if (j < m - 1) arquivo << " ";
        }
        arquivo << "\n";
    }
    arquivo << "\n";
    arquivo.close();
}

int Floresta::getCelula(int linha, int coluna) const {
    return matriz[linha][coluna];
}

void Floresta::definirCelula(int linha, int coluna, int valor) {
    matriz[linha][coluna] = valor;
}

int Floresta::getN() const { return n; }
int Floresta::getM() const { return m; }

bool Floresta::existeFogo() const {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matriz[i][j] == 2)
                return true;
    return false;
}

void Floresta::imprimir() const {
    cout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matriz[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
}

const std::vector<std::vector<int>>& Floresta::acessarMatriz() const {
    return matriz;
}

void Floresta::setMatriz(const std::vector<std::vector<int>>& novaMatriz) {
    matriz = novaMatriz;
}