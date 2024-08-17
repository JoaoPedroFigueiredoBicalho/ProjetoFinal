#include "lig4.hpp"
#include <iostream>

bool Lig4::lerjogada(int jogadaColuna) {
    /// Verifica se a coluna é válida, observando se o usuário colocou algum número negativo ou algum número superior ao tamanho do tabuleiro.
    if (jogadaColuna < 0 || jogadaColuna >= tamanho) {
        std::cout << "Coluna inválida!" << std::endl;
        return false;
    }

    bool coluna_cheia = true;
    /// Procura a linha disponível para a jogada na coluna especificada, e caso a coluna não esteja cheia ele coloca uma peça.
    for (int linha = tamanho - 1; linha >= 0; linha--) {
        if (tabuleiro[linha][jogadaColuna] == ' ') {
            tabuleiro[linha][jogadaColuna] = get_jogada_atual();
            coluna_cheia = false;
            break;
        }
    }

    /// Informa se a coluna está cheia.
    if (coluna_cheia) {
        std::cout << "Coluna cheia!" << std::endl;
        return false;
    }

    /// Alterna o jogador após uma jogada.
    alternar_jogador();

    return true;
}

bool Lig4::tabuleiro_cheio() const {
    /// Verifica se todas as entradas estão preenchidas.
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            if (celula == ' ') return false;
        }
    }
    return true;
}

bool Lig4::checarvitoria(char jogador) const {
    /// Verifica se o jogador da vez ganhou.
    int linhas = tabuleiro.size();
    int colunas = tabuleiro[0].size();

    /// Verificação vertical
    for (int i = 0; i < linhas - 3; i++) {
        for (int j = 0; j < colunas; j++) {
            if (tabuleiro[i][j] == jogador &&
                tabuleiro[i + 1][j] == jogador &&
                tabuleiro[i + 2][j] == jogador &&
                tabuleiro[i + 3][j] == jogador) {
                return true;
            }
        }
    }

    /// Verificação horizontal
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas - 3; j++) {
            if (tabuleiro[i][j] == jogador &&
                tabuleiro[i][j + 1] == jogador &&
                tabuleiro[i][j + 2] == jogador &&
                tabuleiro[i][j + 3] == jogador) {
                return true;
            }
        }
    }

    /// Verificação diagonal principal
    for (int i = 0; i < linhas - 3; i++) {
        for (int j = 0; j < colunas - 3; j++) {
            if (tabuleiro[i][j] == jogador &&
                tabuleiro[i + 1][j + 1] == jogador &&
                tabuleiro[i + 2][j + 2] == jogador &&
                tabuleiro[i + 3][j + 3] == jogador) {
                return true;
            }
        }
    }

    /// Verificação diagonal secundária
    for (int i = 3; i < linhas; ++i) {
        for (int j = 0; j < colunas - 3; ++j) {
            if (tabuleiro[i][j] == jogador &&
                tabuleiro[i - 1][j + 1] == jogador &&
                tabuleiro[i - 2][j + 2] == jogador &&
                tabuleiro[i - 3][j + 3] == jogador) {
                return true;
            }
        }
    }
    return false;
}
