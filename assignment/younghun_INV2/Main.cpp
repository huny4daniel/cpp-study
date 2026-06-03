#include <iostream>
#include <string>
#include "Account.h"
#include "ATMachine.h"

using namespace std;

int main() {
    int select;

    ATMachine atm(100, 50000, "admin");

    while (1) {
        atm.displayMenu();

        cout << "메뉴를 선택하세요: ";
        cin >> select;
        cout << endl;

        switch (select) {
        case 1:
            atm.createAccount();
            break;
        case 2:
            atm.checkMoney();
            break;
        case 3:
            atm.closeAccount();
            break;
        case 4:
            atm.depositMoney();
            break;
        case 5:
            atm.widrawMoney();
            break;
        case 6:
            atm.transfer();
            break;
        case 8:
            atm.managerMode();
            break;
        case 9:
            cout << "안녕히 가세요" << endl;
            return 0;
        default:
            cout << "번호 확인 후 다시 입력하세요." << endl;
        }

        cout << endl;
    }

    return 0;
}