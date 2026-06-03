#ifndef PAYSTRATEGY_H
#define PAYSTRATEGY_H

#define KAKAOPAY_PAYMENT 1
#define APPLEPAY_PAYMENT 2
#define SAMSUNGPAY_PAYMENT 3

#define KAKAOPAY_INTEREST_RATE 0.1      // 카카오페이 결제 수수료 비율
#define APPLEPAY_INTEREST_RATE 0.2      // 애플페이 결제 수수료 비율
#define SAMSUNGPAY_INTEREST_RATE 0.15   // 삼성페이 결제 수수료 비율

class PayStrategy {
public:
    virtual int charge(int amount) = 0; // 결제하기
};

class CardPay : public PayStrategy {
    double interest;
public:
    CardPay(double rate) { this->interest = rate; }
    int charge(int amount);     // 결제금액 = 티켓 가격 + 티켓 가격 * 카카오페이 수수료 비율
};

class ApplePay : public PayStrategy {
    double interest;
public:
    ApplePay(double rate) { this->interest = rate; }
    int charge(int amount);     // 결제금액 = 티켓 가격 + 티켓 가격 * 애플페이 수수료 비율
};

class SamsungPay : public PayStrategy {
    double interest;
public:
    SamsungPay(double rate) { this->interest = rate; }
    int charge(int amount);     // 결제금액 = 티켓 가격 + 티켓 가격 * 삼성페이 수수료 비율
};

#endif
