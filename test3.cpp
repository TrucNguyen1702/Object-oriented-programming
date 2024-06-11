# include<stdio.h>
# include<iostream>
# include<map>
# include<vector>
# include<string>
# include<queue>
using namespace std;
class Vaccine{
protected:
    int id;
    int date;
public:
    Vaccine(int id, int date){
        this-> setId(id);
        this-> setDate(date);
    }
    Vaccine(){}
    void setId(int id)
    {
        this->id = id;
    }
    void setDate(int date)
    {
        this->date = date;
    }
    int getId()
    {
        return this->id;
    }
    int getDate()
    {
        return this->date;
    }
    virtual string getName(){
        return "";
    }
};
class Pfizer : public Vaccine {
/*private:
    string name;*/
public:
    Pfizer(int id,int date) : Vaccine(id,date) {}
    string getName() override {
        return "Pfizer";
    }
};
class Moderna : public Vaccine {
public:
    Moderna(int id, int date) : Vaccine(id, date) {}
    string getName() override {
        return "Moderna";
    }
};
class Person{
private:
    int id;
    string name;
    int yearofBirth;
    vector<Vaccine*> vaccines;
public:
    Person(int id, string name, int yearofBirth){
        this-> setId(id);
        this-> setName(name);
        this-> setYearOfBirth(yearofBirth);
    }
    Person(){}
    void setId(int id)
    {
        this-> id = id;
    }
    void setName(string name)
    {
        this-> name = name;
    }
    void setYearOfBirth(int yearofBirth)
    {
        this-> yearofBirth = yearofBirth;
    }
    int getId()
    {
        return this->id;
    }
    int getYearOfBirth()
    {
        return this->yearofBirth;
    }
     string getName()
    {
        return this->name;
    }
    void immunize(Vaccine* vaccine) {
        vaccines.push_back(vaccine);
    }
    void display(){
        cout<<"Certificate of Immunization"<<endl;
        cout<<"ID: " <<this->getId()<<endl;
        cout<<"Year of birth: "<<this->getYearOfBirth()<<endl;
        cout<<"Name: " <<this->getName()<<endl;
        cout << "---------------------------------------" << endl;
        cout << "Immunization Records:" << endl;

        for (int i = 0; i < vaccines.size(); i++) {
            cout << "Dose " << i + 1 << ": " << vaccines[i]->getName() << " - " << vaccines[i]->getDate() << endl;
        }
    }
};
int main(){
    Pfizer pfizer1(1, 2022);
    Pfizer pfizer2(2, 2023);

    Moderna moderna(3, 2024);

    Person person1(123456789, "John Doe", 1980);
    Person person2(987654321, "Jane Smith", 1990);

    person1.immunize(&pfizer1);
    person1.immunize(&pfizer2);

    person2.immunize(&moderna);
    person2.immunize(&pfizer1);

    person1.display();
    cout << endl;
    person2.display();

    return 0;
}