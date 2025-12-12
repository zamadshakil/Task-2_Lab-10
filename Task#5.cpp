#include <iostream>
#include <cstring>

using namespace std;

char* copyText(const char* text) {
    char* buff = new char[strlen(text) + 1];
    strcpy(buff, text);
    return buff;
}

class Student {
private:
    char* name;
    char* reg;
    char* city;

public:
    Student(const char* n = "", const char* r = "", const char* c = "")
        : name(copyText(n)), reg(copyText(r)), city(copyText(c)) {}

    Student(const Student& other)
        : name(copyText(other.name)), reg(copyText(other.reg)), city(copyText(other.city)) {}

    Student& operator=(const Student& other) {
        if (this != &other) {
            setName(other.name);
            setReg(other.reg);
            setCity(other.city);
        }
        return *this;
    }

    ~Student() {
        delete[] name;
        delete[] reg;
        delete[] city;
    }

    void setName(const char* n) {
        delete[] name;
        name = copyText(n);
    }

    void setReg(const char* r) {
        delete[] reg;
        reg = copyText(r);
    }

    void setCity(const char* c) {
        delete[] city;
        city = copyText(c);
    }

    const char* getName() const { return name; }
    const char* getReg() const { return reg; }
    const char* getCity() const { return city; }

    void display() const {
        cout << "Name: " << name << ", Registration No: " << reg << ", City: " << city << endl;
    }
};

class Instructor {
private:
    char* name;
    char* edu;

public:
    Instructor(const char* n = "", const char* e = "")
        : name(copyText(n)), edu(copyText(e)) {}

    Instructor(const Instructor& other)
        : name(copyText(other.name)), edu(copyText(other.edu)) {}

    Instructor& operator=(const Instructor& other) {
        if (this != &other) {
            setName(other.name);
            setEdu(other.edu);
        }
        return *this;
    }

    ~Instructor() {
        delete[] name;
        delete[] edu;
    }

    void setName(const char* n) {
        delete[] name;
        name = copyText(n);
    }

    void setEdu(const char* e) {
        delete[] edu;
        edu = copyText(e);
    }

    const char* getName() const { return name; }
    const char* getEdu() const { return edu; }

    void display() const {
        cout << "Instructor: " << name << " (" << edu << ")" << endl;
    }
};

const int MAX_STUDENTS = 30;

class Course {
private:
    char* courseName;
    const Instructor* inst;
    const Student* studs[MAX_STUDENTS];
    int count;

    void resetStudents() {
        for (auto& s : studs) {
            s = nullptr;
        }
    }

public:
    Course() : courseName(copyText("")), inst(nullptr), count(0) { resetStudents(); }

    Course(const char* n, const Instructor* i = nullptr)
        : courseName(copyText(n)), inst(i), count(0) { resetStudents(); }

    Course(const Course& other)
        : courseName(copyText(other.courseName)), inst(other.inst), count(other.count) {
        for (int i = 0; i < MAX_STUDENTS; ++i) {
            studs[i] = (i < other.count) ? other.studs[i] : nullptr;
        }
    }

    Course& operator=(const Course& other) {
        if (this != &other) {
            setCourseName(other.courseName);
            inst = other.inst;
            count = other.count;
            for (int i = 0; i < MAX_STUDENTS; ++i) {
                studs[i] = (i < other.count) ? other.studs[i] : nullptr;
            }
        }
        return *this;
    }

    ~Course() {
        delete[] courseName;
    }

    void setCourseName(const char* n) {
        delete[] courseName;
        courseName = copyText(n);
    }

    void setInstructor(const Instructor* i) { inst = i; }

    bool addStudent(const Student* s) {
        if (count >= MAX_STUDENTS) {
            cout << "Cannot add more than " << MAX_STUDENTS << " students." << endl;
            return false;
        }
        studs[count++] = s;
        return true;
    }

    const char* getCourseName() const { return courseName; }
    const Instructor* getInstructor() const { return inst; }
    const Student* getStudentAt(int i) const { return (i >= 0 && i < count) ? studs[i] : nullptr; }
    int getTotalStudentCount() const { return count; }

    void display() const {
        cout << "\nCourse: " << courseName << endl;

        if (inst) {
            inst->display();
        } else {
            cout << "Instructor: (not assigned)" << endl;
        }

        cout << "Total Students: " << count << endl;
        cout << "No.\tRegistration No\t\tStudent Name" << endl;
        for (int i = 0; i < count; ++i) {
            cout << (i + 1) << ".\t" << studs[i]->getReg() << "\t" << studs[i]->getName() << endl;
        }
    }
};

int main() {
    Student s1("Ali", "L1F1YBSCS1ABC", "Lahore");
    Student s2("Ahmad", "L1F1YBSCS2ABC", "Islamabad");
    Student s3("Ammar", "L1F1YBSCS3ABC", "Lahore");

    Course* oopLabSecC4 = new Course();
    oopLabSecC4->setCourseName("OOPFall2023SecC4Lab");

    cout << "Total students in oopLabSecC4: " << oopLabSecC4->getTotalStudentCount() << endl;

    oopLabSecC4->addStudent(&s1);
    oopLabSecC4->addStudent(&s2);
    oopLabSecC4->addStudent(&s3);

    cout << "Total students after adding: " << oopLabSecC4->getTotalStudentCount() << endl;

    Instructor inst1("AASMA ABDUL WAHEED", "MPHIL");
    oopLabSecC4->setInstructor(&inst1);

    cout << "\n-- oopLabSecC4 --";
    oopLabSecC4->display();

    Course oopLabSecC2;
    oopLabSecC2.setCourseName("OOPFall2023SecC2Lab");
    oopLabSecC2.addStudent(&s1);
    oopLabSecC2.addStudent(&s3);

    Instructor inst2("USAMA PERVAIZ", "MPHIL");
    oopLabSecC2.setInstructor(&inst2);

    delete oopLabSecC4;
    oopLabSecC4 = nullptr;

    cout << "\n-- oopLabSecC2 (after deleting oopLabSecC4) --";
    oopLabSecC2.display();

    cout << "\ninst1 still accessible: " << inst1.getName() << endl;
    return 0;
}