#include "Players.hpp"

#include "lig4.hpp"
#include "boardLogic.hpp"
#include "reversi.hpp"

int main()
{
  Player *p = new Player();
  p->ReadArq();
  int fim = 1;
  cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
  cout << "Lista de comandos:" << endl;
  cout << "CJ: Criar Jogador" << endl
       << "RJ: Remover Jogador" << endl
       << "LJ: [A/N] Listar jogadores" << endl;
  cout << "EP: Executar Partida" << endl
       << "FS: Finalizar Sistema" << endl;
  cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;

  while (fim != 0)
  {
    int teste = 0;
    string comando;
    cout << "Digite um comando" << endl;
    cout << "(Para rever lista de comandos digite 0)" << endl;
    cout << "Comando: ";
    cin >> comando;
    if (comando == "CJ")
    {
      string nick;
      string nome;
      cout << "Digite o nick do jogador" << endl;
      while (teste == 0)
      {
        try
        {
          cout << "Nick: ";
          cin >> nick;
          if ((nick.find(" ") != string::npos))
          {
            throw bad_exception();
          }
          else
          {
            teste = 1;
          }
          if (p->CheckPlayer(nick) == true)
          {
            throw invalid_argument(" Erro : este nick ja esta em uso !");
          }
          else
          {
            teste = 1;
          }
        }
        catch (const bad_exception &e)
        {
          cout << "Seu nickname não pode conter espaços em branco" << endl;
          cout << "Digite outro nickname: ";
          cin >> nick;
        }
        catch (const invalid_argument &e)
        {
          cout << e.what() << endl;
          cout << "Digite outro nickname: " << endl;
          cin >> nick;
        }
      }

      // while (nick.find(" ")!=string::npos)
      // {
      //   cout << "NickName não pode conter espaços em branco" << endl;
      //   cin >> nick;
      // }
      // while (p->CheckPlayer(nick)==true)
      // {
      //   cout << "Erro: este nick já está em uso!" << endl;
      //   cout << "Digite outro nome de usuário" << endl;
      // }

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
      cout << "Digite os nicks dos jogadores que irao jogar" << endl;
      cout << "Jogador1: ";
      cin >> jogador;
      while (p->CheckPlayer(jogador) == false)
      {
        cout << "Erro: jogador não encontrado." << endl;
        cout << "Digite o Nick do jogador1 novamente" << endl;
        cout << "Jogador1: ";
        cin >> jogador;
      }
      cout << "Jogador2: ";
      cin >> jogador2;
      while (p->CheckPlayer(jogador2) == false)
      {
        cout << "Erro: jogador não encontrado." << endl;
        cout << "Digite o Nick do jogador2 novamente" << endl;
        cout << "Jogador2: ";
        cin >> jogador2;
      }
      switch (jogo)
      {
      case 'R':
      {
        Reversi *tabuleiro = new Reversi;
        cout << "Digite o tamanho do tabuleiro n x n, entre 4 e 10. O padrão para Reversi é um tabuleiro 8x8." << std::endl;
        int tamanho;
        cin >> tamanho;

        tabuleiro->inicializar_tabuleiro(tamanho);
        tabuleiro->imprimir_tabuleiro();
        char jogador_reversi = 'X';
        char oponente_reversi = 'O';
        char auxiliar = '\0';
        int contador;
        while (tabuleiro->game_over())
        {
          if (contador % 2 == 0)
          {
            cout << "Turno do " << jogador << endl;
          }
          else if (contador % 2 != 0)
          {
            cout << "Turno do " << jogador2 << endl;
          }
          tabuleiro->checar_jogada(jogador_reversi, oponente_reversi);
          int linha, coluna;
          std::cin >> linha;
          std::cin >> coluna;
          tabuleiro->lerjogada((linha - 1), (coluna - 1), jogador_reversi);
          auxiliar = jogador_reversi;
          jogador_reversi = oponente_reversi;
          oponente_reversi = auxiliar;
          tabuleiro->imprimir_tabuleiro();
        }

        if (tabuleiro->get_num_pecas_X() > tabuleiro->get_num_pecas_O())
        {
          p->RevWon(jogador);
          p->RevLost(jogador2);
        }
        else if (tabuleiro->get_num_pecas_X() < tabuleiro->get_num_pecas_O())
        {
          p->RevWon(jogador2);
          p->RevLost(jogador);
        }
        else
        {
          p->RevDraw(jogador, jogador2);
        }
        std::cout << std::endl
                  << "Numero de pecas do Jogador 1: " << tabuleiro->get_num_pecas_X() << std::endl;
        std::cout << std::endl
                  << "Numero de pecas do Jogador 2: " << tabuleiro->get_num_pecas_O() << std::endl;

        delete tabuleiro;
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
        int Endgame = 0;
        while (Endgame == 0)
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

          // chamar o ler jogada e ver se a jogada foi bem sucedida
          if (tabuleiro->lerjogada((coluna - 1)))
          {
            tabuleiro->imprimir_tabuleiro();

            // verifica se o jogador venceu
            if (tabuleiro->checarvitoria('X'))
            {
              p->LigWon(jogador);
              p->LigLost(jogador2);
              Endgame = 1;
            }
            if (tabuleiro->checarvitoria('O'))
            {
              p->LigWon(jogador2);
              p->LigLost(jogador);
              Endgame = 1;
            }
            if (tabuleiro->tabuleiro_cheio())
            {
              Endgame = 1;
            }
            contador++;
          }
        }
        delete tabuleiro;
      }
      }
    }
    else if (comando == "LJ")
    {
      p->ListPlayersbyNick();
    }
    else if (comando == "FS")
    {
      fim = 0;
      p->Victory();
      p->WriteArq();
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
