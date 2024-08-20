#include "Players.hpp"

Player::Player()
{
    /// construtor sem parametros
    this->Nome = " ";
    this->NickName = " ";
    this->LigLoss = 0;
    this->LigWins = 0;
    this->RevLoss = 0;
    this->RevWins = 0;
    this->LigLoss = 0;
    this->LigWins = 0;
    this->LigDraws = 0;
    this->RevLoss = 0;
    this->RevWins = 0;
    this->RevDraws = 0;
    this->VLoss = 0;
    this->VWins = 0;
    this->VDraws = 0;
    this->PlayersCount = 0;
}

Player::Player(string nick, string nome)
{
    /// construtor com parâmetros
    this->Nome = nome;
    this->NickName = nick;
    this->LigLoss = 0;
    this->LigWins = 0;
    this->LigDraws = 0;
    this->RevLoss = 0;
    this->RevWins = 0;
    this->RevDraws = 0;
    this->VLoss = 0;
    this->VWins = 0;
    this->VDraws = 0;
}

Player::~Player()
{
    /// destrutor
    if (PlayersCount % 2 != 0)
    {
        for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end() - 1; it++)
        {
            PlayersList.erase(it);
        }
    }
    else
    {
        for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
        {
            PlayersList.erase(it);
        }
    }
}

void Player::ReadArq()
{
    /// testa se o arquivo de cadastro de jogadores exist e caso exista recadastra todos os usuarios ao iniciar o programa
    string linha;
    int tamanho;
    ifstream arquivo("bin/Players.txt");
    if (arquivo)
    {
        getline(arquivo, linha);
        tamanho = stoi(linha);
        string linha;
        for (int i = 0; i < tamanho; i++)
        {
            Player *temp = new Player();
            getline(arquivo, temp->NickName);
            getline(arquivo, temp->Nome);
            getline(arquivo, linha);
            temp->RevWins = stoi(linha);
            getline(arquivo, linha);
            temp->RevLoss = stoi(linha);
            getline(arquivo, linha);
            temp->RevDraws = stoi(linha);
            getline(arquivo, linha);
            temp->LigWins = stoi(linha);
            getline(arquivo, linha);
            temp->LigLoss = stoi(linha);
            getline(arquivo, linha);
            temp->LigDraws = stoi(linha);
            getline(arquivo, linha);
            temp->VWins = stoi(linha);
            getline(arquivo, linha);
            temp->VLoss = stoi(linha);
            getline(arquivo, linha);
            temp->VDraws = stoi(linha);
            PlayersList.push_back(temp);
            PlayersCount++;
        }
        arquivo.close();
    }
}

Player *Player::GetPlayer(string nick)
{
    /// busca um jogador no vector de jogadores e retorna um ponteiro apontando para ele
    if (PlayersCount != 0)
    {
        for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
        {
            Player *temp = *it;
            if (temp->NickName == nick)
            {
                return (*it);
            }
        }
    }
    return (nullptr);
}

int Player::GetPlayersCount()
{
    /// retorna o número atual de jogadores cadastrados
    return (PlayersCount);
}

