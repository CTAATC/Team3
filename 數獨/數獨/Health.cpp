#include "Health.h"
#include <iostream>
using namespace std;

//傳回生命值
int Health::getHealth() {
	return health;
}

//寫出目前的生命值
void Health::printHealth(){
	cout << "\nYou have " << health << " lives left." << endl;
	cout << endl;
}

//扣一條生命值
int Health::decreaseHealth() {
	health = health - 1;
	return  health;
}
