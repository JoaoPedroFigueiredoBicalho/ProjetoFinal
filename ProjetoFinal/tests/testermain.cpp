#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Player
{
private:
    string NickName;
    string Nome;
    int RevWins;
    int RevLoss;
    int LigWins;
    int LigLoss;
    int NumPlayers;
    vector<Player *> PlayersList;

public:
    Player(string nick, string nome);
    Player();
    ~Player();
    void ReadArq();
    void RegisterPlayer(string nick, string nome);
    void LigWon(string nick);
    void LigLost(string nick);
    void RevWon(string nick);
    void RevLost(string nick);
    Player *getPlayer(string nick);
    void DeletePlayer(string nick);
    void ListPlayersbyNick();
    void ListPlayersbyName();
    void Victory();
    void WriteArq();
};

Player::Player()
{
    this->Nome = " ";
    this->NickName = " ";
    this->LigLoss = 0;
    this->LigWins = 0;
    this->RevLoss = 0;
    this->RevWins = 0;
}
Player::Player(string nick, string nome)
{
    this->Nome = nome;
    this->NickName = nick;
    this->LigLoss = 0;
    this->LigWins = 0;
    this->RevLoss = 0;
    this->RevWins = 0;
}

Player::~Player()
{
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        PlayersList.erase(it);
    }
}

void Player::ReadArq()
{
    string linha;
    int tamanho;
    ifstream arquivo("Players.txt");
    if (!arquivo.eof())
    {
    }
    else
    {
        getline(arquivo, linha);
        tamanho = stoi(linha);
        Player *temp = new Player();
        string linha;
        for (int i = 0; i < tamanho; i++)
        {
            getline(arquivo, temp->NickName);
            getline(arquivo, temp->Nome);
            getline(arquivo, linha);
            temp->RevWins = stoi(linha);
            getline(arquivo, linha);
            temp->RevLoss = stoi(linha);
            getline(arquivo, linha);
            temp->LigWins = stoi(linha);
            getline(arquivo, linha);
            temp->LigLoss = stoi(linha);
            PlayersList.push_back(temp);
        }
    }
    arquivo.close();
}

void Player::RegisterPlayer(string nick, string nome)
{
    int erro = 0;
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
            erro = 1;
        //        throw std::invalid_argument("ERRO: jogador repetido");
    }

    if (erro == 1)
    {
        cout << "ERRO: jogador repetido" << endl;
    }
    else
    {
        temp = new Player(nick, nome);
        PlayersList.push_back(temp);
        cout << "Jogador " << temp->NickName << " cadastrado com sucesso" << endl;
    }
}

Player *Player::getPlayer(string nick)
{
    int x = 0;
    int erro = 1;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        Player *temp = *it;
        x++;
        if (temp->NickName == nick)
        {
            erro = 0;
            break;
        }
    }
    if (erro == 0)
    {
        return (PlayersList[x]);
    }
    else
    {
        cout << "ERRO: jogador inexistente";
        return (nullptr);
    }
}

void Player::LigWon(string nick)
{
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
        {
            temp->LigWins++;
            cout << "@@@" << nick << "GANHOU!" << "@@@" << endl;
        }
    };
}

void Player::LigLost(string nick)
{
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
        {
            temp->LigLoss++;
        }
    };
}
void Player::RevWon(string nick)
{
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
        {
            temp->RevWins++;
            cout << "@@@" << nick << "GANHOU!" << "@@@" << endl;
        }
    };
}

void Player::RevLost(string nick)
{
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
        {
            temp->RevLoss++;
        }
    };
}

void Player::DeletePlayer(string nick)
{
    int erro = 1;
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
        {
            PlayersList.erase(it);
            cout << "Jogador " << temp->NickName << " removido com sucesso" << endl;
            erro = 0;
        }
    }
    if (erro == 1)
    {
        cout << "ERRO: jogador inexistente" << endl;
    }
}

void Player::ListPlayersbyNick()
{
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        cout << ">>>>>> " << temp->NickName << " <<<<<<" << endl;
        cout << "  | REVERSI - V: " << temp->RevWins << " D: " << temp->RevLoss << " |" << endl;
        cout << "  | LIG4    - V: " << temp->LigWins << " D: " << temp->LigLoss << " |" << endl;
        cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    }
}
void Player::ListPlayersbyName()
{
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        cout << ">>>>>> " << temp->Nome << " <<<<<<" << endl;
        cout << "  |REVERSI - V: " << temp->RevWins << "D: " << temp->RevLoss << "|" << endl;
        cout << "  |LIG4    - V: " << temp->LigWins << "D: " << temp->LigLoss << "|" << endl;
        cout << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    }
}

void Player::Victory()
{
    Player *temp;
    Player *temp2;
    string vencedor;
    int empate = 1;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end() - 1; it++)
    {
        for (vector<Player *>::const_iterator it2 = PlayersList.begin() + 1; it2 != PlayersList.end(); it2++)
        {
            temp = *it;
            temp2 = *it2;
            if ((temp->LigWins + temp->RevWins) > (temp2->LigWins + temp2->RevWins))
            {
                empate = 0;
                vencedor = temp->NickName;
            }
            else if ((temp->LigWins + temp->RevWins) < (temp2->LigWins + temp2->RevWins))
            {
                empate = 0;
                vencedor = temp2->NickName;
            }
            else
            {
                empate = 1;
            }
        }
    }
    if (empate == 0)
    {
        cout << "###################" << endl
             << endl;
        cout << vencedor << " VENCEU!" << endl
             << endl;
        cout << "###################" << endl;
    }
    if (empate == 1)
    {
        cout << "################" << endl;
        cout << "     EMPATE!    " << endl;
        cout << "################" << endl;
    }
}

void Player::WriteArq()
{
    ofstream arq("Players.txt");
    arq << NumPlayers;
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        arq << temp->NickName << endl;
        arq << temp->Nome << endl;
        arq << temp->RevWins << endl;
        arq << temp->RevLoss << endl;
        arq << temp->LigWins << endl;
        arq << temp->LigLoss << endl;
    }
    arq.close();
}

int main()
{
    Player p;
    p.ReadArq();
    while (1)
    {
        cout << "digite um comando: ";
        char entrada;
        cin >> entrada;
        switch (entrada)
        {
        case 'c':
        {
            string nick;
            string nome;
            cout << "Digite o nick do jogador" << endl;
            cin >> nick;
            cout << "Digite o nome do jogador" << endl;
            cin >> nome;
            p.RegisterPlayer(nick, nome);
            break;
        }
        case 'd':
        {
            string nick;
            cout << "Digite o nick do jogador que deseja deletar" << endl;
            cin >> nick;
            p.DeletePlayer(nick);
            break;
        }
        case 'g':
        {
            string jogador;
            cout << "digite o nick do jogador que ira ganhar Lig4" << endl;
            cin >> jogador;
            p.LigWon(jogador);
            break;
        }
        case 'G':
        {
            string jogador;
            cout << "digite o nick do jogador que ira ganhar Reversi" << endl;
            cin >> jogador;
            p.RevWon(jogador);
            break;
        }
        case 'p':
        {
            string jogador;
            cout << "digite o nick do jogador que ira perder Lig4" << endl;
            cin >> jogador;
            p.LigLost(jogador);
            break;
        }
        case 'P':
        {
            string jogador;
            cout << "digite o nick do jogador que ira perder Reversi" << endl;
            cin >> jogador;
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
            cout << "opção inválida" << endl;
            break;
        }
    }
}