#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H
#include <string>
#include "Product.h"

class InventoryManager  {
private:
    Product* pProductArray;
    int nMaxSize;
    int nCurrentIndex;

public:
    InventoryManager(int size);
    ~InventoryManager();

    void displayMenu();
    void addProduct(string name, string brand, int quantity, int price, bool active);
    void addProduct();
    void list();
    void removeProduct();
    void searchByName(); // (추가 기능 1: 상품 검색)
    void inbound(); // (추가 기능 2: 상품 입고)
    void outbound(); // (추가 기능 3: 상품 출고)
};

#endif