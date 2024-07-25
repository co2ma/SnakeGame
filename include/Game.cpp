#include "Game.h"

Game::Game() {
    // 게임 초기화 작업
    initscr(); //ncurses 초기화
    cbreak(); //키 입력을 받도록 설정
    noecho(); //키 입력시 문자 안보이게
    keypad(stdscr, TRUE); //화살표키 사용 설정
    curs_set(0); //커서를 화면에 보이지 않게 하기
    nodelay(stdscr, true); //입력 대기 없이 입력 값 없으면 무시
    start_color(); //색상 사용을 선언
    gameOver = false; //게임 오버를 확인 하는 변수
    roundOver = false;
    currentRound = 1;
    timer = 0;
    count = 0;
}

Game::~Game(){
}


void Game::start() {
    mvprintw(5, 5, "GAME START : PRESS ANY KEY");
    mvprintw(8, 5, "Control: Direction key");
    mvprintw(10, 5, "Green + Yellow : Player");
    mvprintw(11, 5, "Cyan : PointItem");
    mvprintw(12, 5, "Magenta : PoisonItem");
    mvprintw(13, 5, "Blue : Portal");
    mvprintw(14, 5, "Black & RED : GAME OVER");


    while ((getch()) == ERR) {}
    for(int i = 1; i <= 4; i++){
        gameOn(i);
    }
    if(gameOver){
        mvprintw(5, 5, "GAME OVER : PRESS ANY KEY");
        while ((getch()) == ERR) {} 
    }
    else{
        mvprintw(5, 5, "GAME CLEAR : PRESS ANY KEY");
        while ((getch()) == ERR) {} 
    }
    endwin();
}

void Game::init(){
    scoreBoard = new ScoreBoard();
    missionBoard = new MissionBoard();
    gameMap = new GameMap();
    snake = new Snake();
    item = new Item();
}

void Game::deleteAll(){
    delete scoreBoard;
    delete missionBoard;
    delete gameMap;
    delete snake;
    delete item;
}

void Game::gameOn(int round){
    init();
    // 게임 루프 및 이벤트 처리 등의 로직 
    const auto delta_time = chrono::milliseconds(200);
    auto before = chrono::steady_clock::now();
    while (!gameOver && !roundOver) {
        const auto now = chrono::steady_clock::now();
        scoreBoard->update(snake->getCurrentLength(), snake->getCurrentGetPoint(), snake->getCurrentGetPoison(), snake->getCurrentUseGate() ,currentRound, timer);  // 스코어 보드 업데이트
        missionBoard->update(snake->getCurrentLength(), snake->getCurrentGetPoint(), snake->getCurrentGetPoison(), snake->getCurrentUseGate());  // 미션 보드 업데이트
        gameMap->update(currentRound);  // 게임 맵 업데이트
        snake->update();  // 뱀 업데이트
        item->update();  // 아이템 업데이트
        if((now - before) >= delta_time){
            snake->snakeOn();
            item->itemOn(snake->getIsEnter());
            before = now;
            if(count == 4){
                timer += 1;
                count = 0;
            } else count += 1;
        }
        refresh();
        gameOver = snake->getIsDead(); // 뱀이 죽어 있으면 반복 중단   
        roundOver = missionBoard->getRoundClear();
    }
    roundOver = false;
    currentRound += 1;
    deleteAll();
}