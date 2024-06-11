/// Nguyen Thanh Truc 
/// MSSV : 20110342
/// Bai tap thuc hanh tong jop
// BAI 1
#include <iostream>
#include <math.h>
using namespace std;
class phanso
{
private:
    double a;
    double b;
public:
    void nhapsl()
    {
        cout << "\n nhap tu so :"; cin >> a;
        cout << " nhap mau so :"; cin >> b;
    }
    void insl()
    {
        cout << " " << a << "/" << b;
    }
    bool operator == (phanso &);
    bool operator != (phanso &);
    bool operator > (phanso &);
    bool operator < (phanso &);
    bool operator >= (phanso &);
    bool operator <= (phanso &);
    int phanso::ucln(int a, int b)
    {
        a = abs(a); b = abs(b);
        if (a*b == 0) return 1;
        while (a != b)
        if (a>b) a -= b;
        else b -= a;
        return a;
    }
    // rut gon ps
    void phanso::rutgon()
    {
        int u;
        u = ucln(a, b);
        a = a / u;
        b = b / u;
    }
};
bool phanso::operator > (phanso &r)
{
    int ts1, ms1;
    ts1 = a*r.b - b*r.a;
    ms1 = b * r.b;
    return (ts1*ms1 > 0);
}
bool phanso::operator < (phanso & r)
{
    if (r>*this)
        return true;
        return false;
}
bool phanso::operator >= (phanso & r)
{
    if (r>*this)
        return true;
    return false;
}
bool phanso::operator <= (phanso & r)
{
    if (r < *this)
        return true;
    return false;
}
phanso max(phanso a[], int n)
{
    phanso max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= max) max = a[i];
    }
    return max;
}
phanso min(phanso a[], int n)
{
    phanso min = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= min) min = a[i];
    }
    return min;
}
void sapxep(phanso a[], int n)
{
    phanso tam;
    int i, j;
    for (i = 0; i < n; ++i)
    for (j = i + 1; j < n; ++j)
    if (a[j] < a[i])
    {
        tam = a[i];
        a[i] = a[j];
        a[j] = tam;
    }
}
bool phanso::operator == (phanso & r)
{
    if (!(*this>r) && !(r>*this))
        return true;
    return false;
}
void main()
{
    phanso p, a[100], psmax,psmin,x;
    int n;
    bool tx=false;
    cout << "nhap so luong phan so: ";
    cin >> n;
  
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap vao so thu " << i+1 << ": "; a[i].nhapsl();
    }
    cout << "\nDay sap xep la: ";
    sapxep(a, n);
    for (int i = 0; i < n; i++)
    {
        a[i].insl();
    }
    cout << "\nPhan so lon nhat la: ";
    psmax = max(a, n);
    psmax.insl();
    cout << "\nPhan so nho nhat la: ";
    psmin = min(a, n);
    psmin.insl();
    cout << "\nDay phan so sau khi rut gon la: ";
    for (int i = 0; i < n; i++)
    {
        a[i].rutgon();
    }
    for (int i = 0; i < n; i++)
    {
        a[i].insl();
    }
    x.nhapsl();
    for (int i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            tx = true;
            cout << "\nPhan so vua nhap co trong day phan so. ";
            break;
        }
    }
    if (tx == false) cout << "Phan so vua nhap khong co trong day";
    cout << "\n\n";
    system("pause");
}