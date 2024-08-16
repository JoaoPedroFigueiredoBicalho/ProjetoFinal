#include "jogoVelha.hpp"
#include <iostream>

bool jogoVelha::lerjogada(int jogadaLinha, int jogadaColuna){
    if (jogadaColuna < 0 || jogadaColuna >= tamanho || jogadaLinha < 0 || jogadaLinha >= tamanho) {
    std::cout << "Jogada inválida!" << std::endl;
    return false;
    }
    
    bool entrada_cheia = true;
    if (tabuleiro[jogadaLinha][jogadaColuna] == ' ') {
        tabuleiro[jogadaLinha][jogadaColuna] = get_jogada_atual();
        entrada_cheia = false;
    }

    if (entrada_cheia) {
        std::cout << "Entrada cheia!" << std::endl;
        return false;
    }
    
    alternar_jogador();
    return true;
}

bool jogoVelha::tabuleiro_cheio() const {
    for (const auto& linha : tabuleiro) {
        for (char celula : linha){
            if (celula == ' ') return false;
        }
    }
    return true;
}


bool jogoVelha::checarvitoria(char jogador) const{
    int linhas = 3;
    int colunas = 3;

    //verificação horizontal
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(tabuleiro[i][j] == jogador && tabuleiro[i][j] == jogador && tabuleiro[i][j] == jogador){
                return true;
            }
        }
    }


    //verificação horizontal
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(tabuleiro[j][i] == jogador && tabuleiro[j][i] == jogador && tabuleiro[j][i] == jogador){
                return true;
            }
        }
    }

    //verificação diagonal 1
    if(tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador){
        return true;
    }

    //verificação diagonal 2
    if(tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador){
    return true;
    }   
    return false;
}