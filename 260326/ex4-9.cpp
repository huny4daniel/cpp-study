#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    string address("경기도 고양시 일산서구 일현로 97-11");
    string copyAddress = (address);

    char text[] = {'L', 'o', 'v', 'e', ' ', 'C', '+', '+', '\0'};
    string title(text);

    cout << str << endl;
    cout << address << endl;
    cout << copyAddress << endl;
    cout << title << endl;
}