bool Player::CheckPlayer(string nick)
{
    /// checa se ja existe algum jogador cadastrado com o nick fornecido e retorna true caso exista
    if (PlayersCount == 0)
    {
        return (false);
    }
    for (vector<Player*>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
        {
            Player* temp = *it;
            if (temp->NickName == nick)
            {
                return (true);
            }
        }
    return (false);
}

void Player::LigWon(string nick)
{
    /// incrementa o numero de vitorias no lig4
    Player *temp = GetPlayer(nick);
    if (temp->NickName == nick)
    {
        temp->LigWins++;
        cout << "======= " << nick << " GANHOU!" << " ======" << endl;
    }
}

void Player::LigLost(string nick)
{
    /// incrementa o numero de derrotas no lig4
    Player *temp = GetPlayer(nick);
    if (temp->NickName == nick)
    {
        temp->LigLoss++;
    }
}

void Player::LigDraw(string nick, string nick2)
{
    /// incrementa o numero de empates no lig4
    Player *temp = GetPlayer(nick);
    Player *temp2 = GetPlayer(nick2);
    {
        temp->LigDraws++;
        temp2->LigDraws++;
        cout << "====== EMPATE ======" << endl;
    }
}

void Player::RevWon(string nick)
{
    /// incrementa o numero de vitorias no reversi
    Player *temp = GetPlayer(nick);
    if (temp->NickName == nick)
    {
        temp->RevWins++;
        cout << "====== " << nick << " GANHOU!" << " ======" << endl;
    }
}

void Player::RevLost(string nick)
{
    /// incrementa o numero de derrotas no reversi
    Player *temp = GetPlayer(nick);
    if (temp->NickName == nick)
    {
        temp->RevLoss++;
    }
}

void Player::RevDraw(string nick, string nick2)
{
    /// incrementa o numero de empates no reversi
    Player *temp = GetPlayer(nick);
    Player *temp2 = GetPlayer(nick2);
    {
        temp->RevDraws++;
        temp2->RevDraws++;
        cout << "====== EMPATE ======" << endl;
    }
}

void Player::VWon(string nick)
{
    /// incrementa o numero de vitorias no jogo da velha
    Player *temp = GetPlayer(nick);
    if (temp->NickName == nick)
    {
        temp->VWins++;
        cout << "====== " << nick << " GANHOU!" << " ======" << endl;
    }
}

void Player::VLost(string nick)
{
    /// incrementa o numero de derrotas no jogo da velha
    Player *temp = GetPlayer(nick);
    if (temp->NickName == nick)
    {
        temp->VLoss++;
    }
}

void Player::VDraw(string nick, string nick2)
{
    /// incrementa o numero de empates no jogo da velha
    Player *temp = GetPlayer(nick);
    Player *temp2 = GetPlayer(nick2);
    {
        temp->VDraws++;
        temp2->VDraws++;
        cout << "====== DEU VELHA ======" << endl;
    }
}

void Player::RegisterPlayer(string nick, string nome)
{
    /// checa se ja existe um jogador com o nick informado  caso nao exista cria um jogador com o nick e nome informados e  adiciona no vector de jogadores
    int erro = 0;
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
            erro = 1;
    }

    if (erro == 1)
    {
        cout << "ERRO: jogador(a) repetido" << endl;
    }
    else
    {
        temp = new Player(nick, nome);
        PlayersList.push_back(temp);
        cout << "Jogador(a) " << temp->NickName << " cadastrado(a) com sucesso" << endl;
        PlayersCount++;
    }
}

void Player::DeletePlayer(string nick)
{
    /// checa se existe um jogador com o nick informado e deleta le caso exista
    int erro = 1;
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        if (temp->NickName == nick)
        {
            PlayersList.erase(it);
            cout << "Jogador(a) " << temp->NickName << " removido(a) com sucesso" << endl;
            erro = 0;
            PlayersCount--;
            break;
        }
    }
    if (erro == 1)
    {
        cout << "ERRO: jogador(a) inexistente" << endl;
    }
}

void Player::ListPlayersbyNick()
{
    /// imprime uma lista de todos os jogadores pelos nicks e na ordem em que foram cadastrados
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        cout << "   >>>>>>>>>> " << temp->NickName << " <<<<<<<<<<" << endl;
        cout << "  | REVERSI       - V: " << temp->RevWins << " D: " << temp->RevLoss << " E: " << temp->RevDraws << " |" << endl;
        cout << "  | LIG4          - V: " << temp->LigWins << " D: " << temp->LigLoss << " E: " << temp->LigDraws << " |" << endl;
        cout << "  | JOGO DA VELHA - V: " << temp->VWins << " D: " << temp->VLoss << " E: " << temp->VDraws << " |" << endl;
        cout << "  ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    }
}

void Player::ListPlayersbyName()
{
    /// imprime uma lista de todos os jogadores pelos nomes e na ordem em que foram cadastrados
    Player *temp;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        cout << "   >>>>>>>>>>> " << temp->Nome << " <<<<<<<<<<<" << endl;
        cout << "  | REVERSI       - V: " << temp->RevWins << " D: " << temp->RevLoss << " E: " << temp->RevDraws << " |" << endl;
        cout << "  | LIG4          - V: " << temp->LigWins << " D: " << temp->LigLoss << " E: " << temp->LigDraws << " |" << endl;
        cout << "  | JOGO DA VELHA - V: " << temp->VWins << " D: " << temp->VLoss << " E: " << temp->VDraws << " |" << endl;
        cout << "  ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨" << endl;
    }
}

