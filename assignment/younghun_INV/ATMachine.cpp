#include <iostream>
#include <string>
#include <random>
#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {
    nMaxAccountNum = size;
    nMachineBalance = balance;
    strManagerPassword = password;
    nCurrentAccountNum = 0;
    pAcctArray = new Account[size];
}

ATMachine::~ATMachine() {
    delete[] pAcctArray;
}

void ATMachine::displayMenu() {
    cout << "------------------------" << endl;
    cout << "- TUKOREA BANK -" << endl;
    cout << "------------------------" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 계좌 조회" << endl;
    cout << "3. 계좌 해지" << endl;
    cout << "4. 계좌 입금" << endl;
    cout << "5. 계좌 출금" << endl;
    cout << "6. 계좌 이체" << endl;
    cout << "8. 고객 관리" << endl;
    cout << "9. 업무 종료" << endl;
}

void ATMachine::createAccount() {
    string name, password;

    cout << "------ 개설 ------" << endl;
    cout << "이름 입력: ";
    cin >> name;
    cout << "암호 입력: ";
    cin >> password;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(100, 999);

    int id;
    bool duplicate;

    do {
        id = dist(gen);
        duplicate = false;
        for (int i = 0; i < nMaxAccountNum; i++) {
            if (pAcctArray[i].getAcctID() == id) {
                duplicate = true;

                break;
            }
        }
    } while (duplicate);

    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == -1) {
            pAcctArray[i].create(id, 0, name, password);
            nCurrentAccountNum++;
            cout << name << "님 " << id << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다" << endl;

            return;
        }
    }
    cout << "계좌 개설 실패: 최대 계좌 수를 초과했습니다." << endl;
}

void ATMachine::checkMoney() {
    int id;
    string password;

    cout << "------ 조회 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;

    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int result = pAcctArray[i].check(id, password);

            if (result == AUTHENTIFICATION_FAIL) {
                cout << "인증 실패" << endl;
            }

            else {
                cout << "현재 잔액 : " << result << endl;
            }

            return;
        }
    }

    cout << "존재하지 않는 계좌입니다." << endl;
}

void ATMachine::closeAccount() {
    int id;
    string password;

    cout << "------ 조회 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;

    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int result = pAcctArray[i].check(id, password);

            if (result == AUTHENTIFICATION_FAIL) {
                cout << "인증 실패" << endl;

                return;
            }

            pAcctArray[i].close();
            if (pAcctArray[i].getAcctID() == -1) {
                nCurrentAccountNum--;
                cout << id << " 계좌가 해지되었습니다. 감사합니다." << endl;
            }

            return;
        }
    }
    cout << "존재하지 않는 계좌입니다." << endl;
}

void ATMachine::depositMoney() {
    int id, money;
    string password;

    cout << "------ 입금 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;
    cout << "입금액 입력: ";
    cin >> money;

    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int result = pAcctArray[i].deposit(id, password, money);
            if (result == AUTHENTIFICATION_FAIL) {
                cout << "인증 실패" << endl;
            }
            else {
                cout << "현재 잔액 : " << result << endl;
                cout << "입금 완료" << endl;
            }

            return;
        }
    }
    cout << "존재하지 않는 계좌입니다." << endl;
}

void ATMachine::widrawMoney() {
    int id, money;
    string password;

    cout << "------ 출금 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;
    cout << "출금액 입력: ";
    cin >> money;

    if (nMachineBalance < money) {
        cout << "ATM 잔액이 부족합니다." << endl;

        return;
    }

    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            int result = pAcctArray[i].widraw(id, password, money);
            if (result == AUTHENTIFICATION_FAIL) {
                cout << "인증 실패" << endl;
            }
            else {
                nMachineBalance -= money;
                cout << "현재 잔액 : " << result << endl;
                cout << "출금 완료" << endl;
            }

            return;
        }
    }
    cout << "존재하지 않는 계좌입니다." << endl;
}

void ATMachine::transfer() {
    int id, targetId, money;
    string password;

    cout << "------ 이체 ------" << endl;
    cout << "계좌번호 입력: ";
    cin >> id;
    cout << "비밀번호 입력: ";
    cin >> password;
    cout << "이체계좌 입력: ";
    cin >> targetId;
    cout << "이체금액 입력: ";
    cin >> money;

    int srcIdx = -1, dstIdx = -1;
    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() == id) {
            srcIdx = i;
        }
        if (pAcctArray[i].getAcctID() == targetId) {
            dstIdx = i;
        }
    }

    if (srcIdx == -1) {
        cout << "출금 계좌가 존재하지 않습니다." << endl;

        return;
    }

    if (dstIdx == -1) {
        cout << "이체 계좌가 존재하지 않습니다." << endl;

        return;
    }

    int result = pAcctArray[srcIdx].widraw(id, password, money);
    if (result == AUTHENTIFICATION_FAIL) {
        cout << "인증 실패" << endl;

        return;
    }

    pAcctArray[dstIdx].deposit(targetId, money);
    cout << "현재 잔액 : " << result << endl;
    cout << "이체 완료" << endl;
}

bool ATMachine::isManager(string password) {
    return strManagerPassword == password;
}

void ATMachine::displayReport() {
    Statistics::sort(pAcctArray, nMaxAccountNum);

    int activeCount = 0;
    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() != -1) {
            activeCount++;
        }
    }

    cout << "------------------------" << endl;
    cout << "ATM 현재 잔고: " << nMachineBalance << "원" << endl;
    cout << "고객 잔고 총액: " << Statistics::sum(pAcctArray, nMaxAccountNum) << "원(중" << activeCount << "명)" << endl;
    cout << "고객 잔고 평균: " << Statistics::average(pAcctArray, nMaxAccountNum) << "원" << endl;
    cout << "고객 잔고 최소: " << Statistics::min(pAcctArray, nMaxAccountNum) << "원" << endl;
    cout << "고객 잔고 최고: " << Statistics::max(pAcctArray, nMaxAccountNum) << "원" << endl;
    cout << "------------------------" << endl;
    cout << "- 고객 계좌 목록 -" << endl;
    cout << "------------------------" << endl;

    int rank = 1;
    for (int i = 0; i < nMaxAccountNum; i++) {
        if (pAcctArray[i].getAcctID() != -1) {
            cout << rank++ << ". " << pAcctArray[i].getAccountName() << " " << pAcctArray[i].getAcctID() << "  " << pAcctArray[i].getBalance() << "원" << endl;
        }
    }
}

void ATMachine::managerMode() {
    string password;

    cout << "------ 관리 ------" << endl;
    cout << "관리자 비밀번호 입력: ";
    cin >> password;

    if (!isManager(password)) {
        cout << "비밀번호가 틀립니다." << endl;

        return;
    }
    cout << endl;
    cout << "관리자입니다." << endl;
    cout << endl;
    displayReport();
}
