#ifndef TICKET_H
#define TICKET_H

#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
    int nRow;           // 좌석 행
    int nCol;           // 좌석 열
    char charCheck;     // 예약 여부
    int nReservedID;    // 예약 번호
    int nPayAmount;     // 결제 금액
    int nPayment;       // 결제 수단
public:
    Ticket() {}
    void setCheck(char check) { charCheck = check; }
    char getCheck() { return charCheck; }
    void setSeat(int row, int col) { nRow = row; nCol = col; }
    void setReservedID(int reserved) { nReservedID = reserved; }
    int getReservedID() { return nReservedID; }

    void setPayAmount(int amount) { nPayAmount = amount; }   // 총 결제액
    int getPayAmount() { return nPayAmount; }
    void setPayment(int payment) { nPayment = payment; }     // 결제 방식 설정
};

#endif
