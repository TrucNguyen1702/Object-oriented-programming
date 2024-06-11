#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book;
class BorrowerRecord;
class Library;

class Book
{
private:
    string number;
    string author;
    string title;
    BorrowerRecord *borrower;

public:
    Book(string number, string author, string title)
    {
        this->setNumber(number);
        this->setAuthor(author);
        this->setTitle(title);
        this->setBorrower(NULL);
    }
    Book(string title) : Book("NA", "NA", title) {}
    Book() : Book("NA", "NA", "NA") {}

    // Number
    void setNumber(string number)
    {
        this->number = number;
    }
    string getNumber()
    {
        return this->number;
    }

    // Author
    void setAuthor(string author)
    {
        this->author = author;
    }
    string getAuthor()
    {
        return this->author;
    }

    // Title
    void setTitle(string title)
    {
        this->title = title;
    }
    string getTitle()
    {
        return this->title;
    }

    // Borrower
    void setBorrower(BorrowerRecord *borrower)
    {
        this->borrower = borrower;
    }
    BorrowerRecord *getBorrower()
    {
        return this->borrower;
    }
    void attachBorrower(BorrowerRecord *borrower)
    {
        this->setBorrower(borrower);
    }
    void detachBorrower()
    {
        this->setBorrower(NULL);
    }

    void display()
    {
        cout << "Book: " << endl;
        cout << "\tNumber: " << this->getNumber() << endl;
        cout << "\tAuthor: " << this->getAuthor() << endl;
        cout << "\tTitle: " << this->getTitle() << endl;
    }
};

class BorrowerRecord
{
private:
    string name;
    vector<Book *> books;

public:
    BorrowerRecord(string name)
    {
        this->setName(name);
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }

    void attachBook(Book *book)
    {
        this->books.push_back(book);
    }
    void detachBook(Book *book)
    {
        for (int i = 0; i < this->books.size(); i++)
        {
            if (this->books[i] == book)
            {
                this->books.erase(this->books.begin() + i);
                break;
            }
        }
    }

    void display()
    {
        cout << "Borrower: " << endl;
        cout << "\tName: " << this->getName() << endl;
    }
};

class Library
{
private:
    string name;
    vector<Book *> stock;
    vector<BorrowerRecord *> borrowers;

public:
    Library(string name)
    {
        this->setName(name);
    }

    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }

    // 1. Add one book
    void addOneBook(Book *book)
    {
        this->stock.push_back(book);
    }

    // 2. Register one borrower
    void registerOneBorrower(string name)
    {
        BorrowerRecord *borrower = new BorrowerRecord(name);
        this->borrowers.push_back(borrower);
    }

    // 3. Display books available
    void displayBooksAvailable()
    {
        cout << "Books Available:" << endl;
        for (int i = 0; i < this->stock.size(); i++)
            if (this->stock[i]->getBorrower() == NULL)
                this->stock[i]->display();
    }

    // 4. Display books on loan
    void displayBooksOnLoan()
    {
        cout << "Books On Loan:" << endl;
        for (int i = 0; i < this->stock.size(); i++)
            if (this->stock[i]->getBorrower() != NULL)
                this->stock[i]->display();
    }

    // 5. Lend one book
    void lendOneBook(string number, string name)
    {
        // Find book
        Book *book = NULL;
        for (int i = 0; i < this->stock.size(); i++)
        {
            if (this->stock[i]->getNumber() == number)
            {
                book = this->stock[i];
                break;
            }
        }
        if (book == NULL)
        {
            cout << "Book not exists";
            return;
        }
        if (book->getBorrower() != NULL)
        {
            cout << "Book on loan" << endl;
            return;
        }

        // Find borrower
        BorrowerRecord *borrower = NULL;
        for (int i = 0; i < this->borrowers.size(); i++)
        {
            if (this->borrowers[i]->getName() == name)
            {
                borrower = this->borrowers[i];
                break;
            }
        }
        if (borrower == NULL)
        {
            cout << "Borrower not exists" << endl;
            return;
        }

        // Attach book and borrower
        book->attachBorrower(borrower);
        borrower->attachBook(book);
    }

    // 6. Return one book
    void returnOneBook(string number)
    {
        // Find book
        Book *book = NULL;
        for (int i = 0; i < this->stock.size(); i++)
        {
            if (this->stock[i]->getNumber() == number)
            {
                book = this->stock[i];
                break;
            }
        }
        if (book == NULL)
        {
            cout << "Book not exists";
            return;
        }
        if (book->getBorrower() == NULL)
        {
            cout << "Book not borrowed" << endl;
            return;
        }
        BorrowerRecord *borrower = book->getBorrower();

        // Detach book and borrower
        book->detachBorrower();
        borrower->detachBook(book);
    }

    void display()
    {
        cout << "Library's Name: " << this->getName() << endl;
        cout << "Stock: " << endl;
        for (int i = 0; i < this->stock.size(); i++)
            this->stock[i]->display();
        cout << "Borrowers: " << endl;
        for (int i = 0; i < this->borrowers.size(); i++)
            this->borrowers[i]->display();
    }
};

int main()
{
    Book c("001", "ABC", "C");
    Book java("002", "XYZ", "Java");
    Book python("003", "KLM", "Python");
    Library lib("HCMUS Library");

    // Add one book
    lib.addOneBook(&c);
    lib.addOneBook(&java);
    lib.addOneBook(&python);
    // Register one borrower
    lib.registerOneBorrower("Alice");
    lib.registerOneBorrower("Bob");
    // Display library
    lib.display();
    // Display books available
    lib.displayBooksAvailable();
    // Lend one book
    lib.lendOneBook("001", "Alice");
    lib.lendOneBook("003", "Bob");
    // Return one book
    lib.returnOneBook("003");
    // Display books on loan
    lib.displayBooksOnLoan();

    return 0;
}