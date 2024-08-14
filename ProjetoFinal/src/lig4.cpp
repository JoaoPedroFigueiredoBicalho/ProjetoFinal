#include "lig4.hpp"

void Lig4::lerjogada(int jogadaColuna)
{
    int coluna_cheia = 1;
    if (jogadaColuna < 0 || jogadaColuna >= get_tamanho()) {
        std::cout << "Coluna inválida!" << std::endl;
        return;
    } else {

    for (int linha = get_tamanho() - 1; linha >= 0; linha--) {
        if (get_tabuleiro()[linha][jogadaColuna] == ' ') {
            get_tabuleiro()[linha][jogadaColuna] = jogada;
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
    for (const auto& linha: get_tabuleiro()){
        for (char celula: linha){
            if(celula == ' ')return false;
        }
    }
    return true;
}

bool Lig4::checarvitoria(char jogador){
    int linhas = get_tabuleiro().size();
    int colunas = get_tabuleiro()[1].size();

    //verificação vertical
    for (int i = 0; i < linhas - 3; i++){
        for (int j = 0; j < colunas; j++){
            if(get_tabuleiro()[i][j] == jogador && get_tabuleiro()[i+1][j] == jogador && get_tabuleiro()[i+2][j] == jogador && get_tabuleiro()[i+3][j] == jogador){
                return true;
            }
        }
    }

    //verificacao horizontal
    for (int i = 0; i < linhas - 3; i++){
        for (int j = 0; j < colunas; j++){
            if(get_tabuleiro()[i][j] == jogador && get_tabuleiro()[i][j+1] == jogador && get_tabuleiro()[i][j+2] == jogador && get_tabuleiro()[i][j+3] == jogador){
                return true;
            }
        }
    }

    //verificacao diagonal principal
    for (int i = 0; i < linhas - 3; i++) {
        for (int j = 0; j < colunas - 3; j++){
            if (get_tabuleiro()[i][j] == jogador && get_tabuleiro()[i+1][j+1] == jogador && get_tabuleiro()[i+2][j+2] == jogador && get_tabuleiro()[i+3][j+3] == jogador){
                return true;
            }
        }
    }


    // Verificação diagonal secundaria
    for (int i = 3; i < linhas ; ++i) {
        for (int j = 0; j < colunas - 3; ++j) {
            if (get_tabuleiro()[i][j] == jogador && get_tabuleiro()[i-1][j+1] == jogador &&
                get_tabuleiro()[i-2][j+2] == jogador && get_tabuleiro()[i-3][j+3] == jogador) {
                return true;
            }
        }
    }
    return false;
}
