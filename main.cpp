#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) {
        name = n;
    }

    virtual void display() const {
        cout << "Name: " << name << endl;
    }

    virtual ~Person() {
    }
};

class Student : public Person {
private:
    int id;
    float marks[3];

public:
    Student(string n, int studentId, float m1, float m2, float m3)
        : Person(n) {
        id = studentId;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    ~Student() override {
    }

    float calculateAverage() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0f;
    }

    float calculateAverage(float bonus) const {
        return calculateAverage() + bonus;
    }

    void display() const override {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;
        cout << "Average: " << calculateAverage() << endl;
        cout << "Result: "
             << (calculateAverage() >= 50.0f ? "Pass" : "Fail") << endl;
    }
};

int main() {
    string name;
    int id;
    float mark1, mark2, mark3;

    cout << "=== Student Management System ===" << endl;

    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter student ID: ";
    cin >> id;

    cout << "Enter three marks: ";
    cin >> mark1 >> mark2 >> mark3;

    Student student(name, id, mark1, mark2, mark3);

    cout << "\n=== Student Information ===" << endl;
    student.display();

    cout << "Average with bonus: "
         << student.calculateAverage(5.0f) << endl;

    Person* personPointer = &student;
    cout << "\n=== Polymorphism ===" << endl;
    personPointer->display();

    return 0;
}
