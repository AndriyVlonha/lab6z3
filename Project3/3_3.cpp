#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Human {
protected:
    string name; 
    int age;     
public:
    Human(const string& name = "", int age = 0) : name(name), age(age) {}

    virtual ~Human() {}

    friend istream& operator>>(istream& in, Human& h) {
        cout << "������ ��'� �����: ";
        in >> h.name;
        cout << "������ �� �����: ";
        in >> h.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Human& h) {
        out << "��'�: " << h.name << ", ³�: " << h.age;
        return out;
    }
};

class Father : virtual public Human {
protected:
    string fatherName;   
    int fatherAge;       
    string occupation;   
public:
    Father(const string& fatherName = "", int fatherAge = 0, const string& occupation = "")
        : fatherName(fatherName), fatherAge(fatherAge), occupation(occupation) {
    }

    virtual ~Father() {}

    friend istream& operator>>(istream& in, Father& f) {
        cout << "\n--- �������� ����� ��� ������ ---\n";
        cout << "������ ��'� ������: ";
        in >> f.fatherName;
        cout << "������ �� ������: ";
        in >> f.fatherAge;
        cout << "������ ������� ������: ";
        in >> f.occupation;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Father& f) {
        out << "��'� ������: " << f.fatherName
            << ", ³� ������: " << f.fatherAge
            << ", ������� ������: " << f.occupation;
        return out;
    }
};

class Mother : virtual public Human {
protected:
    string motherName;   
    int motherAge;       
    string hobby;       
public:
    Mother(const string& motherName = "", int motherAge = 0, const string& hobby = "")
        : motherName(motherName), motherAge(motherAge), hobby(hobby) {
    }

    virtual ~Mother() {}

    friend istream& operator>>(istream& in, Mother& m) {
        cout << "\n--- �������� ����� ��� ����� ---\n";
        cout << "������ ��'� �����: ";
        in >> m.motherName;
        cout << "������ �� �����: ";
        in >> m.motherAge;
        cout << "������ ��� �����: ";
        in >> m.hobby;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Mother& m) {
        out << "��'� �����: " << m.motherName
            << ", ³� �����: " << m.motherAge
            << ", ��� �����: " << m.hobby;
        return out;
    }
};


class Daughter : public Father, public Mother {
    string school;  
public:

    Daughter(const string& dName = "", int dAge = 0,
        const string& fName = "", int fAge = 0, const string& occupation = "",
        const string& mName = "", int mAge = 0, const string& hobby = "",
        const string& school = "")
        : Human(dName, dAge), Father(fName, fAge, occupation), Mother(mName, mAge, hobby), school(school) {
    }

    virtual ~Daughter() {}

    friend istream& operator>>(istream& in, Daughter& d) {
        cout << "\n=== �������� ����� ��� ����� ===\n";
        in >> static_cast<Human&>(d);
        in >> static_cast<Father&>(d);
        in >> static_cast<Mother&>(d);
        cout << "\n������ ����� ����� �����: ";
        in >> d.school;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Daughter& d) {
        out << "\n=== ���������� ��� ����� ===\n";
        out << "����� -> " << static_cast<const Human&>(d) << "\n";
        out << "������ -> " << static_cast<const Father&>(d) << "\n";
        out << "���� -> " << static_cast<const Mother&>(d) << "\n";
        out << "����� �����: " << d.school << "\n";
        return out;
    }

    void printParentInfo() const {
        cout << "\n--- ���������� ��� ������ ---\n";
        cout << static_cast<const Father&>(*this) << "\n";
        cout << static_cast<const Mother&>(*this) << "\n";
    }
};

int main() {;
SetConsoleOutputCP(1251);
SetConsoleCP(1251);
    Daughter d;

    cin >> d;

    cout << d;

    d.printParentInfo();

    return 0;
}
