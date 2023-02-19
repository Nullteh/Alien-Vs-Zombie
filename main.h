#include <iostream>
using namespace std;

class GameSettings 
{
    protected:
        // Default settings
        int BoardRws = 9; //Board Rows 
        int BoardClmns = 7; //Board Columns
        int ZombieAmnt = 1; // Zombie Amount

    public:
         // Only shows current settings and nothing else
        void ShowSettings() 
        {
            cout << "Default Game Settings" << endl
                 << "---------------------" << endl
                 << "Board Rows     : " << BoardRws << endl
                 << "Board Columns  : " << BoardClmns << endl
                 << "Zombie Count   : " << ZombieAmnt << "\n" <<  endl;
        }

        // Call this method to change settings
        void ChangeSettings();

        // Pass along 3 memory addresses to get values through pointers 
        void GetSettings(int *RowNum, int *ColumnNum, int *ZombNum) 
        {
            *RowNum = BoardRws;
            *ColumnNum = BoardClmns;
            *ZombNum = ZombieAmnt;
        }
};

void board();

int ClearScreen(); // clear screen, taken from helper.cpp
/*{
    #if defined(_WIN32)
        return std::system("cls");
    #elif defined(__linux__) || defined(__APPLE__)
        return std::system("clear");
    #endif
};*/

int Pause();
/*{
    #if defined(_WIN32)
        return std::system("pause");
    #elif defined(__linux__) || defined(__APPLE__)
        return std::system(R"(read -p "Press any key to continue . . . " dummy)");
    #endif
};*/