#include "Players.hpp"
#include <iostream>

int main(){
    Player p;
    while(1){
        char entrada;
    switch (entrada)
    {
    case 'c':
        string nick;
        string nome;
        cout<<"Digite o nick do jogador"<<endl;
        cin>>nick;
        cout<<"Digite o nome do jogador"<<endl;
        cin>>nome;
        p.RegisterPlayer(nick,nome);

        break;
    case 'd':
        string nick;
        cout<<"Digite o nick do jogador"<<endl;
        cin>>nick;
        p.DeletePlayer(nick);
        break;
    case 'E':
        string jogador;
        cout<<"digite o nick do jogador que ira jogar"<<endl;
        cin>>jogador;
        p.LigWon(jogador);
        break;
    case 'l':
        string jogador;
        cout<<"digite o nick do jogador que ira jogar"<<endl;
        cin>>jogador;
        p.LigWon(jogador);
        break;
    case 'v':
        p.Victory();
        break;
    
    default:
        break;
    }
}
}