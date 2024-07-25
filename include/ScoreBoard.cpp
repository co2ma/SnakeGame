#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() {
    // 점수 초기화 작업
    scoreWin = newwin(9, 15, 0, MAP_WIDTH*2);
    box(scoreWin, 0, 0);
}

void ScoreBoard::update(int length, int point, int poison, int gate, int currentRound, int timer) {
    // 스코어 보드 업데이트 로직 구현
    mvwprintw(scoreWin, 1, 1, "Score Board");
    mvwprintw(scoreWin, 2, 1, "B: %d / 30", length);
    mvwprintw(scoreWin, 3, 1, "+: %d", point);
    mvwprintw(scoreWin, 4, 1, "-: %d", poison);
    mvwprintw(scoreWin, 5, 1, "G: %d", gate);
    mvwprintw(scoreWin, 6, 1, "Time: %d", timer);
    mvwprintw(scoreWin, 7, 1, "Stage: %d", currentRound);


    wrefresh(scoreWin);
}
