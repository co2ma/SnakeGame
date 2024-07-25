#include "GameMap.h"

deque<p> GameMap::player; // 스태틱 변수 초기화
p GameMap::pointItem;
p GameMap::poisonItem;
p GameMap::portal1;
p GameMap::portal2;
p GameMap::deadItem;

GameMap::GameMap(){
    // 게임 맵 초기 작업
}

GameMap::~GameMap(){ 
    // delete 할때 마다 static 변수 초기화
    player.clear();
    pointItem = p(0, 0);
    poisonItem = p(0, 0);
    portal1 = p(0, 0);
    portal2 = p(0, 0);
    deadItem = p(0, 0);
}

void GameMap::update(const int currentRound) { //맵 업데이트
    init_pair(RED, COLOR_RED, COLOR_RED);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    for(int y=0; y<MAP_HEIGHT; y++){    
        for(int x=0; x<MAP_WIDTH*2; x+=2){
            if(y==0||y==MAP_HEIGHT-1||x==0||x==MAP_WIDTH*2-2){
                if((x==0 && y==0) || (x==0 && y==MAP_HEIGHT-1) || (x==MAP_WIDTH*2-2 && y==0) || (x==MAP_WIDTH*2-2 && y==MAP_HEIGHT-1)){
                    attron(COLOR_PAIR(RED));
                    mvprintw(y, x, "^ ");
                    attroff(COLOR_PAIR(RED));
                }
                else{
                    attron(COLOR_PAIR(RED));
                    mvprintw(y, x, "# ");
                    attroff(COLOR_PAIR(RED));
                }
            }
            else{
                attron(COLOR_PAIR(WHITE));
                mvprintw(y, x, "@ ");
                attroff(COLOR_PAIR(WHITE));
            }
        }
    }
    if(currentRound == 2){
        attron(COLOR_PAIR(RED));
        mvprintw(MAP_HEIGHT/2, MAP_WIDTH/2-1 , "# # # # # # # # # # ");
        attroff(COLOR_PAIR(RED));
    }
    else if(currentRound == 3){
        attron(COLOR_PAIR(RED));
        mvprintw(MAP_HEIGHT/2/2, MAP_WIDTH/2-1 , "# # # # # # # # # # ");
        mvprintw(MAP_HEIGHT/2, MAP_WIDTH/2-1 , "# # # # # # # # # # ");
        mvprintw(MAP_HEIGHT/2 + MAP_HEIGHT/2/2, MAP_WIDTH/2-1 , "# # # # # # # # # # ");
        attroff(COLOR_PAIR(RED));
    }
    else if(currentRound == 4){
        attron(COLOR_PAIR(RED));
        for(int i = MAP_HEIGHT/2/2; i < MAP_HEIGHT/2/2 + 10; i++){
            mvprintw(i, MAP_WIDTH, "# ");
        }
        mvprintw(MAP_HEIGHT/2, MAP_WIDTH/2-1 , "# # # # # # # # # # ");
        attroff(COLOR_PAIR(RED));
    }
}
