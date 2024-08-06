#include <iostream>
#include <vector>
#include "main.h"
#include "player.h"

//declaring global game map
std::vector<std::vector<std::string>> dungeon = 
{   
    //room 3 - possible to encounter (3) enemies
    {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
    {"-1", "3", "3", "3", "3", "3", "3", "3", "3", "3", "3", "-1"},
    {"-1", "3", "3", "3", "3", "3", "3", "3", "3", "3", "3", "-1"},
    {"-1", "3", "3", "3", "3", "3", "3", "3", "3", "3", "3", "-1"},
    {"-1", "3", "3", "3", "3", "3", "3", "3", "3", "3", "3", "-1"},
    {"-1", "3", "3", "3", "3", "3", "3", "3", "3", "3", "3", "-1"},
    {"-1", "3", "3", "3", "3", "3", "3", "3", "3", "3", "3", "-1"},
    
    //room 2 - possible to encounter (2) enemies
    {"-1", "2", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},
    {"-1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "-1"},
    {"-1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "-1"},
    {"-1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "-1"},
    {"-1", "2", "2", "2", "2", "2", "2", "2", "2", "2", "2", "-1"},

    //room 1 encounters just one enemy
    {"-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "1", "-1"},
    {"-1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "-1"},
    {"-1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "-1"},
    {"-1", "p", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"},


 };

Player player("Roghbradden");

int main()
{
    gameLoop();
    return 0;
}

void gameLoop() {

    std::string userInput;

    //while (true) {
    clearScreen();
    printDungeon();

    std::cout << "Current Health: " << player.getHealthPoints() << '\n';
    //}
}

//functional methods
void clearScreen() {
    // Call the system function to execute the "cls" command
    system("cls");
}

void printDungeon() {

    for (int i = 0; i < dungeon.size() * 2; i++) {
        std::cout << "-";
    }

    for (int i = 0; i < dungeon.size(); i++) {
        for (int j = 0; j < dungeon[i].size(); j++) {
            if (dungeon[i][j] == "-1") {
                std::cout << "  ";
            }
            else {
                std::cout << dungeon[i][j] << " ";
            }
        }
        std::cout << '\n';
    }

    for (int i = 0; i < dungeon.size() * 2; i++) {
        std::cout << "-";
    }

    std::cout << '\n';

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
