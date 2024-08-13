#include <vector>
#include <iostream>

using namespace std;

class Jogos
{
private:
  int linha = 6;

  vector<vector<char>> tabuleiro{
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '},
      {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

public:
  void lerjogada(int jogadaLinha, int jogadaColuna, char jogada)
  {
    tabuleiro[jogadaLinha - 1][jogadaColuna - 1] = jogada;
  }

  void imprimir_tabuleiro()
  {
    for (int i = 0; i < tabuleiro.size(); i++)
    {
      cout << endl;
      for (int j = 0; j < tabuleiro[0].size(); j++)
      {
        cout << "|" << tabuleiro[i][j];
        if (j == tabuleiro[0].size() - 1)
          cout << "|";
      }
    }
  }
};

int main()
{
  int jogadaLinha, jogadaColuna;
  char jogada;
  Jogos lig4;

  cin >> jogadaLinha >> jogadaColuna >> jogada;
  lig4.lerjogada(jogadaLinha, jogadaColuna, jogada);

  lig4.imprimir_tabuleiro();
}