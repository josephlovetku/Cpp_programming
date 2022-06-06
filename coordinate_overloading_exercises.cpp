/******************************************************************************

An Exercise for Operator Overloading in C++
Reference: An Hung in NTU
Author: Joseph Chuang-Chieh Lin
Date: May 30 20222

*******************************************************************************/
#include <iostream>

using namespace std;

class Coord {
private:
    int x, y;
public:
    Coord() = default;
    Coord(int a): x(a), y(a) { x = a; y = a; }
    Coord(int a, int b): x(a), y(b) {}
    
    Coord operator+(const Coord &c) { 
        Coord temp;
        temp.x = x + c.x ;
        temp.y = y + c.y ;
        return temp;
    }
    /*
    void operator=(const Coord &c) { 
        x = c.x; 
        y = c.y;
    }*/
    
    Coord operator=(const Coord &c) { 
        x = c.x; 
        y = c.y;
        return *this;
    }
    
    bool operator==(const Coord&); 
    bool operator!=(const Coord&);
    Coord& operator++() {  // prefix ++: 例如:  ++a
        x++; 
        y++; 
        return *this;
    }
    Coord operator++(int) { //postfix ++: 例如:  a++
        Coord temp = *this;
        x++; 
        y++;
        return temp;
    }
    void print() { cout << x << ", " << y << endl; }
    friend Coord operator+(const Coord &ob1, const Coord &ob2) {
        return Coord(ob1.x+ob2.x, ob1.y+ob2.y);
    };
    friend ostream& operator<<(ostream&, const Coord&);
    friend istream& operator>>(istream&, Coord&);
};

ostream& operator<<(ostream& os, const Coord& c) {
    os << "(" << c.x << ", " << c.y << ")" << endl;
    return os;
}

istream& operator>>(istream& is, Coord& c) {
    cout << "Enter x: "; 
    is >> c.x;
    cout << "Enter y: ";
    is >> c.y;
    return is;
}

bool Coord::operator==(const Coord& ob2) {// return type: true or false
    return (this->x == ob2.x) && (this->y == ob2.y);
}

bool Coord::operator!=(const Coord& ob2) {// return type: true or false
    return (this->x != ob2.x) || (this->y != ob2.y);
}

int main()
{
    Coord o1(10,10), o2(5,3), o3, o4, o5;
    o4 = o3 = o1 + o2;// o3 = o1 + o2 ;
    o4.print(); //later, you can use cout << o3 ;
    if (o3 == o4) {
        cout << "o3 and o4 are equal" << endl;
    }
    if (o3 != o1) {
        cout << "o3 and o1 are unequal" << endl;
    }
    o3++;
    o3.print();
    cout << "Now we are trying (o4++):" << endl;
    (o4++).print();
    o4 = 11 + o2;
    o4.print();
    cout << o3;
    cin >> o5;
    cout << o5;
    return 0;
}

