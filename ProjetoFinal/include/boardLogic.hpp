#ifndef BOARDLOGIC_HPP
#define BOARDLOGIC_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class boardLogic
{
protected:
  std::vector<std::vector<char>> tabuleiro;
  int tamanho;
  char jogada = 'X';

public:
  // metodo virtual
  virtual void lerjogada(int jogadaLinha, int jogadaColuna, char jogada);

  std::vector<std::vector<char>> &get_tabuleiro();

  void set_tabuleiro(int linha, int coluna, char jogada);

  // tamanho por parametro
  virtual void inicializar_tabuleiro(int tamanho);

  // Imprime o tabuleiro no console
  void imprimir_tabuleiro();

  // Obtém o jogador que está realizando a jogada atual
  char get_jogada_atual() const;

  // Alterna entre os jogadores 'X' e 'O'
  void alternar_jogador();

  // pro reversi
  int get_tamanho();
};

#endif // BOARDLOGIC_HPP
