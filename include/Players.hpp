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
  int LigDraws;
  int RevWins;
  int RevLoss;
  int RevDraws;
  int VWins;
  int VLoss;
  int VDraws;
  vector<Player *> PlayersList;

public:
  Player(string nick, string nome);
  Player();
  ~Player();
  void ReadArq();
  Player *GetPlayer(string nick);
  int GetPlayersCount();
  void LigWon(string nick);
  void LigLost(string nick);
  void LigDraw(string nick, string nick2);
  void RevWon(string nick);
  void RevLost(string nick);
  void RevDraw(string nick, string nick2);
  void VWon(string nick);
  void VLost(string nick);
  void VDraw(string nick, string nick2);
  bool CheckPlayer(string nick);
  void RegisterPlayer(string nick, string nome);
  void DeletePlayer(string nick);
  void ListPlayersbyNick();
  void ListPlayersbyName();
  int SumPoints(int l, int r, int v);
  void Victory(int l, int r, int v);
  void WriteArq();
};

#endif