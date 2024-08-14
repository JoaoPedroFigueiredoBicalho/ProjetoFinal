#include "Players.hpp"
#include "reversi.hpp"
#include "lig4.hpp"

int main(){
    Player* p=new Player();
    int fim=1;
    cout<<"¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨"<<endl;
    cout<<"Lista de comandos:"<<endl;
    cout<<"CJ: Criar Jogador"<<endl<<"RJ: Remover Jogador"<<endl<<"LJ: [A/N] Listar jogadores"<<endl;
    cout<<"EP: Executar Partida"<<endl<<"FS: Finalizar Sistema"<<endl;
    cout<<"¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨"<<endl;
    cout<<"Digite um comando: "<<endl;
    
    while(fim){
        string comando;
        cin>>comando;
    if (comando=="CJ")
        {
            string nick;
            string nome;
            cout<<"Digite o nick do jogador"<<endl;
            cin>>nick;
            cout<<"Digite o nome do jogador"<<endl;
            cin>>nome;
            p->RegisterPlayer(nick,nome);
            break;
        }
    else if(comando=="RJ")
        {
            string nick;
            cout<<"Digite o nick do jogador"<<endl;
            cin>>nick;
            p->DeletePlayer(nick);
            break;
        }
    else if (comando =="EP")
        {
            string jogador;
            string jogador2;
            char jogo;
            cout<<"Digite R para jogar Reversi ou L para jogar Lig4"<<endl;
            cin>>jogo;
            cout<<"Digite os nicks dos jogadores que irão jogar"<<endl;
            cin>>jogador;
            cin>>jogador2;
            switch(jogo){
            case 'R':
            {
                

            }
            case 'L':
            {

            }
            }
            break;
        }
    else if (comando=="LJ")
        {
            p->ListPlayersbyNick();
            break;
        }
    else if (comando=="FS")
        {
            fim=0;
            p->Victory();
            break;
        }
    else
    { 
        cout<<"Comando inválido :("<<endl;
        cout<<"Digite um novo comando";
    }  
    delete p;
    }
}