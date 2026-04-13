void msg(int id) { cout << id << endl; }
void msg(int id, string s = "Hello") {
    cout << id << " " << s << endl;
}
int main() {
    msg(5);
    // msg(int)인지 msg(int, string="Hello")인지 모호
}