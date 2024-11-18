// S. Trowbridge 2024
#include <iostream>

class Shape {                                               // base class
protected:    
    int edges;
public:
    Shape(): edges(0) {}
    Shape(int e): edges(e) {}
    void print() const { std::cout << edges << "\n"; }
};

class Circle : public Shape {                               // derived class: Circle is-a Shape
    float radius;
public:
    Circle(): Shape(0), radius(1.0) {}
    void print() const {                                    // redefined: different function body from base class version
        std::cout << edges << " " << radius << "\n";
    }
    void print(int n) const {                               // overloaded: different parameter list from base class version
        for(int i=0; i<n; ++i) {
            std::cout << edges << " " << radius << "\n";
        }
    }
};

int main() {
    std::cout << std::endl;

    Shape s;
    s.print();

    std::cout << "\n";

    Circle c;
    c.print();
    c.print(3);

    std::cout << std::endl;
    return 0;
}
