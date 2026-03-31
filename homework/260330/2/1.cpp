#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int score;

public:
    Student(string n, int s) : name(n), score(s) {}

    void print() {
        cout << "이름: " << name << ", 점수: " << score << endl;
    }
};

int main() {
    Student arr[3] = {
        Student("홍길동", 90),
        Student("이순신", 85),
        Student("강감찬", 78)
    };

    for (int i = 0; i < 3; i++) {
        arr[i].print();   // arr[i] → 객체, "." 연산자로 멤버 접근
    }

    return 0;
}
