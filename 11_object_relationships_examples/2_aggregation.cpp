// S. Trowbridge 2024
#include <iostream>

// aggregation - a "has-a" b
// 1/4 are same as composition (see composition example)
// 2) an address may simultaneously belong to multiple person objects
// 3) object lifetimes are independent (no big three)
class Address {
private:
    std::string location;
public:
    Address(): location("") {}
    Address(std::string l): location(l) {}
    std::string getLocation() const { return location; }
};

class Person {
private:
    std::string name;
    Address *home;                                                      // pointer or reference to an external object 
public:
    Person(): name(""), home(nullptr) {}                                // set home to nullptr
    Person(std::string n): name(n), home(nullptr) {}                    // set the home to nullptr 
    Person(std::string n, Address &h): name(n), home(&h) {}             // connect to an external Address object

    void setHome(Address &h) { home = &h; }                             // point home to an external Address object
    Address* getHome() { return home; }                                 // return a pointer to the external Address object

    friend std::ostream& operator<<(std::ostream &out, const Person &c); 
};

std::ostream& operator<<(std::ostream &out, const Person &p) {
    out << p.name << " " << p.home->getLocation();                      // arrow operator used to deference the pointer
    return out;
}

int main() {
    std::cout << std::endl;

    Address *a1 = new Address{"5150 Ventura Blvd."};                    // address object lifetime is independent of any person objects it associates with

    Person p1{"Kim"};                                                   // kim is homeless
    Person p2{"Sloan", *a1};                                            // sloan has address a1
    p1.setHome( *(p2.getHome()) );                                      // kim moves in with sloan, a1 is shared by kim and sloan

    std::cout << p1 << "\n";
    std::cout << p2 << "\n";

    std::cout << std::endl;
    return 0;
}
