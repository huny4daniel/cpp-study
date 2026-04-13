float square(float a) { return a * a; }
double square(double a) { return a * a; }
int main() {
    cout << square(3);
    // 3은 int -> float, double 모두 변환 가능
}