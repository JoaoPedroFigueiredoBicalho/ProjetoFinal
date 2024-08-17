#include "boardLogic.hpp"
#include <iostream>

void boardLogic::lerjogada(int jogadaLinha, int jogadaColuna, char jogada)
{
  /// Método virtual que é sobrecarregado pelas classes jogo, utilizado para ler as jogadas.
}

void boardLogic::set_tabuleiro(int linha, int coluna, char jogada)
{
  /// Coloca um caractere específico em uma casa selecionada no tabuleiro.
  tabuleiro[linha][coluna] = jogada;
}

std::vector<std::vector<char>> &boardLogic::get_tabuleiro()
{
  /// Retorna o tabuleiro.
  return tabuleiro;
};

void boardLogic::inicializar_tabuleiro(int tamanho)
{
  if (tamanho < 4 || tamanho > 10)
  {
    throw std::out_of_range("O tamanho do tabuleiro deve estar entre 4 e 10.");
  }
  this->tamanho = tamanho;
  /// Redimensiona o tabuleiro no tamanho escolhido e o inicializa com espaços vazios.
  tabuleiro.resize(tamanho, std::vector<char>(tamanho, ' '));
}

void boardLogic::imprimir_tabuleiro()
{
  /// Imprime o tabuleiro, com número de linhas e colunas colocados nas extremidades.
  std::cout << "##############" << std::endl
            << "  |";
  for (int contador = 0; contador < tabuleiro.size(); contador++)
  {
    std::cout << contador + 1 << "|";
  }
  for (int i = 0; i < tabuleiro.size(); i++)
  {
    std::cout << std::endl;
    if (i + 1 < 10)
      std::cout << " ";
    std::cout << i + 1;

    for (int j = 0; j < tabuleiro[i].size(); j++)
    {
      std::cout << "|" << tabuleiro[i][j];
      if (j == tabuleiro[i].size() - 1)
        std::cout << "|";
    }
  }
  std::cout << std::endl
            << "##############" << std::endl;
}

char boardLogic::get_jogada_atual() const
{
  /// Retorna a jogada atual.
  return jogada;
}

void boardLogic::alternar_jogador()
{ /// Altera os caracteres dos jogadores.
  jogada = (jogada == 'X') ? 'O' : 'X';
}

int boardLogic::get_tamanho()
{ /// Retorna o tamanho do tabuleiro.
  return tamanho;
}