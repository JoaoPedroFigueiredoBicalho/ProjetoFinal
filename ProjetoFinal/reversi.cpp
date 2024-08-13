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
        if (((linha >= get_tabuleiro().size()) || (linha < 0)) || ((coluna >= get_tabuleiro().size()) || (coluna < 0)))
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

void Reversi::checar_casas_viradas(int direcao)
{
  switch (direcao)
  case '1':
  {
  }
}