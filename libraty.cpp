#include <string>
#include <iostream>
#include <vector>
using namespace std;
class BorrowerRecord;

class Book {
private:    // information hidden
    string number;
    string author;
    string title;
    BorrowerRecord* borrower;    // assoc att

public:
    void attachBorrower(BorrowerRecord* br) {
        this->setBorrower(br);
    }
    // Overloading Constructors: no return type
    // full constructor
    Book(string number, string author, string title) {
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
        this->setBorrower(NULL);
    }
    // chaining constructor
    Book(string number) : Book(number, "NA", "NA") {
    }

    // default constructor
    Book() : Book("000") {
    }

    // access methods: getters and setters
    BorrowerRecord* getBorrower() {
        return this->borrower;
    }
    void setBorrower(BorrowerRecord* br) {
        this->borrower = br;
    }
    string getNumber() {
        return this->number;
    }
    void setNumber(string number) {
        this->number = number;
    }
    void setAuthor(string author) {
        this->author = author;
    }
    string getAuthor() {
        return this->author;
    }
    void setTitle(string title) {
        this->title = title;
    }
    string getTitle() {
        return this->title;
    }
    void display() {
        cout << "Book:" << endl;
        cout << "\tNumber:\t" << this->getNumber() << endl;
        cout << "\tAuthor:\t" << this->getAuthor() << endl;
        cout << "\tTitle:\t" << this->getTitle() << endl;
    }
};

class BorrowerRecord {
    string name;
    vector<Book*> books;
public:
    void attachBook(Book* book) {
        this->books.push_back(book);
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
    void display() {
        cout << "Borrower:" << endl;
        cout << "\tName:\t" << this->getName() << endl;
    }
};
class Library {
private:
    string name;
    vector<Book*> stock;
    vector<BorrowerRecord*> borrowers;

public:
    Library(string name) {
        this->setName(name);
    }
    // 5. Lend one book
    void lendOneBook(string number, string name) {
        // find the book on number
        Book* bk = NULL;
        for (int i = 0; i < this->stock.size(); i++) {

        }

        // find the borrower on name
        BorrowerRecord* br = NULL;
        for (int i = 0; i < this->borrowers.size(); i++) {

        }

        // attach bk and br
    }
    // 3. Display books available for loan
    void displayBooksAvailableForLoan() {
        cout << "Books Available For Loan:" << endl;
        for (int i = 0; i < this->stock.size(); i++)
            if (this->stock[i]->getBorrower() == NULL) // book is available
                this->stock[i]->display();
    }
    // 4. Display books on loan
    void displayBooksOnLoan() {
        cout << "Books On Loan:" << endl;
        for (int i = 0; i < this->stock.size(); i++)
            if (this->stock[i]->getBorrower() != NULL) // book is available
                this->stock[i]->display();
    }
    // 2. Add one book -> stock
    void addOneBook(Book *book) {
        this->stock.push_back(book);
    }
    // 1. Register one borrower
    void registerOneBorrower(string name) {
        // create a object of BorrowerRecord
        BorrowerRecord* borrower = new BorrowerRecord(name);
        // add the borrower to "borrowers" att.        
        this->borrowers.push_back(borrower);
    }
    
    void display() {
        cout << "Lib's Name: " << this->getName() << endl;
        cout << "Stock: " << endl;
        for (int i = 0; i < this->stock.size(); i++)
            this->stock[i]->display();
        cout << "Borrowers: " << endl;
        for (int i = 0; i < this->borrowers.size(); i++)
            this->borrowers[i]->display();
    }

    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }
};
int main() {
    Book c("001", "ABC", "C");
    Book java("002", "XYZ", "Java");
    Book python("003", "KLM", "Python");
    Library lib("HCMUS Lib");
    // Add one book
    lib.addOneBook(&c);
    lib.addOneBook(&java);
    lib.addOneBook(&python);
    // Register one borrower
    lib.registerOneBorrower("Alice");
    lib.registerOneBorrower("Bob");
    //lib.display();
    // Display books available for loan
    lib.displayBooksAvailableForLoan();
    // Display books on loan
    lib.displayBooksOnLoan();
    // Lend one book
    lib.lendOneBook("001", "Alice");
}