#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include "Ticket.h"
#include "PayStrategy.h"
#include "Review.h"
#include "SortStrategy.h"
using namespace std;

class Screen {
protected:
    int nTicketPrice;           // 티켓 가격
    int nRowMax, nColMax;       // 좌석 행과 열 최대 값
    int nCurrentReservedId;     // 발급된 마지막 예약 번호 : 100번부터 시작
    Ticket** pSeatArray;       // 스크린 좌석에 대한 티켓 배열
    string strMovieName;        // 스크린 상영중인 영화 제목

    PayStrategy* payStrategy;   // 결제 전략
    SortStrategy* sortStrategy; // 리뷰 정렬 전략
    vector<Review> reviewList;  // 상영관 영화 리뷰 목록
public:
    Screen(string name, int price, int row, int col);
    ~Screen();
    void showSeatMap();                 // 좌석 예약 여부 맵으로 보기
    virtual void showMovieMenu();       // 영화 예매 메뉴
    void reserveTicket();               // 좌석 예약하기
    void cancelReservation();           // 좌석 예약 취소하기
    virtual void showMovieInfo() = 0;   // 영화 소개 정보

    // 추가 기능 1 : 티켓 결제
    int getTicketPrice() { return nTicketPrice; }       // 결제를 위해 티켓 가격 읽기
    void setPayStrategy(PayStrategy* payStrategy);      // 결제 전략 선택
    void processPayment();                              // 결제 하기

    // 추가 기능 2, 3 : 리뷰 작성, 출력
    void setSortStrategy(SortStrategy* sortStrategy);   // 리뷰 정렬 전략 교체
    void addReview();                                   // 리뷰 작성
    void showReviews();                                 // 리뷰 출력

    // 추가 기능 4 : 통계 관리
    int getRowMax() { return nRowMax; }
    int getColMax() { return nColMax; }
    Ticket** getTicketArray() { return pSeatArray; }
};

class CGVScreen : public Screen {
public:
    CGVScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
    void showMovieInfo();
};

class LotteCinemaScreen : public Screen {
public:
    LotteCinemaScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
    void showMovieInfo();
};

class MegaboxScreen : public Screen {
public:
    MegaboxScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
    void showMovieInfo();
};

#endif
