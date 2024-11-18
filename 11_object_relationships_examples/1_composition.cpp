// S. Trowbridge 2024
#include <iostream>

// composition - a "has-a" b
// 1) a person has-a heart, a heart is part-of a person
// 2) a heart belongs to one person
// 3) the lifetime of an heart is linked to the the lifetime of a person
// 4) a heart is not aware that is part-of a person
class Heart {
private:
    int rate;
public:
    Heart(): Heart(0) {}
    Heart(int r): rate(r) {}
    int getRate() const { return rate; } 
    void setRate(int r) { rate = r; }
};

class Person {
private:
    std::string name;
    Heart myHeart;                                                  // Person has-a Heart
public:
    Person(): name("anon"), myHeart() {}                            // call Heart default constructor
    Person(std::string n): name(n), myHeart() {}                    // call Heart default constructor
    Person(std::string n, int b): name(n), myHeart(b) {}            // call Heart one-parameter constructor
    int getRate() const { return myHeart.getRate(); }               // call Heart accessor to return myHeart rate
    void setRate(int r) { myHeart.setRate(r); }                     // call Heart mutator to assign myHeart rate

    friend std::ostream& operator<<(std::ostream &out, const Person &c);
};

std::ostream& operator<<(std::ostream &out, const Person &p) {
    out << p.name << " " << p.myHeart.getRate() << "bpm";
    return out;
}

int main() {
    std::cout << std::endl;

    Person c1{};
    Person c2{"John", 80};

    std::cout << c1 << "\n";
    std::cout << c2 << "\n";

    std::cout << std::endl;
    return 0;
}
