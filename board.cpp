#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "main.h"
#include "GameMenu.h"
using namespace std;

struct Zombie {
    char id;
    int life;
    int attack;
    int range;
};

class Game
{
    vector< vector<char> > map_;
    int axisX_, axisY_, numZombies_;
    vector<Zombie> zombies_;

public:
    Game(int axisX = 0, int axisY = 0, int numZombies = 0);
    void init(int axisX, int axisY,int numZombies);
    void display() const;
    void moveLeft(); 
    void moveRight();
    void moveUp();
    void moveDown();

};

int alienX;
int alienY;
int zomX;
int zomY;

Game::Game(int axisX, int axisY, int numZombies)
{
    init(axisX, axisY, numZombies);
}

// game object
void Game::init(int axisX, int axisY,int numZombies)
{
    axisX_ = axisX;
    axisY_ = axisY;
    numZombies_ = numZombies;

    char objects[] = {' ',' ',' ','v','>','<','^','p','h','r'};    
    int noOfObjects = {10};

    alienX = (axisX / 2);
    alienY = (axisY / 2);


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
        
            if (axisY == alienY && axisX == alienX)
            {
                map_[axisY][axisX] = 'A';
            }
            else if (axisY == zomY && axisX == zomX)
            {
                map_[axisY][axisX] = 'Z';
            }
        } 
    }   
}

// Alien Movement
void Game::moveLeft()
{
    if (alienX > 0 && map_[alienY][alienX - 1] != 'Z' && map_[alienY][alienX - 1] != 'r' )
    {
        map_[alienY][alienX] = ' ';
        alienX--;
        map_[alienY][alienX] = 'A';
    }
}

void Game::moveRight()
{
    if (alienX < axisX_ - 1 && map_[alienY][alienX + 1] != 'Z' && map_[alienY][alienX + 1] != 'r')
    {
        map_[alienY][alienX] = ' ';
        alienX++;
        map_[alienY][alienX] = 'A';
    }
}

void Game::moveUp()
{
    if (alienY > 0  && map_[alienY - 1][alienX] != 'Z' && map_[alienY - 1][alienX] != 'r')
    {
        map_[alienY][alienX] = ' ';
        alienY--;
        map_[alienY][alienX] = 'A';
    }
}

void Game::moveDown()
{
    if (alienY < axisY_ -1 && map_[alienY + 1][alienX] != 'Z' && map_[alienY + 1][alienX] != 'r')
    {
        map_[alienY][alienX] = ' ';
        alienY++;
        map_[alienY][alienX] = 'A';
    }
}

// User input for controls
void Controls(Game& game)
{
    string UserInput; 
    cout << "Input: ";
    while (cin >> UserInput)
    {
        if (UserInput == "up")
        {
            ClearScreen();
            game.moveUp(); 
            game.display();
        }
        else if (UserInput == "down")
        {
            ClearScreen();
            game.moveDown();
            game.display();
        }
        else if (UserInput == "left")
        {
            ClearScreen();
            game.moveLeft();
            game.display();
        }
        else if (UserInput == "right")
        {
            ClearScreen();
            game.moveRight();
            game.display();
        }
        else if (UserInput == "arrow")
        {
            // insert code
        }
        else if (UserInput == "help")
        {
            ClearScreen();
            game.display();
            ShowCommands();
        }
        else if (UserInput == "save")
        {
            // save code
        }
        else if (UserInput == "load")
        {
            // load code
        }
        else if (UserInput == "quit")
        {
            char ExitConfirm;
            ClearScreen();
            cout << "Are you sure you want to quit? Any unsaved progress will be lost!" << endl
                 << "y/n: ";
            cin >> ExitConfirm; 

            switch (ExitConfirm)
            {
                case 'y':
                {
                    ClearScreen();
                    cout << "Goodbye!";
                    exit(0);
                }

                case 'n':
                {
                    ClearScreen();
                    game.display();
                    break;
                } 

                default:
                {
                    ClearScreen();
                    game.display();
                    cout << "Invalid Input, type 'y' to confirm quiting the game" << endl; 
                }
            }

        }

        else
        {
        cout << "Invalid Input, Please enter the \"help\" command to see the available commands." << endl;
        }
    }
}


// Output of the game board
void Game::display() const
{
    cout << " --__--__--__--__--__--__- " << endl;
    cout << " = Aliens Vs. Zombies = "  << endl;
    cout << " __--__--__--__--__--__--_ \n" << endl;

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
        for (int j = 0; j < axisX_; ++j)
    {
        cout << "+-";
    }
        cout << "+" << endl;
    //  column number
    cout << "  ";
    for (int j = 0; j < axisX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < axisX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}


void board() //board + board settings
{
    srand(time(NULL));

    int RowNum, ColumnNum, ZombNum;

    Game game; 
    GameSettings settings;

    settings.ShowSettings();
    settings.ChangeSettings();
    ClearScreen();

    settings.GetSettings(&RowNum, &ColumnNum, &ZombNum); 
    game.init(RowNum, ColumnNum, ZombNum); // Update axisX_ and axisY_
    game.display(); //Display the board
    Controls(game);
}