#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    string brand;
    int quantity;
    int price;
    bool active;

public:
    Product() : id(0), quantity(0), price(0), active(false) {}

    int getId() { return id; }
    string getName() { return name; }
    bool getActive() { return active; }
    int getQuantity() { return quantity; }

    void print();
    void createProduct(int id, string name, string brand, int quantity, int price, bool active);
    void setActive(bool active) { this->active = active; }
    void increaseQuantity(int id, int amount);
    void reduceQuantity(int amount);
};

#endif
