// Ho va ten : NGUYEN THANH TRUC
// MSSV:20110342
// BAI 2
#include<iostream>
#include "PhanSo.h"
#include<math.h>
using namespace std;
class PhanSo
{
    int tu,mau;
    public PhanSo()
    {
        tu=0;
        mau=1;
    }
}
void set(int t,int m)
{
    tu=t;
    mau=m;
}
struct PhanSo
{
    int tu,mau;
};
int uscln(int a, int b)
{
    if(b==0) return abs(a);
    return uscln(b,a%b);
}
void PS_Rutgon(PhanSo*a)
{
    int u = uscln(a->tu, a->mau);
    a->tu /= u;
    a->mau /= u;
    if(a->mau<0)
    {
        a->tu = -a->tu;
        a->mau = -a->mau;
    }
}
void PS_Nhap(PhanSo*a)
{
    cout<<"Nhap lan luot tu va mau cua phan so";
    cin >> tu >> mau;
}
void PS_Xuat(PhanSo a)
{
    cout << tu << "/" <<mau<<endl;
}
void PS_CONG(PhanSo a,PhanSo b)
{
    PhanSo c;
    c.tu = tu.a*b.mau+a.mau*b.tu;
    c.mau = a.mau*b.mau;
    PS_Rutgon(&c);
    return c;
}
void PS_Nhan(PhanSo a,PhanSo b)
{
    PhanSo c;
    c.tu=a.tu*b.tu;
    c.mau=a.mau*b.mau;
    PS_Rutgon(&c);
    return c;
}