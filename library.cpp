#include<string>
#include<stdio.h>
#include<iostream>
#include<Book.h>
#include<Library.h>
#include<BorrowerRecord.h>
#include<vector>

using namespace std;
int main() {

    Book a("001","Olivia","C++");
    Book c("002","Oreil","MarchineLearning");
    Book b("003","James","Python");
    Library lib("HCMUS Library");
    lib.AddOneBook(&a);
    lib.AddOneBook(&b);
    lib.AddOneBook(&c);
    b.display();
    c.display();
    a.display();
    lib.display();
    lib.RegisterOneBorrower("Truc");
    lib.RegisterOneBorrower("Nam");
    lib.display();
    lib.lendOneBook("001","Truc");
    lib.lendOneBook("002","Nam");
    lib.DisplayBooksAvailableForLoan();
    lib.DisplayBooksOnLoan();
    return 0;

}