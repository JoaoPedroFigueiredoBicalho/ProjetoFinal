#ifndef REVERSI_H
#define REVERSI_H
#include "boardLogic.hpp"
class Reversi : public boardLogic
{
private:
  const char Jogador1 = 'X';
  const char Jogador2 = 'O';

public:
  void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);
  void checar_jogada_valida(int linha, int coluna);
  void checar_casas_viradas(int direcao);
};
#endif