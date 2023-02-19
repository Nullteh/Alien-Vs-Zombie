// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT4L 
// Names: AHMAD FATHI | LOO CHUAN MING | MUHAMMAD SYAHMI
// IDs: 1211102056 | 1211102069 | 1211101975
// Emails: 1211102056@student.mmu.edu.my | 1211102069@student.mmu.edu.my | 1211101975@student.mmu.edu.my
// Phones: 011-20784558 | 011-10691933 | 019-3808395
// ********************************************************* 

#include <iostream>
#include <cstdlib>
#include "main.h"
using namespace std;

int ClearScreen() // clear screen, taken from helper.cpp
{
    #if defined(_WIN32)
        return std::system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
    #endif
}

int Pause()
{
    #if defined(_WIN32)
        return std::system("pause");
    #elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
    #endif
}

int SetValidNum()
{
    
    int NumBuffer;
    do
    {
        cin >> NumBuffer;
        if (NumBuffer <= 0 || NumBuffer % 2 == 0)
        {
            cout << "Invalid Input, Please insert positive odd number. Not negative or even number." << endl;
        }

    }
    while (NumBuffer <= 0 || NumBuffer % 2 ==0);

    return NumBuffer;
}

int ZombieValidNum()
{
    int NumBuffer;
    do
    {
        cin >> NumBuffer;
        if (NumBuffer < 1 || NumBuffer > 9)
        {
            cout << "Invalid Input, Please insert between the value of 1 to 9. With 9 being the maximum zombies" << endl;
        }
    } 
    while (NumBuffer < 1 || NumBuffer > 9);

    return NumBuffer;
    
}

void GameSettings::ChangeSettings() 
{
    char input;
    
    //recursion
    cout << "Do you wish to change the game settings (y/n)? => ";
    cin >> input; 

    switch(input) {
        case 'y' : // player wants to change the settings
            // add code where it clear the screen
            cout << "Board Settings" << endl
                 << "--------------" << endl;

            // Both Rows and Columns MUST be ODD-numbered due to requirements
            // Have a code to only accept non-negative odd numbers for both inputs
            // ALSO, each one of these inputs need to have a check for only accepting non-negative numbers and no other chars
            // (WIP)
            cout << "Enter Rows => "; 
            BoardRws = SetValidNum(); 
            cout << endl;

            cout << "Enter Columns => ";
            BoardClmns = SetValidNum();
            cout << endl;
        
            cout << "Zombie Settings" << endl
                << "---------------" << endl;

            cout << "Enter Number of Zombies => ";
            ZombieAmnt = ZombieValidNum();

            cout << "\n" << "Settings Updated" << endl;
            Pause();
            ClearScreen();
            break;

        case 'n' : // Player continues with default settings
        // add code where it clears the screen
            break;

        default: // Wrong user input
            cout << endl << "Invalid Input. If you want to continue with the default settings, type \"n\"." << endl
                << "Or type \"y\" to change the default settings. \n" << endl;

            // When user inputs wrongly, method calls itself recursively until users inputs correctly
            ChangeSettings();
    }
}

int main()
{
    cout << "-------------------" << endl
         << "| Alien VS Zombie |" << endl
         << "-------------------" << endl;

    cout << "1. Play";
    cout << endl << "2. Quit\n" << endl;
        
    cout << "type in the number corresponding to the menu" << endl;
    cout << "Input: ";
    char MenuInput;
    cin >> MenuInput;

    switch (MenuInput)
    {
        case '1':
            ClearScreen();
            board();

        case '2':
            exit(0);
    }
     
        
}