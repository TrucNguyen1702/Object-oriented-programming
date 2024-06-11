#include<iostream>
using namespace std;
class complex
{
  float x; // phần thực
  float y; // phần ảo
  public:
  complex(){} // khởi tạo 
  complex( float real, float imag) //khởi tạo
  {
    x=real; 
    y=imag;
   }
  complex operator+(complex c); 
  void display(void);
};
complex complex::operator+(complex c) 
{
  complex temp; // biến tạm
  temp.x = x + c.x;
  temp.y = y + c.y; 
  return(temp); 
}
void complex::display(void) 
{
  cout<< x <<"+ j"<< y <<"\n"; 
}
int main() 
{
  complex c1, c2, c3; //khởi tạo 
  c1 = complex(2.5, 3.5); //khởi tạo
  c2 = complex(1.6, 2.7);
  c3 = c1 + c2; 
  cout<< "c1 = ";
  c1.display(); 
  cout<< "c2 = ";
  c2.display(); 
  cout<< "c3 = ";
  c3.display(); 
  return 0; 
}
#include <iostream>
using namespace std;

class distance {
private:
    int feet, inches; 
public:
    distance() { 
        feet = 0; 
        inches = 0; 
    } 
    distance(int f) { 
        feet = f; 
        inches = 0; 
    } 
    distance(int f, int i) { 
        feet = f; 
        inches = i; 
    } 
    void display() { 
        cout << feet << " " << inches << endl; 
    }
    friend distance operator+(distance, int); 
};

distance operator+(distance d, int x) {
    int totalInches = d.feet * 12 + d.inches + x;
    int feet = totalInches / 12;
    int inches = totalInches % 12;
    return distance(feet, inches);
}

int main() {
    distance d1(2, 5);
    distance d2 = d1 + 10;
    d2.display();
    return 0;
}

#include <iostream>
using namespace std;

class distance {
private:
    int feet, inches; 
public:
    distance() { 
        feet = 0; 
        inches = 0; 
    } 
    distance(int f) { 
        feet = f; 
        inches = 0; 
    } 
    distance(int f, int i) { 
        feet = f; 
        inches = i; 
    } 
    void display() { 
        cout << feet << " " << inches << endl; 
    }
    void getdata() { 
        cout << "Enter distance in feet and inches: "; 
        cin >> feet >> inches; 
    }
    int operator<(distance d1) {
        if (feet < d1.feet)
            return 1;
        else if (feet == d1.feet && inches < d1.inches) 
            return 1;
        else 
            return 0;
    }
};

int main() {
    distance d1, d2;
    d1.getdata(); 
    d2.getdata(); 
    if(d1 < d2)
        cout << "The first distance is smaller." << endl; 
    else
        cout << "The second distance is smaller." << endl;
    return 0;
}
