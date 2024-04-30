#ifndef HEALTH_H
#define HEALTH_H

class Health {
private:
	int health = 3;

public:
	int getHealth();
	void printHealth();
	int decreaseHealth();
};

#endif
