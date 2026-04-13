class Person {
    char* name;  int id;
public:
    Person(int id, char* name);
    ~Person() { if(name) delete [] name; }
};
int main() {
    Person father(1, "Kitae");
    Person daughter(father); // 디폴트 복사 생성자 (얕은 복사)
}