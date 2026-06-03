#include <iostream>
#include <string>
#include "Screen.h"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {
    strMovieName = name;
    nRowMax = row;
    nColMax = col;
    nTicketPrice = price;
    pSeatArray = new Ticket * [nRowMax];
    for (int r = 0; r < nRowMax; r++) {
        pSeatArray[r] = new Ticket[nColMax];
    }
    for (int i = 0; i < nRowMax; i++) {
        for (int j = 0; j < nColMax; j++) {
            pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
        }
    }
    nCurrentReservedId = 100;       // 예약 번호 100번부터 시작
    payStrategy = NULL;
    sortStrategy = new LatestSort(); // 기본 정렬 : 최신순
}

Screen::~Screen() {
    for (int r = 0; r < nRowMax; r++) {
        delete[] pSeatArray[r];
    }
    delete[] pSeatArray;
    if (payStrategy) delete payStrategy;
    if (sortStrategy) delete sortStrategy;
}

// 좌석 예약 현황 맵 출력
void Screen::showSeatMap() {
    cout << "    [ 좌석 예약 현황 ]" << endl;
    cout << "    ";
    for (int c = 1; c <= nColMax; c++) {
        cout << "[" << c << "] ";
    }
    cout << endl;
    for (int i = 0; i < nRowMax; i++) {
        cout << "[" << (i + 1) << "] ";
        for (int j = 0; j < nColMax; j++) {
            cout << "[" << pSeatArray[i][j].getCheck() << "] ";
        }
        cout << endl;
    }
}

// 영화 예매 메뉴
void Screen::showMovieMenu() {
    cout << "-----------------------------" << endl;
    cout << " 메뉴 : " << strMovieName << endl;
    cout << "-----------------------------" << endl;
    cout << "1. 영화 정보" << endl;
    cout << "2. 예약 현황" << endl;
    cout << "3. 좌석 예약" << endl;
    cout << "4. 예약 취소" << endl;
    cout << "5. 예약 결제" << endl;
    cout << "6. 리뷰 작성" << endl;
    cout << "7. 리뷰 보기" << endl;
    cout << "9. 메인 메뉴 이동" << endl;
    cout << endl;
}

// 좌석 예약하기
void Screen::reserveTicket() {
    int row, col;
    cout << "    [ 좌석 예약 ]" << endl;
    cout << "좌석 행 번호 입력(1 - " << nRowMax << ") : ";
    cin >> row;
    cout << "좌석 열 번호 입력(1 - " << nColMax << ") : ";
    cin >> col;

    if (row < 1 || row > nRowMax || col < 1 || col > nColMax) {
        cout << "잘못된 좌석 번호입니다." << endl;
        return;
    }

    Ticket& seat = pSeatArray[row - 1][col - 1];
    if (seat.getCheck() != SEAT_EMPTY_MARK) {
        cout << "이미 예약된 좌석입니다." << endl;
        return;
    }

    seat.setCheck(SEAT_RESERVED_MARK);
    seat.setSeat(row, col);
    seat.setReservedID(nCurrentReservedId);
    cout << "행[" << row << "] 열[" << col << "] " << nCurrentReservedId
        << " 예약 번호로 접수되었습니다." << endl;
    nCurrentReservedId++;
}

// 좌석 예약 취소하기 (결제 후 취소 불가)
void Screen::cancelReservation() {
    int id;
    cout << "    [ 좌석 예약 취소]" << endl;
    cout << "예약 번호 입력 : ";
    cin >> id;

    for (int i = 0; i < nRowMax; i++) {
        for (int j = 0; j < nColMax; j++) {
            Ticket& seat = pSeatArray[i][j];
            if (seat.getCheck() != SEAT_EMPTY_MARK && seat.getReservedID() == id) {
                if (seat.getCheck() == SEAT_COMPLETION_MARK) {
                    cout << "결제가 완료된 예약은 취소할 수 없습니다." << endl;
                    return;
                }
                seat.setCheck(SEAT_EMPTY_MARK);
                cout << id << " 예약 번호가 취소 처리되었습니다." << endl;
                return;
            }
        }
    }
    cout << "해당 예약 번호를 찾을 수 없습니다." << endl;
}

// 결제 전략 선택
void Screen::setPayStrategy(PayStrategy* strategy) {
    if (payStrategy) delete payStrategy;
    payStrategy = strategy;
}

