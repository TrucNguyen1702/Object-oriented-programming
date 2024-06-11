# include<stdio.h>
# include<iostream>
# include<map>
# include<vector>
# include<string>
# include<queue>
using namespace std;
class Product{
protected:
    int id;
    string name;
    double price;
public:
    Product(int id, string name, double price){
        this-> setId(id);
        this-> setName (name);
        this-> setPrice(price);
    }
    Product(){}
    // Product(int id, string name, double price): id(id),name(name),price(price){}
    void setId(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    int getId()
    {
        return this->id;
    }
    double getPrice()
    {
        return this->price;
    }
    string getName()
    {
        return this->name;
    }
    void display(){
        cout<<"ID: " <<this->getId()<<endl;
        cout<<"Name: "<<this->getName()<<endl;
        cout<<"Price: "<<this->getPrice()<<endl;
    }
};
class Book : public Product{
private:
    string title;
    string author;
public:
    Book(string title, string author)
    {
        this->setTitle(title);
        this->setAuthor(author);
    }
    Book(int id, string name, double price, string title, string author):Product(id,name,price),title(title),author(author){}
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string Author)
    {
        this->author = author;
    }
    string getTitle(){
        return this->title;
    }
    string getAuthor(){
        return this->author;
    }
    void display(){
        cout<<"ID: " <<this->getId()<<endl;
        cout<<"Name: " <<this->getName()<<endl;
        cout<<"Price: " <<this->getPrice()<<endl;
        cout<<"Title: " <<this->getTitle()<<endl;
        cout<<"Author: " <<this->getAuthor()<<endl;
    }
};
class Pen : public Product{
private:
    string type;
    string color;
public:
    Pen(string type, string color){
        this->setType(type);
        this->setColor(color);
    }
    Pen(int id, string name, double price, string type, string color): Product(id, name, price), type(type), color(color){}
    void setType(string type)
    {
        this->type = type;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    string getType()
    {
        return this->type;
    }
    string getColor()
    {
        return this->color;
    }
    void display(){
        cout<<"ID: " <<this->getId()<<endl;
        cout<<"Name: " <<this->getName()<<endl;
        cout<<"Price: " <<this->getPrice()<<endl;
        cout<<"Type: " <<this->getType()<<endl;
        cout<<"Color: " <<this->getColor()<<endl;
    }
};
class Item: public Product{
private:
    Product*product;
    int number;
public:
    Item(Product*product, int number){
        this->setNumber(number);
        this->setProduct(product);
    }
    Item(){}
    // Item(Product*product, int number):product(product),number(number){}
    void setNumber(int number){
        this->number = number;
    }
    void setProduct(Product*product){
        this->product = product;
    }
    int getNumber(){
        return this->number;
    }
    Product* getProduct(){
        return this->product;
    }
    void display(){
        product->display();
        cout<<"Number: "<<this->getNumber()<<endl;
    }
    double getPrice(){
        return product->getPrice()*number;
    }
};
class Cart{
private:
    int id;
    vector<Item*> items;
    // map<string, Item*> items;
public:
    Cart(int id){
        this->setId(id);
    }
    Cart(){}
    // Cart(int id):id(id){}
    void setId(int id){
        this->id = id;
    }
    int getId(){
        return this->id;
    }
    /*map<string, Item*> getItem(){
        return this->items;
    }*/
    void addItem(Product*p, int number){
        Item*item = new Item(p,number);
        items.push_back(item);
    }
    void display(){
        cout<<"Cart Id: "<<this->getId()<<endl;
        double totalPrice = 0;
        for (int i = 0; i < items.size(); i++){
            cout<<"Item: " << i+1<<":"<<endl;
            items[i]->display();
            totalPrice += items[i]->getPrice();
        }
        cout<<"Total Price: "<<totalPrice<<endl;
    }
};
int main(){
    Book* b = new Book(1, "Book A", 19.99, "Title A", "Author A");
    Book* c = new Book(2, "Book A", 29.99, "Title c", "Author C");
    Pen* p = new Pen(2, "Pen B", 3.99, "Ballpoint", "Black");
    Cart* cart = new Cart(1);
    cart->addItem(b,1);
    cart->addItem(p,2);
    cart->addItem(c,3);
    cart->display();
    return 0;
}