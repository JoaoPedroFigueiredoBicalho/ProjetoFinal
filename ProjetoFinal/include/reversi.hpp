#ifndef REVERSI_H
#define REVERSI_H
#include "boardLogic.hpp"
class Reversi : public boardLogic
{
private:
  const char Jogador1 = 'X';
  const char Jogador2 = 'O';

public:
  void checar_jogada(int linha, int coluna);
  void checar_casas_a_virar(int linha, int coluna, int direcao);
  bool checar_se_dentro_do_tabuleiro(int linha, int coluna);
  void virar_casas(int linha, int coluna, int dir_l, int dir_c);
};
#endif