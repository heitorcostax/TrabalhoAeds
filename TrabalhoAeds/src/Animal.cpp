#include "Animal.hpp"

Animal::Animal(int linha, int coluna)
    : linha(linha), coluna(coluna), totalPassos(0), aguaEncontrada(0), vivo(true), iteracaoMorte(-1) {}

Animal::~Animal() {}

void Animal::mover(Floresta& floresta) {
    if (floresta.getCelula(linha, coluna) == 4) {
        aguaEncontrada++;
    } else {
        if (coluna + 1 < floresta.getM() && floresta.getCelula(linha, coluna + 1) != 4) {
            coluna++;
            totalPassos++;
        }
        if (floresta.getCelula(linha, coluna) != 4) {
            floresta.definirCelula(linha, coluna, 0);
        }
    }
}

bool Animal::foiAtingidoPeloFogo(Floresta& floresta) {
    if (floresta.getCelula(linha, coluna) == 2) {
        vivo = false;
        return true;
    }
    return false;
}

int Animal::getLinha() const {
    return linha;
}

int Animal::getColuna() const {
    return coluna;
}

int Animal::getTotalPassos() const {
    return totalPassos;
}

int Animal::getAguaEncontrada() const {
    return aguaEncontrada;
}

bool Animal::estaVivo() const {
    return vivo;
}

int Animal::getIteracaoMorte() const {
    return iteracaoMorte;
}

void Animal::definirIteracaoMorte(int iteracao) {
    iteracaoMorte = iteracao;
}