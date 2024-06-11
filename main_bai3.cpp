#include "Time.h"
using namespace std;
int main(){
    Time t(12,1,1);
    t.display();
    t.SetTime(23,59,59);
    t.display();
    t.nextSecond();
    t.display();
    t.nextSecond();
    t.display();
    t.SetTime(7,0,0);
    t.display();
    t.previousSecond();
    t.display();
    return 0;
}