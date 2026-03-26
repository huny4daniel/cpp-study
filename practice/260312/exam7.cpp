#include <iostream>
#include <string>

using namespace std;

int main() {
    char input[100];
    string answer;
    string message = "종료하고싶으면 yes를 입력하세요>> ";
    
    while (answer != "yes") {
        cout << message;

        cin.getline(input, 100);
        answer = input;
    }

    cout << "종료합니다..." << "\n";
    return 0;
}