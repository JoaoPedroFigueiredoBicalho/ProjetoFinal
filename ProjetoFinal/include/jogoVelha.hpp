#ifndef JOGOVELHA_HPP
#define JOGOVELHA_HPP

#include "boardLogic.hpp"

class jogoVelha : public boardLogic
{
public:
  void inicializar_tabuleiro();

  bool lerjogada(int jogadaLinha, int jogadaColuna);

  bool tabuleiro_cheio() const;

  bool checarvitoria(char jogador) const;

  void get_num_pecas_o();

  void get_num_pecas_x();
};

#endif