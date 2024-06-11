#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<Book.h>
using namespace std;
class BorrowerRecord{
    private:
        string Name;
        string Id;
        vector<Book*>Books;
    public:
    // Access methods
        vector<Book*> getBook(){
            return this -> Books;
        }
        void setName(string Name){
            this -> Name = Name;
        }
        string getName(){
            return this -> Name;
        }
        void setId(string Id){
            this -> Id = Id;
        }
        string getId(){
            return this -> Id;
        }
        void AttachBook(Book*Book){
            this -> Books.push_back(Book);
        }
        void detachBook(Book*Book){
            for (int i = 0; i < this->Books.size(); i++){
                if (this->Books[i] == Book){
                    this -> Books.erase(this->Books.begin()+i);
                    break;
                }
            }
        }
        BorrowerRecord(string Name, string Id){
            this -> setId(Id);
            this -> setName(Name);
        }
        BorrowerRecord(string Name): BorrowerRecord("NA",Name){}
        BorrowerRecord(): BorrowerRecord("NA","NA"){}

        void display(){
            cout << "Borrower is : " << endl;
            cout << "\tName: \t" << this -> getName() << endl;
        }


};
