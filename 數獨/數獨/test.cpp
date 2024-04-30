#include "Sudoku.h"
#include "Health.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int ver, m_r, m_c, input_answer;
	srand(time(NULL));
	ver = rand() % 1;

	Health Health1;
	Sudoku Sudoku1(ver);


	while(Health1.getHealth() != 0 and Sudoku1.mazeCheck() == true) {
		Health1.printHealth();
		Sudoku1.print();
		cin >> m_r >> m_c >> input_answer;
		if (input_answer != Sudoku1.mazeAnswer(ver,m_r,m_c)) Health1.decreaseHealth();
		else Sudoku1.setMaze(m_r, m_c, input_answer);
	}

	if (Health1.getHealth() == 0) cout << "You lose." << endl;
	else if (Sudoku1.mazeCheck() != true) cout << "Congratulation, you won!" << endl;
	
}