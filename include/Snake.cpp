#include "Snake.h"

// 뱀 관련 초기화
Snake::Snake() {
    srand(time(NULL));
    /*
        int x = (rand() % MAP_WIDTH / 3)*2 + (MAP_WIDTH / 3 * 2);
        int y = (rand() % MAP_HEIGHT / 3) + MAP_HEIGHT / 3;
        player.push_back(p(x,y));
        player.push_back(p(x,y+1));
        player.push_back(p(x,y+2));
        player.push_back(p(x,y+3));
    */
    player.push_back(p(6,14));
    player.push_back(p(6,15));
    player.push_back(p(6,16));
    player.push_back(p(6,17));
    snakeDirection = UP;
    currentLength = 4;
    currentGetPoint = 0;
    currentGetPoison = 0;
    currentUseGate = 0;
    isDead = false;
    isEnter = false;
    count = -1;
}

// 뱀 업데이트 로직 구현
void Snake::update() {
    bool head = true;
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    for(auto& locate : player){
        if(head == true){
            attron(COLOR_PAIR(GREEN));
            mvprintw(locate.second, locate.first, "* ");
            head = false;
            attroff(COLOR_PAIR(GREEN));
        }
        else{
            attron(COLOR_PAIR(YELLOW));
            mvprintw(locate.second, locate.first, "& ");
            attroff(COLOR_PAIR(YELLOW));
        }
    }
}

// 뱀 상호작용 관련 내용
void Snake::snakeOn(){
    if(currentLength < 3) isDead = true;
    inputWait();
    int x = player.front().first;
    int y = player.front().second;

    if(snakeDirection == UP) y -= 1;
    else if(snakeDirection == DOWN) y += 1;
    else if(snakeDirection == RIGHT) x += 2;
    else if(snakeDirection == LEFT) x -= 2;
    
    auto item = mvinch(y, x) & A_CHARTEXT;
    if(item == '#' || item == '&' || item == 'G'){ isDead = true; }
    
    if(item == '('){
        x = portal2.first;
        y = portal2.second;
        portalMove(x, y, item);   
    }
    else if(item == ')'){
        x = portal1.first;
        y = portal1.second;
        portalMove(x, y, item);
    }
    player.push_front(p(x, y));
    if(item == '-'){ 
        poisonItem = {0, 0}; 
        player.pop_back();
        currentLength -= 1;
        currentGetPoison += 1;
    }
    if(item == '+'){ 
        if(currentLength < 30){
            pointItem = {0, 0}; 
            currentLength += 1;
            currentGetPoint += 1;
        }
    }
    else{ 
        player.pop_back();       
    }
    if(count == 0){   
        portal1 = p(0, 0);
        portal2 = p(0, 0);
        count -= 1;   
        isEnter = false;
    } 
    else count -= 1;
}

// 뱀 키보드 입력 대기
void Snake::inputWait(){
    int ch = getch(); // 입력값 기다림
    if (ch == KEY_UP /*&& snakeDirection != DOWN*/) {         // 위쪽 방향키 입력 시
        snakeDirection = UP;
    } 
    else if (ch == KEY_DOWN /*&& snakeDirection != UP*/) {    // 아래쪽 방향키 입력 시
        snakeDirection = DOWN;
    } 
    else if (ch == KEY_LEFT /*&& snakeDirection != RIGHT*/) {    // 왼쪽 방향키 입력 시
        snakeDirection = LEFT;
    } 
    else if (ch == KEY_RIGHT /*&& snakeDirection != LEFT*/) {   // 오른쪽 방향키 입력 시
        snakeDirection = RIGHT;
    }
    while ((getch()) != ERR) {} // 입력 버퍼 날리기
} 

