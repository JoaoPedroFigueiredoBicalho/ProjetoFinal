#ifndef LIG4_H
#define LIG4_H
#include "boardLogic.hpp"
class Lig4 : public boardLogic
{
public:
  void lerjogada(int jogadaColuna);
  bool checarvitoria(char jogada);
  bool tabuleiro_cheio();
};
#endif