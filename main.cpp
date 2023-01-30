// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT4L 
// Names: AHMAD FATHI | LOO CHUAN MING | MUHAMMAD SYAHMI
// IDs: 1211102056 | 1211102069 | 1211101975
// Emails: 1211102056@student.mmu.edu.my | 1211102069@student.mmu.edu.my | 1211101975@student.mmu.edu.my
// Phones: 011-20784558 | 011-10691933 | 019-3808395
// ********************************************************* 

#include "pf/helper.h"
#include <iostream>
using namespace std;

class GameSettings 
{
    protected:
        // Default settings
        int BoardRws = 5; //Board Rows 
        int BoardClmns = 9; //Board Columns
        int ZombieAmnt = 1; // Zombie Amount

    public:
         // Only shows current settings and nothing else
        void ShowSettings() {
            cout << "Default Game Settings" << endl
                 << "---------------------" << endl
                 << "Board Rows     : " << BoardRws << endl
                 << "Board Columns  : " << BoardClmns << endl
                 << "Zombie Count   : " << ZombieAmnt << "\n" <<  endl;
        }

        // Call this method to change settings
        void ChangeSettings();

        // Pass along 3 memory addresses to get values through pointers 
        void GetSettings(int *RowNum, int *ColumnNum, int *ZombNum) {
            *RowNum = BoardRws;
            *ColumnNum = BoardClmns;
            *ZombNum = ZombieAmnt;
        }
};

void EvenCheck(int x) //Checks if the numbers are even (WIP)
{
    int y = x;

    if (y % 2 == 0)
    cout << "Even Numbers are Not Accepted.\n Please Use Odd Numbers Instead.";

    else
    cin >> x;
}


// "::" is a scope resolution identifier
// This basically allows you to define a method from outside a class scope
// without making the code look clunky or making it too long
void GameSettings::ChangeSettings() {
    char input;
    
    //recursion
    cout << "Do you wish to change the game settings (y/n)? => ";
    cin >> input; 

    switch(input) {
        case 'y' : // player wants to change the settings
            system("CLS");
           
            cout << "Board Settings" << endl
                << "--------------" << endl;

            // Both Rows and Columns MUST be ODD-numbered due to requirements
            // Have a code to only accept non-negative odd numbers for both inputs
            // ALSO, each one of these inputs need to have a check for only accepting non-negative numbers and no other chars
            // (WIP)
            cout << "Enter Rows => "; 
            cin >> BoardRws;

            cout << "Enter Columns => ";
            cin >> BoardClmns;
            cout << endl;
        
            cout << "Zombie Settings" << endl
                << "---------------" << endl;

            cout << "Enter Number of Zombies => ";
            cin >> ZombieAmnt;

            cout << "\n" << "Settings Updated" << endl 
                << "Press any key to continue .   .   ."; // Add stop + input to let user continue
            break;

        case 'n' : // Player continues with default settings
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
    // Variables stored in main
    int RowNum, ColumnNum, ZombNum;

    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl << endl;
    
    GameSettings settings;
    // The two methods below need to be called from a menu function/class
    settings.ShowSettings();
    settings.ChangeSettings();


    // To get values from Settings to be used in board game code, or in main() to be passed along
    // Explanation, GetSettings() method requires 3 inputs to be passed along,
    // ie. 3 variables RowNum, ColumnNum & ZombNum
    // However, you can ONLY return ONE value from a method/function

    // So in order to "return" values, you instead send the memory addresses of the aforementioned variables
    // via the Address-of (&) Operator. This gives the memory address of the variable it is being used on
    // Meaning, if you dereference that address via a Dereferencer (*) Operator, you can then access the
    // proper values of the original variable that you used the (&) operator on

    // eg. RowNum = 1 is a normal variable, you know how it works
    // &RowNum gives the MEMORY ADDRESS of RowNum, but NOT the actual value that is contained within RowNum
    // You store &RowNum's value into a pointer variable, eg. int *PtrRowNum
    // (ptr = pointer, which is just arbitrary and used for better distinction)
    // PtrRowNum = memory address, *PtrRowNum = value of RowNum
    // Then using *PtrRowNum, you can now access RowNum's value
    // Changing *PtRRowNum would also change RowNum's actual value. This is because *PtrRowNum is pointed to
    // RowNum and therefore changes its values DIRECTLY. The opposite is also true from RowNum to *PtrRowNum

    // Hence, passing the memory address of the three variables into the method will yield back values into the
    // aforementioned variables due to using pointers. All without "returning" the values
    settings.GetSettings(&RowNum, &ColumnNum, &ZombNum);
    cout << "\n\nRow Number: " << RowNum << "\nColumn Number: " << ColumnNum << "\nZombie Number: " << ZombNum;


    // INSERT BOARD GAME CODE
    //pf::Pause();
}