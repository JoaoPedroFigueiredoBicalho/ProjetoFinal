#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:
    string Nome;
    string NickName;
    int LigWins;
    int LigLoss;
    int RevWins;
    int RevLoss;
    vector<Player*> PlayersList;
public:
    
    Player(string nick, string nome);
    ~Player();
    void LigWon();
    void LigLost();
    void RevWon();
    void RevLost();
    Player* getPlayer(string nick);
    void RegisterPlayer(string nick, string nome);
    void DeletePlayer(string nick);
    void ListPlayersbyNick();
    void ListPlayersbyName();
    void Victory();

};


