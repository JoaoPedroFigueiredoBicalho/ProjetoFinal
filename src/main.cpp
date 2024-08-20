#include "Players.hpp"
#include "lig4.hpp"
#include "boardLogic.hpp"
#include "reversi.hpp"
#include "jogoVelha.hpp"

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
      int erro = 0;
      cout << "Digite o nick do jogador" << endl;
      while (teste == 0)
      {
        try
        {
          cout << "Nick: ";
          if (erro == 0)
            cin.ignore();
          getline(cin, nick);
          if (nick.empty())
          {
            erro++;
            throw invalid_argument("Nick nao pode estar em branco!");
          }
          if ((nick.find(" ") != string::npos))
          {
            erro++;
            throw bad_exception();
          }
          if (p->CheckPlayer(nick) == true)
          {
            erro++;
            throw invalid_argument(" Erro : este nick ja esta em uso !");
          }
          teste = 1;
        }
        catch (const bad_exception &e)
        {
          cout << "Seu nickname não pode conter espaços em branco" << endl;
        }
        catch (const invalid_argument &e)
        {
          cout << e.what() << endl;
        }
      }
      erro = 0;
      teste = 0;
      cout << "Digite o nome do jogador" << endl;
      while (teste == 0)
      {
        try
        {
          cout << "Nome: ";

          getline(cin, nome);
          if (nome.empty())
          {
            erro++;
            throw invalid_argument("Nome nao pode estar em branco!");
          }
          for (int i = 0; i < nome.size(); i++)
          {
            if (isdigit(nome[i]))
              throw bad_exception();
            erro++;
          }
          teste = 1;
        }
        catch (const bad_exception &e)
        {
          cout << "Seu nome não pode conter números" << endl;
        }
        catch (const invalid_argument &e)
        {
          cout << e.what() << endl;
        }
      }
      p->RegisterPlayer(nick, nome);
      erro = 0;
    }
    else if (comando == "RJ")
    {
      if (p->GetPlayersCount() == 0)
      {
        cout << "Nenhum jogador cadastrado!" << endl;
      }

      string nick;
      cout << "Digite o nick do jogador que voce quer remover" << endl;
      while (teste == 0)
      {
        try
        {
          cin >> nick;
          if (p->CheckPlayer(nick) == false)
          {
            throw invalid_argument(" Erro : Nickname nao encontrado !");
          }
          teste = 1;
        }
        catch (const invalid_argument &e)
        {
          cout << e.what() << endl;
        }
      }
      p->DeletePlayer(nick);
    }
    else if (comando == "EP")
    {
      if (p->GetPlayersCount() < 2)
      {
        cout << "E necessario cadastrar mais " << (2 - p->GetPlayersCount()) << "jogador(es) para executar essa função!" << endl;
      }
      else
      {
        string jogador;
        string jogador2;
        char jogo;
        cout << "Digite R para jogar Reversi, L para jogar Lig4 ou V para jogar o Jogo da Velha" << endl;
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
          int tamanho;
          bool tamanhoValido = false;

          while (!tamanhoValido)
          {
            try
            {
              cout << "Digite o tamanho do tabuleiro n x n, entre 4 e 10. O padrao para Reversi e um tabuleiro 8x8." << endl;
              cin >> tamanho;
              tabuleiro->inicializar_tabuleiro(tamanho);
              tamanhoValido = true;
            }
            catch (const out_of_range &e)
            {
              cout << "Erro: " << e.what() << endl;
            }
          }

          tabuleiro->imprimir_tabuleiro();
          char jogador_reversi = 'X';
          char oponente_reversi = 'O';
          char auxiliar = '\0';
          int contador = 0;
          while (tabuleiro->game_over())
          {
            try
            {
              if (contador % 2 == 0)
              {
                cout << "Turno de " << jogador << endl;
              }
              else
              {
                cout << "Turno de " << jogador2 << endl;
              }
              int linha, coluna;
              if (tabuleiro->checar_jogada(jogador_reversi, oponente_reversi, jogador))
              {

                try
                {
                  while (true)
                  {
                    cout << "Digite a linha e coluna de sua jogada: ";
                    cin >> linha;
                    cin >> coluna;
                    cin.ignore(1000, '\n');
                    if (cin.fail() || linha > tamanho || coluna > tamanho)
                    {
                      cin.clear();
                      cin.ignore(1000, '\n');
                      throw out_of_range("Erro: Jogada invalida.");
                    }
                    else
                      break;
                  }

                  tabuleiro->lerjogada((linha - 1), (coluna - 1), jogador_reversi);
                }
                catch (const out_of_range &e)
                {
                  cout << e.what() << endl;
                  cout << "Digite outra jogada" << endl;
                  continue;
                }
              }
            }
            catch (const invalid_argument &e)
            {
              cout << e.what() << endl;
              cout << "Digite outra jogada" << endl;
              continue;
            }
            auxiliar = jogador_reversi;
            jogador_reversi = oponente_reversi;
            oponente_reversi = auxiliar;
            if (tabuleiro->get_termino() == 0)
              tabuleiro->imprimir_tabuleiro();
            contador++;
          }

        endgame:
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
          cout << "Fim de jogo!" << endl;
          cout << endl
               << "Numero de pecas de " << jogador << ": " << tabuleiro->get_num_pecas_X() << endl;
          cout << endl
               << "Numero de pecas de " << jogador2 << ": " << tabuleiro->get_num_pecas_O() << endl;

          delete tabuleiro;
          break;

        } // fim do case R

        case 'L':
        {
          Lig4 *tabuleiro = new Lig4;
          int tamanho;
          bool tamanhoValido = false;

          while (!tamanhoValido)
          {
            try
            {
              cout << "Digite o tamanho do tabuleiro n x n (entre 4 e 10): " << endl;
              cin >> tamanho;
              tabuleiro->inicializar_tabuleiro(tamanho);
              tamanhoValido = true;
            }
            catch (const out_of_range &e)
            {
              cout << "Erro: " << e.what() << endl;
            }
          }

          tabuleiro->imprimir_tabuleiro();
          int contador = 0;
          int Endgame = 0;
          while (Endgame == 0)
          {
            if (contador % 2 == 0)
            {
              cout << "Turno do " << jogador << endl;
            }
            else
            {
              cout << "Turno do " << jogador2 << endl;
            }
            int coluna;
            cout << "Digite a coluna de entrada (1-" << tamanho << "): ";
            cin >> coluna;

            if (tabuleiro->lerjogada((coluna - 1)))
            {
              tabuleiro->imprimir_tabuleiro();

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
          break;

        } // fim do case L

        case 'V':
        {
          jogoVelha *tabuleiro = new jogoVelha;
          tabuleiro->inicializar_tabuleiro();
          tabuleiro->imprimir_tabuleiro();
          int contador = 0;
          int Endgame = 0;
          while (Endgame == 0)
          {
            if (contador % 2 == 0)
            {
              cout << "Turno do " << jogador << endl;
            }
            else
            {
              cout << "Turno do " << jogador2 << endl;
            }
            int linha;
            cout << "Digite a linha de entrada (1-3): " << endl;
            cin >> linha;
            linha--;
            int coluna;
            cout << "Digite a coluna de entrada (1-3): " << endl;
            cin >> coluna;
            coluna--;
            if (tabuleiro->lerjogada(linha, coluna))
            {
              tabuleiro->imprimir_tabuleiro();
              if (tabuleiro->checarvitoria('X'))
              {
                p->VWon(jogador);
                p->VLost(jogador2);
                Endgame = 1;
              }
              if (tabuleiro->checarvitoria('O'))
              {
                p->VWon(jogador2);
                p->VLost(jogador);
                Endgame = 1;
              }
              if (tabuleiro->tabuleiro_cheio())
              {
                p->VDraw(jogador, jogador2);
                Endgame = 1;
              }
              contador++;
            }
          }
          delete tabuleiro;
          break;
        }

        } // fim do case V
      } // fim do switch
    }
    else if (comando == "LJ")
    {
      cout << "Deseja listar pelo Nick [digite A] ou Nome [diite N]?" << endl;
      char parameter;
      cin >> parameter;
      if (parameter == 'A')
        p->ListPlayersbyNick();
      if (parameter == 'N')
        p->ListPlayersbyName();
    }
    else if (comando == "FS")
    {
      fim = 0;
      p->Victory(1, 0, 0);
      p->Victory(0, 1, 0);
      p->Victory(0, 0, 1);
      p->Victory(1, 1, 1);
      p->WriteArq();
      break;
    }
    else if (comando == "0")
    {
      cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
      cout << "Lista de comandos:" << endl;
      cout << "CJ: Criar Jogador" << endl
           << "RJ: Remover Jogador" << endl
           << "LJ: [A/N] Listar jogadores" << endl;
      cout << "EP: Executar Partida" << endl
           << "FS: Finalizar Sistema" << endl;
      cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    }
    else
    {
      cout << "Comando invalido :(" << endl;
    }
  }
  delete p;
  return 0;
}
