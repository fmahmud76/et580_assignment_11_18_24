// S. Trowbridge 2024
#include <iostream>

class Employee {
protected:
    std::string name;
public:
    Employee(): name("") { std::cout << "EMPLOYEE CONSTRUCTOR\n"; }
    Employee(std::string n): name(n) { std::cout << "EMPLOYEE CONSTRUCTOR\n"; }
};

class Scholar {
protected:
    std::string name;
public:
    Scholar(): name("") { std::cout << "SCHOLAR CONSTRUCTOR\n"; }
    Scholar(std::string n): name(n) { std::cout << "SCHOLAR CONSTRUCTOR\n"; }
};

/*
    Multiple Inheritance:
    Employee     Scholar
        \        /
         Professor
*/
class Professor : public Employee, public Scholar { // multiple inheritance: professor is-an employee AND is-a scholar
public:
    Professor(): Employee(), Scholar() { std::cout << "PROFESSOR CONSTRUCTOR\n"; }
    Professor(std::string n): Employee(n), Scholar(n) {  std::cout << "PROFESSOR CONSTRUCTOR\n"; } 

    void func(std::string n) {
        //name = n;                                 // compiler error: ambiguity, should we update Scholar::name or Employee::name
        Scholar::name = n;
    }
};

int main() {
    std::cout << std::endl;

    Professor("John Smith");

    std::cout << std::endl;
    return 0;
}
