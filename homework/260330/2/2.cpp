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

    Student* ptr = arr;   // 배열 이름 = 첫 번째 원소의 주소
    for (int i = 0; i < 3; i++) {
        ptr->print();     // ptr → 포인터, "->" 연산자로 멤버 접근
        ptr++;            // 다음 원소로 이동
    }

    return 0;
}
