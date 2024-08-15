#include <string>
#include <iostream>
#include <vector>
#include <fstream>

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
    int NumPlayers;
    vector<Player*> PlayersList;
public:
    
    Player(string nick, string nome);
    Player();
    ~Player();
    void ReadArq();
    void LigWon(string nick);
    void LigLost(string nick);
    void RevWon(string nick);
    void RevLost(string nick);
    Player* getPlayer(string nick);
    void RegisterPlayer(string nick, string nome);
    void DeletePlayer(string nick);
    void ListPlayersbyNick();
    void ListPlayersbyName( );
    void Victory();
    void WriteArq();

};


