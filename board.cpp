#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Game
{
    vector< vector<char> > map_;
    int axisX_, axisY_;
    // char pause, quit, help;

public:
    Game(int axisX = 9, int axisY = 5);
    void init(int axisX, int axisY);
    void display() const;
    // void menu(char);
};

Game::Game(int axisX, int axisY)
{
    init(axisX, axisY);
    // menu(help);
}

//ERROR, FIX PLEASE
void Game::init(int axisX, int axisY)
{
    axisX_ = axisX;
    axisY_ = axisY;

    char objects[] = {};    
    int noOfObjects = {};

    map_.resize(axisY_);
    for (int i = 0; i < axisY_; ++i)
    {
        map_[i].resize(axisX_);     
    }

    for (int axisY = 0; axisY < axisY_; ++axisY)
    {
        for (int axisX = 0; axisX < axisX_; ++axisX)
        {
            int objNo = rand() % noOfObjects;
            map_[axisY][axisX] = objects[objNo];
        }
    }
}

void Game::display() const
{
    cout << " --__--__--__--__--__--__- " << endl;
    cout << " = Aliens Vs. Zombies = "  << endl;
    cout << " __--__--__--__--__--__--_ " << endl;

    // each row
    for (int i = 0; i < axisY_; ++i)
    {
        cout << "  ";
        for (int j = 0; j < axisX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;

        // row numbers
        cout << setw(2) << (axisY_ - i);

        for (int j = 0; j < axisX_; ++j)
        {
            cout << "|" << map_[i][j];
        } 
        cout << "|" << endl;
    }

    //lower border
    cout << "  ";
    
}

//void Game::menu(char menu)
// {
//     char h;
//     cout << "Would you like to look at our GameMenu?" << endl;
//     cout << "If so please type in 'h' to view the commands" << endl;
//     cin >> h;
        
//         if(h=help)
//             cout << "Commands:" << endl;
//             cout << "";

// }

void test1_1()
{
    Game game;
    game.display();
}

int main()
{
    srand(1);
    // for testing the map
    test1_1();
}