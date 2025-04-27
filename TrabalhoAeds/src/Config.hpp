#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "Floresta.hpp"

class Config {
public:
    Config();
    void propagar(
        Floresta& floresta,
        bool influenciaVento,
        bool ventoCima,
        bool ventoBaixo,
        bool ventoEsquerda,
        bool ventoDireita
    );
};

#endif