#include "Config.hpp"

using namespace std;

Config::Config() {}

void Config::propagar(
    Floresta& floresta,
    bool influenciaVento,
    bool ventoCima,
    bool ventoBaixo,
    bool ventoEsquerda,
    bool ventoDireita
) {
    int n = floresta.getN();
    int m = floresta.getM();
    const auto& matrizOrig = floresta.acessarMatriz();
    vector<vector<int>> matrizNova = matrizOrig; 

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cell = matrizOrig[i][j];

            if (cell == 1) { 
                bool vaiQueimar = false;

                if (!influenciaVento) {
                    if (i > 0     && matrizOrig[i-1][j] == 2) vaiQueimar = true;
                    if (i+1 < n   && matrizOrig[i+1][j] == 2) vaiQueimar = true;
                    if (j > 0     && matrizOrig[i][j-1] == 2) vaiQueimar = true;
                    if (j+1 < m   && matrizOrig[i][j+1] == 2) vaiQueimar = true;
                } else {
                    if (ventoCima     && i > 0     && matrizOrig[i-1][j] == 2) vaiQueimar = true;
                    if (ventoBaixo    && i+1 < n   && matrizOrig[i+1][j] == 2) vaiQueimar = true;
                    if (ventoEsquerda && j > 0     && matrizOrig[i][j-1] == 2) vaiQueimar = true;
                    if (ventoDireita  && j+1 < m   && matrizOrig[i][j+1] == 2) vaiQueimar = true;
                }

                if (vaiQueimar)
                    matrizNova[i][j] = 2;
            }
            else if (cell == 2) {
                matrizNova[i][j] = 3;
            }
        }
    }
    floresta.setMatriz(matrizNova);
}