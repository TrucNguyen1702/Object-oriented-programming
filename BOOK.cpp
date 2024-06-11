#include <string>
#include <iostream>
#include<vector>
using namespace std;

 

class Book {

private:    

    string number;

    string author;

    string title;

 

public:

    //Constructors

    Book(string number,string author,string title){

        this->setNumber(number);

        this->setAuthor(author);

        this->setTitle(title);

    }

    Book() : Book("NA", "NA", "NA") {}

    Book(string number):Book(number, "NA", "NA") {}

    // access methods: getters and setters

    void setNumber(string number){

        this->number = number;

    }

    string getNumber() {

        return this->number;

    }

    void setAuthor(string author) {

        this->author = author;

    }

    string getAuthor(){

        return this->author;

    }

    void setTitle(string title) {

        this->title = title;

    }

    string getTitle(){

        return this->title;

    }

    void display() {
        cout << this->getNumber() << "\t" << this->getAuthor() << "\t" << this->getTitle() << "\n";
    }

};

class Library {
private:
    string namelib;
    vector<Book*> stock;
public:
    Library(string namelib){
        this ->namelib = namelib;
    }
     void addOneBook(Book *book){

        this ->stock.push_back(book);

    }

    string getName(){

        return this->namelib;

    }

    void setName(string namelib){

        this -> namelib = namelib;    

    }
     void display(){

        cout << this->namelib << endl;

        for(int i=0; i<this->stock.size() ; i++){

            this->stock[i]->display();

        }

    }
};
class BorrowerRecord {
private:
    string namebor;
public:
    // Access methods
    void setName(string namebor) {
        this->namebor = namebor;
    }
    string getName() {
        return this->namebor;
    }
    // Constructors
    BorrowerRecord(string namebor) {
        this->setName(namebor);
    }
    void display() {
        cout << "Borrower:" << endl;
        cout << "\tName" << this->getName() << endl;
    }
};

int main() {

    Book b("001","James","Python");

    Book c("002","Mickey","Artictis");

    Book a("003","Oreil","Marchine Learning");
    Library t("UNIVERSITY OF SCIENCE");
    t.addOneBook(&a);
    t.addOneBook(&b);
    t.addOneBook(&c);
    t.display();
    return 0;

}