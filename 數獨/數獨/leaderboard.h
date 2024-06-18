#ifndef LEADERBOARD_H
#define LEADERBOARD_H
using namespace std;

#include "Player.h"
#include <vector>

class Leaderboard {
public:
    // 保存玩家信息到文件
    static void savePlayerInfo(const  vector<Player>& leaderboard);

    // 從文件加載排行榜
    static vector<Player> loadLeaderboard();

    // 顯示排行榜
    static void displayLeaderboard(const  vector<Player>& leaderboard);
};

#endif // LEADERBOARD_H
