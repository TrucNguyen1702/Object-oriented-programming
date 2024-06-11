#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Section;
class ScheduleOfClasses;
class Person;
class Professor;
class Student;
class Transcript;
class TranscriptEntry;

class Course {
    string courseNo;
    string courseName;
    double credits;

    vector<Section*> offeredAsSection;
    vector<Course*> prerequisites;
public:
    // Constructor
    Course(string courseNo, string courseName, double credits) {
        this->setCourseNo(courseNo);
        this->setCourseName(courseName);
        this->setCredits(credits);
    }
    Course() : Course("000", "NA", 0) {};

    // Access Method
    string getCourseNo() {
        return this->courseNo;
    }
    void setCourseNo(string aCourseNo) {
        this->courseNo = aCourseNo;
    }
    string getCourseName() {
        return this->courseName;
    }
    void setCourseName(string aCourseName) {
        this->courseName = aCourseName;
    }
    double getCredits() {
        return this->credits;
    }
    void setCredits(double Credits){
        this->credits = Credits;
    }

    // Other Methods
    bool hasPrerequisites();
    void addPrerequisites(Course* c);
    Section* scheduleSection(string day, string time, string room, int capacity);
    bool checkStudentPassPrerequisites(Student* st);
};

class Section {
    string sectionNo;
    string dayOfWeek;
    string timeOfDay;
    string room;
    int seatingCapacity;

    Course* course;
    ScheduleOfClasses* schedule;
    Professor* instructor;
    // Key: Student's ssn
    map<string, Student*> students;
    // Key: Student
    map<Student*, TranscriptEntry*> grades;
    
public:
    // Constructor
    Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity) {
        this->setSectionNo(sectionNo);
        this->setDayOfWeek(dayOfWeek);
        this->setTimeOfDay(timeOfDay);
        this->setRoom(room);
        this->setSeatingCapacity(seatingCapacity);
    }
    Section() :Section("000", "NA", "NA", "NA", 0) {};

    // Access Method
    string getSectionNo(){
        return this->sectionNo;
    }
    void setSectionNo(string aSectionNo) {
        this->sectionNo = aSectionNo;
    }
    string getDayOfWeek() {
        return this->dayOfWeek;
    }
    void setDayOfWeek(string aDayOfWeek) {
        this->dayOfWeek = aDayOfWeek;
    }
    string getTimeOfDay() {
        return this->timeOfDay;
    }
    void setTimeOfDay(string aTimeOfDay) {
        this->timeOfDay = aTimeOfDay;
    }
    string getRoom() {
        return this->room;
    }
    void setRoom(string aRoom) {
        this->room = aRoom;
    }
    int getSeatingCapacity() {
        return this->seatingCapacity;
    }
    void setSeatingCapacity(int aSeatingCapacity) {
        this->seatingCapacity = aSeatingCapacity;
    }
    Course* getCourse() {
        return this->course;
    }
    void setCourse(Course* course) {
        this->course = course;
    }
    ScheduleOfClasses* getSchedule() {
        return this->schedule;
    }
    void setSchedule(ScheduleOfClasses* schedule) {
        this->schedule = schedule;
    }
    Professor* getProfessor() {
        return this->instructor;
    }
    void setProfessor(Professor* instuctor) {
        this->instructor = instructor;
    }

    // Other Method
    void notificationEnroll(int noti);
    bool enroll(Student* st);
    bool drop(Student* st);
    bool postGrade(Student* st, string grade);
    bool changeGrade(Student* st, string grade);
    bool confirmSeatAvailability();
};

class ScheduleOfClasses {
    string semester;

    vector<Section*> sections;
public:
    // Constructor
    ScheduleOfClasses(string semester) {
        this->setSemester(semester);
    }
    ScheduleOfClasses() :ScheduleOfClasses("NA") {};

    // Access Method
    string getSemester() {
        return this->semester;
    }
    void setSemester(string aSemester) {
        this->semester = aSemester;
    }

