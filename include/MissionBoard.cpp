#include "MissionBoard.h"

MissionBoard::MissionBoard() {
    // 미션 초기화 작업
    missionWin = newwin(7, 15, 9, MAP_WIDTH * 2);
    box(missionWin, 0, 0);
    roundClear = false;
}

void MissionBoard::update(int length, int point, int poison, int gate) {
    // 미션 보드 업데이트 로직 구현
    mvwprintw(missionWin, 1, 1, "Mission");
    mvwprintw(missionWin, 2, 1, "B: 10 (%c)", length >= 10 ? 'v' : ' ');
    mvwprintw(missionWin, 3, 1, "+: 5 (%c)", point >= 5 ? 'v' : ' ');
    mvwprintw(missionWin, 4, 1, "-: 2 (%c)", poison >= 2 ? 'v' : ' ');
    mvwprintw(missionWin, 5, 1, "G: 1 (%c)", gate >= 1 ? 'v' : ' ');
    if(length >= 10 && point >= 5 && poison >= 2 && gate >= 1){
        roundClear = true;
    }
    wrefresh(missionWin);
}
