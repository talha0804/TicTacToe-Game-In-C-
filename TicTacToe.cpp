#include <iostream>
using namespace std;
#define rows 3
#define cols 3
class Board
{
    char **Cell;

public:
    Board()
    {
        Cell = new char *[rows];
        for (int i = 0; i < rows; i++)
            Cell[i] = new char[cols];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Cell[i][j] = '-';
            }
        }
    }
    char getCell(int r, int c)
    {
        return Cell[r][c];
    }
    void SetCell(int r, int c, char symbol)
    {
        Cell[r][c] = symbol;
    }
    void showBoard()
    {
        cout << "**************Tic Tac Toe Game *****************" << endl;
        ;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << Cell[i][j] << "  ";
            }
            cout << endl;
            cout << endl;
        }
    
        
    }
    ~Board()
    {
        for (int i = 0; i < rows; i++)
            delete[] Cell[i];
        delete[] Cell;
    }
};
class Player
{
    string name;
    char symbol;

public:
    Player() : name(" "), symbol('\0') {}
    Player(const string &name, const char &symbol) : name(name), symbol(symbol) {}
    void SetName(const string &name)
    {
        this->name = name;
    }
    string GetName() const
    {
        return name;
    }
    void SetSymbol(const char &Symbol)
    {
        this->symbol = symbol;
    }
    char GetSymbol() const
    {
        return symbol;
    }
    int TakeTurn()
    {

        while (true)
        {
            int cell;
            cout << name << " Enter Cell Number (1-9) :";
            cin >> cell;
            if (cell >= 1 && cell <= 9)
            {
                return cell - 1;
            }
            else
            {
                cout << "Error::Invalid Cell Number Please agin Eneter a Valid Cell Number (1-9) :";
            }
        }
    }
};
class Game
{
    Board board;
    Player player1;
    Player player2;

public:
    Game(const Player &player1, const Player &player2) : player1(player1), player2(player2) {}
    bool CheckWinner(char symbol)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (board.getCell(0, i) == symbol && board.getCell(1, i) == symbol && board.getCell(2, i) == symbol)
                return true;
        }
        for (int i = 0; i < 3; ++i)
        {
            if (board.getCell(i, 0) == symbol && board.getCell(i, 1) == symbol && board.getCell(i, 2) == symbol)
                return true;
        }
        if (board.getCell(0, 0) == symbol && board.getCell(1, 1) == symbol && board.getCell(2, 2) == symbol)
            return true;
        if (board.getCell(0, 2) == symbol && board.getCell(1, 1) == symbol && board.getCell(2, 0) == symbol)
            return true;
        return false;
    }
    void playGame()
    {
        Player CurrentPlayer = player1;
        int turn = 0;
        while (true)
        {
            board.showBoard();
            int move = CurrentPlayer.TakeTurn();
            int row = move / 3;
            int col = move % 3;
            if (board.getCell(row, col) == '-')
            {
                board.SetCell(row, col, CurrentPlayer.GetSymbol());

                if (CheckWinner(CurrentPlayer.GetSymbol()))
                {
                    cout << CurrentPlayer.GetName() << " wins! the game" << endl;
                    break;
                }
                else if (turn == 8)
                {
                    cout << "It is a tie!" << endl;
                    break;
                }
                else
                {

                    char currentSymbol = CurrentPlayer.GetSymbol();
                    char player1Symbol = player1.GetSymbol();
                    char player2Symbol = player2.GetSymbol();

                    CurrentPlayer = (currentSymbol == player1Symbol) ? player2 : player1;
                    turn++;
                }
            }
            else
            {
                std::cout << "That cell is already taken. Try again." << std::endl;
            }
        }
    }
};
int main()
{    

    
    string n1,n2;
    char s1,s2;
    cout << "Enter First Player Name:";
    cin>>n1;
    cout << n1 << " Please Enter your Symbol:";
    cin >> s1;
    cout << "Enter Second  Player Name:";
    cin >> n2;
    cout << n2 << " Please Enter your Symbol:";
    cin >> s2;

    Player player1(n1,s1);
    Player player2(n2, s2);
    Game game(player1, player2);
    game.playGame();
}
