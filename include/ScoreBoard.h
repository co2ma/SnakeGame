#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "GameMap.h"
#include "Snake.h"

class ScoreBoard {
public:
    ScoreBoard();
    void update(int length, int point, int poison, int gate, int currentRound, int timer);
    WINDOW *scoreWin;

private:
    // 점수와 관련된 멤버 변수들을 선언할 수 있습니다.
};

#endif 
