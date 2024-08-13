#include "lig4.hpp"

void Lig4::lerjogada(int jogadaColuna, char jogada)
{
    if (jogadaColuna < 0 || jogadaColuna >= tamanho) {
        std::cout << "Coluna inválida!" << std::endl;
        return;
    }

    for (int linha = 0; linha <= tamanho; linha++) {
        if (tabuleiro[linha][jogadaColuna] == ' ') {
            tabuleiro[linha][jogadaColuna] = jogada;
        }
    }
}

