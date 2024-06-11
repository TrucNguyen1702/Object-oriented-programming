#include <iostream>
#include <map>

using namespace std;

class Employee
{
private:
    string number;
    string name;
    double salary;

public:
    Employee(string number, string name, double salary)
    {
        this->number = number;
        this->name = name;
        this->salary = salary;
    }

    void setNumber(string number)
    {
        this->number = number;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }

    string getNumber()
    {
        return this->number;
    }
    string getName()
    {
        return this->name;
    }
    double getSalary()
    {
        return this->salary;
    }

    virtual void display() = 0;
};

class Programmer : public Employee
{
private:
    string language;

public:
    Programmer(string number, string name, double salary, string language) : Employee(number, name, salary)
    {
        this->language = language;
    }

    void setLanguage(string language)
    {
        this->language = language;
    }

    string getLanguage()
    {
        return this->language;
    }

    void display()
    {
        cout << "\tNumber: " << this->getNumber() << endl;
        cout << "\tName: " << this->getName() << endl;
        cout << "\tSalary: " << this->getSalary() << endl;
        cout << "\tLanguage: " << this->language << endl;
        cout << endl;
    }
};

class ProjectLeader : public Programmer
{
private:
    map<string, Programmer *> Teams;

public:
    ProjectLeader(string number, string name, double salary, string language) : Programmer(number, name, salary, language) {}

    void addProgrammer(Programmer *p)
    {
        this->Teams.emplace(p->getNumber(), p);
    }

    void display() {
        cout << "-------------------------------" << endl;
        cout << "Project Leader: " << endl;
        Programmer::display();
        cout << "Team: " << endl;
        for (auto it = this->Teams.begin(); it != this->Teams.end(); it++)
        {
            it->second->display();
        }
        cout << "-------------------------------" << endl;
    }
};

class SoftwareHouse
{
private:
    string name;
    map<string, Employee *> Staffs;

public:
    SoftwareHouse(string name)
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

    void addStaff(Employee *staff)
    {
        this->Staffs.emplace(staff->getNumber(), staff);
    }

    void displayStaff()
    {
        cout << "Software House: " << this->getName() << endl;

        cout << "Employees: " << endl;
        for (auto it = this->Staffs.begin(); it != this->Staffs.end(); it++)
        {
            it->second->display();
        }
    }
};

int main()
{
    SoftwareHouse sh("Objects-R-Us");

    Programmer p1("123", "John", 2000, "Ada");
    Programmer p2("234", "Ken", 2500, "C++");
    Programmer p3("456", "Peter", 3000, "Java");

    ProjectLeader pl1("567", "Jon", 4000, "C");
    ProjectLeader pl2("789", "Jessie", 4000, "Java");
    ProjectLeader pl3("999", "James", 5000, "R");

    pl1.addProgrammer(&p1);
    pl1.addProgrammer(&p2);
    pl2.addProgrammer(&p3);

    sh.addStaff(&p1);
    sh.addStaff(&p2);
    sh.addStaff(&p3);
    sh.addStaff(&pl1);
    sh.addStaff(&pl2);

    sh.displayStaff();

    return 0;
}