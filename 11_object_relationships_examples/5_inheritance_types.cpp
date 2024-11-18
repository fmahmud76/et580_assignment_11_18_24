// S. Trowbridge 2024
#include <iostream>

// protected recommended instead of private for B classes
class B {
private:
    int pri;                                            // not accessible in D class
protected:
    int pro;                                           // accessible in D class
public:
    int pub;                                            // accessible in D class
    int getPro() const { return pro; }
    int getPri() const { return pri; }
};

class D: public B { // D is-a B
public:
    int getBasePro() const { return pro; }                 // direct access to B protected
    int getBasePri() const { return getPri(); }            // indirect access to B private
    //int getBasePri() const { return pri; }               // compiler error: D cannot direct access B private
};

int main() {
    std::cout << std::endl;

    B b{};
    std::cout << b.pub << "\n\n";                       // main can direct access B public
    // std::cout << b.pro << "\n";                      // compiler error: main cannot direct access B protected
    // std::cout << b.pri << "\n";                      // compiler error: main cannot direct access B private

    D d{};                                              
    std::cout << d.pub << "\n";                         // B direct access to D public              
    std::cout << d.getPro() << "\n";                    // B direct access to D protected                         
    std::cout << d.getPri() << "\n";                    // B indirect access to D private                                                           

    std::cout << std::endl;
    return 0;
}
