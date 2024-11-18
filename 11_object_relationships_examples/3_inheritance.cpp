// S. Trowbridge 2024
#include <iostream>

class Shape {                                       // base class
private:    
    int edges;
public:
    Shape(): edges(0) { 
        std::cout << "SHAPE CONSTRUCTOR\n";
    }
    Shape(int e): edges(e) { 
        std::cout << "SHAPE CONSTRUCTOR\n"; 
    }
    int getEdges() const { return edges; }
};

class Circle : public Shape {                       // derived class: Circle is-a Shape
public:
    Circle(): Shape(0) {
        std::cout << "CIRCLE CONSTRUCTOR\n";       
    };
};

int main() {
    std::cout << std::endl;

    Shape s(0);                                     // base constructor called
    std::cout << s.getEdges() << " edges\n\n";

    Circle c;                                       // bass and derived constructors called
    std::cout << c.getEdges() << " edges\n\n";      // derived object calls inherited base function

    std::cout << std::endl;
    return 0;
}
