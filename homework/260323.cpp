#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
public:
    // 매개변수가 있는 생성자만 선언
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }
    int getArea() { return width * height; }
};

int main() {
    Rectangle rect1(3, 5);  // 정상: 매개변수 있는 생성자 호출
    cout << "rect1의 면적: " << rect1.getArea() << endl;

    // Rectangle rect2;        // 컴파일 오류 발생!
    // error: no matching function for call to 'Rectangle::Rectangle()'

    return 0;
}