#include <bits/stdc++.h>
using namespace std;
 
#include <iostream>
class Counter
{
private:
    int count;
public:
    Counter(int c=0):count(c){}
    Counter& operator++(){
        count++;
        return *this;
    }
    Counter operator++(int){
        Counter temp(*this);
        count++;
        return temp;
    }
    void display()
    {
        cout << this->count << endl;
    }
};
int main() {
	Counter c(7);
	++c;
	Counter d=c++;
	c.display();
	d.display();
	return 0;
}
