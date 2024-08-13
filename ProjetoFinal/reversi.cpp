#include "reversi.hpp"

void Reversi::lerjogada(int jogadaLinha, int jogadaColuna, char jogada)
{
  get_tabuleiro()[0][0] = 'X';
  imprimir_tabuleiro();
}