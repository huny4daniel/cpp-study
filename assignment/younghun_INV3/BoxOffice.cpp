#include <iostream>
#include <string>
#include "Screen.h"
#include "BoxOffice.h"
#include "Statistics.h"
using namespace std;

TUKoreaBox::TUKoreaBox() {
    pCGVScreen = NULL;
    pLotteCinemaScreen = NULL;
    pMegaBoxScreen = NULL;
}

TUKoreaBox::~TUKoreaBox() {
    if (pCGVScreen) delete pCGVScreen;
    if (pLotteCinemaScreen) delete pLotteCinemaScreen;
    if (pMegaBoxScreen) delete pMegaBoxScreen;
}

// 스크린 객체 생성
void TUKoreaBox::Initialize() {
    // Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
    pCGVScreen = new CGVScreen("샹치와 텐 링즈의 전설", 15000, 8, 8);
    pLotteCinemaScreen = new LotteCinemaScreen("이터널스", 12000, 10, 10);
    pMegaBoxScreen = new MegaboxScreen("스파이더맨: 노 웨이 홈", 20000, 8, 8);
}

// 상영관 선택 메뉴
Screen* TUKoreaBox::selectMenu() {
    int select;
    while (1) {
        cout << "-----------------------------" << endl;
        cout << "    상영관 메인 메뉴" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. CJ CGV        1관" << endl;
        cout << "2. 롯데시네마    2관" << endl;
        cout << "3. 메가박스      3관" << endl;
        cout << "5. 통계관리" << endl;
        cout << endl;
        cout << "선택(1~3, 5) 그외 종료 : ";
        cin >> select;
        cout << endl;

        switch (select) {
        case 1:
            return pCGVScreen;
        case 2:
            return pLotteCinemaScreen;
        case 3:
            return pMegaBoxScreen;
        case 5:
            manage();
            break;          // 통계 출력 후 메인 메뉴 재출력
        default:
            return NULL;    // 그 외 종료
        }
    }
}

// 통계 관리 (관리자 인증 후 매출/판매량 출력)
void TUKoreaBox::manage() {
    string pwd;
    cout << "-----------------------------" << endl;
    cout << "        관리자 메뉴" << endl;
    cout << "-----------------------------" << endl;
    cout << "관리자 비밀번호 입력 : ";
    cin >> pwd;
    cout << endl;

    if (pwd != BOXOFFICE_MANAGER_PWD) {
        cout << "비밀번호가 일치하지 않습니다." << endl;
        return;
    }

    int total = Statistics::totalSalesCount(pCGVScreen)
        + Statistics::totalSalesCount(pLotteCinemaScreen)
        + Statistics::totalSalesCount(pMegaBoxScreen);

    cout << "1. CJ CGV 상영관 결제금액 : " << Statistics::totalRevenue(pCGVScreen) << endl;
    cout << "2. 롯데시네마 상영관 결제금액 : " << Statistics::totalRevenue(pLotteCinemaScreen) << endl;
    cout << "3. 메가박스 상영관 결제금액 : " << Statistics::totalRevenue(pMegaBoxScreen) << endl;
    cout << "4. 전체 티켓 판매량 : " << total << endl;
}
