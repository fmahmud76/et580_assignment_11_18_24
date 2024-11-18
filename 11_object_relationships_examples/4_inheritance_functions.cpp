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
private:
    float radius;
public:
    Circle(): Shape(0), radius(0.0) {
        std::cout << "CIRCLE CONSTRUCTOR\n";       
    };
    Circle(float r): Shape(0), radius(r) {
        std::cout << "CIRCLE CONSTRUCTOR\n";       
    };     
    float getRadius() const { return radius; }
};

class Triangle : public Shape {                       // derived class: Circle is-a Shape
private:
    std::string type;
public:
    Triangle(): Shape(3), type("") {
        std::cout << "TRIANGLE CONSTRUCTOR\n";       
    };
    Triangle(std::string t): Shape(3), type(t) {
        std::cout << "TRIANGLE CONSTRUCTOR\n";       
    }; 
    std::string getType() const { return type; }   

};

int main() {
    std::cout << std::endl;

    Shape s(0);                                     
    std::cout << s.getEdges() << " edges\n\n";

    Circle c(3.5);                                  
    std::cout << c.getEdges() << " edges " << c.getRadius() << " radius\n\n";     

    Triangle t("Isoceles");
    std::cout << t.getEdges() << " edges " << t.getType() << "\n";

    std::cout << std::endl;
    return 0;
}
