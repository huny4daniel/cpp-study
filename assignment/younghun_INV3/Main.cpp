#include <iostream>
#include <string>
#include <windows.h>
#include "Screen.h"
#include "BoxOffice.h"
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    TUKoreaBox box;
    Screen* screen = NULL;
    bool bScreenMenu = true;
    int select = 0;

    box.Initialize();   // 3개의 스크린 객체 생성

    while (1) {
        if (bScreenMenu) {
            screen = box.selectMenu();
            bScreenMenu = false;
            if (!screen) return 0;
        }
        screen->showMovieMenu();
        cout << "메뉴를 선택하세요(0번 종료): ";
        cin >> select; cout << endl;

        switch (select) {
        case 1: // 영화 정보
            screen->showMovieInfo();
            break;
        case 2: // 좌석 현황
            screen->showSeatMap();
            break;
        case 3: // 좌석 예약
            screen->reserveTicket();
            break;
        case 4: // 예약 취소
            screen->cancelReservation();
            break;
        case 5: // 예약 결제
            screen->processPayment();
            break;
        case 6: // 리뷰 작성
            screen->addReview();
            break;
        case 7: // 리뷰 보기
            screen->showReviews();
            break;
        case 9: // 스크린 메인 메뉴
            bScreenMenu = true;
            break;
        case 0: // 종료
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "번호 확인 후 다시 입력하세요." << endl;
        }

        cout << endl;
    }

    return 0;
}
