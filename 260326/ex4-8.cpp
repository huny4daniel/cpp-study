#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle() {
        radius = 1;
    }
    
    ~Circle() {
    }

    void setRadius(int r) {
        radius = r;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }
};

class CircleManager {
    Circle* pArray = NULL;

    int size = 0;

    void input();
    void decide();

public:
    CircleManager();
    ~CircleManager();

    void run();
};

CircleManager::CircleManager() {
    cout << "생성하고자 하는 원의 개수? ";
    cin >> size;

    if (size <=0) {
        return;
    }

    pArray = new Circle[size];
}

CircleManager::~CircleManager() {
    if (pArray != NULL) {
        delete[] pArray;
    }
}

void CircleManager::input() {
    int radius;
    for (int i = 0; i < size; i++) {
        cout << "원" << i + 1 << ": ";
        cin >> radius;

        pArray[i].setRadius(radius);
    }
}

void CircleManager::decide() {
    int count = 0;

    Circle* p = pArray;

    for (int i = 0; i < size; i++) {
        cout << p->getArea() << ' ';

        if (p->getArea() >= 100 && p->getArea() <= 200) {
            count++;
        }

        p++;
    }
    cout << endl << "면적이 100에서 200 사이인 원의 개수는 " << count << endl;
}

void CircleManager::run() {
    input();
    decide();
}

int main() {
    CircleManager *pMan = new CircleManager();
    pMan->run();

    delete pMan;

    return 0;
}