#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int score;

public:
    Student(string n, int s) : name(n), score(s) {}
    ~Student() {
        cout << name << " 소멸자 호출" << endl;
    }

    void print() {
        cout << "이름: " << name << ", 점수: " << score << endl;
    }
};

int main() {
    // new 연산자로 객체 배열 동적 생성
    Student* arr = new Student[3]{
        Student("홍길동", 90),
        Student("이순신", 85),
        Student("강감찬", 78)
    };

    cout << "동적 객체 배열 출력" << endl;
    for (int i = 0; i < 3; i++) {
        arr[i].print();
    }

    cout << "\n메모리 반환 (delete[])" << endl;
    delete[] arr;   // 반드시 delete[]를 사용해야 모든 소멸자가 호출됨
    arr = nullptr;

    return 0;
}
