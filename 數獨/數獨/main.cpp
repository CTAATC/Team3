#include "Sudoku.h"
#include "Player.h"
#include "Leaderboard.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// 提示功能示例
void giveHint(Sudoku& Sudoku1, Player& player, int ver) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (Sudoku1.getMazeValue(i, j) == '.') {
                cout << "Hint: [" << i << "][" << j << "] = " << Sudoku1.mazeAnswer(ver, i, j) << endl;
                player.decreaseHealth();  // 每提示一次扣一次生命值
                return;
            }
        }
    }
}

int main() {
    int ver, m_r, m_c;
    char input_answer;
    string playerName;
    srand(time(NULL));
    ver = rand() % 2;

    Player player(playerName, 0, 3); // 創建玩家物件，初始分數為0，健康狀態為3
    Sudoku Sudoku1(ver);

    // 紀錄遊戲開始時間
    auto start_time = chrono::high_resolution_clock::now();
    int mistakes = 0;
    char command;

    // 若生命數不等於0而且還有未填完的空格時繼續讓玩家輸入答案
    while (player.getHealth() != 0 && Sudoku1.mazeCheck() == true) {
        player.printHealth();
        Sudoku1.print();
        cin >> command;
        if (command == 'h') {
            giveHint(Sudoku1, player, ver);
            continue;
        }
        else {
            cin.putback(command);
            cin >> m_r >> m_c >> input_answer;
            if (input_answer != Sudoku1.mazeAnswer(ver, m_r, m_c)) {
                player.decreaseHealth();
                mistakes++;
            }
            else {
                Sudoku1.setMaze(m_r, m_c, input_answer);
            }
        }
    }

    bool gameCompleted = (player.getHealth() != 0 && Sudoku1.mazeCheck() != true);

    if (!gameCompleted) {
        cout << "You lose." << endl;
    }
    else {
        cout << "Congratulations, you won!" << endl;
    }

    // 記錄遊戲結束時間
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;
    int minutes = static_cast<int>(elapsed.count() / 60);
    int seconds = static_cast<int>(elapsed.count()) % 60;

    cout << "遊戲時間: " << setw(2) << setfill('0') << minutes << " 分 "
        << setw(2) << setfill('0') << seconds << " 秒" << endl;

    // 請求玩家輸入名字
    cout << "請輸入你的名字: ";
    cin >> playerName;

    // 保存玩家信息到排行榜
    vector<Player> leaderboard = Leaderboard::loadLeaderboard();
    leaderboard.push_back(Player(playerName, static_cast<int>(elapsed.count()), player.getHealth()));
    sort(leaderboard.begin(), leaderboard.end());
    Leaderboard::savePlayerInfo(leaderboard);

    // 顯示排行榜
    Leaderboard::displayLeaderboard(leaderboard);

    return 0;
}