    // Other Methods
    void addSection(Section* s) {
        for (int i = 0; i < this->sections.size(); i++) {
            if (this->sections[i] == s)
                return;
        }
        this->sections.push_back(s);
        s->setSchedule(this);
        return;
    }
};

class Person {
    string ssn;
    string name;
public:
    //Constructor
    Person(string name, string ssn) {
        this->setSsn(ssn);
        this->setName(name);
    }
    Person(string ssn) : Person(ssn, "NA") {};
    Person() :Person("???-??-????", "NA") {};

    // Access Method
    string getSsn() {
        return this->ssn;
    }
    void setSsn(string aSsn) {
        this->ssn = aSsn;
    }
    string getName() {
        return this->name;
    }
    void setName(string aName) {
        this->name = aName;
    }

    // Other Method
    virtual void display() {
        cout << "\tSSN:     \t" << this->getSsn() << endl;
        cout << "\tName:    \t" << this->getName() << endl;
    }
    virtual string toString() = 0;
};

class Professor : public Person{
    string title;
    string department;
    vector<Section*> teaches;

public:
    // Constructor
    Professor(string ssn, string name, string title, string department) : Person(ssn, name){
        this->setTitle(title);
        this->setDepartment(department);
    }
    Professor(string ssn):Professor(ssn, "NA", "NA", "NA") {};

    // Access Method
    string getTitle() {
        return this->title;
    }
    void setTitle(string aTitle) {
        this->title = aTitle;
    }
    string getDepartment() {
        return this->department;
    }
    void setDepartment(string aDepartment) {
        this->department = aDepartment;
    }

    // Other Method
    void display() {
        cout << "--- Professor ---\n";
        this->Person::display();
        cout << "\tTitle:    \t" << this->getTitle() << endl;
        cout << "\tDepartment:\t" << this->getDepartment() << endl;
    }
    void agreeToTeach(Section* s) {
        for (int i = 0; i < this->teaches.size(); i++) {
            if (this->teaches[i] == s) {
                return;
            }
        }
        this->teaches.push_back(s);
    }
    string toString() {
        return this->getName() + " (" + this->getSsn() + ") [" + this->getTitle() + " - " + this->getDepartment() + "]";
    }
};

class Student : public Person{
    string major;
    string degree;
    vector<Section*> attends;
    Transcript* transcript;

public:
    // Constructor
    Student(string ssn, string name, string major, string degree);
    Student(string ssn) : Student(ssn, "NA", "NA", "NA") {};

    // Access Method
    string getMajor() {
        return this->major;
    }
    void setMajor(string aMajor) {
        this->major = aMajor;
    }
    string getDegree() {
        return this->degree;
    }
    void setDegree(string aDegree) {
        this->degree = aDegree;
    }
    Transcript* getTranscript() {
        return this->transcript;
    }
    void setTranscript(Transcript* ts) {
        this->transcript = ts;
    }

    // Other Methods
    void display();
    bool addSection(Section* aSection);
    void dropSection(Section* aSection);
    bool isEnrolledIn(Section* s);
    void displayCourseSchedule();
    void displayTranscript();
    string toString();
};

class Transcript {
    Student* studentOwner;
    vector<TranscriptEntry*> transcriptEntries;
public:
    // Constructor
    Transcript(Student* studentOwner){
        this->setStudentOwner(studentOwner);
    }

    // Access Method
    Student* getStudentOwener() {
        return this->studentOwner;
    }
    void setStudentOwner(Student* studentOwner) {
        this->studentOwner = studentOwner;
    }

    // Other Methods
    bool verifyCompletion(Course* course);
    void addTranscriptEntry(TranscriptEntry* te);
    void display();
};

