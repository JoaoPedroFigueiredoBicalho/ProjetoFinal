#ifndef REVERSI_H
#define REVERSI_H
#include "boardLogic.hpp"
class Reversi : public boardLogic
{
public:
  void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);
};
#endif