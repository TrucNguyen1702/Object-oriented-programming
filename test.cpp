#include <iostream>

using namespace std;

#include <string>
#include <iostream>

using namespace std;

class Book {
private:
    string number;
    string author;
    string title;

public:
    // constructors
    Book(string number,string title, string author){
        this->setNumber(number);
        this->setTitle(title);
        this->setAuthor(author)

    }
    Book():Book("NA","NA","NA"){

    }
    
    // Access methods: getters and setters
    void setNumber(string number) {
        this->number = number;
    }
    string getNumber() {
        return this->number;
    }
    void setTitle(string title){
        this->title = title;
    }
    string getTitle(){
        return this->title;
    }
    void setAuthor(string author){
        this->author = author;
    }
    void display() {
        cout << this->getNumber() << endl;
        cout << 
    }
class Library{
    string name;
    vector<Book> stock;
public:
    //1. Add one book
    void addOneBooK(Book*book){
        
    }
}
int main(){
    Book book;
    //book.setNumber( "001 " ) ;
    Book c("002");
    c. display();

    return 0;
}
