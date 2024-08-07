#include "player.h"

//constructors
Player::Player(const std::string &nameIn, const std::vector<std::vector<std::string>> &dungeonIn)
	
	: name(nameIn), 
	attackLevel(1), 
	maxHealth(10), 
	healthPoints(10), 
	keys(0), 
	hasMap(false), 
	hasBeen(dungeonIn.size(), std::vector<bool>(dungeonIn[0].size(), false))
{}

//getters
std::string Player::getName() const {
	return this->name;
}

int Player::getAttackLevel() const {
	return this->attackLevel;
}

int Player::getMaxHealth() const {
	return this->maxHealth;
}

int Player::getHealthPoints() const {
	return this->healthPoints;
}

int Player::getKeys() const {
	return this->keys;
}

bool Player::getHasMap() const {
	return this->hasMap;
}

std::vector<std::vector<bool>> Player::getHasBeen() const {
	return this->hasBeen;
}

//setters
void Player::setName(const std::string &nameIn) {
	this->name = nameIn;
}

void Player::setAttackLevel(const int &attackLevelIn) {
	this->attackLevel = attackLevelIn;
}

void Player::setMaxHealth(const int &maxHealthIn) {
	this->maxHealth = maxHealthIn;
}

void Player::setHealthPoints(const int &healthPointsIn) {
	this->healthPoints = healthPointsIn;
}

void Player::setKeys(const int &keysIn) {
	this->keys = keysIn;
}

void Player::setHasMap(const bool &hasMapIn) {
	this->hasMap = hasMapIn;
}

void Player::setHasBeen(const std::vector<std::vector<bool>> &hasBeenIn) {
	this->hasBeen = hasBeenIn;
}