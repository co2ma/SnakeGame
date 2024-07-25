#ifndef GAME_H
#define GAME_H

#include "ScoreBoard.h"
#include "MissionBoard.h"
#include "GameMap.h"
#include "Snake.h"
#include "Item.h"
#include <chrono>


class Game {
public:
    Game();
    ~Game();
    void start();
    void init();
    void deleteAll();
    void gameOn(int round);

private:
    ScoreBoard *scoreBoard;
    MissionBoard *missionBoard;
    GameMap *gameMap;
    Snake *snake;
    Item *item;
    bool gameOver;
    int roundOver;
    int currentRound;
    int timer;
    int count;
};

#endif 
