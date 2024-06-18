#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const string& n, int s, int h) : name(n), score(s), health(h) {}

bool Player::operator<(const Player& other) const {
    return score < other.score; // 分數高的排前面
}
void Player::printHealth() {
    cout << "\nYou have " << health << " lives left." << endl;
    cout << endl;
}
string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

int Player::getHealth() const {
    return health;
}

void Player::decreaseHealth() {
    health--;
}
