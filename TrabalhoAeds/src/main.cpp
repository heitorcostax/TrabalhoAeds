#include "Gerenciador.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "Iniciando simulacao de propagacao de incendio em floresta..." << endl;
    Gerenciador gerenciador;
    gerenciador.executarSimulacao();
    cout << "Simulacao concluida. Resultados salvos em 'resultados.txt'." << endl;
    return 0;
}