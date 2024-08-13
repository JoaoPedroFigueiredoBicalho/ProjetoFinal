#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include <vector>
#include <iostream>

class boardLogic
{
protected:
  std::vector<std::vector<char>> tabuleiro;
  int tamanho;
  char jogada = 'X';

public:
  virtual void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);
  void imprimir_tabuleiro();
  void inicializar_tabuleiro(int tamanho);
  std::vector<std::vector<char>> get_tabuleiro();
};

#endif