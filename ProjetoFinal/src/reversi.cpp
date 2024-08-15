#include "reversi.hpp"

void Reversi::inicializar_tabuleiro(int tamanho)
{
    boardLogic::inicializar_tabuleiro(tamanho);
    set_tabuleiro(tamanho/2,(tamanho/2),'X');
    set_tabuleiro((tamanho/2)-1,(tamanho/2),'O');
    set_tabuleiro((tamanho/2)-1,((tamanho/2)-1),'X');
    set_tabuleiro(tamanho/2,((tamanho/2)-1),'O');
}

void Reversi::lerjogada(int linha, int coluna, char jogador)
{
  for (int i = 0; i < JogadasValidas.size(); i++)
  {
    if ((JogadasValidas[i][0] == linha) && (JogadasValidas[i][1] == coluna))
    {
      virar_casas(JogadasValidas[i][0], JogadasValidas[i][1], JogadasValidas[i][2], JogadasValidas[i][3], JogadasValidas[i][4], jogador);
    }
  }
}

void Reversi::checar_jogada(char jogador, char oponente)
{
  int linha, coluna;
  int dir = 1;
  JogadasValidas.clear();
  JogadasValidas.resize(0);
  for (int cont_l = 0; cont_l < get_tamanho(); cont_l++)
  {
    for (int cont_c = 0; cont_c < get_tamanho(); cont_c++)
    {
      if (get_tabuleiro()[cont_l][cont_c] == jogador)
      {
        linha = cont_l;
        coluna = cont_c;
        dir = 1;
        for (int i = (linha + 1); i >= (linha - 1); i--)
        {
          for (int j = (coluna - 1); j <= (coluna + 1); j++)
          {
            if (!(checar_se_dentro_do_tabuleiro(i, j)))
            {
              continue;
            }
            else if ((get_tabuleiro()[i][j] == oponente))
            {
              checar_direcao(i, j, dir, oponente);
            }
            dir++;
          }
        }
      }
    }
  }
  if(JogadasValidas.empty()) game_over();
}

bool Reversi::checar_se_dentro_do_tabuleiro(int linha, int coluna)
{
  bool valido = true;
  if (((linha >= get_tabuleiro().size()) || (linha < 0)) || ((coluna >= get_tabuleiro().size()) || (coluna < 0)))
    valido = false;
  return valido;
}

void Reversi::checar_casas_a_virar(int linha, int coluna, int dir_l, int dir_c, char oponente)
{
  for (int i = 1; checar_se_dentro_do_tabuleiro(linha + (i * dir_l), coluna + (i * dir_c)); i++)
  {
    if (get_tabuleiro()[linha + (i * dir_l)][coluna + (i * dir_c)] == oponente)
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
      termino=0;
      break;
    }
    else
      break;
  }
}

void Reversi::checar_direcao(int linha, int coluna, int direcao, char oponente)
{
  switch (direcao)
  {
  case 1:
  {
    checar_casas_a_virar(linha, coluna, 1, -1, oponente);
    break;
  }
  case 2:
  {
    checar_casas_a_virar(linha, coluna, 1, 0, oponente);
    break;
  }
  case 3:
  {
    checar_casas_a_virar(linha, coluna, 1, 1, oponente);
    break;
  }
  case 4:
  {
    checar_casas_a_virar(linha, coluna, 0, -1, oponente);
    break;
  }
  case 6:
  {
    checar_casas_a_virar(linha, coluna, 0, 1, oponente);
    break;
  }
  case 7:
  {
    checar_casas_a_virar(linha, coluna, -1, -1, oponente);
    break;
  }
  case 8:
  {
    checar_casas_a_virar(linha, coluna, -1, 0, oponente);
    break;
  }
  case 9:
  {
    checar_casas_a_virar(linha, coluna, -1, 1, oponente);
    break;
  }
  }
}

void Reversi::virar_casas(int linha, int coluna, int dir_l, int dir_c, int i, char jogador)
{
  for (i; i > 0; i--)
  {
    set_tabuleiro(linha - (i * dir_l), coluna - (i * dir_c), jogador);
    if (jogador=='X') 
    {
        num_pecas_O--;
        num_pecas_X++;
    }
    else 
    {
        num_pecas_X--;
        num_pecas_O++;
    }
  }
  set_tabuleiro(linha, coluna, jogador);
}

bool Reversi::game_over()
{
  termino++;
  if (termino==2||num_pecas_X==0||num_pecas_O==0)
  {
    if (num_pecas_X>num_pecas_O) std::cout<< "Jogador 1 venceu!"; 
    else if (num_pecas_X<num_pecas_O) std::cout<< "Jogador 2 venceu!";
    else std::cout<< "Empate";
    return (false);
  }
  
  return (true);
}

int Reversi::get_termino()
{
    return this->termino;
}