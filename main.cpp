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
    {"-1", "s", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1", "-1"}


 };

//global player object
Player player("Roghbradden", dungeon);

int main()
{
    //calling the main game loop
    gameLoop();
    return 0;
}

void gameLoop() {

    //user input for commands
    std::string userInput;

    //storing the player's starting position
    //this will be used to update the player's position
    //passed by reference to the moveHandler function
    //passed by reference to the printDungeon function
    //passed by reference to the inputHandler function
    std::vector<int> playerPosition = playerStart();

    while (true) {

        //clearing terminal screen
        clearScreen();

        //printing the dungeon map
        printDungeon(playerPosition);

        //printing player stats
        std::cout << "Current Health: " << player.getHealthPoints() << '\n';

        //prompting for user input
        std::cout << "Enter a command or type 'help' for a list of commands...\n";
        std::cout << ">";

        //reading user input
        std::cin >> userInput;

        //handling user input commands
        inputHandler(userInput, playerPosition);

    }
}

std::vector<int> playerStart() {

    std::vector<int> playerPostion;

    //finding the
    for (int i = 0; i < dungeon.size(); i++) {
		for (int j = 0; j < dungeon[i].size(); j++) {
			if (dungeon[i][j] == "s") {
				playerPostion.push_back(i);
				playerPostion.push_back(j);
			}
		}
	}

    return playerPostion;
}

void inputHandler(std::string& userInput, std::vector<int> &playerPosition){

    std::cout << '\n';

    if (userInput == "help") {
        std::cout << "Commands: \n";
        std::cout << "m - move\n";
        std::cout << "i - inventory\n";
        std::cout << "c - change equipment\n";
        std::cout << "e - exit program\n";

        std::cout << '\n';
        std::cout << "Type \"Enter\" to continue...\n";

        std::cin.ignore();
        std::cin.get();
    }
	else if (userInput == "m") {

        moveHandler(playerPosition);

	}
	else if (userInput == "i") {
        std::cout << "Inventory: \n";
        std::cout << "Weapons: \n";
        std::cout << "Magic: \n";
        std::cout << "Items: \n";
	}
	else if (userInput == "c") {
        std::cout << "Change Equipment: \n";
        std::cout << "Enter a command to change equipment: \n";
        std::cout << "w - change weapon";
        std::cout << "m - change magic";
	}
	else if (userInput == "e") {
        std::cout << "Exiting program...\n";
		exit(0);
	}
	else {
        std::cout << "Invalid command. Please try again...\n";
        std::cout << "Type \"Enter\" to continue...\n";
        std::cin.ignore();
        std::cin.get();
	}

    std::cout << '\n';

}

void moveHandler(std::vector<int>& playerPosition) {



    std::cout << "Enter a direction to move: \n";
    std::cout << "w - up" << '\n';
    std::cout << "a - left" << '\n';
    std::cout << "s - down" << '\n';
    std::cout << "d - right" << '\n';

    std::string direction;
    std::cin >> direction;


    if (direction == "w") {
        playerPosition[0] -= 1;
    }
    else if (direction == "a") {
        playerPosition[1] -= 1;
    }
    else if (direction == "s") {
        playerPosition[0] += 1;
    }
    else if (direction == "d") {
        playerPosition[1] += 1;
    }
    else {

        std::cout << '\n';

        std::cout << "Invalid option. Please try again...\n";
        std::cout << "Type \"Enter\" to continue...\n";

        std::cin.ignore();
        std::cin.get();
    }
}

//functional methods
void clearScreen() {
    // Call the system function to execute the "cls" command
    system("cls");
}

void printDungeon(std::vector<int> &playerPosition) {

    for (int i = 0; i < dungeon.size() * 2; i++) {
        std::cout << "-";
    }

    for (int i = 0; i < dungeon.size(); i++) {
        for (int j = 0; j < dungeon[i].size(); j++) {
            if (dungeon[i][j] == "-1") {
                std::cout << "  ";
            }
            else if(i == playerPosition[0] && j == playerPosition[1]) {
                std::cout << "p ";
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
