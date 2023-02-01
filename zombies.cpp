#include "zombies.h" 
#include <iostream>

zombies::zombies()
{
    Amount(spawn);
    Status(zombiesHP, zombiesDMG, zombiesRG);
}

void zombies::Amount(int Amnt)
{
    int * Amnt[9];
    
}

void zombies::Status(int status)
{
    int zombiesHP[] = {100, 150} [rand()% zombiesHP];
    int zombiesDMG[] = {5, 10} [rand()% zombiesDMG];
    int zombiesRG[] = {1,2} [rand()% zombiesRG];

}