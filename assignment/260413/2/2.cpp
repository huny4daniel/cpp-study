Person::Person(Person& person) {
    this->id = person.id;
    int len = strlen(person.name);
    this->name = new char[len+1];    // 새로운 메모리 할당
    strcpy(this->name, person.name); // 문자열 내용 복사
}