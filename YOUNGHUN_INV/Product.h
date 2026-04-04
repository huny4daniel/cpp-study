#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product {
private:
    int id; // 상품 번호
    string name; // 상품 이름
    string brand; // 브랜드 명
    int quantity; // 상품 갯수
    int price; // 상품 단가
    bool active; // 등록 여부, 등록(true), 삭제(false)

public:
    Product() : id(0), quantity(0), price(0), active(false) {}

    int getId() { return id; }
    string getName() { return name; }
    bool getActive() { return active; }
    int getQuantity() { return quantity; } // (추가 기능 2: 상품 입고)

    void print(); // 상품 정보 출력
    void createProduct(int id, string name, string brand, int quantity, int price, bool active); // 상품 생성
    void setActive(bool active) { this->active = active; } // 상품 삭제 (active = false)
    void increaseQuantity(int id, int amount); // (추가 기능 2: 상품 입고)
    void reduceQuantity(int id, int amount); // (추가 기능 3: 상품 출고)
};

#endif