#include "Leaderboard.h"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void Leaderboard::savePlayerInfo(const vector<Player>& leaderboard) {
    ofstream file("leaderboard.txt");
    if (!file.is_open()) {
        cerr << "無法打開排行榜文件！" << endl;
        return;
    }

    for (const auto& player : leaderboard) {
        file << player.getName() << " " << player.getScore() << " " << player.getHealth() << endl;
    }

    cout << "排行榜已保存到 leaderboard.txt 文件中。" << endl;
}

vector<Player> Leaderboard::loadLeaderboard() {
    vector<Player> leaderboard;
    ifstream file("leaderboard.txt");
    if (!file.is_open()) {
        cerr << "無法加載排行榜文件！" << endl;
        return leaderboard;
    }

    string name;
    int score, health;
    while (file >> name >> score >> health) {
        Player player(name, score, health);
        leaderboard.push_back(player);
    }

    return leaderboard;
}

void Leaderboard::displayLeaderboard(const vector<Player>& leaderboard) {
    cout << "排行榜：" << endl;
    int rank = 1;
    for (const auto& player : leaderboard) {
        cout << rank << ". " << player.getName() << " - 花費時間: " << player.getScore() << " 秒 - 剩餘生命: " << player.getHealth() << endl;
        rank++;
    }
}
