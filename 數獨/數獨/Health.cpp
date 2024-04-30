#include "Health.h"
#include <iostream>
using namespace std;


int Health::getHealth() {
	return health;
}

void Health::printHealth(){
	cout << "\nYou have " << health << " lives left." << endl;
	cout << endl;
}

int Health::decreaseHealth() {
	health = health - 1;
	return  health;
}