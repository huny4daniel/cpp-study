#include <iostream>

using namespace std;

int main() {
    cout << "주소를 입력하세요>>";

    char address[100];
    cin.getline(address, 100, '\n'); // 키보드로부터 한 라인 읽기 (버퍼 방식)

    cout << "주소는 " << address << "입니다\n"; // 주소 출력
}