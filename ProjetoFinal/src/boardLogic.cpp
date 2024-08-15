#include "boardLogic.hpp"

void boardLogic::lerjogada(int jogadaLinha, int jogadaColuna, char jogada)
{
}

void boardLogic::set_tabuleiro(int linha, int coluna, char jogada)
{
  tabuleiro[linha][coluna] = jogada;
}

void boardLogic::inicializar_tabuleiro(int tamanho)
{
  this->tamanho = tamanho;
  tabuleiro.resize(tamanho, std::vector<char>(tamanho, ' '));
}

void boardLogic::imprimir_tabuleiro()
{
  std::cout << "#########" << std::endl;
  for (int i = 0; i < tabuleiro.size(); i++)
  {
    std::cout << std::endl;
    for (int j = 0; j < tabuleiro[0].size(); j++)
    {
      std::cout << "|" << tabuleiro[i][j];
      if (j == tabuleiro[0].size() - 1)
        std::cout << "|";
    }
  }
  std::cout << std::endl
            << "#########" << std::endl;
}

int boardLogic::get_tamanho()
{
  return tamanho;
}
void boardLogic::set_tamanho(int tamanho)
{
  this->tamanho = tamanho;
}

std::vector<std::vector<char>> &boardLogic::get_tabuleiro()
{
  return tabuleiro;
};