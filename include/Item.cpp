#include "Item.h"

// 아이템 초기화
Item::Item() {
    srand(time(NULL));
    itemDelay = 0;
}

// 아이템 위치 업데이트
void Item::update() {
    init_pair(CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    if(!(pointItem.first == 0 || pointItem.second == 0)){
        attron(COLOR_PAIR(CYAN));
        mvprintw(pointItem.second, pointItem.first, "+ ");
        attroff(COLOR_PAIR(CYAN));
    }
    if(!(poisonItem.second == 0 || poisonItem.first == 0)){
        attron(COLOR_PAIR(MAGENTA));
        mvprintw(poisonItem.second, poisonItem.first, "- ");
        attroff(COLOR_PAIR(MAGENTA));
    }
    if(!(deadItem.second == 0 || deadItem.first == 0)){
        attron(COLOR_PAIR(BLACK));
        mvprintw(deadItem.second, deadItem.first, "G ");
        attroff(COLOR_PAIR(BLACK));
    }
    if(!(portal1.second == 0 && portal1.first == 0)){
        attron(COLOR_PAIR(BLUE));
        mvprintw(portal1.second, portal1.first, "( ");
        attroff(COLOR_PAIR(BLUE));
    }
    if(!(portal2.second == 0 && portal2.first == 0)){
        attron(COLOR_PAIR(BLUE));
        mvprintw(portal2.second, portal2.first, ") ");
        attroff(COLOR_PAIR(BLUE));
    }
}

// 아이템 좌표 설정
void Item::itemOn(bool isEnter) {
    vector <int> datas;
    if(itemDelay % 20 == 0){    
        while(true){
            int x = (rand() % (MAP_WIDTH-2))*2 + 2;
            int y = (rand() % (MAP_HEIGHT-2)) + 1;
            if(checkDup(datas, x, y)) continue;
            auto item = mvinch(y, x) & A_CHARTEXT;
            if(item != '&' && item != '*' && item != '#'){
                pointItem = p(x,y);
                break;
            }
        }
    } // 점수 아이템 구현
    if(itemDelay % 20 == 0){
        while(true){
            int x = (rand() % (MAP_WIDTH-2))*2 + 2;
            int y = (rand() % (MAP_HEIGHT-2)) + 1;
            if(checkDup(datas, x, y)) continue;
            auto item = mvinch(y, x) & A_CHARTEXT;
            if(item != '&' && item != '*' && item != '#'){
                poisonItem = p(x,y);
                break;
            }
        }   
    } // 독 아이템 구현
    if(itemDelay % 20 == 0){
        while(true){
            int x = (rand() % (MAP_WIDTH-2))*2 + 2;
            int y = (rand() % (MAP_HEIGHT-2)) + 1;
            if(checkDup(datas, x, y)) continue;
            auto item = mvinch(y, x) & A_CHARTEXT;
            if(item != '&' && item != '*' && item != '#'){
                deadItem = p(x,y);
                break;
            }
        }   
    } // 즉시 gameOver 아이템 구현
    if(itemDelay >= 40 && !isEnter){
        while(true){
            int x = (rand() % MAP_WIDTH) * 2 ;
            int y = rand() % MAP_HEIGHT;
            auto item = mvinch(y, x) & A_CHARTEXT;
            if(item == '#'){
                portal1 = p(x,y);
                break;
            }
        }   
        while(true){
            int x = (rand() % MAP_WIDTH) * 2 ;
            int y = rand() % MAP_HEIGHT;
            auto item = mvinch(y, x) & A_CHARTEXT;
            if(item == '#'){
                portal2 = p(x,y);
                break;
            }
        }       
        itemDelay = 1;
    } //포탈 생성 메커니즘 
    else itemDelay += 1;
    
}

// 좌표 중복 검사 함수
bool Item::checkDup(vector<int>& datas, int x, int y){
    bool dupl = false;
    for(auto k : datas){
        if(k == x || k == y){
            dupl = true;
            break;
        }
    }
    if(dupl) return true;
    datas.push_back(x);
    datas.push_back(y);
    return false;
}