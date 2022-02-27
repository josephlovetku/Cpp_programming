#include <iostream>
using namespace std;

class rectangle {
public:
	typedef int unit;
  	void area();  	
	void set(unit wd, unit ht);  	
private:
	unit width;
	unit height;
};

void rectangle::set(unit wd, unit ht) 
{
	width = wd;
	height = ht;
}


void rectangle::area() 
{
  cout << "The area of the rectangle is: " << width * height << endl;
}

int main()
{
  rectangle obj; //creating object of rectangle class
  rectangle::unit x, y;
  cout << "Enter width: "; 
  cin >> x;
  cout << "Enter height: ";
  cin >> y;
  obj.set(x, y);
  obj.area(); 
  return 0;
}
