#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
using namespace std;

class Sudoku {
private:
	char maze[9][9];
	char answer[9][9];
	char answer1[81] = { '1','8','6','7','3','2','4','5','9','2','7','9','4','1','5','6','8','3','3','4','5','8','9','6','7','2','1','4','1','8','5','7','9','2','3','6','5','9','2','3','6','4','1','7','8','7','6','3','1','2','8','5','9','4','9','2','1','6','5','3','8','4','7','8','3','7','2','4','1','9','6','5','6','5','4','9','8','7','3','1','2' };
        char answer2[81] = { '6','7','2','9','8','4','5','3','1','8','3','1','2','5','7','6','4','9','5','4','9','6','1','3','8','2','7','9','2','8','5','6','1','3','7','4','4','1','5','3','7','8','9','6','2','7','6','3','4','2','9','1','8','5','1','5','7','8','3','2','4','9','6','3','9','6','7','4','5','2','1','8','2','8','4','1','9','6','7','5','3' };
public:
	Sudoku(int);
	char mazeAnswer(int, int, int);
	void setMaze(int, int, char);
	void print();
	bool mazeCheck();
	char getMazeValue(int, int);
};

#endif
