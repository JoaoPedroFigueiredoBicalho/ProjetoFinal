#ifndef JOGOVELHA_HPP
#define JOGOVELHA_HPP

#include "boardLogic.hpp"

class jogoVelha : public boardLogic{
public:

    void lerjogada(int jogadaLinha, int jogadaColuna);

    bool tabuleiro_cheio() const;

    bool checarvitoria(char jogador) const;
};

#endif