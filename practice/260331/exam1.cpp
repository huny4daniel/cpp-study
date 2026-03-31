#include <iostream>
using namespace std;

int main() {
    double* arr = new double[5];

    cout << "온도 5개 입력>>";

    double sum = 0;
    double average = 0;

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    average = sum / 5;

    cout << "평균은 " << average << endl;
}