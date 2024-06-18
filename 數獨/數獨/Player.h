#ifndef PLAYER_H
#define PLAYER_H
using namespace std;

#include <string>

class Player {
private:
     string name;
    int score;
    int health; 

public:
    Player(const  string& n, int s, int h);

    bool operator<(const Player& other) const;

     string getName() const;
    int getScore() const;
    int getHealth() const;
    void printHealth();
    void decreaseHealth(); 
};

#endif // PLAYER_H
