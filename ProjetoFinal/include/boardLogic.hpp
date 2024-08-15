#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include <vector>
#include <iostream>

class boardLogic
{
private:
  std::vector<std::vector<char>> tabuleiro;
  int tamanho;

protected:
   char jogada = 'X';

public:
  virtual void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);
  void imprimir_tabuleiro();
  void inicializar_tabuleiro();
  std::vector<std::vector<char>> get_tabuleiro();
  void set_tabuleiro(int linha, int coluna, char jogada);
  int get_tamanho() ;
  void set_tamanho(int tamanho);

};

#endif