#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
class zombies
{
    
    int zombiesHP;
    int zombiesDMG;
    int zombiesRG;
    int spawn;
*/


class Zombie
{
public:
    int id;       // Unique ID of the zombie
    int life;     // Health points 
    int attack;   // Attack power 
    int range;    // Attack range
    int ZomX, ZomY; // current location for zombie

    // Constructor to initialize a zombie with random attributes
    Zombie(int id)
    {
        id = id;
        life = rand() % 101 + 100;     // Random life between 100 and 200
        attack = rand() % 11 + 10;    // Random attack between 10 and 20
        range = rand() % 4 + 1;       // Random range between 1 and 4
    }

    void move(int new_x, int new_y) // new location for zombie
    {
        ZomX = new_x;
        ZomY = new_y;
    }

    bool InRange(Zombie target) // checks if zombie is in range to attack Alien
    {
        int distance = sqrt(pow(ZomX - target.ZomX, 2) + pow(ZomY - target.ZomY, 2));
        return distance <= range;
    }

    void attackZombie(Zombie& target) // Attack zombie
    {
        target.life -= attack;
        if (target.life < 0)
        {
            target.life = 0;
        }

        cout << "Zombie " << id << " attacked Alien " << target.id << " for " << attack << " damage!\n";
    }
};
