// S. Trowbridge 2024
#include <iostream>

class Shape {
protected:
    int *size;
public:
    Shape(): size( new int(0) ) {}   
    Shape(int s): size( new int(s) ) {}    
    friend void swap(Shape &lhs, Shape &rhs) noexcept;          
    Shape(const Shape &s)                                       
        : size( new int( *(s.size) ))             
    {       
    }
    Shape& operator=(const Shape &s)                            
    {
        Shape tmp{s};                                           
        swap(*this, tmp);                                       
        return *this;                                           
    }
    ~Shape() 
    {                                                  
        delete size;                                   // base destructor deletes base dynamic members                                         
    }
    friend std::ostream& operator<<(std::ostream& out, const Shape &s);
    void print() const 
    { 
        std::cout << size << "\n";
    }    
};
void swap(Shape &lhs, Shape &rhs) noexcept 
{                                                                
    using std::swap;                                                                                                   
    swap(lhs.size, rhs.size);                                                                         
}

class Circle : public Shape {
private:
    float *radius;
public:
    Circle(): Shape(), radius( new float(1.0) ) {}
    Circle(int s, float r): Shape(s), radius( new float(r) ) {}
    friend void swap(Circle &lhs, Circle &rhs) noexcept;   
    Circle(const Circle &c)
        :Shape(c), radius( new float( *c.radius ))  // derived copy constructor must call the base copy constructor
    {
    } 
    Circle& operator=(const Circle &c)
    {
        Circle::operator=(c);                       // derived assignment overload must call base assignment overload
        Circle tmp{c};
        swap(*this, tmp);
        return *this;
    }
    ~Circle()
    {
        delete radius;                              // derived destructor deletes derived dynamic members 
    }
    void print() const                              // redefined print function
    { 
        std::cout << size << " " 
                  << radius << "\n";
    }
};
void swap(Circle &lhs, Circle &rhs) noexcept 
{                                                                
    using std::swap;                                                
    swap(lhs.radius, rhs.radius);                                                                                   
}

int main() 
{
    std::cout << std::endl;

    Shape s1(10);
    Shape s2(20);
    Shape s3 = s2;              // base copy constructor

    s1.print();                 // base print
    s2.print();
    s3.print();
    std::cout << "\n";

    Circle c1(10, 1.5);
    Circle c2(20, 2.5);
    Circle c3 = c2;             // derived copy constructor

    c1.print();                 // redefined print
    c2.print();
    c3.print();
    std::cout << "\n";

    Circle c4{};
    c4 = c1;                    // derived assignment operator overload
    c4.print();
    std::cout << "\n";

    s3 = c2;                    // copy a circle to a shape, slicing occurs
    s3.print();

    //c2 = s3;                  // compiler error: cannot copy a shape to a circle

    std::cout << std::endl;
    return 0;
}