// 결제 하기
void Screen::processPayment() {
    int id;
    cout << "    [ 좌석 예약 결제]" << endl;
    cout << "예약 번호 입력 : ";
    cin >> id;

    Ticket* target = NULL;
    for (int i = 0; i < nRowMax && !target; i++) {
        for (int j = 0; j < nColMax; j++) {
            if (pSeatArray[i][j].getReservedID() == id &&
                pSeatArray[i][j].getCheck() == SEAT_RESERVED_MARK) {
                target = &pSeatArray[i][j];
                break;
            }
        }
    }

    if (!target) {
        cout << "결제할 수 있는 예약 번호가 아닙니다." << endl;
        return;
    }

    cout << "-----------------------------" << endl;
    cout << "        결제 방식 선택" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. KakaoPay" << endl;
    cout << "2. ApplePay" << endl;
    cout << "3. SamsungPay" << endl;
    cout << endl;
    cout << "결제 방식(1~3) : ";

    int pay;
    cin >> pay;

    string payName;
    switch (pay) {
    case KAKAOPAY_PAYMENT:
        setPayStrategy(new CardPay(KAKAOPAY_INTEREST_RATE));
        payName = "KakaoPay";
        break;
    case APPLEPAY_PAYMENT:
        setPayStrategy(new ApplePay(APPLEPAY_INTEREST_RATE));
        payName = "ApplePay";
        break;
    case SAMSUNGPAY_PAYMENT:
        setPayStrategy(new SamsungPay(SAMSUNGPAY_INTEREST_RATE));
        payName = "SamsungPay";
        break;
    default:
        cout << "잘못된 결제 방식입니다." << endl;
        return;
    }

    int amount = payStrategy->charge(getTicketPrice());
    target->setCheck(SEAT_COMPLETION_MARK);
    target->setPayAmount(amount);
    target->setPayment(pay);
    cout << endl;
    cout << payName << " 결제가 완료되었습니다. : " << amount << endl;
}

// 리뷰 정렬 전략 교체
void Screen::setSortStrategy(SortStrategy* strategy) {
    if (sortStrategy) delete sortStrategy;
    sortStrategy = strategy;
}

// 리뷰 작성
void Screen::addReview() {
    string author, content;
    int score;

    cout << "-----------------------------" << endl;
    cout << " " << strMovieName << " 영화 후기 작성" << endl;
    cout << "-----------------------------" << endl;

    cin.ignore();
    cout << "이름 : ";
    getline(cin, author);
    cout << "한줄평 : ";
    getline(cin, content);
    cout << "평점 (1~5점) : ";
    cin >> score;

    reviewList.push_back(Review(author, content, score));
    cout << "후기가 등록되었습니다!" << endl;
}

// 리뷰 출력
void Screen::showReviews() {
    cout << "-----------------------------" << endl;
    cout << " " << strMovieName << " 영화 평점 및 후기" << endl;
    cout << "-----------------------------" << endl;
    cout << "    [ 정렬 조건 선택 ]" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. 최신 등록순" << endl;
    cout << "2. 평점 높은순" << endl;
    cout << "3. 평점 낮은순" << endl;
    cout << "원하는 정렬 방식을 선택하세요: ";

    int sel;
    cin >> sel;

    string sortName;
    switch (sel) {
    case 2:
        setSortStrategy(new HighScoreSort());
        sortName = "평점 높은순";
        break;
    case 3:
        setSortStrategy(new LowScoreSort());
        sortName = "평점 낮은순";
        break;
    case 1:
    default:
        setSortStrategy(new LatestSort());
        sortName = "최신순";
        break;
    }

    cout << "-> 정렬 기준이 [" << sortName << "]으로 변경되었습니다." << endl;
    cout << endl;

    // 원본(reviewList)은 삽입 순서를 유지하고 복사본을 정렬해 출력
    vector<Review> sorted = reviewList;
    sortStrategy->sortReviews(sorted);
    for (int i = 0; i < (int)sorted.size(); i++) {
        sorted[i].showReview();
    }
}

// 영화 소개 정보
void CGVScreen::showMovieInfo() {
    cout << "-----------------------------" << endl;
    cout << "[ " << strMovieName << " ]" << endl;
    cout << "-----------------------------" << endl;
    cout << "상영관 : CGV IMAX 1관" << endl;
    cout << "주인공 : 시무 리우, 토니 청" << endl;
    cout << "줄거리 : 전설적인 텐 링즈 조직에 맞서 싸우게 된 샹치의 ..." << endl;
    cout << "가격 : " << nTicketPrice << endl;
}

void LotteCinemaScreen::showMovieInfo() {
    cout << "-----------------------------" << endl;
    cout << "[ " << strMovieName << " ]" << endl;
    cout << "-----------------------------" << endl;
    cout << "상영관 : 롯데시네마 SUPER PLEX 2관" << endl;
    cout << "주인공 : 젬마 찬, 리처드 매든" << endl;
    cout << "줄거리 : 수천 년 전 지구에 파견된 영원불멸의 존재 이터널스가 ..." << endl;
    cout << "가격 : " << nTicketPrice << endl;
}

void MegaboxScreen::showMovieInfo() {
    cout << "-----------------------------" << endl;
    cout << "[ " << strMovieName << " ]" << endl;
    cout << "-----------------------------" << endl;
    cout << "상영관 : 메가박스 The Boutique 3관" << endl;
    cout << "주인공 : 톰 홀랜드, 젠다야" << endl;
    cout << "줄거리 : 정체가 밝혀진 스파이더맨 피터 파커는 모든 것을 되돌리기 위해 ..." << endl;
    cout << "가격 : " << nTicketPrice << endl;
}
