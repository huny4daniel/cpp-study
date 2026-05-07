#include <iostream>
#include <string>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x, int y) : x(x), y(y) {
    }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void show() {
        cout << "(" << x << "," << y << ")";
    }
};

class ColorPoint : public Point {
private:
    string color;

public:
    ColorPoint(int x, int y, string color) : Point(x, y), color(color) {
    }

    void setColor(string color) {
        this->color = color;
    }
    void show() {
        cout << color << "색으로 ";
        Point::show();
        cout << "에 위치한 점입니다." << endl;
    }
};

int main() {
    ColorPoint cp (5, 5, "RED");

    cp.setPoint(30, 40);
    cp.setColor("BLUE");
    
    cp.show();
}