#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H
#include "Product.h"

class InventoryManager {
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
    void searchByName();
    void inbound();
    void outbound();
};

#endif
