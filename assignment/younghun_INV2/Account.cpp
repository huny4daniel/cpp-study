#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

Account::Account() : nID(-1), nBalance(0), strAccountName(""), strPassword("") {
}

inline bool Account::authenticate(int id, string passwd) {
    return (nID == id && strPassword == passwd);
}

void Account::create(int id, int money, string name, string password) {
    nID = id;
    nBalance = money;
    strAccountName = name;
    strPassword = password;
}

void Account::close() {
    if (nBalance != 0) {
        cout << "잔액이 존재하여 해지할 수 없습니다." << endl;

        return;
    }

    nID = -1;
    nBalance = 0;
    strAccountName = "";
    strPassword = "";
}

int Account::check(int id, string password) {
    if (!authenticate(id, password)) {
        return AUTHENTIFICATION_FAIL;
    }

    return nBalance;
}

int Account::deposit(int id, string password, int money) {
    if (!authenticate(id, password)) {
        return AUTHENTIFICATION_FAIL;
    }

    nBalance += money;

    return nBalance;
}

int Account::widraw(int id, string password, int money) {
    if (!authenticate(id, password)) {
        return AUTHENTIFICATION_FAIL;
    }

    if (nBalance < money) {
        cout << "잔액이 부족합니다." << endl;
        return nBalance;
    }

    nBalance -= money;

    return nBalance;
}

bool Account::deposit(int id, int money) {
    if (nID != id) {
        return false;
    }

    nBalance += money;

    return true;
}
