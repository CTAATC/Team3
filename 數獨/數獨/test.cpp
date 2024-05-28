#include "Sudoku.h"
#include "Health.h"
#include "player.h" 
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int calculateScore(double timeSpent, int mistakes, bool gameCompleted) {
    if (!gameCompleted) {
        return 0; // 如果遊戲未完成,分數為0分
    }
    int baseScore = 1000;  // 基礎分數
    int timePenalty = static_cast<int>(timeSpent * 1);  //每秒少1分
    int mistakePenalty = mistakes * 50;  // 每次錯誤扣10分
    int score = baseScore - timePenalty - mistakePenalty;
    return score > 0 ? score : 0;  // 分數最小值為0分
}

// 提示功能示例
void giveHint(Sudoku& Sudoku1, int ver) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (Sudoku1.getMazeValue(i, j) == 0) {
                cout << "Hint: [" << i << "][" << j << "] = " << Sudoku1.mazeAnswer(ver, i, j) << endl;
                return;
            }
        }
    }
}

int main() {
    int ver, m_r, m_c, input_answer;
    string playerName;
    srand(time(NULL));
    ver = rand() % 1;

    Health Health1;
    Sudoku Sudoku1(ver);

    // 紀錄遊戲開始時間
    auto start_time = chrono::high_resolution_clock::now();
    int mistakes = 0;
    char command;

    while (Health1.getHealth() != 0 && Sudoku1.mazeCheck() == true) {
        Health1.printHealth();
        Sudoku1.print();
        cin >> command;
        if (command == 'h') {
            giveHint(Sudoku1, ver);
            continue;
        }
        else {
            cin.putback(command);
            cin >> m_r >> m_c >> input_answer;
            if (input_answer != Sudoku1.mazeAnswer(ver, m_r, m_c)) {
                Health1.decreaseHealth();
                mistakes++;
            }
            else {
                Sudoku1.setMaze(m_r, m_c, input_answer);
            }
        }
    }


    if (Health1.getHealth() == 0)
        cout << "You lose." << endl;
    else if (Sudoku1.mazeCheck() != true)
        cout << "Congratulation, you won!" << endl;

    // 記錄遊戲結束時間
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    int minutes = static_cast<int>(elapsed.count() / 60);
    int seconds = static_cast<int>(static_cast<int>(elapsed.count()) % 60);
    bool gameCompleted = (Health1.getHealth() != 0 && Sudoku1.mazeCheck() != true);

    cout << "遊戲時間: " << setw(2) << setfill('0') << static_cast<int>(minutes) << " 分 " << setw(2) << setfill('0') << static_cast<int>(seconds) << " 秒" << endl;

    // 計算分數
    int score = calculateScore(elapsed.count(), mistakes, gameCompleted);
    cout << "你的分數是: " << score << endl;

    // 請求玩家輸入名字
    cout << "請輸入你的名字: ";
    cin >> playerName;

    // 保存玩家信息到排行榜
    vector<PlayerInfo> leaderboard = loadLeaderboard();
    leaderboard.push_back({ playerName, score });
    sort(leaderboard.begin(), leaderboard.end());
    savePlayerInfo(leaderboard);

    // 顯示排行榜
    displayLeaderboard(leaderboard);

    return 0;
}
