#include "reversi.hpp"

void Reversi::lerjogada(int linha, int coluna)
{
  checar_jogada();
  for (int i = 0; i < JogadasValidas.size(); i++)
  {
    if ((JogadasValidas[i][0] == linha) && (JogadasValidas[i][1] == coluna))
     {
         virar_casas(JogadasValidas[i][0], JogadasValidas[i][1], JogadasValidas[i][2], JogadasValidas[i][3], JogadasValidas[i][4]);
     }
  }
}

void Reversi::checar_jogada()
{
  int linha, coluna;
  int dir = 1;
  for (int i = 0; i < get_tamanho(); i++)
  {
    for (int j = 0; j < get_tamanho(); j++)
    {
      if (get_tabuleiro()[i][j] == Jogador1)
      {
        linha = i;
        coluna = j;
        dir=1;
        for (int i = (linha + 1); i >= (linha - 1); i--)
        {
            for (int j = (coluna - 1); j <= (coluna + 1); j++)
            {
                if (!(checar_se_dentro_do_tabuleiro(i, j)))
                {
                    continue;
                }
                else if ((get_tabuleiro()[i][j] == Jogador2))
                {
                    checar_direcao(i, j, dir);
                }
                    dir++;
            }
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
  return valido;
}

void Reversi::checar_casas_a_virar(int linha, int coluna, int dir_l, int dir_c)
{
  for (int i = 1; checar_se_dentro_do_tabuleiro(linha + (i * dir_l), coluna + (i * dir_c)); i++)
  {
    if (get_tabuleiro()[linha + (i * dir_l)][coluna + (i * dir_c)] == Jogador2)
    {
      continue;
    }
    else if (get_tabuleiro()[linha + (i * dir_l)][coluna + (i * dir_c)] == ' ')
    {
      std::vector<int> p1;
      p1.push_back(linha + (i * dir_l));
      p1.push_back(coluna + (i * dir_c));
      p1.push_back(dir_l);
      p1.push_back(dir_c);
      p1.push_back(i);
      JogadasValidas.push_back(p1);
      break;
    }
    else
      break;
  }
}

void Reversi::checar_direcao(int linha, int coluna, int direcao)
{
  switch (direcao)
  {
  case 1:
  {
    checar_casas_a_virar(linha, coluna, 1, -1);
    break;
  }
  case 2:
  {
    checar_casas_a_virar(linha, coluna, 1, 0);
    break;
  }
  case 3:
  {
    checar_casas_a_virar(linha, coluna, 1, 1);
    break;
  }
  case 4:
  {
    checar_casas_a_virar(linha, coluna, 0, -1);
    break;
  }
  case 6:
  {
    checar_casas_a_virar(linha, coluna, 0, 1);
    break;
  }
  case 7:
  {
    checar_casas_a_virar(linha, coluna, -1, 1);
    break;
  }
  case 8:
  {
    checar_casas_a_virar(linha, coluna, -1, 0);
    break;
  }
  case 9:
  {
    checar_casas_a_virar(linha, coluna, -1, 1);
    break;
  }
  }
}

void Reversi::virar_casas(int linha, int coluna, int dir_l, int dir_c, int i)
{
  for (i; i > 0; i--)
  {
    set_tabuleiro(linha - (i * dir_l), coluna - (i * dir_c), Jogador1);
  }
  set_tabuleiro(linha,coluna,Jogador1);
}