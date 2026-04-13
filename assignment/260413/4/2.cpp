int add(int a, int b) { return a + b; }
int add(int &a, int &b) { return a + b; }
int main() {
    int x = 3, y = 5;
    add(x, y);
    // 어떤 add()를 호출할지 모호함
}