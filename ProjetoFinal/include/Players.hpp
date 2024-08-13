#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Player
{
private:
    string Nome;
    string NickName;
    int Wins;
    int Loss;
    vector<Player*> PlayersList;
public:
    
    Player(string nick, string nome);
    ~Player();
    Player* getPlayer(string nick);
    void RegisterPlayer(string nick, string nome);
    void DeletePlayer(string nick);
    
};


