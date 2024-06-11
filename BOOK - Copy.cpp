#include <string>
#include <iostream>
#include<vector>
using namespace std;

class BorrowerRecord;

class Book {

private:    

    string number;

    string author;

    string title;

    BorrowerRecord* borrower;
 

public:

    //Constructors

    Book(string number,string author,string title){

        this->setNumber(number);

        this->setAuthor(author);

        this->setTitle(title);

    }

    Book() : Book("NA", "NA", "NA") {}

    Book(string number):Book(number, "NA", "NA") {}
    void attachBorrower(BorrowerRecord* br) {
        this->setBorrower(br);
    }
    void detachBorrower() {
        this->setBorrower(NULL);
    }
     BorrowerRecord *getBorrower() {
        return this->borrower;
    }
    void setBorrower(BorrowerRecord *br_name) {
        this->borrower = br_name;
    }

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

class BorrowerRecord {
private:
    string name;
    vector<Book*> BorroweredBook;
public:
    //Link Book to the Borrower
    void attachBook(Book* bk) {
        this->BorroweredBook.push_back(bk);
    }
    //Unlink a book with a borrower
    void detachBook(Book* bk) {
        int index = 0;
        for (int i = 0; i < this->BorroweredBook.size(); i++) {
            if (this->BorroweredBook[i] == bk) {
                index = i;
                break;
            }
        }
        this->BorroweredBook.erase(this->BorroweredBook.begin() + index);
    }
    // Access methods
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    // Constructors
    BorrowerRecord(string name) {
        this->setName(name);
    }
    BorrowerRecord():BorrowerRecord("NA"){}
    void display() {
        cout << "Borrower:" << endl;
        cout << "\tName" << this->getName() << endl;
    }
};

class Library {
private:
    string name;
    vector<Book*> stock;
    vector<BorrowerRecord*> borrowers;
public:
    Library(string name){
        this ->name = name;
    }
     string getName(){

        return this->name;

    }

    void setName(string name){

        this -> name = name;    

    }
     void addOneBook(Book *book){

        this ->stock.push_back(book);

    }
     //2. Register BorrowerRecord
    void registerOneBorrower(string name) {
        BorrowerRecord* br = new BorrowerRecord(name);
        borrowers.push_back(br);
    }
     //3. Display book available
    void displayBooksAvailableForLoan() {
        cout << "Books available:" << endl;
        for (int i = 0; i < this->stock.size(); i++) {
            if (this->stock[i]->getBorrower() == NULL)
                this->stock[i]->display();
        }
        cout << "=============================" << endl;
    }
    // 4. Display books available for loan
    void displayBooksOnLoan() {
        cout << "Books on loan:" << endl;
        for (int i = 0; i < this->stock.size(); i++) {
            if (this->stock[i]->getBorrower() != NULL)
                this->stock[i]->display();
        }
        cout << "=============================" << endl;
    }
     //5. Lend a book
    void lendOneBook(string number, string name) {
        //find the book on number (available)
        Book* bk = NULL;
        for (int i = 0; i < this->stock.size(); i++) {
            if (this->stock[i]->getNumber() == number) {
                bk = this->stock[i];
                break;
            }
        }
        if (bk == NULL) {
            cout << "Book not exists!";
            return;
        }
        else { // Check book be borrowed yet
            if (bk->getBorrower() != NULL) {
                cout << "Book on loan!" << endl;
                return;
            }
        }
        //find the borrower
        BorrowerRecord* br = NULL;
        for (int i = 0; i < this->borrowers.size(); i++) {
            if (this->borrowers[i]->getName() == name) {
                br = this->borrowers[i];
                break;
            }    
        }
        if (br == NULL) {
            cout << "Borrower not exists" << endl;
            return;
        }
        //attach the book and borrower
        bk->attachBorrower(br);
        br->attachBook(bk);

    }

    //6. Return a book
    void returnOneBook(string number) {
        Book* bk = NULL;
        for (int i = 0; i < this->stock.size(); i++) {
            //Upgrade data structor to find faster, like stack, linklist...
            if (this->stock[i]->getNumber() == number) {
                bk = this->stock[i];
                break;
            }
        }
        if (bk == NULL) {
            cout << "Book not exists!";
            return;
        }
        else {
            BorrowerRecord* br = NULL;
            if (bk->getBorrower() == NULL) {
                cout << "Book not borrowed!" << endl;
                return;
            }
        }
        BorrowerRecord* br = bk->getBorrower();
        //detach the book and borrower
        bk->detachBorrower();
        br->detachBook(bk);
        cout << "Book was return!" << endl;
    }
   
     void display(){

        cout << this->name << endl;

        for(int i=0; i<this->stock.size() ; i++){

            this->stock[i]->display();

        }
         cout << "=============================" << endl;
        cout << "List of Borrower:" << endl;
        for (int i = 0; i < this->borrowers.size(); i++) {
            this->borrowers[i]->display();
        }
        cout << "=============================" << endl;
    }
};


int main() {

    Book b("001","James","Python");

    Book c("002","Mickey","Artictis");

    Book a("003","Oreil","Marchine Learning");
    Library t("UNIVERSITY OF SCIENCE");
    t.addOneBook(&b);
    t.addOneBook(&c);
    t.addOneBook(&a);
    t.registerOneBorrower("Alice");
    t.registerOneBorrower("Bob");
    t.display();
    t.displayBooksAvailableForLoan();
    t.lendOneBook("001", "Alice");
    t.lendOneBook("002", "Bob");
    t.returnOneBook("001");
    t.returnOneBook("002");
    t.displayBooksOnLoan();
    t.displayBooksAvailableForLoan();  
    return 0;

}