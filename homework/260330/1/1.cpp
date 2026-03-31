#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r) {          // 매개변수 있는 생성자만 존재
        radius = r;
        cout << "생성자 호출: radius = " << r << endl;
    }
    double getArea() { return 3.14 * radius * radius; }
};

int main() {
    Circle c1(10);           // 정상: 매개변수 전달

    Circle circleArray[3] = { Circle(1), Circle(2), Circle(3) };
    
    // Circle circleArray[3];   // 컴파일 오류 발생!

    return 0;
}