// 뱀 포탈 이동 관련 구현
void Snake::portalMove(int &x, int &y, unsigned int &item){
    
    if(snakeDirection == UP){
        item = mvinch(y-1, x) & A_CHARTEXT;
        if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')' || !(x > 0 && x < MAP_WIDTH*2) || !(y-1 > 0 && y-1 < MAP_HEIGHT)){
            item = mvinch(y, x-2) & A_CHARTEXT;
            if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x-2 > 0 && x-2 < MAP_WIDTH*2) || !(y > 0 && y < MAP_HEIGHT)){
                item = mvinch(y, x+2) & A_CHARTEXT;
                if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x+2 > 0 && x+2 < MAP_WIDTH*2) || !(y > 0 && y < MAP_HEIGHT)){
                    item = mvinch(y+1, x) & A_CHARTEXT;
                    y += 1;
                    snakeDirection = DOWN;
                }
                else{ 
                    x += 2; 
                    snakeDirection = RIGHT;
                }
            }
            else{ 
                x -= 2; 
                snakeDirection = LEFT;
            }
        }
        else{ y -= 1; }
    }
    else if(snakeDirection == DOWN){
        item = mvinch(y+1, x) & A_CHARTEXT;
        if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x > 0 && x < MAP_WIDTH*2) || !(y+1 > 0 && y+1 < MAP_HEIGHT)){
            item = mvinch(y, x+2) & A_CHARTEXT;
            if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x+2 > 0 && x+2 < MAP_WIDTH*2) || !(y > 0 && y < MAP_HEIGHT)){
                item = mvinch(y, x-2) & A_CHARTEXT;
                if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x-2 > 0 && x-2 < MAP_WIDTH*2) || !(y > 0 && y < MAP_HEIGHT)){
                    item = mvinch(y-1, x) & A_CHARTEXT;
                    y -= 1;
                    snakeDirection = UP;
                }
                else{ 
                    x -= 2; 
                    snakeDirection = LEFT;
                }
            }
            else{ 
                x += 2;
                snakeDirection = RIGHT;
            }
        }
        else{ y += 1; }
    }
    else if(snakeDirection == RIGHT){
        item = mvinch(y, x+2) & A_CHARTEXT;
        if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x+2 > 0 && x+2 < MAP_WIDTH*2) || !(y > 0 && y < MAP_HEIGHT)){
            item = mvinch(y-1, x) & A_CHARTEXT;
            if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x > 0 && x < MAP_WIDTH*2) || !(y-1 > 0 && y-1 < MAP_HEIGHT)){
                item = mvinch(y+1, x) & A_CHARTEXT;
                if(item == '#' || item == '&' || item == '^'|| item == '(' || item == ')'  || !(x > 0 && x < MAP_WIDTH*2) || !(y+1 > 0 && y+1 < MAP_HEIGHT)){
                    item = mvinch(y, x-2) & A_CHARTEXT;
                    x -= 2;
                    snakeDirection = LEFT;
                }
                else{ 
                    y += 1; 
                    snakeDirection = DOWN;
                }
            }
            else{ 
                y -= 1; 
                snakeDirection = UP;
            }
        }
        else{ x += 2; }
    }
    else if(snakeDirection == LEFT){
        item = mvinch(y, x-2) & A_CHARTEXT;
        if(item == '#' || item == '&' || item == '^' || item == '(' || item == ')' || !(x-2 > 0 && x-2 < MAP_WIDTH*2) || !(y > 0 && y < MAP_HEIGHT)){
            item = mvinch(y+1, x) & A_CHARTEXT;
            if(item == '#' || item == '&' || item == '^' || item == '(' || item == ')' || !(x > 0 && x < MAP_WIDTH*2) || !(y+1 > 0 && y+1 < MAP_HEIGHT)){
                item = mvinch(y-1, x) & A_CHARTEXT;
                if(item == '#' || item == '&' || item == '^' || item == '(' || item == ')' || !(x > 0 && x < MAP_WIDTH*2) || !(y-1 > 0 && y-1 < MAP_HEIGHT)){
                    item = mvinch(y, x+2) & A_CHARTEXT;
                    x += 2;
                    snakeDirection = RIGHT;
                }
                else{ 
                    y -= 1; 
                    snakeDirection = UP;
                }
            }
            else{
                y += 1; 
                snakeDirection = DOWN;
            }
        }
        else{ x -= 2; }
    }
    
    currentUseGate += 1;
    count = currentLength;
    isEnter = true;
}