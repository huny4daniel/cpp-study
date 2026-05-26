#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using std::string;

#define AUTHENTIFICATION_FAIL    -1
#define AUTHENTIFICATION_SUCCESS  1

class Account {
private:
    int nID;
    int nBalance;
    string strAccountName;
    string strPassword;

    inline bool authenticate(int id, string passwd);

public:
    Account();
    void create(int id, int money, string name, string password);
    void close();
    int check(int id, string password);
    int deposit(int id, string password, int money);
    int widraw(int id, string password, int money);
    bool deposit(int id, int money);
    int getAcctID() {
        return nID;
    }
    int getBalance() {
        return nBalance;
    }
    string getAccountName() {
        return strAccountName;
    }
};

#endif
