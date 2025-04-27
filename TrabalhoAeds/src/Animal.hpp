#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "Floresta.hpp"

class Animal {
public:
    Animal(int linha, int coluna);
    ~Animal();

    void mover(Floresta& floresta);
    bool foiAtingidoPeloFogo(Floresta& floresta);

    int getLinha() const;
    int getColuna() const;
    int getTotalPassos() const;
    int getAguaEncontrada() const;
    bool estaVivo() const;
    int getIteracaoMorte() const;
    void definirIteracaoMorte(int iteracao);

private:
    int linha, coluna;
    int totalPassos;
    int aguaEncontrada;
    bool vivo;
    int iteracaoMorte;
};

#endif