#ifndef LIG4_HPP
#define LIG4_HPP

#include "boardLogic.hpp"

class Lig4 : public boardLogic {
public:
    // Processa a jogada na coluna especificada
    void lerjogada(int jogadaColuna);

    // Verifica se o tabuleiro está cheio
    bool tabuleiro_cheio() const;

    // Verifica se há um vencedor no tabuleiro
    bool checarvitoria(char jogador) const;
};

#endif // LIG4_HPP