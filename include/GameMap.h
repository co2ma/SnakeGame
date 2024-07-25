#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <ncurses.h>
#include <utility>
#include <deque>

using namespace std;

typedef pair<int, int> p;

const int MAP_WIDTH = 22;
const int MAP_HEIGHT = 22;

class GameMap {
public:
    GameMap();
    ~GameMap();
    void update(const int currentRound);
    void createMap();
    void itemOn();
    static deque <p> player; //뱀의 좌표들을 담고 있는 deque 자료형
    static p pointItem; // 점수 아이템의 위치를 담고 있는 pair
    static p poisonItem; // 독 아이템의 위치를 담고 있는 pair
    static p portal1; // 포탈1번 아이템의 위치를 담고 있는 pair
    static p portal2; // 포탈2번 아이템의 위치를 담고 있는 pair
    static p deadItem; // 추가사항 : 먹으면 죽는 아이템
    

protected:
    WINDOW *gameWin;
    enum Color {ZERO, RED, WHITE, GREEN, YELLOW, CYAN, MAGENTA, BLUE, BLACK};
    int snakeDirection;
};

#endif
