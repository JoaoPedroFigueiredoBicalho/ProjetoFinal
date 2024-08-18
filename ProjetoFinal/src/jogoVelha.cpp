#include "jogoVelha.hpp"
#include <iostream>

void jogoVelha::inicializar_tabuleiro(int tamanho)
{
  /// Inicializa o tabuleiro por um método override e inicializa com espaços vazios.
  this->tamanho = tamanho;

  tabuleiro.resize(tamanho, std::vector<char>(tamanho, ' '));
}

bool jogoVelha::lerjogada(int jogadaLinha, int jogadaColuna)
{  
  /// Método que lê a jogada do usuário (linha e coluna) e substitui o espaço vazio pela jogada do jogador, caso a entrada seja válida.
  if (jogadaColuna < 0 || jogadaColuna >= tamanho || jogadaLinha < 0 || jogadaLinha >= tamanho)
  {  
    /// Verifica se a jogada está dentro dos limites do tabuleiro.
    std::cout << "Jogada inválida!" << std::endl;
    return false;
  }

  // Variável booleana que será utilizada para checagem da entrada (disponível ou indisponível).
  bool entrada_cheia = true;
  if (tabuleiro[jogadaLinha][jogadaColuna] == ' ')
  {
    /// Realiza a jogada, caso a entrada solicitada esteja vazia.
    tabuleiro[jogadaLinha][jogadaColuna] = get_jogada_atual();
    entrada_cheia = false;
  }

  if (entrada_cheia)
  {
    std::cout << "Entrada cheia!" << std::endl;
    return false;
  }

  /// Alterna o jogador para a próxima rodada.
  alternar_jogador();
  return true;
}

bool jogoVelha::tabuleiro_cheio() const
{
  /// Método para verificar se o tabuleiro está cheio.
  for (const auto &linha : tabuleiro)
  {
    for (char celula : linha)
    {
      if (celula == ' ')
        return false;
    }
  }
  return true;
}

bool jogoVelha::checarvitoria(char jogador) const
{
  /// Método para checar se o jogador realizou uma sequência de 3 (horizontal, vertical ou diagonal).
  int linhas = 3;
  int colunas = 3;

  /// Verificação horizontal.
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 1; j++)
    {
      if (tabuleiro[i][j] == jogador && tabuleiro[i][j + 1] == jogador && tabuleiro[i][j + 2] == jogador)
      {
        return true;
      }
    }
  }

  /// Verificação vertical.
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 1; j++)
    {
      if (tabuleiro[j][i] == jogador && tabuleiro[j + 1][i] == jogador && tabuleiro[j + 2][i] == jogador)
      {
        return true;
      }
    }
  }

  /// Verificação da diagonal principal.
  if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
  {
    return true;
  }

  /// Verificação da diagonal secundária.
  if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
  {
    return true;
  }
  return false;
}
