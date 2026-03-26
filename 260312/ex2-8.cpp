#include <iostream>
#include <string> // string 클래스 헤더파일

using namespace std;

int main() {
    string song("Falling in love with you");
    string elvis("Elvis Presly");
    string singer; // 기본 생성자로 빈 문자열로 초기화됨

    cout << song + "를 부른 가수는? "; // + 연산자 오버로딩으로 문자열 연결
    cout << "(힌트: 첫글자는 " << elvis[0] << "): ";

    getline(cin, singer);
    if (singer == elvis) {
        cout << "맞았습니다.";
    }
    else {
        cout << "틀렸습니다. " + elvis + "입니다." << endl;
    }
}