class TranscriptEntry {
    string grade; // A+, A, B+, B, C, D+, D, F  
    Section* section;
    Transcript* transcript; 

public:
    // Constructor
    TranscriptEntry(string grade, Transcript* ts, Section* sec) {
        this->setTranscript(ts);
        this->setGrade(grade);
        this->setSection(sec);
    }

    // Access Method
    string getGrade() {
        return this->grade;
    }
    void setGrade(string aGrade) {
        this->grade = aGrade;
    }
    Section* getSection() {
        return this->section;
    }
    void setSection(Section* sec) {
        this->section = sec;
    }
    Transcript* getTranscript() {
        return this->transcript;
    }
    void setTranscript(Transcript* ts) {
        this->transcript = ts;
    }

    // Other Methods
    bool passGrade(Course* course) {
        // Assume that grade is in a right format
        if (this->section->getCourse() == course) {
            if (this->getGrade() == "F" || this->getGrade() == "D" || this->getGrade() == "D+") {
                return false;
            }
            else {
                return true;
            }
        }
        // He/She doesn't study this course
        return false;
    }
};

//======================== Implement Method ========================

//================ Course ================
bool Course::hasPrerequisites() {
    if (this->prerequisites.size() > 0)
        return true;
    else
        return false;
}
void Course::addPrerequisites(Course* c) {
    for (int i = 0; i < this->prerequisites.size(); i++) {
        if (this->prerequisites[i] == c)
            return;
    }
    this->prerequisites.push_back(c);
}
Section* Course::scheduleSection(string day, string time, string room, int capacity) {
    Section* s = new Section(to_string(this->offeredAsSection.size() + 1), day, time, room, capacity);
    s->setCourse(this);
    this->offeredAsSection.push_back(s);
    return s;
}
bool Course::checkStudentPassPrerequisites(Student* st) {
    for (int i = 0; i < this->prerequisites.size(); i++) {
        if (!st->getTranscript()->verifyCompletion(this->prerequisites[i])) {
            return false;
        }
    }
    return true;
}
//========================================

//================ Section ================
void Section::notificationEnroll(int noti) {
    if (noti == 1) {
        cout << "Enrollment failed; Previously enrolled!\n\n";
    }
    else if (noti == 2) {
        cout << "Enrollment failed; Prerequisites not satisfied!\n\n";
    }
    else if (noti == 3) {
        cout << "Enrollment failed; Section was full!\n\n";
    }
    else {
        cout << "Enrollment successful!\n\n";
    }
}
bool Section::enroll(Student* st) {    
    // Check: Students have passed this course before
    cout << st->getName() <<  "enroll Sec No." << this->getSectionNo() << " - " << this->getCourse()->getCourseName() << ": ";
    if (st->getTranscript()->verifyCompletion(this->getCourse())) {
        this->notificationEnroll(1);
        return false;
    }
    // Check: Students have passed this prerequisites course before
    if (!this->getCourse()->checkStudentPassPrerequisites(st)) {
        this->notificationEnroll(2);
        return false;
    }
    // Check: Seating Capacity 
    if (!this->confirmSeatAvailability()) {
        this->notificationEnroll(3);
        return false;
    }
    else {
        if (!st->addSection(this)) {
            cout << "You've enrolled in this section!\n\n";
            return false;
        }
        else {
            this->students[st->getSsn()] = st;
            this->notificationEnroll(0);
            return true;
        }
    }
}
bool Section::drop(Student* st) {
    if (st->isEnrolledIn(this)) {
        this->students.erase(st->getSsn());
        st->dropSection(this);
        return true;
    }
    else {
        return false;
    }
}
bool Section::postGrade(Student* st, string grade) {
    // Assume that grade is in a right format
    
    // If you want to change grade, you must use changeGrade method
    if (this->grades.find(st) != this->grades.end()) {
        return false;
    }
    TranscriptEntry* te = new TranscriptEntry(grade, st->getTranscript(), this);
    st->getTranscript()->addTranscriptEntry(te);
    this->grades[st] = te;
    return true;
}
bool Section::changeGrade(Student* st, string grade) {
    if (this->grades.find(st) != this->grades.end()) {
        TranscriptEntry* temp = this->grades[st];
        temp->setGrade(grade);
        return true;
    }
    return false; // Students don't have grade to change
}
bool Section::confirmSeatAvailability() {
    if (this->students.size() < this->getSeatingCapacity()) {
        return true;
    }
    else {
        return false;
    }
}
//=========================================

