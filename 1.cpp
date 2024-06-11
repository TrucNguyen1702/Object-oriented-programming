# include<stdio.h>
# include<iostream>
# include<map>
# include<vector>
# include<string>
# include<queue>
using namespace std;

class Person;
class Professor;
class Student;
class Section;
class Course;
class Transcript;
class TranscriptEntry;
class ScheduleOfClasses;
class EnrollmentStatus;

class Person
{
private:
    string name;
    string ssn;
public:
    // Constructors
    Person(string name, string ssn){
        this-> setName (name);
        this-> setSsn(ssn);
    }
    Person(string name): Person(name, "NA"){

    }
    Person(): Person("NA","NA"){

    }
    void displayName(){
        cout<< this->getName() <<endl;
    }
    // GET & SET
    void setSsn(string ssn)
    {
        this->ssn = ssn;
    }
    void setName(string nme)
    {
        this-> name = name;
    }
    string getSsn(){
        return this -> ssn;
    }
    string getName(){
        return this -> name;
    }
    void display(){
        cout<< this->getName() <<"\t"<< this->getSsn();
    }
    virtual void display(){
        cout<<"Ho va ten: "<< this -> getName() << endl;
        cout<<"ID:" << this->getSsn()<<endl;
    }
};

class Professor: public Person
{
private:
    string title;
    string department;
    map<string,Section*> sections;
    map<string, Student*> advise;
public:
    void setTitle(string title){
        this->title = title;
    }
    string getTitle(){
        return this->title;
    }
    void addDepartment(string department){
        this->department = department;
    }
    // full contructor
    Professor(string Id, string name, string title, string department): Person(Id, name){
        this->setTitle(title);
        this->addDepartment(department);
    }
    Professor() :Person(){
        this->setTitle("NA");
        this->addDepartment(NULL);
    }
    // agree to teach
    void agreeToTeach(Section *section){
        this->section.insert({section->getSectionNo(), section});
        section->setInstructor(this);
    }
    void removeSection(Section* section);
    //display
    void displayNamePro(){
        cout<< "Professor: ";
        Person::displayName();
    }
    void display(){
        cout<<"========= Professor ========="<<endl;
        Person::display();
        cout<<"Title: "<< this->getTitle()<<endl;
        cout<<"Department: "<< this->department<<endl;
    }
};
class Student: public Person{
private:
    string major, degree;
    string department;
    Professor* professor;
    map<string, Section*> sections;
    vector<Section*>attends;
    Transcript* transcript;
public:
    void setMajor(string major){
        this->major = major;
    }
    void setDegree(string degree){
        this->degree = degree;
    }
    void setDepartment(string department){
        this->department = department;
    }
    void setTranscript(Transcript*transcript){
        this -> transcript = transcript;
    }
    string getMajor(){
        return this -> major;
    }
    string getDegree(){
        return this -> degree;
    }
    string getDepartment(){
        return this -> department;
    }
    Transcript* getTranscript(){
        return this -> transcript;
    }
    // full contructor
    Student(string id, string name, string major, string degree, string department): Person(id,name){
        this -> setMajor(major);
        this -> setDegree(degree);
        this -> setDepartment(department);
        this -> setTranscript(transcript);
    }
    Student():Student("NA","NA","NA","NA", NULL){}
    void advisor(Professor * professor){
        this->professor = professor;
    }
    map<string, Section*> getSection(){
        return this->sections;
    }
    void addSection(Section * s){
        attends.push_back(s);
    }
    void dropSection(Section*s){
        for (int i = 0; i < attends.size();i++){
            if(attends.at(i) == s){
                attends.erase(attends.begin()+i);
            }
        }
    }
    bool isEnrollIn(Section*s){
        if (find(attends.begin(), attends.end(), s) != attends.end()){
            return true;
        } else {
            return false;
        }
    }
    void printTranscript();
    void displayCourseSchedule();
    bool isCurrentlyEnrolledInSimilar(Section*s);
    void display(){
        cout << "========= STUDENT =========\n";
        this -> Person::display();
        cout << "Major: "<< this->major<<endl;
        cout << "Degree: "<< this->degree<<endl;
    }
};
class Course {
private:
    string courseNo;
    string courseName;
    double credits;
    map<string, Course*> prerequisites;
    map<string, Section*> offeredAsSection;
public:
    bool hasPrerequisites(){
        if (prerequisites.size()>0){
            return true;
        } else {
            return false;
        }
    }
    void setCourseNo(string courseNo){
        this->courseNo = courseNo;
    }
    void setCourseName(string courseName){
        this->courseName = courseName;
    }
    void setCredits(double credits){
        this->credits = credits;
    }
    string getCourseNo(){
        return this -> courseNo;
    }
    string getCourseName(){
        return this -> courseName;
    }
    double getCredits(){
        return this -> credits;
    }
    map<string, Section*> getSection(){
        return this->offeredAsSection;
    }
    map<string, Course*> getCourse(){
        return this->prerequisites;
    }
    void addSection(Section*s){
        offeredAsSection[s->getSectionNo()] = s;
    }
    Section*scheduleSelection(char day, string time, string room, int capacity){
        Section*s = new Section(offeredAsSection.size()+1,day,time, this, room,capacity);
        addSection(s);
        return (s);
    }
};
class Section{
private:
    int sectionNo;
    char dayOfWeek;
    string timeOfDay;
    string room;
    int capacity;
    Course* representedCourse;
    ScheduleOfClasses* offeredIn;
    Professor* instructor;
    map<string, Student*> enrolledStudents;
    map<Student*,TranscriptEntry*> assignedGrades;
public:
    Section(int sectionNo, char day, string time, string room, int num, Course*c, ScheduleOfClasses*Class, Professor*p){
        this -> setSectionNo(sectionNo);
        this -> setDayOfWeek(day);
        this -> setTimeOfDay(time);
        this -> setRoom(room);
        this -> setCapacity(num);
        this -> setCourse(c);
        this -> setClass(Class);
        this -> setInstructor(p);
    }
    Section(int sectionNo, char day, string time, string room, int num, Course*c):Section(sectionNo, day, time, room,c,NULL, NULL){
    }
    Section(int sectionNo, int num, Course*c): Section(sectionNo,"NA","NA","NA", num ,c, NULL, NULL){
    }
    Section(Course* c): Section("NA",c){
    }
    // setter and getter
    void setSectionNo(int sectionNo) {
        this->sectionNo = sectionNo;
    }
    void setDayOfWeek(char day){
        this->dayOfWeek = day;
    }
    void setTimeOfDay(string time){
        this->timeOfDay = time;
    }
    void setRoom(string room){
        this ->room = room;
    }
    void setCapacity(int capacity){
        this-> capacity = capacity;
    }
    void setCourse(Course*c){
        this ->representedCourse = c;
    }
    void setClass(ScheduleOfClasses*Class){
        this-> offeredIn = Class;
    }
    void setInstructor(Professor*p){
        this->instructor = p;
    }
    int getSectionNo(){
        return this -> sectionNo;
    }
    char getDayOfWeek(){
        return this -> dayOfWeek;
    }
    string getTimeOfDay(){
        return this -> timeOfDay;
    }
    string getRoom(){
        return this -> room;
    }
    int getCapacity(){
        return this -> capacity;
    }
    Course* getCourse(){
        return this -> representedCourse;
    }
    ScheduleOfClasses*getClasses(){
        return this -> offeredIn;
    }
    Professor* getInstructor(){
        return this-> instructor;
    }
    void display(){
        cout << "======== SECTION =========\n"<<endl;
        cout << "Section No: " << this -> sectionNo << endl;
        cout << "Day of Week: "<< this -> dayOfWeek << endl;
        cout << "Time of Day: " << this -> timeOfDay << endl;
        cout << "Room: "<< this-> room<<endl;
        cout << "Seating Capacity: "<< this -> capacity << endl;
        if(this -> representedCourse != NULL)
            cout << "Course: " << this->representedCourse->getCourseName() <<endl;
        /*if (this -> offeredIn != NULL){
            cout << "Semester : "<< this -> offeredIn -> getSemester()<<endl;*/
        if(this->instructor != NULL)
            cout << "Instructor: " << this -> instructor -> getName()<<endl;
    }
    EnrollmenStatus enroll(Student*s){
        Transcript*transcript = s->getTranscript();
        if (s->isEnrolledIn(this) || transcript->verifyCompletion(representedCourse)) {
            return EnrollmentStatus::prevEnroll;
        }
        Course*c = representedCourse;
        if(c->hasPrerequisites()){
            for(Course*pre: c->getPrerequisites()){
                if(!transcript->verifyCompletion(pre)){
                    return EnrollmenStatus->prereq;
                }
            }
        }
        if (!confirmSeatAvailability()){
            return EnrollmentStatus::sec;
        }
        enrolledStudents[s->getSsn()] = s;
        s->addSection(this);
        return EnrollmentStatus::success;
    };
    bool drop(Student*s);
    bool postGrade(Student*s, double grade);
    bool confirmSeatAvailability(){
        return (this->enrolledStudents.size()<this->getCapacity());
    }
};
class ScheduleOfClasses{
private:
    string semester;
    map<string,Section*> sectionsOffered;
public:
    ScheduleOfClasses(string semester){
        this->setSemeter(semester);
    }
    string getSemeter(){
        return this -> semester;
    }
    void setSemeter(string semester){
        this-> semester = semester;
    }
    void addSection(Section*sec){
        string key = sec -> getSectionNo();
        sectionsOffered.insert({key,sec});
        //sec->setOfferedIn(this);
    }
    Section* findSection(int sectionNo){
        return this->sectionsOffered{sectionNo};
    }
};
class TranscriptEntry{
private:
    string grade;
    Student*student;
    Section*section;
    Transcript*transcript;
public:
    void setGrade(string grade){
        this -> grade = grade;
    }
    string getGrade(){
        return this->grade;
    }
    void setStudent(Student*student){
        this-> student = student;
    }
    Student*getStudent(){
        return this->student;
    }
    void setSection(Section*section){
        this->section = section;
    }
    Section* getSection(){
        return this->section;
    }
    void setTranscript(Transcript*transcript){
        this->transcript=transcript;
    }
    Transcript*getTranscript(){
        return this->transcript;
    }
    TranscriptEntry(Student*s, string grade, Section* se, Transcript*T){
        this->setGrade(grade);
        this->setSection(se);
        this->setStudent(s);
        Transcript*t = s -> getTranscript();
        this->setTranscript(T);
        T->addTranscriptEntry(this);
    }
    bool passingGrade(string grade){
        bool outcome = false;
        if(validateGrade(grade)){
            if(grade._Starts_with("A")||grade._Starts_with("B")||grade._Starts_with("C")||grade._Starts_with("D")){
                outcome = true;
            }
        }
    return outcome;}
    void displayGrade(){
        cout<<"Section NO: "<< this->getSection()->getSectionNo()<<endl;
        cout<<"Grade: "<<this->getGrade()<<endl;
    }
};
/*bool Student:: isEnrollIn(Section*section){
    for (int i=0; i< this->attends.size(),i++){
        if (this->attends[i]==section||section->getRepresentCourse()==attends[i]->getRepresentedCourse()){
            return true;
        }else{
            return false;
        }
    }
}*/
/*void Course::scheduleSelection(string day, string time, string room, int capacity){
    string s;
    s = to_string(this->offeredAsSection.size()+1);
            Section*section = new Section(this->getCourseNo()+"-"+s,day,time,room,capacity);
            this->offeredAsSection.push_back(section);
            section->setRepresentedCourse(this);
}*/
class Transcript{
private:
    Student* Owner;
    vector<TranscriptEntry*>TList;
public:
    void setOwner(Student*s){
        this->Owner = s;
    }
    Student*getOwner(){
        return this->Owner;
    }
    void addTranscriptEntry(TranscriptEntry*te){
        this-> TList.push_back(te);
    }
    vector<TranscriptEntry*> getTranscriptEntry(){
        return this->TList;
    }
    bool verifyCompletion(Course*c){
        bool outcome = false;
        for(TranscriptEntry te: transcriptEntries){
            Section*s = te.getSection();
            if(s->isSectionOf(c)){
                if(TranscriptEntry::passingGrade(te.getGrade())){
                    outcome=true;
                    break;
                }
            }
        }
        return outcome;
    }
    // hoặc
    bool verifyCompletionn(Course*c);
    Transcript(Student* s){
        setOwner(s); 
    }
    void display();
};
int main(){
    //cout<<"Hello Thanh Truc";    s
}