#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
using namespace std;
struct PlayerInfo {
    string name;
    int score;

    PlayerInfo(const string& n, int s) : name(n), score(s) {}

    
    bool operator<(const PlayerInfo& other) const {
        return score > other.score; // 分數高的排前面
    }
};

// 保存玩家信息
void savePlayerInfo(const std::vector<PlayerInfo>& leaderboard);

// 加載排行榜
std::vector<PlayerInfo> loadLeaderboard();

// 顯示排行榜
void displayLeaderboard(const std::vector<PlayerInfo>& leaderboard);

#endif 
