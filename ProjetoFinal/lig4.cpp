#include "lig4.hpp"

void Lig4::lerjogada(int jogadaColuna, char jogada)
{
    if (jogadaColuna < 0 || jogadaColuna >= tamanho) {
        std::cout << "Coluna inválida!" << std::endl;
        return;
    }

    for (int linha = 0; linha <= tamanho; linha++) {
        for (int coluna = 0; coluna <= tamanho; coluna ++) {
        if (tabuleiro[linha][coluna] == ' ') {

        }
        }
    }
}
