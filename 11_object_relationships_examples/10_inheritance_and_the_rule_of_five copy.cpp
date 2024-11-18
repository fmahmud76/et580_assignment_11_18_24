// S. Trowbridge 2023
#include <iostream>

class Vehicle {
protected:
    std::string *brand;
public:
    Vehicle(): Vehicle("Brand") { }
    Vehicle(std::string b): brand(new std::string(b)) { }
    void print() const { std::cout << *brand << std::endl; }                    // base print function

    Vehicle(const Vehicle &rhs): brand( new std::string(*(rhs.brand)) ) {       // copy constructor
    }
    Vehicle& operator=(const Vehicle &rhs) {                                    // assignment overload
        Vehicle tmp(rhs);
        swap(*this, tmp);
        return *this;
    }
    Vehicle(Vehicle &&rhs) noexcept = default;                                  // move constructor
    Vehicle& operator=(Vehicle &&rhs) noexcept = default;                       // move assignment
    ~Vehicle() {                                                                // destructor
        delete brand;                                                           // only deallocate base data
    }
    friend void swap(Vehicle &obj, Vehicle &tmp) {                              // swap for assignment overload
        using std::swap;
        swap(obj.brand, tmp.brand);                                             // only swap base data
    }
};

class Car : public Vehicle {                                                    // car is-a vehicle
private:
    int *numDoors;
public:
    Car(): Car("Brand", 0) { }
    Car(std::string b, int nd): Vehicle(b), numDoors(new int(nd)) { }
    void print() const {                                                        // redefined print function
        std::cout << *brand << " " << *numDoors << "-door" << std::endl; 
    } 

    Car(const Car &c):                                                          // derived copy constructor            
        Vehicle(c),                                                             // call base copy constructor                    
        numDoors( new int(*(c.numDoors)) ) {
    }
    Car& operator=(const Car &rhs) {                                            // derived assignment overload
        Vehicle::operator=(rhs);                                                // call base assignment overload                            
        Car tmp(rhs);
        swap(*this, tmp);
        return *this;
    }
    Car(Car &&rhs) = default;                                                   // derived move constructor
    Car& operator=(Car &&rhs) = default;                                        // derived move assignment
    ~Car() {                                                                    // derived destructor
        delete numDoors;                                                        // only deallocate derived data
    }
    friend void swap(Car &obj, Car &tmp) {                                      // derived swap for assigment overload
        using std::swap;
        swap(obj.numDoors, tmp.numDoors);                                       // only swap derived data
    }    
};

int main() {
    std::cout << std::endl;

    Vehicle v1("Acura");
    Vehicle v2("BMW");
    Vehicle v3 = v2;                                                            // base copy constructor

    v1.print();                                                                 // base print
    v2.print();
    v3.print();
    std::cout << "\n";

    Car c1("Lexus",2);
    Car c2("Audi",3);
    Car c3 = c2;                                                                // derived copy constructor

    c1.print();                                                                 // redefined derived
    c2.print();
    c3.print();
    std::cout << "\n";

    Car c4{};
    c4 = c1;                                                                    // derived assignment operator overload
    c4.print();
    std::cout << "\n";

    v3 = c2;                                                                    // copy car to vehicle, slicing occurs
    v3.print();

    //c2 = v3;                                                                  // compiler error: cannot copy vehicle to car

    std::cout << std::endl;
    return 0;
}
