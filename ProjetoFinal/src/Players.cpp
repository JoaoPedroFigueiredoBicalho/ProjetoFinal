#include "Players.hpp"

Player::Player(string nome, string nick)
{
    this->Nome = nome;
    this->NickName = nick;
    this->Loss = 0;
    this->Wins = 0;
}

void Player::RegisterPlayer(string nick, string nome)
{
    int erro = 0;
    for(vector<Player*>::const_iterator it=PlayersList.begin(); it!=PlayersList.end(); it++)
    {
        Player* temp = *it;
        if(temp->NickName==nick)
        erro = 1;
    }
    if (erro == 1)
    {
        cout<<"ERRO: jogador repetido"<<endl;
    }
}