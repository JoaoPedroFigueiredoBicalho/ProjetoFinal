#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include <vector>
#include <iostream>

class boardLogic
{
private:
  std::vector<std::vector<char>> tabuleiro;

public:
  virtual void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);
  void imprimir_tabuleiro();
  void inicializar_tabuleiro(int tamanho);
};

#endif