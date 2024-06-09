#include "Sudoku.h"
#include <iostream>
using namespace std;

Sudoku::Sudoku(int version) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            maze[i][j] = '.';
        }
    }
        
    
    if (version == 0) {
        maze[1][4] = maze[5][3] = maze[7][5] = '1';
        maze[2][7] = maze[4][2] = maze[5][4] = maze[6][1] = '2';
        maze[3][7] = maze[5][2] = '3';
        maze[2][1] = maze[3][0] = maze[5][8] = maze[7][4] = maze[8][2] = '4';
        maze[0][7] = maze[3][3] = maze[4][0] = '5';
        maze[0][2] = maze[3][8] = maze[4][4] = maze[7][7] = '6';
        maze[2][6] = maze[5][0] = maze[6][8] = maze[8][5] = '7';
        maze[0][1] = maze[2][3] = maze[3][2] = maze[5][5] = '8';
        maze[0][8] = maze[1][2] = maze[3][5] = maze[5][7] = maze[7][6] = maze[8][3] = '9';
    }
        
    else if (version == 1) {
    maze[0][8] = maze[1][2] = maze[3][5] = maze[4][1] = maze[7][7] = '1';
    maze[3][1] = maze[5][4] = maze[8][0] = '2';
    maze[0][7] = maze[1][1] = maze[5][2] = maze[6][4] = '3';
    maze[0][5] = maze[2][1] = maze[4][0] = maze[6][6] = maze[7][4] = '4';
    maze[0][6] = maze[2][0] = maze[3][3] = '5';
    maze[1][6] = maze[4][7] = maze[5][1] = maze[6][8] = maze[8][5] = '6';
    maze[1][5] = maze[2][8] = maze[3][7] = maze[7][3] = maze[8][6] = '7';
    maze[1][0] = maze[2][6] = maze[8][1] = '8';
    maze[1][8] = maze[2][2] = maze[4][6] = maze[6][7] = maze[7][1] = '9';
    }
}

char Sudoku::mazeAnswer(int ver, int m_r, int m_c) {
    if (ver == 0) {
        int a = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                answer[i][j] = answer1[a];
                a += 1;
            }
        }

        return answer[m_r][m_c];
    }

    if (ver == 1) {
        int a = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                answer[i][j] = answer2[a];
                a += 1;
            }
        }

    return answer[m_r][m_c];
    }
}

void Sudoku::setMaze(int row, int column, char input) {
    maze[row][column] = input;
}
char Sudoku::getMazeValue(int row, int column) {
    return maze[row][column];
}
void Sudoku::print() {

    int a = 0;
    cout << "  012 345 678 " << endl;

    for (int i = 0; i < 9; i++) {
        cout << a << "|";
        a += 1;
        for (int j = 0; j < 9; j++) {
            cout << maze[i][j];
            if (j % 3 == 2) cout << "|";
        }
        cout << endl;
        if (i % 3 == 2) cout << " -------------" << endl;
    }
    cout << "請輸入三個數字 [直排] [橫排] [要輸入的數字] 或輸入 'h' 來獲取提示" << endl;
}

bool Sudoku::mazeCheck() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (maze[i][j] == '.') {
                return true;
                break;
            }
        }
    }


}
