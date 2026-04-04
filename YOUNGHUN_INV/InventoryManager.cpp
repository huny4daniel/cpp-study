#include <iostream>
#include "InventoryManager.h"
using namespace std;

InventoryManager::InventoryManager(int size) {
    pProductArray = new Product[size];
    nMaxSize = size;
    nCurrentIndex = 0;
}

InventoryManager::~InventoryManager() {
    delete[] pProductArray;
}

void InventoryManager::displayMenu() {
    cout << "\n----------------------" << endl;
    cout << "- TUKOREA INVENTORY -" << endl;
    cout << "----------------------" << endl;
    cout << "1. 상품 등록" << endl;
    cout << "2. 전체 목록" << endl;
    cout << "3. 상품 삭제" << endl;
    cout << "4. 상품검색" << endl;
    cout << "5. 상품입고" << endl;
    cout << "6. 상품출고" << endl;
    cout << "9. 업무종료" << endl;
}

void InventoryManager::addProduct(string name, string brand, int quantity, int price, bool active) {
    if (nCurrentIndex >= nMaxSize) {
        cout << "상품 목록이 가득 찼습니다." << endl;
        return;
    }
    
    int id = nCurrentIndex + 1;
    pProductArray[nCurrentIndex].createProduct(id, name, brand, quantity, price, active);
    nCurrentIndex++;

    cout << "상품이 등록되었습니다. (ID : " << id << ", " << name << ")" << endl;
}

void InventoryManager::addProduct() {
    string name, brand;
    int quantity, price;

    cout << "------ 등록 ------" << endl;
    cout << "상품명   : "; 
    cin >> name;

    cout << "브랜드   : "; 
    cin >> brand;

    cout << "상품수   : "; 
    cin >> quantity;

    cout << "상품가격 : "; 
    cin >> price;

    addProduct(name, brand, quantity, price, true);
}

void InventoryManager::list() {
    cout << "등록된 상품 : " << nCurrentIndex << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < nCurrentIndex; i++) {
        pProductArray[i].print();
    }
}

void InventoryManager::removeProduct() {
    int id;

    cout << "------ 삭제 ------" << endl;
    cout << "상품ID   : "; 
    cin >> id;

    for (int i = 0; i < nCurrentIndex; i++) {
        if (pProductArray[i].getId() == id) {
            pProductArray[i].setActive(false);
            cout << "상품이 삭제되었습니다. (ID : " << id << ")" << endl;

            return;
        }
    }

    cout << "해당 ID의 상품이 없습니다." << endl;
}

void InventoryManager::searchByName() {
    string name;
    int count = 0;

    cout << "------ 검색 ------" << endl;
    cout << "상품명   : ";
    cin >> name;
    cout << endl;

    for (int i = 0; i < nCurrentIndex; i++) {
        if (pProductArray[i].getActive() && pProductArray[i].getName() == name) {
            pProductArray[i].print();
            count++;
        }
    }

    cout << "\n 검색상품 건수 : " << count << endl;
}

void InventoryManager::inbound() {
    int id, amount;

    cout << "------ 입고 ------" << endl;
    cout << "상품ID   : "; 
    cin >> id;

    cout << "입고개수 : "; 
    cin >> amount;

    for (int i = 0; i < nCurrentIndex; i++) {
        if (pProductArray[i].getId() == id && pProductArray[i].getActive()) {
            pProductArray[i].increaseQuantity(id, amount);
            cout << "상품입고 완료 (ID : " << id << "), Quantity : " << pProductArray[i].getQuantity() << endl;

            return;
        }
    }

    cout << "해당 ID의 상품이 없거나 삭제된 상품입니다." << endl;
}

void InventoryManager::outbound() {
    int id, amount;

    cout << "------ 출고 ------" << endl;
    cout << "상품ID   : "; 
    cin >> id;
    
    cout << "출고개수 : "; 
    cin >> amount;

    for (int i = 0; i < nCurrentIndex; i++) {
        if (pProductArray[i].getId() == id && pProductArray[i].getActive()) {
            if (amount > pProductArray[i].getQuantity()) {
                cout << "재고가 부족합니다. 현재 재고 : " << pProductArray[i].getQuantity() << endl;
                return;
            }
            pProductArray[i].reduceQuantity(id, amount);
            cout << "상품출고 완료 (ID : " << id << "), Quantity : " << pProductArray[i].getQuantity() << endl;

            return;
        }
    }

    cout << "해당 ID의 상품이 없거나 삭제된 상품입니다." << endl;
}