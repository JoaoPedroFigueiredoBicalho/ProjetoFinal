#include "reversi.hpp"

void Reversi::inicializar_tabuleiro(int tamanho)
{
  /// Método override que inicializa o tabuleiro colocando quatro peças iniciais no centro.
  boardLogic::inicializar_tabuleiro(tamanho);
  set_tabuleiro(tamanho / 2, (tamanho / 2), 'X');
  set_tabuleiro((tamanho / 2) - 1, (tamanho / 2), 'O');
  set_tabuleiro((tamanho / 2) - 1, ((tamanho / 2) - 1), 'X');
  set_tabuleiro(tamanho / 2, ((tamanho / 2) - 1), 'O');
}

void Reversi::checar_jogada_multidirecional(int i, int linha, int coluna, char jogador)
{
  /// Checa se uma jogada irá virar casas em múltiplas direções, e ajusta o cálculo de número de peças conforme necessário.
  if (i == JogadasValidas.size() - 1)
  {
    if (jogador == 'X')
      num_pecas_X++;
    else
      num_pecas_O++;
  }
  else
    for (int j = i + 1; j < JogadasValidas.size(); j++)
    {
      if ((JogadasValidas[j][0] == linha) && (JogadasValidas[j][1] == coluna))
      {
        break;
      }
      if (j == JogadasValidas.size() - 1)
      {
        if (jogador == 'X')
          num_pecas_X++;
        else
          num_pecas_O++;
      }
    }
}

void Reversi::lerjogada(int linha, int coluna, char jogador)
{
  /// Recebe a jogada colocada pelo jogador, a compara com as jogadas válidas daquela posição e chama os métodos corretos dependendo da jogada ser ou não válida.
  int jogadaCerta = 0;
  for (int i = 0; i < JogadasValidas.size(); i++)
  {
    if ((JogadasValidas[i][0] == linha) && (JogadasValidas[i][1] == coluna))
    {
      checar_jogada_multidirecional(i, linha, coluna, jogador);
      virar_casas(JogadasValidas[i][0], JogadasValidas[i][1], JogadasValidas[i][2], JogadasValidas[i][3], JogadasValidas[i][4], jogador);
      jogadaCerta = 1;
    }
    if (i == JogadasValidas.size() - 1 && jogadaCerta == 0)
    {
      if (!JogadasValidas.empty())
      {
        throw std::invalid_argument("Jogador realizou uma jogada nao valida");
      }
    }
  }
}

bool Reversi::checar_jogada(char jogador, char oponente)
{
  /// Checa as jogadas válidas em uma determinada posição, além de que quais casas virariam.
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
              dir++;
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
  if (JogadasValidas.empty())
  {
    std::cout << "O jogador " << jogador << " nao possui jogadas validas!" << std::endl;
    termino++;
    game_over();
    return false;
  }
  else
    return true;
}

bool Reversi::checar_se_dentro_do_tabuleiro(int linha, int coluna)
{
  /// Checa se uma determinada posição está dentro do tabuleiro ou não.
  bool valido = true;
  if (((linha >= get_tabuleiro().size()) || (linha < 0)) || ((coluna >= get_tabuleiro().size()) || (coluna < 0)))
    valido = false;
  return valido;
}

void Reversi::checar_casas_a_virar(int linha, int coluna, int dir_l, int dir_c, char oponente)
{
  /// Checa a quantidade de casas que serão viradas dado uma jogada válida.
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
      termino = 0;
      break;
    }
    else
      break;
  }
}

void Reversi::checar_direcao(int linha, int coluna, int direcao, char oponente)
{
  /// Checa a direção que uma determinada jogada irá virar casas.
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
  /// Realiza a jogada válida, virando as casas em seu caminho.
  for (i; i > 0; i--)
  {
    set_tabuleiro(linha - (i * dir_l), coluna - (i * dir_c), jogador);
    if (jogador == 'X')
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
  /// Método que retorna uma booleana e confere se o jogo terminou.
  if (termino == 2 || num_pecas_X == 0 || num_pecas_O == 0)
  {
    if (num_pecas_X > num_pecas_O)
      return (false);
  }

  return (true);
}

int Reversi::get_termino()
{
  /// Retorna o número utilizado na análise do fim do jogo.
  return this->termino;
}

void Reversi::set_termino(int termino)
{
  this->termino = termino;
}

int Reversi::get_num_pecas_O()
{
  /// Retorna o número de peças do jogador 2.
  return num_pecas_O;
}

int Reversi::get_num_pecas_X()
/// Retorna o número de peças do jogador 1.
{
  return num_pecas_X;
}