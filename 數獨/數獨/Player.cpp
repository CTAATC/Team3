#include "player.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// 保存玩家信息到文件
void savePlayerInfo(const vector<PlayerInfo>& leaderboard) {
    ofstream file("leaderboard.txt");
    if (!file) {
        cerr << "無法打開排行榜文件！" << endl;
        return;
    }

    for (const auto& player : leaderboard) {
        file << player.name << " " << player.score << endl;
    }

    cout << "排行榜已保存到 leaderboard.txt 文件中。" << std::endl;
}

// 從文件加載排行榜
    vector<PlayerInfo> loadLeaderboard() {
    vector<PlayerInfo> leaderboard;
    ifstream file("leaderboard.txt");
    if (!file) {
        cerr << "無法加載排行榜文件！" << endl;
        return leaderboard;
    }

    std::string name;
    int score;
    while (file >> name >> score) {
        leaderboard.push_back({ name, score });
    }

    return leaderboard;
}

// 顯示排行榜
void displayLeaderboard(const vector<PlayerInfo>& leaderboard) {
    cout << "排行榜：" << endl;
    int rank = 1;
    for (const auto& player : leaderboard) {
        cout << rank << ". " << player.name << " - " << player.score << " 分" << endl;
        rank++;
    }
}
