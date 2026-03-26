#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "두 개의 정수를 입력하세요>> ";
    
    int num1;
    cin >> num1;

    int num2;
    cin >> num2;

    int plus = num1 + num2;
    int minus = num1 - num2;
    int multi = num1 * num2;

    cout << num1 << "+" << num2 << "=" << plus << endl;
    cout << num1 << "-" << num2 << "=" << minus << endl;
    cout << num1 << "*" << num2 << "=" << multi << endl;

}