//================ Student ================
Student:: Student(string ssn, string name, string major, string degree) : Person(ssn, name) {
    this->setMajor(major);
    this->setDegree(degree);
    Transcript* ts = new Transcript(this);
    this->setTranscript(ts);
}
void Student::display() {
    cout << "--- Student ---\n";
    this->Person::display();
    cout << "\tMajor:    \t" << this->getMajor() << endl;
    cout << "\tDegree:   \t" << this->getDegree() << endl;
    this->displayCourseSchedule();
    this->displayTranscript();
    cout << endl;
}
bool Student::addSection(Section* aSection) {
    if (!isEnrolledIn(aSection)) {
        attends.push_back(aSection);
        return true;
    }
    else {
        return false;
    }
}
void Student::dropSection(Section* aSection) {
    for (int i = 0; i < this->attends.size(); i++) {
        if (this->attends[i] == aSection) {
            this->attends.erase(this->attends.begin() + i);
        }
    }
}
bool Student::isEnrolledIn(Section* s) {
    for (int i = 0; i < this->attends.size(); i++) {
        if (this->attends[i] == s) {
            return true;
        }
    }
    return false;
}
void Student::displayCourseSchedule() {
    cout << "  Course Schedule of: " << this->toString() << endl;
    for (int i = 0; i < this->attends.size(); i++) {
        cout << "\tCourse No.:   \t" << this->attends[i]->getCourse()->getCourseNo() << " - Name: " << this->attends[i]->getCourse()->getCourseName() << endl;
        cout << "\tSection No.:  \t" << this->attends[i]->getSectionNo() << endl;
        cout << "\tDay and Time: \t" << this->attends[i]->getDayOfWeek() + " - " << this->attends[i]->getTimeOfDay() << endl;
        cout << "\tRoom:         \t" << this->attends[i]->getRoom() << endl;
        if (this->attends[i]->getProfessor())
            cout << "\tProfessor:  \t" << this->attends[i]->getProfessor()->toString() << endl;
        else
            cout << "\tProfessor:  \tUnknow!" << endl;
        cout << "\t--------\n";
    }
}
void Student::displayTranscript() {
    this->getTranscript()->display();
}
string Student::toString() {
    return this->getName() + " (" + this->getSsn() + ") [" + this->getDegree() + " - " + this->getMajor() + "]";
}
//=========================================

