#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, f, r;

    cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
    getline(cin, s, '&');
    cin.ignore();

    cout << endl << "find: ";
    getline(cin, f, '\n');

    cout << "replace: ";
    getline(cin, r, '\n');

    int startindex = 0;
    while (true) {
        int findex = s.find(f, startindex);

        if (findex == -1) {
            break;
        }

        s.replace(findex, f.length(), r);
        startindex = findex + r.length();
    }
    cout << s << endl;
}