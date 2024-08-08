#pragma once

void clearScreen();
void printDungeon(std::vector<int> &playerPosition);
void gameLoop();
void inputHandler(std::string &userInput, std::vector<int> &playerPosition);
void moveHandler(std::vector<int> &playerPosition);

std::vector<int> playerStart();