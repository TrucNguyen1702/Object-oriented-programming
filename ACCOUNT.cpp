#include <string>
#include <iostream>
#include<vector>
using namespace std;
class AccountOwner;
class Account {

private:    

    string id;

    float balance;
    vector<AccountOwner*> owners;
public:
    Account(string id,float balance){
        this->setid(id);
        this->setbalance(balance);
    }
    Account(): Account("NA",0){}
    Account(string id):Account(id,0){}
    void setid(string id){
        this-> id = id;
        }
    string getid() {

        return this->id;

    }
    void setbalance(float balance){
        this-> balance = balance;
        }
    float getbalance() {

        return this->balance;

    }
    void display() {
        cout << "ID:" << this->getid()<< endl;
        cout << "\tBalance" << this->getbalance() << endl;
    }
    void displayOwners(){
         cout << "Owners of Account " << id << endl;
        for (int i = 0; i < owners.size(); i++) {
            cout << owners[i]->getName() << endl;
        }
    }
    void addOwner(AccountOwner* owner) {
        owners.push_back(owner);
        owner->registerAccount(this);
    }
};
class AccountOwner{
private:
    string name;
     vector<Account*> accounts;
public:
    AccountOwner(string name){
        this->setName(name);
    }
    AccountOwner():AccountOwner("NA"){}
    AccountOwner(string name):AccountOwner(name){}
    void setName(string name){
        this->name = name;
    }
    string getName() {

        return this->name;

    }
    //void register()
    void display() {
        cout << this->getName() << "\n";
    }
};

int main(){
    Account a("123","John");
    Account b("567","Jenny");
}
