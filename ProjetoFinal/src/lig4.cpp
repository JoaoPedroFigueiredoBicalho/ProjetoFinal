#include "lig4.hpp"

void Lig4::lerjogada(int jogadaColuna, char jogada)
{
    int coluna_cheia = 1;
    if (jogadaColuna < 0 || jogadaColuna >= tamanho) {
        std::cout << "Coluna inválida!" << std::endl;
        return;
    } else {

    for (int linha = tamanho - 1; linha >= 0; linha--) {
        if (tabuleiro[linha][jogadaColuna] == ' ') {
            tabuleiro[linha][jogadaColuna] = jogada;
            coluna_cheia = 0;
            break;
        } 
    }
    if (coluna_cheia == 1) {
        std::cout << "Coluna cheia!" << std::endl;
        return;
    }
    }
    if (jogada == 'X') {
        jogada = 'O';
    } else {
        jogada = 'X';
    } 

    
    
}

bool Lig4::tabuleiro_cheio(){
    for (const auto& linha: tabuleiro){
        for (char celula: linha){
            if(celula == ' ')return false;
        }
    }
    return true;
}

bool Lig4::checarvitoria(char jogador){
    int linhas = tabuleiro.size();
    int colunas = tabuleiro[1].size();

    //verificação vertical
    for (int i = 0; i < linhas - 3; i++){
        for (int j = 0; j < colunas; j++){
            if(tabuleiro[i][j] == jogador && tabuleiro[i+1][j] && tabuleiro[i+2][j] == jogador && tabuleiro[i+3][j] == jogador){
                return true;
            }
        }
    }

    //verificacao horizontal
    for (int i = 0; i < linhas - 3; i++){
        for (int j = 0; j < colunas; j++){
            if(tabuleiro[i][j] == jogador && tabuleiro[i][j+1] && tabuleiro[i][j+2] == jogador && tabuleiro[i][j+3] == jogador){
                return true;
            }
        }
    }

    //verificacao diagonal esquerda pra direita
    for (int i = 0; i < linhas - 3; i++) {
        for (int j = 0; j < colunas; j++){
            if (tabuleiro[i][j] == jogador && tabuleiro[i+1][j+1] == jogador && tabuleiro[i+2][j+2] == jogador && tabuleiro[i+3][j+3] == jogador){
                return true;
            }
        }
    }


    // Verificação diagonal direita para esquerda
    for (int i = 3; i < linhas; ++i) {
        for (int j = 0; j < colunas - 3; ++j) {
            if (tabuleiro[i][j] == jogador && tabuleiro[i-1][j+1] == jogador &&
                tabuleiro[i-2][j+2] == jogador && tabuleiro[i-3][j+3] == jogador) {
                return true;
            }
        }
    }

}

