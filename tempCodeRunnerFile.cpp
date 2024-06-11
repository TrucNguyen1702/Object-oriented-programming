#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AccountOwner;  // Chỉ định trước để phần khai báo ở dưới có thể sử dụng

class Account {
private:
    int id;
    double balance;
    vector<AccountOwner*> owners;  // Danh sách các chủ sở hữu của tài khoản

public:
    Account(int id, double balance) {
        this->setid(id);
        this->setbalance(balance);
    }
    Account(): Account(0,0){}
    Account(int id):Account(id,0){}
     void setid(int id){
        this-> id = id;
        }
    int getid() {

        return this->id;

    }
    void setbalance(float balance){
        this-> balance = balance;
        }
    float getbalance() {

        return this->balance;

    }
    void display() {
        cout << "Account ID: " << id << endl;
        cout << "Balance: " << balance << endl;
    }

    void displayOwners() {
        cout << "Owners of Account " << id << endl;
        for (int i = 0; i < owners.size(); i++) {
            cout << owners[i]->getName() << endl;
        }
    }

    void addOwner(AccountOwner* owners) {
        owners.push_back(owners);
        owners -> registerAccount(this);
    }
};

class AccountOwner {
private:
    string name;
    vector<Account*> accounts;  // Danh sách các tài khoản của chủ sở hữu

public:
    AccountOwner(string name) {
        this->setname(name);
    }
    AccountOwner():AccountOwner("NA"){}
    //AccountOwner(string name):AccountOwner(name){}
    void setname(string name){
        this->name = name;
    }
    string getName() {

        return this->name;

    }
    void display() {
        cout << "Account Owner: " << name << endl;
    }

    void registerAccount(Account* account) {
        accounts.push_back(account);
    }

    void displayAccounts() {
        cout << "Accounts of " << name << endl;
        for (int i = 0; i < accounts.size(); i++) {
            cout << "Account ID: " << accounts[i]->getid() << endl;
            cout << "Balance: " << accounts[i]->getbalance() << endl;
        }
    }
};

int main() {
    // Tạo ra ba tài khoản khác nhau
    Account* account1 = new Account(1, 1000);
    Account* account2 = new Account(2, 500);
    Account* account3 = new Account(3, 2000);

    // Tạo ra các chủ tài khoản
    AccountOwner* owner1 = new AccountOwner("John");
    AccountOwner* owner2 = new AccountOwner("Jenny");
    AccountOwner* owner3 = new AccountOwner("Bob");

    // Thêm các chủ tài khoản vào danh sách chủ sở hữu của tài khoản
    account1->addOwner(owner1);
    account1->addOwner(owner2);
    account2->addOwner(owner3);

    // Hiển thị thông tin tài khoản và chủ tài khoản
    account1->display();  
    account1->displayOwners();  
    account2->displayOwners();  
    owner1->displayAccounts();  
    owner2->displayAccounts();  
    owner3->displayAccounts();  

    // Giải phóng bộ nhớ
    delete account1;
    delete account2;
    delete account3;
    delete owner1;
    delete owner2;
    delete owner3;

    return 0;
}
