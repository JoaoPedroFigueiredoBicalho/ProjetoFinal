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
    void RegisterPlayer(string nick, string nome);
    
};


