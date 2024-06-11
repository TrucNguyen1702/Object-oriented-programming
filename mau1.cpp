#include <iostream>
#include <map>
#include <string>

using namespace std;

// Forward declaration of classes
class Book;
class Borrower;
class Library;

// Declaration of classes 
class Book{
private:
    string _theCatalogueNumber;
    string _theTitle;
    string _theAuthor;
    Borrower* _theBorrower;
public:
    // Constructor & Destructor
    Book();
    Book(string, string, string);
    ~Book();

    // Getters & Setters
    string getCatalogueNumber();
    void setCatalogueNumber(string);

    string getTitle();
    void setTitle(string);

    string getAuthor();
    void setAuthor(string);

    Borrower* getTheBorrower();
    void setTheBorrower(Borrower*);

    // Other methods
    void attachBorrower(Borrower*);
    void detachBorrower(Borrower*);
    void display();
};

class Borrower{
private:
    string _theName;
    // map of catalogue number and book
    map<string, Book*> _theBorrowedBooks;
public:
    // Constructor & Destructor
    Borrower();
    Borrower(string, map<string, Book*>);
    ~Borrower();

    // Getters & Setters
    string getName();
    void setName(string);

    map<string, Book*> getTheBorrowedBooks();
    void setTheBorrowedBooks(map<string, Book*>);

    // Other methods
    void attachBook(Book*);
    void detachBook(Book*);
};
class Library{
private:
    string _theName;
    // map of catalogue number and book
    map<string, Book*> _theLoanStock;
    // map of borrower name and borrower
    map<string, Borrower*> _theBorrowers;
public:
    //Constructor & Destructor
    Library();
    Library(string);
    ~Library();

    // Getters & Setters
    string getName();
    void setName(string);

    map<string, Book*> getTheLoanStock();
    void setTheLoanStock(map<string, Book*>);

    map<string, Borrower*> getTheBorrowers();
    void setTheBorrowers(map<string, Borrower*>);

    // Other methods
    void registerOneBorrower(Borrower*);
    void addOneBook(Book*);
    void displayBooksAvailableForLoan();
    void displayBooksOnLoan();
    void lendOneBook(string, string);
    void returnOneBook(string, string);
};

// Implementation of classes
Book::Book(){
    cout << "Book is created" << endl;
    _theCatalogueNumber = "Default catalogue number";
    _theTitle = "Default title";
    _theAuthor = "Default author";
    _theBorrower = nullptr;
}

Book::Book(string catalogueNumber, string title, string author){
    cout << "Book is created" << endl;
    this->_theCatalogueNumber = catalogueNumber;
    this->_theTitle = title;
    this->_theAuthor = author;
    this->_theBorrower = nullptr;
}

Book::~Book(){
    cout << "Book is destroyed" << endl;
}

string Book::getCatalogueNumber(){
    return _theCatalogueNumber;
}
void Book::setCatalogueNumber(string catalogueNumber){
    this->_theCatalogueNumber = catalogueNumber;
}

string Book::getTitle(){
    return _theTitle;
}
void Book::setTitle(string title){
    this->_theTitle = title;
}

string Book::getAuthor(){
    return _theAuthor;
}
void Book::setAuthor(string author){
    this->_theAuthor = author;
}

Borrower* Book::getTheBorrower(){
    return _theBorrower;
}

void Book::setTheBorrower(Borrower* theBorrower){
    this->_theBorrower = theBorrower;
}

void Book::attachBorrower(Borrower* aBorrower){
    this->_theBorrower = aBorrower;
}

void Book::detachBorrower(Borrower* aBorrower){
    this->_theBorrower = nullptr;
}

void Book::display(){
    cout << "Catalogue number: " << _theCatalogueNumber << endl;
    cout << "Title: " << _theTitle << endl;
    cout << "Author: " << _theAuthor << endl;
    if (_theBorrower != nullptr){
        cout << "Borrower: " << _theBorrower->getName() << endl;
    }
    else {
        cout << "Borrower: " << "No borrower" << endl;
    }
}

Borrower::Borrower(){
    cout << "Borrower is created" << endl;
    _theName = "Default name";
    _theBorrowedBooks = map<string, Book*>();
}

Borrower::Borrower(string name, map<string, Book*> theBorrowedBooks){
    cout << "Borrower is created" << endl;
    this->_theName = name;
    this->_theBorrowedBooks = theBorrowedBooks;
}

Borrower::~Borrower(){
    cout << "Borrower is destroyed" << endl;
}

string Borrower::getName(){
    return _theName;
}
void Borrower::setName(string name){
    this->_theName = name;
}

map<string, Book*> Borrower::getTheBorrowedBooks(){
    return _theBorrowedBooks;
}
void Borrower::setTheBorrowedBooks(map<string, Book*> theBorrowedBooks){
    this->_theBorrowedBooks = theBorrowedBooks;
}

void Borrower::attachBook(Book* aBook){
    _theBorrowedBooks.insert(pair<string, Book*>(aBook->getCatalogueNumber(), aBook));
}

void Borrower::detachBook(Book* aBook){
    _theBorrowedBooks.erase(aBook->getCatalogueNumber());
}

Library::Library(){
    cout << "Library is created" << endl;
    _theName = "Default name";
    _theLoanStock = map<string, Book*>();
    _theBorrowers = map<string, Borrower*>();
}

