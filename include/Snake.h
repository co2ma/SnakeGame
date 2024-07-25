#ifndef SNAKE_H
#define SNAKE_H

#include "GameMap.h"

enum DIRECTION{UP, RIGHT, DOWN, LEFT};



class Snake : public GameMap {
public:
    Snake();
    void update();
    void snakeOn();
    void inputWait();
    bool getIsDead(){ return isDead; }
    int getCurrentLength() { return currentLength; }
    int getCurrentGetPoint() { return currentGetPoint; }
    int getCurrentGetPoison() { return currentGetPoison; }
    int getCurrentUseGate() { return currentUseGate; }
    void setIsEnter() { isEnter = false; }
    bool getIsEnter() { return isEnter; }

private:
    int x, y; //뱀의 x, y 좌표 값
    bool isDead; //뱀이 살아있는지 확인
    void portalMove(int &x, int &y, unsigned int &item);
    int currentLength;
    int currentGetPoint;
    int currentGetPoison;
    int currentUseGate; 
    int count;
    bool isEnter;
};

#endif
