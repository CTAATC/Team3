#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>
using namespace std;

class Sudoku {
private:
	int maze[9][9] = { 0 };
	int answer[9][9];
	int answer1[81] = { 1,8,6,7,3,2,4,5,9,2,7,9,4,1,5,6,8,3,3,4,5,8,9,6,7,2,1,4,1,8,5,7,9,2,3,6,5,9,2,3,6,4,1,7,8,7,6,3,1,2,8,5,9,4,9,2,1,6,5,3,8,4,7,8,3,7,2,4,1,9,6,5,6,5,4,9,8,7,3,1,2 };
public:
	Sudoku(int);
	int mazeAnswer(int, int, int);
	void setMaze(int, int, int);
	void print();
	bool mazeCheck();
	int getMazeValue(int row, int column);
};

#endif