//================ Transcript ================
bool Transcript::verifyCompletion(Course* course) {
    for (int i = 0; i < this->transcriptEntries.size(); i++) {
        if (this->transcriptEntries[i]->getSection()->getCourse() == course) {
            if (this->transcriptEntries[i]->passGrade(course)) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    // He/She doesn't study this course
    return false;
}
void Transcript::addTranscriptEntry(TranscriptEntry* te) {
    this->transcriptEntries.push_back(te);
}
void Transcript::display() {
    cout << "  Transcript of: " << this->studentOwner->toString() << endl;
    for (int i = 0; i < this->transcriptEntries.size(); i++) {
        cout << "\tCourse Name: \t" << this->transcriptEntries[i]->getSection()->getCourse()->getCourseName() << endl;
        if (this->transcriptEntries[i])
            cout << "\tGrade:   \t" << this->transcriptEntries[i]->getGrade() << endl;
        else
            cout << "\tGrade:    \tUnknow!\n";
        cout << "\t--------\n";
    }
}
//============================================

int main() {
    vector<Professor*> professors;
    vector<Student*> students;
    vector<Course*> courses;

    ScheduleOfClasses sche("HK2-2023");
    Professor* p1, * p2, * p3;
    Student* s1, * s2, * s3;
    Course* c1, * c2, * c3, * c4, * c5;
    Section* sec1, * sec2, * sec3, * sec4, * sec5, * sec6, * sec7;

    p1 = new Professor("Jacquie Barker", "123-45-6789", "Adjunct Professor", "Information Technology");
    p2 = new Professor("Claudio Cioffi", "567-81-2345", "Full Professor", "Computational Social Sciences");
    p3 = new Professor("Snidely Whiplash", "987-65-4321", "Full Professor", "Physical Education");
    professors.push_back(p1);
    professors.push_back(p2);
    professors.push_back(p3);

    s1 = new Student("Joe Blow", "111-11-1111", "Math", "M.S.");
    s2 = new Student("Fred Schnurd", "222-22-2222", "Information Technology", "Ph. D.");
    s3 = new Student("Mary Smith", "333-33-3333", "Physics", "B.S.");
    students.push_back(s1);
    students.push_back(s2);
    students.push_back(s3);

    c1 = new Course("CMP101", "Beginning Computer Technology", 3.0);
    c2 = new Course("OBJ101", "Object Methods for Software Development", 3.0);
    c3 = new Course("CMP283", "Higher Level Languages (Java)", 3.0);
    c4 = new Course("CMP999", "Living Brain Computers", 3.0);
    c5 = new Course("ART101", "Beginning Basketweaving", 3.0);

    courses.push_back(c1);
    courses.push_back(c2);
    courses.push_back(c3);
    courses.push_back(c4);
    courses.push_back(c5);

    c2->addPrerequisites(c1);
    c3->addPrerequisites(c2);
    c4->addPrerequisites(c3);

    sec1 = c1->scheduleSection("Mon", "8:10 - 10:00 PM", "GOVT101", 30); // 1
    sec2 = c1->scheduleSection("Wed", "6:10 - 8:00 PM", "GOVT202", 30);  // 2
    sec3 = c2->scheduleSection("Thu", "4:10 - 6:00 PM", "GOVT105", 25);  // 1
    sec4 = c2->scheduleSection("Tue", "6:10 - 8:00 PM", "SCI330", 25);     // 2
    sec5 = c3->scheduleSection("Mon", "6:10 - 8:00 PM", "GOVT101", 20);  // 1
    sec6 = c4->scheduleSection("Thu", "4:10 - 6:00 PM", "SCI241", 15);   // 1
    sec7 = c5->scheduleSection("Mon", "4:10 - 6:00 PM", "ARTS25", 40);   // 1

    sche.addSection(sec1);
    sche.addSection(sec2);
    sche.addSection(sec3);
    sche.addSection(sec4);
    sche.addSection(sec5);
    sche.addSection(sec6);
    sche.addSection(sec7);

    p3->agreeToTeach(sec1);
    p2->agreeToTeach(sec2);
    p1->agreeToTeach(sec3);
    p3->agreeToTeach(sec4);
    p1->agreeToTeach(sec5);
    p2->agreeToTeach(sec6);
    p3->agreeToTeach(sec7);

    cout << "====================================\n   Student registration has begun!\n====================================\n";
    
    sec1->enroll(s1);
    sec1->enroll(s1);
    sec2->enroll(s2);
    sec3->enroll(s2);
    sec7->enroll(s2);
    sec1->enroll(s3);

    sec1->postGrade(s1, "C+");
    sec1->postGrade(s3, "A");
    sec1->changeGrade(s1, "B");

    sec3->enroll(s1); 

    cout << "\n====================================\n   Professor Information\n====================================\n";
    p1->display();
    p2->display();
    p3->display();

    cout << "\n====================================\n   Student Information\n====================================\n";
    s1->display();
    s2->display();
    s3->display();

    return 0;
}