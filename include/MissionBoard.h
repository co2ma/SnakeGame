#ifndef MISSIONBOARD_H
#define MISSIONBOARD_H

#include "GameMap.h"

class MissionBoard {
public:
    MissionBoard();
    void update(int length, int point, int poison, int gate);
    WINDOW *missionWin;
    bool getRoundClear() { return roundClear; }
private:
    // 미션과 관련된 멤버 변수들을 선언할 수 있습니다.
    bool roundClear;
};

#endif 