int Player::SumPoints(int l, int r, int v)
{
    /// contabiliza o total de pontos de um determinado jogador multiplicando vitorias por 3 e empates po 1
    return (((this->LigWins * 3) + this->LigDraws) * l + ((this->RevWins * 3) + this->RevDraws) * r + ((this->VWins * 3) + this->VDraws) * v);
}

void Player::Victory(int l, int r, int v)

{
    /// chama a função sumpoints e contabiliza/imprime o vencedor de cada jogo e o vencedor geral
    Player *temp;
    Player *temp2;
    Player *temp3;
    string vencedor;
    int v1 = 0;
    int v2 = 0;
    int VRef = 0;
    int empate = 1;
    int teste = l * r * v;
    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        for (vector<Player *>::const_iterator it2 = PlayersList.begin(); it2 != PlayersList.end(); it2++)
        {
            temp = *it;
            temp2 = *it2;
            v1 = temp->SumPoints(l, r, v);
            v2 = temp2->SumPoints(l, r, v);
            if (temp->NickName == temp2->NickName)
            {
            }
            else if (v1 > v2 && v1 > VRef)
            {
                VRef = v1;
                empate = 0;
                vencedor = temp->NickName;
            }
            else if (v2 > v1 && v2 > VRef)
            {
                VRef = v2;
                empate = 0;
                vencedor = temp2->NickName;
            }
            else
            {
                if (VRef == 0 || (VRef == v1 && temp->NickName != vencedor) || (VRef == v2 && temp2->NickName != vencedor))
                    empate = 1;
            }
        }
    }
    if (l == 1 && teste == 0)
    {
        cout << "--------------------" << endl;
        cout << "--------------------" << endl;
        cout << "Resultado Lig4" << endl;
        if (empate == 0)
        {
            cout << "Vencedor(a): " << vencedor << endl;
            cout << "--------------------" << endl;
        }
        else
            cout << "EMPATE!" << endl
                 << "--------------------" << endl;
    }
    else if (r == 1 && teste == 0)
    {
        cout << "--------------------" << endl;
        cout << "Resultado Reversi" << endl;
        if (empate == 0)
        {
            cout << "Vencedor(a): " << vencedor << endl;
            cout << "--------------------" << endl;
        }
        else
            cout << "EMPATE!" << endl
                 << "--------------------" << endl;
    }
    else if (v == 1 && teste == 0)
    {
        cout << "--------------------" << endl;
        cout << "Resultado Jogo da Velha" << endl;
        if (empate == 0)
        {
            cout << "Vencedor(a): " << vencedor << endl;
            cout << "--------------------" << endl;
            cout << "--------------------" << endl;
        }
        else
            cout << "EMPATE!" << endl
                 << "--------------------" << endl
                 << "--------------------" << endl;
    }
    else if (empate == 0 && teste == 1)
    {
        cout << "Resultado final:" << endl;
        cout << "###########################" << endl
             << endl;
        cout << vencedor << " CAMPEA(O)!" << endl
             << endl;
        cout << "###########################" << endl;
    }
    if (empate == 1 && teste == 1)
    {
        cout << "Resultado final:" << endl;
        cout << "################" << endl
             << endl;
        cout << "     EMPATE!    " << endl
             << endl;
        cout << "################" << endl;
    }
}

void Player::WriteArq()
{
    /// abre ou cria o arquivo de cadastro e salva todos os usuarios cadastrados nele para leitura na proxima execução do programa
    ofstream arq("bin/Players.txt");
    arq << PlayersCount << endl;
    Player *temp;

    for (vector<Player *>::const_iterator it = PlayersList.begin(); it != PlayersList.end(); it++)
    {
        temp = *it;
        arq << temp->NickName << endl;
        arq << temp->Nome << endl;
        arq << temp->RevWins << endl;
        arq << temp->RevLoss << endl;
        arq << temp->RevDraws << endl;
        arq << temp->LigWins << endl;
        arq << temp->LigLoss << endl;
        arq << temp->LigDraws << endl;
        arq << temp->VWins << endl;
        arq << temp->VLoss << endl;
        arq << temp->VDraws << endl;
    }
    arq.close();
}
