#ifndef ITEM_H
#define ITEM_H

#include "GameMap.h"

class Item : public GameMap {
public:
    Item();
    void update();
    void itemOn(bool isEnter);
private:
    int itemDelay; //설정한 시간 x delay 만큼 의 시간 지연
    bool checkDup(vector<int>& datas, int x, int y); //중복 확인 검사 아이템 안겹치게
};

#endif 