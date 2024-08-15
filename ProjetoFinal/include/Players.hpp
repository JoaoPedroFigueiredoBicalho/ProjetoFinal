#ifndef PLAYERS_HPP
#define PLAYERS_HPP

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
  int PlayersCount;
  int LigWins;
  int LigLoss;
  int RevWins;
  int RevLoss;
  vector<Player *> PlayersList;

public:
  Player(string nick, string nome);
  Player();
  ~Player();
  void ReadArq();
  void LigWon(string nick);
  void LigLost(string nick);
  void RevWon(string nick);
  void RevLost(string nick);
  Player *getPlayer(string nick);
  void RegisterPlayer(string nick, string nome);
  void DeletePlayer(string nick);
  void ListPlayersbyNick();
  void ListPlayersbyName();
  void Victory();
  void WriteArq();
};

#endif
