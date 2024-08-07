#pragma once

#include <iostream>
#include <vector>

class Player {

private:
	//attributes
	std::string name;
	int attackLevel;
	int maxHealth;
	int healthPoints;
	int keys;
	bool hasMap;
	std::vector<std::vector<bool>> hasBeen;

	//players inventory
	std::vector<std::string> weapons;
	std::vector<std::string> magic;
	std::vector<std::string> items;
	
	//storing the player's currently equipped items
	std::string currentWeapon;
	std::string currentMagic;

public:
	Player(const std::string& nameIn, const std::vector<std::vector<std::string>> &dungeonIn);

	//getters
	std::string getName() const;
	int getAttackLevel() const;
	int getMaxHealth() const;
	int getHealthPoints() const;
	int getKeys() const;
	bool getHasMap() const;
	std::vector<std::vector<bool>> getHasBeen() const;

	//setters
	void setName(const std::string &nameIn);
	void setAttackLevel(const int &attackLevelIn);
	void setMaxHealth(const int &maxHealthIn);
	void setHealthPoints(const int &healthPointsIn);
	void setKeys(const int &keysIn);
	void setHasMap(const bool &hasMapIn);
	void setHasBeen(const std::vector<std::vector<bool>> &hasBeenIn);

	//methods
};

