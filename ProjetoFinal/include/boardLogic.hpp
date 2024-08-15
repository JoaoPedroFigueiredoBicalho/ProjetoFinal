#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include <vector>
#include <iostream>

class boardLogic
{
private:
  int tamanho;
  std::vector<std::vector<char>> tabuleiro;

protected:
  char jogada = 'X';

public:
  virtual void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);
  void imprimir_tabuleiro();
  virtual void inicializar_tabuleiro(int tamanho);
  std::vector<std::vector<char>> &get_tabuleiro();
  void set_tabuleiro(int linha, int coluna, char jogada);
  int get_tamanho();
  void set_tamanho(int tamanho);
};

#endif