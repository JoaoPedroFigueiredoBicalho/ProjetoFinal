#ifndef LIG4_H
#define LIG4_H
#include "boardLogic.hpp"
class Lig4 : public boardLogic
{
public:
  void lerjogada(int jogadaColuna, char jogada) override;
  void checarvitoria(char jogada);
  void tabuleiro_cheio();
  
};
#endif