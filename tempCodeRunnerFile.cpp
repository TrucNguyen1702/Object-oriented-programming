#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;

class Book {
    private:    // information hidden
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

        Book(string title):Book(title, "NA", "NA") {}

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

            cout << this->getNumber()<<endl;

            cout << this->getAuthor()<<endl;

            cout << this->getTitle()<<endl;
        }
    

};

 

int main() {

    Book b;

    b.setNumber("001");

    b.setAuthor("James");

    b.setTitle("Python");

    b.display();

    return 0;

}