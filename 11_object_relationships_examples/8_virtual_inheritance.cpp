// S. Trowbridge 2024
#include <iostream>

class Person {
protected:
    std::string name;
public:
    Person(): name("") { std::cout << "PERSON CONSTRUCTOR\n" ;}
    Person(std::string n): name(n) { std::cout << "PERSON CONSTRUCTOR\n"; }    
};

class Employee : public virtual Person{                     // employee is-a person : virtual inheritance
protected:
public:
    Employee(): Person("") { std::cout << "EMPLOYEE CONSTRUCTOR\n"; }
    Employee(std::string n): Person(n) { std::cout << "EMPLOYEE CONSTRUCTOR\n"; }
};

class Scholar : public virtual Person {                     // scholar is-a person : virtual inheritance
public:
    Scholar(): Person("") { std::cout << "SCHOLAR CONSTRUCTOR\n"; }
    Scholar(std::string n): Person(n) { std::cout << "SCHOLAR CONSTRUCTOR\n"; }
};

/*
    Multiple Inheritance: Diamond Problem 
          Person
        /        \
    Employee     Scholar
        \        /
         Professor
*/
class Professor : public Employee, public Scholar { // professor is-an employee AND is-a scholar AND is-a person
public:
    Professor(): Employee(), Scholar() { std::cout << "PROFESSOR CONSTRUCTOR\n"; }
    Professor(std::string n): Employee(n), Scholar(n) {  std::cout << "PROFESSOR CONSTRUCTOR\n"; } 

    void func(std::string n) {
        name = n;                                   // scope resolution not required because only one name variable will be created (virtual inheritance)
    }
};

int main() {
    std::cout << std::endl;

    Professor("John Smith");

    std::cout << std::endl;
    return 0;
}
