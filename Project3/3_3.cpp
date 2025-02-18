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
        cout << "Введіть ім'я дочки: ";
        in >> h.name;
        cout << "Введіть вік дочки: ";
        in >> h.age;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Human& h) {
        out << "Ім'я: " << h.name << ", Вік: " << h.age;
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
        cout << "\n--- Введення даних для батька ---\n";
        cout << "Введіть ім'я батька: ";
        in >> f.fatherName;
        cout << "Введіть вік батька: ";
        in >> f.fatherAge;
        cout << "Введіть професію батька: ";
        in >> f.occupation;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Father& f) {
        out << "Ім'я батька: " << f.fatherName
            << ", Вік батька: " << f.fatherAge
            << ", Професія батька: " << f.occupation;
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
        cout << "\n--- Введення даних для матері ---\n";
        cout << "Введіть ім'я матері: ";
        in >> m.motherName;
        cout << "Введіть вік матері: ";
        in >> m.motherAge;
        cout << "Введіть хобі матері: ";
        in >> m.hobby;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Mother& m) {
        out << "Ім'я матері: " << m.motherName
            << ", Вік матері: " << m.motherAge
            << ", Хобі матері: " << m.hobby;
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
        cout << "\n=== Введення даних для дочки ===\n";
        in >> static_cast<Human&>(d);
        in >> static_cast<Father&>(d);
        in >> static_cast<Mother&>(d);
        cout << "\nВведіть назву школи дочки: ";
        in >> d.school;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Daughter& d) {
        out << "\n=== Інформація про дочку ===\n";
        out << "Дочка -> " << static_cast<const Human&>(d) << "\n";
        out << "Батько -> " << static_cast<const Father&>(d) << "\n";
        out << "Мати -> " << static_cast<const Mother&>(d) << "\n";
        out << "Школа дочки: " << d.school << "\n";
        return out;
    }

    void printParentInfo() const {
        cout << "\n--- Інформація про батьків ---\n";
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
