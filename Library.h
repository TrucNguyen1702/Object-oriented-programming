#include<string>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<Book.h>
#include<BorrowerRecord.h>
using namespace std;
class Library{
    private:
        string Name;
        vector<Book*>stock;
        vector<BorrowerRecord*>Borrower;
        vector<Book*>getStock(){
            return this->stock;
        }
    public:
        Library(string Name){
            this->setName(Name);
        }
        // Add One Book
        void AddOneBook(Book * Book){
            this->stock.push_back(Book);
        }
        string getName(){
            return this -> Name;
        }
        void setName(string Name){
            this-> Name = Name;
        }
        // Register one borrower
        void RegisterOneBorrower(string Name){
            BorrowerRecord* Borrower = new BorrowerRecord(Name);
            this -> Borrower.push_back(Borrower);
        }
        void DisplayBooksAvailableForLoan(){
            cout<<"Books Available Loan: " << endl;
            for (int i = 0; i < this->getStock().size(); i++){
                if(this->stock[i]->getBorrower()==NULL)
                    this->stock[i]->display();
            }

        }
        void DisplayBooksOnLoan(){
            cout<<"Books On Loan: "<<endl;
            for(int k=0; k < this->Borrower.size();k++){

                if(this->Borrower[k]->getBook().empty()){

                    continue;

                }
                else{
                    cout << "Borrower: " << endl;

                    this -> Borrower[k]->display();

                    cout << this -> Borrower[k]->getName() << " is borrowing " <<endl;

                    for (int i = 0; i < this->getStock().size(); i++){

                        if (this->stock[i]->getBorrower() != NULL) // book is unavailable

                            if(this->Borrower[k]==this->stock[i]->getBorrower()){

                            

                                this->stock[i]->display();

                            }

                            else{

                                continue;

                            }          

                    }

                }
            }

        }
        ////////////////////////////////      
        void lendOneBook(string number, string name){
            Book*bk = NULL;
            for (int i = 0; i < this->stock.size();i++){
                if(number == this->stock[i]->getNumber()){
                    bk = this->stock[i];
                    break;
                }
            }
            BorrowerRecord * br = NULL;
            for (int k = 0; k<this->Borrower.size(),k++){
                if(Name == this->Borrower[k]->getName()){
                    br = this->Borrower[k];
                    break;
                }
            }
            //  Check On Loan
            if(bk == NULL){
                cout <<"Book not exis!!"<<endl;
                return;
            }
            else{
                if(bk->getBorrower() != NULL){
                    cout<<"Book on loan!" << endl;
                    return 0;
                }
            }
            bk -> AttachBorrower(br);
            br -> AttachBook(bk);
        }
        // return one book
        void ReturnOneBook(string number){
            Book*book = NULL;
            for(int i = 0; i<this->stock.size();i++){
                if(number == this->stock[i]->getNumber()){
                    book = this->stock[i];
                    break;
                }
            }
            if(Book == NULL){
                cout<< "Book not exists!";
                return;
            }
            if (Book->getBorrower() == NULL){
                cout<<"Book not borrowed!"<<endl;
                return;
            }
            BorrowerRecord *Borrower = Book -> getBorrower();
            Book->detachBorrower();
            Borrower->detachBook(Book);
        }

        ////////////////////////////////
        void displayS(){
            cout<< "Library's name is " + this->Name << endl;
            for (int i = 0; i < this->stock.size(); i++){
                cout<< "Book" << i+1 << ":"<<endl;
                (*stock[i]).display();
                cout << "\n";
            }
            for (int i = 0; i < this->borrower.size(); i++){
                cout<<"Borrower is: "<< endl;
                this->Borrower[i]->display();
                cout << "\n";
            }
        }

};