Library::Library(string aName){
    cout << "Library is created" << endl;
    _theName = aName;
    _theLoanStock = map<string, Book*>();
    _theBorrowers = map<string, Borrower*>();
}
Library::~Library(){
    cout << "Library is destroyed" << endl;
    _theLoanStock.clear();
    _theBorrowers.clear();
}

map<string, Book*> Library::getTheLoanStock(){
    return _theLoanStock;
}
void Library::setTheLoanStock(map<string, Book*> theLoanStock){
    this->_theLoanStock = theLoanStock;
}

map<string, Borrower*> Library::getTheBorrowers(){
    return _theBorrowers;
}
void Library::setTheBorrowers(map<string, Borrower*> theBorrowers){
    this->_theBorrowers = theBorrowers;
}

void Library::registerOneBorrower(Borrower *aBorrower){
    // add the new borrower to the map
    this->_theBorrowers.insert(pair<string, Borrower*>(aBorrower->getName(), aBorrower));
}

void Library::addOneBook(Book *aBook){
    // add the new book to the map
    cout << "Adding book: " << aBook->getTitle() << " to the library" << endl;
    this->_theLoanStock.insert(pair<string, Book*>(aBook->getCatalogueNumber(), aBook));
}

void Library::displayBooksAvailableForLoan(){
    if (this->_theLoanStock.empty()){
        cout << "No books available for loan" << endl;
        return;
    }
    for (auto book : this->_theLoanStock){
        cout << book.second->getTitle() << endl;
    }
}

void Library::displayBooksOnLoan(){
    bool check = false;
    for (auto borrower : this->_theBorrowers){
        if (!borrower.second->getTheBorrowedBooks().empty() && check == false){
            check = true;
        }
        for (auto book : borrower.second->getTheBorrowedBooks()){
            cout << book.second->getTitle() << endl;
        }
    }
    if (check == false){
        cout << "No books on loan" << endl;
    }
}

void Library::lendOneBook(string aCatalogueNumber, string aBorrowerName){
    cout << "Lending book: " << aCatalogueNumber << " to " << aBorrowerName << endl;
    // find the book
    auto book = this->_theLoanStock.find(aCatalogueNumber);
    // find the borrower
    auto borrower = this->_theBorrowers.find(aBorrowerName);
    if (book != this->_theLoanStock.end() && borrower != this->_theBorrowers.end()){
        // attach the book to the borrower
        borrower->second->attachBook(book->second);
        // add borrower to the book
        book->second->attachBorrower(borrower->second);
        // remove the book from the library's map
        this->_theLoanStock.erase(book);
        // 
    }
    else {
        cout << "The book or the borrower is not registered" << endl;
    }
}

void Library::returnOneBook(string aCatalogueNumber, string aBorrowerName){
    cout << "Returning book: " << aCatalogueNumber << " from " << aBorrowerName << endl;
    auto borrower = this->_theBorrowers.find(aBorrowerName);
    if (borrower != this->_theBorrowers.end()){
        // find the book
        auto book = borrower->second->getTheBorrowedBooks().find(aCatalogueNumber);
        if (book != borrower->second->getTheBorrowedBooks().end()){
            // add the book to the library's map
            this->_theLoanStock.insert(pair<string, Book*>(aCatalogueNumber, book->second));
            // remove the book from the borrower's map
            borrower->second->detachBook(book->second);
            // remove the borrower from the book
            book->second->detachBorrower(borrower->second);
        }
        else {
            cout << "The book is not of the borrower" << endl;
        }
    }
    else {
        cout << "The borrower is not registered" << endl;
    }
}

// main function to test the program

int main(){
    // create a library
    Library *aLibrary = new Library("Library 1");
    // create a books
    Book *book1 = new Book("Catalogue 1", "Book 1", "Author 1");
    Book *book2 = new Book("Catalogue 2", "Book 2", "Author 2");
    Book *book3 = new Book("Catalogue 3", "Book 3", "Author 3");
    Book *book4 = new Book("Catalogue 4", "Book 4", "Author 4");

    // create a borrower
    Borrower *aBorrower = new Borrower("Borrower 1", map<string, Book*>());
    aLibrary->registerOneBorrower(aBorrower);

    // add the books to the library
    aLibrary->addOneBook(book1);
    aLibrary->addOneBook(book2);
    aLibrary->addOneBook(book3);
    aLibrary->addOneBook(book4);

    // display the books available for loan
    cout << "Books available for loan:" << endl;
    aLibrary->displayBooksAvailableForLoan();

    // display the books on loan
    cout << "Books on loan:" << endl;
    aLibrary->displayBooksOnLoan();

    // lend a book
    aLibrary->lendOneBook("Catalogue 1", "Borrower 1");

    // display the books available for loan
    cout << "Books available for loan:" << endl;
    aLibrary->displayBooksAvailableForLoan();

    // display the books on loan
    cout << "Books on loan:" << endl;
    aLibrary->displayBooksOnLoan();

    // return a book
    aLibrary->returnOneBook("Catalogue 1", "Borrower 1");

    // display the books available for loan
    cout << "Books available for loan:" << endl;
    aLibrary->displayBooksAvailableForLoan();

    // display the books on loan
    cout << "Books on loan:" << endl;
    aLibrary->displayBooksOnLoan();

    // free the memory
    delete aLibrary;
    delete book1;
    delete book2;
    delete book3;
    delete book4;
    cout << "End of program" << endl;
    return 0;
}