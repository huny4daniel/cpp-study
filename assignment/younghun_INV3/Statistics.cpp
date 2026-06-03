#include "Statistics.h"
#include "Ticket.h"

// 스크린 관의 티켓 결제 금액 총액 (결제 완료된 좌석만 합산)
int Statistics::totalRevenue(Screen* pScreen) {
    int sum = 0;
    int rowMax = pScreen->getRowMax();
    int colMax = pScreen->getColMax();
    Ticket** seats = pScreen->getTicketArray();

    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if (seats[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                sum += seats[i][j].getPayAmount();
            }
        }
    }
    return sum;
}

// 스크린 관의 티켓 판매량 (결제 완료된 좌석 개수)
int Statistics::totalSalesCount(Screen* pScreen) {
    int count = 0;
    int rowMax = pScreen->getRowMax();
    int colMax = pScreen->getColMax();
    Ticket** seats = pScreen->getTicketArray();

    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if (seats[i][j].getCheck() == SEAT_COMPLETION_MARK) {
                count++;
            }
        }
    }
    return count;
}
