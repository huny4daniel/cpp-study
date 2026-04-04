#include <iostream>
#include "Product.h"
using namespace std;

void Product::print() {
    cout << id << ", " << name << ", " << brand << ", " << quantity << ", " << price << ", " << active << endl;
}

void Product::createProduct(int id, string name, string brand, int quantity, int price, bool active) {
    this->id = id;
    this->name = name;
    this->brand = brand;
    this->quantity = quantity;
    this->price = price;
    this->active = active;
}

void Product::increaseQuantity(int id, int amount) {
    this->id = id;
    this->quantity += amount;
}

void Product::reduceQuantity(int id, int amount) {
    this->id = id;
    this->quantity -= amount;
}