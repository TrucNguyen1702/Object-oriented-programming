#include<iostream>
#include "PhanSo.h"
using namespace std;
int main(){
    PHANSO ps1(4);
    cout<<"Phan So 1: "<<ps1<<endl;
    PHANSO ps2(8);
    cout<<"Phan So 2: "<<ps2<<endl;
    PHANSO add,multi;
    add=ps1+ps2;
    multi=ps1*ps2;
    cout<<"Add: "<<add<<endl;
    cout<<"Multi: "<<multi<<endl;
    cin>>ps1>>ps2;
    return 0;
}