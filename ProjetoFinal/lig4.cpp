#include "lig4.hpp"

void Lig4::lerjogada(int jogadaColuna, char jogada)
{
    if (jogadaColuna < 0 || jogadaColuna >= tamanho) {
        std::cout << "Coluna inválida!" << std::endl;
        return;
    } else {

    for (int linha = tamanho; linha >= 0; linha--) {
        if (tabuleiro[linha][jogadaColuna] == ' ') {
            tabuleiro[linha][jogadaColuna] = jogada;
        } 
    }
    }
    if (jogada = 'X') {
        jogada = 'O';
    } else {
        jogada = 'X';
    } 
    //colocar o tratamento de excecao para coluna cheia
}

