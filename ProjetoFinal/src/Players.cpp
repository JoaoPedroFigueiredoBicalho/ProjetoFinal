#include "Players.hpp"

Player::Player(string nome, string nick)
{
    this->Nome = nome;
    this->NickName = nick;
    this->Loss = 0;
    this->Wins = 0;
}

Player* Player::getPlayer(string nick)
{
    int x = 0;
    int erro = 1;
    for(vector<Player*>::const_iterator it=PlayersList.begin(); it!=PlayersList.end(); it++)
    {
        Player* temp = *it;
        x++;
        if(temp->NickName==nick)
        {
            erro = 0;
            break;
        }
    }
    if(erro == 0)
    {
        return(PlayersList[x]);
    }else
    {
        cout<<"ERRO: jogador inexistente";
        return(nullptr);
    }
}

void Player::RegisterPlayer(string nick, string nome)
{
    int erro = 0;
    Player* temp;
    for(vector<Player*>::const_iterator it=PlayersList.begin(); it!=PlayersList.end(); it++)
    {
        temp = *it;
        if(temp->NickName==nick)
        erro = 1;
//        throw std::invalid_argument("ERRO: jogador repetido");
    }
    
    if (erro == 1)
    {
        cout<<"ERRO: jogador repetido"<<endl;
    }else
    {
        PlayersList.push_back(new Player(nome,nick));
        cout<<"Jogador"<<temp->NickName<<"cadastrado com sucesso"<<endl;
    }
}
    void Player::DeletePlayer(string nick)
    {
        int erro = 1;
        Player* temp;
    for(vector<Player*>::const_iterator it=PlayersList.begin(); it!=PlayersList.end(); it++)
    {
        temp = *it;
        if(temp->NickName==nick)
        {
            PlayersList.erase(it);
            cout<<"Jogador" <<temp->NickName<<"removido com sucesso"<<endl;
            erro = 0;
        }
    }
    if (erro == 1)
        {
            cout<<"ERRO: jogador inexistente"<<endl;
        }
    }
//    Rodrigo galo
