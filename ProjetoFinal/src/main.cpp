#include "Players.hpp"
#include "reversi.hpp"
#include "lig4.hpp"
#include "boardLogic.hpp"

int main()
{
  Player *p = new Player();
  int fim = 1;

  while (fim != 0)
  {
    string comando;
    cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    cout << "Lista de comandos:" << endl;
    cout << "CJ: Criar Jogador" << endl
         << "RJ: Remover Jogador" << endl
         << "LJ: [A/N] Listar jogadores" << endl;
    cout << "EP: Executar Partida" << endl
         << "FS: Finalizar Sistema" << endl;
    cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    cout << "Digite um comando: " << endl;
    cin >> comando;
    if (comando == "CJ")
    {
      string nick;
      string nome;
      cout << "Digite o nick do jogador" << endl;
      cin >> nick;
      cout << "Digite o nome do jogador" << endl;
      cin >> nome;
      p->RegisterPlayer(nick, nome);
    }
    else if (comando == "RJ")
    {
      string nick;
      cout << "Digite o nick do jogador" << endl;
      cin >> nick;
      p->DeletePlayer(nick);
    }
    else if (comando == "EP")
    {
      string jogador;
      string jogador2;
      char jogo;
      cout << "Digite R para jogar Reversi ou L para jogar Lig4" << endl;
      cin >> jogo;
      cout << "Digite os nicks dos jogadores que irão jogar" << endl;
      cin >> jogador;
      cin >> jogador2;
      switch (jogo)
      {
      case 'R':
      {
        Reversi *tabuleiro = new Reversi;
        cout << "Digite o tamanho do tabuleiro n x n" << endl;
        int tamanho;
        cin >> tamanho;
        Reversi *tabuleiro = new Reversi;
        tabuleiro->inicializar_tabuleiro(tamanho);
        tabuleiro->imprimir_tabuleiro();
        char jogador1 = 'X';
        char jogador2 = 'O';
        char auxiliar;
        while (tabuleiro->get_termino() < 2)
        {
          tabuleiro->checar_jogada(jogador1, jogador2);
          int linha, coluna;
          std::cin >> linha;
          std::cin >> coluna;
          tabuleiro->lerjogada(linha, coluna, jogador1);
          auxiliar = jogador1;
          jogador1 = jogador2;
          jogador2 = auxiliar;
          tabuleiro->imprimir_tabuleiro();
        }
      }
      case 'L':
      {
        // obs: se der problema use Lig4 tabuleiro;
        Lig4 *tabuleiro = new Lig4;
        cout << "Digite o tamanho do tabuleiro n x n" << endl;
        int tamanho;
        cin >> tamanho;

        tabuleiro->inicializar_tabuleiro(tamanho);
        tabuleiro->imprimir_tabuleiro();
        int contador = 0;
        while (!tabuleiro->tabuleiro_cheio())
        {
          if (contador % 2 == 0)
          {
            cout << "Turno do " << jogador << endl;
          }
          else if (contador % 2 != 0)
          {
            cout << "Turno do " << jogador2 << endl;
          }
          int coluna;
          cout << "Digite a coluna de entrada (1-" << tamanho << "): ";
          cin >> coluna;

          //chamar o ler jogada e ver se a jogada foi bem sucedida
          if(tabuleiro->lerjogada((coluna-1))) {
            tabuleiro->imprimir_tabuleiro();
          

<<<<<<< HEAD
          // verifica se o jogador venceu
          if (tabuleiro->checarvitoria('X'))
          {
=======
          //verifica se o jogador venceu
          if(tabuleiro->checarvitoria('X')){
>>>>>>> 2652b48ce91849ddda2292ffb629bbf5c418ea27
            p->LigWon(jogador);
            p->LigLost(jogador2);
            break;
          }
<<<<<<< HEAD
          if (tabuleiro->checarvitoria('O'))
          {
=======
          if(tabuleiro->checarvitoria('O')){
>>>>>>> 2652b48ce91849ddda2292ffb629bbf5c418ea27
            p->LigWon(jogador2);
            p->LigLost(jogador);
            break;
          }
          contador++;
          }
        }
      }
      }
      break;
    }
    else if (comando == "LJ")
    {
      p->ListPlayersbyNick();
    }
    else if (comando == "FS")
    {
      fim = 0;
      p->Victory();
      break;
    }
    else
    {
      cout << "Comando inválido :(" << endl;
      cout << "Digite um novo comando";
    }
  }
  delete p;
  return 0;
}