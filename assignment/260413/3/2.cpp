void f(Person person) {
    person.changeName("dummy");
}
int main() {
    Person father(1, "Kitae");
    f(father);  // person 매개 변수의 복사 생성자 호출
}