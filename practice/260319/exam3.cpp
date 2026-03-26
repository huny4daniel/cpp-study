#include <iostream>
using namespace std;

class Account {
    string owner;
    int balance;

public:
    Account(string name);
    void deposit(int money);
    int withdraw(int money);
    int inquiry();
    string getOwner() {
        return owner;
    }
};

Account::Account(string name) {
    owner = name;
    balance = 0;
}

void Account::deposit(int money) {
    balance += money;
}

int Account::inquiry() {
    return balance;
}

int Account::withdraw(int money) {
    if (money > balance) {
        money = balance;
        balance = 0;
    }
    else {
        balance -= money;
    }
    return money;
}

int main() {
    Account a("황수희");

    a.deposit(20000);
    cout << a.getOwner() << " 잔액은 " << a.inquiry() <<endl;

    int money = a.withdraw(15000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << " 잔액은 " << a.inquiry() <<endl;
    
    money = a.withdraw(8000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << " 잔액은 " << a.inquiry() <<endl;
}