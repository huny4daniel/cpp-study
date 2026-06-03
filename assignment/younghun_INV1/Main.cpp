#include <iostream>
#include <string>
using namespace std;
#include "Product.h"
#include "InventoryManager.h"

int main() {
    int select;
    InventoryManager iMananger(100);
    iMananger.addProduct("C++", "인피니티", 10, 30000, true);
    iMananger.addProduct("자바", "한빛미디어", 10, 35000, true);
    iMananger.addProduct("파이썬", "생능출판사", 10, 33000, true);

    while (1) {
        iMananger.displayMenu();
        cout << "메뉴를 선택하세요: ";
        cin >> select; cout << endl;

        switch (select) {
        case 1:
            iMananger.addProduct();
            break;
        case 2:
            iMananger.list();
            break;
        case 3:
            iMananger.removeProduct();
            break;
        case 4:
            iMananger.searchByName();
            break;
        case 5:
            iMananger.inbound();
            break;
        case 6:
            iMananger.outbound();
            break;
        case 9:
            cout << "안녕히 가세요" << endl;
            return 0;
        default:
            cout << "번호 확인 후 다시 입력하세요." << endl;
        }
    }
    
    return 0;
}