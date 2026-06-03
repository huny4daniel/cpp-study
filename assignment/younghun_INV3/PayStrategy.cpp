#include "PayStrategy.h"

// 결제금액 = 티켓 가격 + 티켓 가격 * 카카오페이 수수료 비율
int CardPay::charge(int amount) {
    return amount + (int)(amount * interest);
}

// 결제금액 = 티켓 가격 + 티켓 가격 * 애플페이 수수료 비율
int ApplePay::charge(int amount) {
    return amount + (int)(amount * interest);
}

// 결제금액 = 티켓 가격 + 티켓 가격 * 삼성페이 수수료 비율
int SamsungPay::charge(int amount) {
    return amount + (int)(amount * interest);
}
