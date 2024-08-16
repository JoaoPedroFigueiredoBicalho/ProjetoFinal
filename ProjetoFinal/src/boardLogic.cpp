#include "boardLogic.hpp"
#include <iostream>

void boardLogic::lerjogada(int jogadaLinha, int jogadaColuna, char jogada) {}

void boardLogic::set_tabuleiro(int linha, int coluna, char jogada)
{
  tabuleiro[linha][coluna] = jogada;
}

// mudança
std::vector<std::vector<char>> &boardLogic::get_tabuleiro()
{
  return tabuleiro;
};

void boardLogic::inicializar_tabuleiro(int tamanho)
{
  this->tamanho = tamanho;
  // Redimensiona o vetor 'tabuleiro' para 'tamanho x tamanho' e inicializa com
  // espaços vazios
  tabuleiro.resize(tamanho, std::vector<char>(tamanho, ' '));
}

void boardLogic::imprimir_tabuleiro()
{
  std::cout << "##############" << std::endl;
  std::cout << " |1|2|3|4|5|6|";
  for (int i = 0; i < tabuleiro.size(); i++)
  {
    std::cout << std::endl
              << i + 1;
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

char boardLogic::get_jogada_atual() const { return jogada; }

void boardLogic::alternar_jogador() { jogada = (jogada == 'X') ? 'O' : 'X'; }

// pro reversi
int boardLogic::get_tamanho() { return tamanho; }