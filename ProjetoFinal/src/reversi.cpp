#include "reversi.hpp"

void Reversi::checar_jogadas_validas()
{
}

void Reversi::checar_jogada(int linha, int coluna)
{
  int dir = 1;
  if (get_tabuleiro()[linha][coluna] == ' ')
  {
    for (linha = (linha - 1); linha <= (linha + 1); linha++)
    {
      for (coluna = (coluna - 1); coluna <= (coluna + 1); coluna++)
      {
        if (!(checar_se_dentro_do_tabuleiro(linha, coluna)))
        {
          continue;
        }
        else if ((get_tabuleiro()[linha][coluna] == Jogador2))
        {
          checar_casas_a_virar(linha, coluna, dir);
        }
        dir++;
      }
    }
  }
}

bool Reversi::checar_se_dentro_do_tabuleiro(int linha, int coluna)
{
  bool valido = true;
  if (((linha >= get_tabuleiro().size()) || (linha < 0)) || ((coluna >= get_tabuleiro().size()) || (coluna < 0)))
    valido = false;
  return valido;
}

void Reversi::virar_casas(int linha, int coluna, int dir_l, int dir_c)
{
  for (int i = 1; checar_se_dentro_do_tabuleiro(linha + (i * dir_l), coluna + (i * dir_c)); i++)
  {
    if (get_tabuleiro()[linha + (i * dir_l)][coluna + (i * dir_c)] == Jogador2)
    {
      continue;
    }
    else if (get_tabuleiro()[linha + (i * dir_l)][coluna + (i * dir_c)] == Jogador1)
    {
      for (i - 1; i >= 0; i--)
      {
        set_tabuleiro(linha + (i * dir_l), coluna + (i * dir_c), Jogador1);
      }
    }
    else
      break;
  }
}

void Reversi::checar_casas_a_virar(int linha, int coluna, int direcao)
{
  switch (direcao)
  {
  case 1:
  {
    virar_casas(linha, coluna, -1, -1);
    break;
  }
  case 2:
  {
    virar_casas(linha, coluna, -1, 0);
    break;
  }
  case 3:
  {
    virar_casas(linha, coluna, -1, 1);
    break;
  }
  case 4:
  {
    virar_casas(linha, coluna, 0, -1);
    break;
  }
  case 6:
  {
    virar_casas(linha, coluna, 0, 1);
    break;
  }
  case 7:
  {
    virar_casas(linha, coluna, -1, 1);
    break;
  }
  case 8:
  {
    virar_casas(linha, coluna, 1, 0);
    break;
  }
  case 9:
  {
    virar_casas(linha, coluna, 1, 1);
    break;
  }
  }
}