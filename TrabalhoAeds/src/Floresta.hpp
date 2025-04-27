#ifndef FLORESTA_HPP
#define FLORESTA_HPP

#include <vector>
#include <string>

class Floresta {
public:
    Floresta(int n, int m);
    ~Floresta();

    void carregarDoArquivo(const std::string& nomeArquivo, int& linhaAnimal, int& colunaAnimal);
    void salvarNoArquivo(const std::string& nomeArquivo) const;
    void imprimirComAnimal(int linhaAnimal, int colunaAnimal) const;

    void salvarNoArquivoComAnimal(const std::string& nomeArquivo, int linhaAnimal, int colunaAnimal) const;

    void salvarTrilhaAnimal(const std::string& nomeArquivo, int linhaAnimal, int colunaAnimal, int iteracao) const;
    int getCelula(int linha, int coluna) const;
    void definirCelula(int linha, int coluna, int valor);
    int getN() const;
    int getM() const;
    bool existeFogo() const;
    void imprimir() const;
    const std::vector<std::vector<int>>& acessarMatriz() const;
    void setMatriz(const std::vector<std::vector<int>>& novaMatriz);

private:
    int n, m;
    std::vector<std::vector<int>> matriz;
};

#endif