#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "구입할 물품의 개수>>";
    cin >> size;

    int *p = new int[size];
    cout << "물품 " << size << "개의 가격 입력>>";

    for (int i = 0; i < size; i++) {
        cin >> p[i];
    }

    int min = p[0];
    int max = p[0];
    
    for (int i = 1; i < size; i++) {
        if (p[i] < min) {
            min = p[i];
        }
        if (p[i] > max) {
            max = p[i];
        }
    }

    cout << "제일 싼 가격은>> " << min << endl;
    cout << "제일 비싼 가격은>> " << max << endl;
}