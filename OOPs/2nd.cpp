#include <iostream>
using namespace std;

// Basic class definition
class Person {
private:
    string name;
    int age;
public:
    // Constructor
    Person(string n, int a) : name(n), age(a) {}

    // Member function
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person p1("Alice", 25);
    p1.display();

    return 0;
}