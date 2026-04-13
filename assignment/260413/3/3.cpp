Person g() {
    Person mother(2, "Jane");
    return mother;  // mother의 복사본 생성, 복사 생성자 호출
}
int main() {
    g();  // "복사 생성자 실행 Jane" 출력
}