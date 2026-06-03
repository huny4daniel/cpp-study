#ifndef BOXOFFICE_H
#define BOXOFFICE_H

#include "Screen.h"

#define BOXOFFICE_MANAGER_PWD "admin"

class BoxOffice {
public:
    virtual Screen* selectMenu() { return NULL; }  // 상영관 선택 메뉴
    void Initialize() {}
};

class TUKoreaBox : public BoxOffice {
    CGVScreen* pCGVScreen;
    LotteCinemaScreen* pLotteCinemaScreen;
    MegaboxScreen* pMegaBoxScreen;
public:
    TUKoreaBox();
    ~TUKoreaBox();
    Screen* selectMenu();
    void Initialize();
    void manage();      // 통계 관리
};

#endif
