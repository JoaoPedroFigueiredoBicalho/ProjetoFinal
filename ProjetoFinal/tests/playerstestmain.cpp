#include "Players.hpp"
#include <iostream>

int main(){
    Player p;
    p.ReadArq();
    while(1){
        cout<<"digite um comando: ";
        char entrada;
        cin>>entrada;
    switch (entrada)
    {
    case 'c':
    {
        string nick;
        string nome;
        cout<<"Digite o nick do jogador"<<endl;
        cin>>nick;
        cout<<"Digite o nome do jogador"<<endl;
        cin>>nome;
        p.RegisterPlayer(nick,nome);
        break;
    }
    case 'd':
    {
        string nick;
        cout<<"Digite o nick do jogador que deseja deletar"<<endl;
        cin>>nick;
        p.DeletePlayer(nick);
        break;
    }
    case 'g':
    {
        string jogador;
        cout<<"digite o nick do jogador que ira ganhar Lig4"<<endl;
        cin>>jogador;
        p.LigWon(jogador);
        break;
    }
     case 'G':
    {
        string jogador;
        cout<<"digite o nick do jogador que ira ganhar Reversi"<<endl;
        cin>>jogador;
        p.RevWon(jogador);
        break;
    }
    case 'p':
    {
        string jogador;
        cout<<"digite o nick do jogador que ira perder Lig4"<<endl;
        cin>>jogador;
        p.LigLost(jogador);
        break;
    }
    case 'P':
    {
        string jogador;
        cout<<"digite o nick do jogador que ira perder Reversi"<<endl;
        cin>>jogador;
        p.RevLost(jogador);
        break;
    }
    case 'l':
    {
        p.ListPlayersbyNick();
        break;
    }
    case 'L':
    {
        p.ListPlayersbyName();
        break;
    }
    case 'v':
    {
        p.Victory();
        p.WriteArq();
        break;
    }

    default:
        cout<<"opção inválida"<<endl;
        break;
    }
}
}