#ifndef REVERSI_H
#define REVERSI_H
#include "boardLogic.hpp"
class Reversi : public boardLogic
{
private:
  const char Jogador1 = 'X';
  const char Jogador2 = 'O';
  std::vector<std::vector<int>> JogadasValidas;
  int num_pecas_J1=0;
  int num_pecas_J2=0;
  int termino=0;

public:
  void inicializar_tabuleiro(int tamanho);
  void checar_jogadas_validas();
  void lerjogada(int linha, int coluna, char jogador);
  void checar_jogada(char jogador, char oponente);
  void checar_direcao(int linha, int coluna, int direcao, char oponente);
  bool checar_se_dentro_do_tabuleiro(int linha, int coluna);
  void checar_casas_a_virar(int linha, int coluna, int dir_l, int dir_c, char oponente);
  void virar_casas(int linha, int coluna, int dir_l, int dir_c, int i, char jogador);
  bool game_over();
  int get_termino();
};
#endif