#include "reversi.hpp"

void Reversi::lerjogada(int jogadaLinha, int jogadaColuna, char jogada)
{
}

void Reversi::checar_jogada_valida(int linha, int coluna)
{
  if (get_tabuleiro()[linha][coluna] == Jogador1)
  {
    for (linha = (linha - 1); linha <= (linha + 1); linha++)
    {
      for (coluna = (coluna - 1); coluna <= (coluna + 1); coluna++)
      {
        if (checar_se_dentro_do_tabuleiro(linha, coluna))
        {
          continue;
        }
        else if ((get_tabuleiro()[linha][coluna] == Jogador2))
        {
        }
      }
    }
  }
}

bool Reversi::checar_se_dentro_do_tabuleiro(int linha, int coluna)
{
  bool valido = true;
  if (((linha >= get_tabuleiro().size()) || (linha < 0)) || ((coluna >= get_tabuleiro().size()) || (coluna < 0)))
    valido = false;
}

void Reversi::checar_casas_viradas(int linha, int coluna, int direcao)
{
  switch (direcao)
  case '1':
  {
    for (int i = 1; checar_se_dentro_do_tabuleiro(linha - i, coluna - i); i++)
      if (get_tabuleiro()[linha - i][coluna - i] == Jogador2)
      {
            }
  }
}