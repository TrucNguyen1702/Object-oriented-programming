#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<BorrowerRecord.h>

using namespace std;
class Book {
    private:    // information hidden
        string number;
        string author;
        string title;
        BorrowerRecord Borrower;
    public:

    //Constructors

        Book(string number,string author,string title){

            this->setNumber(number);

            this->setAuthor(author);

            this->setTitle(title);

            this->setBorrower(NULL);

        }

        Book() : Book("NA", "NA", "NA") {}

        Book(string number): Book(number,"NA","NA") {}
        Book(string number, string title): Book(number,"NA",title){}
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
        void Book::setBorrower(BorrowerRecord * Borrower = NULL){
            this -> Borrower = Borrower;
        }
        BorrowerRecord* getBorrower(){
            return this -> Borrower;
        }
        void AttachBorrower(BorrowerRecord*Borrower){
            setBorrower(Borrower);
        }
        void detachBorrower(){
            setBorrower(NULL);
        }
        void display() {
            cout << "Book" << endl;

            cout << this->getNumber()<<endl;

            cout << this->getAuthor()<<endl;

            cout << this->getTitle()<<endl;
        }
    

};
