#pragma once
#include <iostream>

using namespace std;

class sign {
private:
    string name;
    string surname;
    string nsign;
    int date[3];

public:

    sign() {
        name = "";
        surname = "";
        nsign = "";
        date[0] = 0;
        date[1] = 0;
        date[2] = 0;
    }

    void setname(const string& newname) { name = newname; };
    string getname() const { return name; };
    void setsurname(const string& newsurname) { surname = newsurname; };
    string getsurname() const { return surname; };
    void setsign(const string& newsign) { nsign = newsign; };
    string getsign() const { return nsign; };
    void setdate(const int& newday, const int& newmonth, const int& newyear) { date[0] = newday; date[1] = newmonth; date[2] = newyear; };
    const int* getdate() const { return date; }

    friend ostream& operator<<(ostream& out, const sign& sign) {
        out << "Name: " << sign.name << "\n"
            << "Surname: " << sign.surname << "\n"
            << "Sign: " << sign.nsign << "\n"
            << "Date of birth: " << sign.date[0] << "." << sign.date[1] << "." << sign.date[2] << "\n";
        return out;
    }

    friend istream& operator>>(istream& in, sign& sign) {
        cout << "Enter name: ";
        in >> sign.name;

        cout << "Enter surname: ";
        in >> sign.surname;

        cout << "Enter sign: ";
        in >> sign.nsign;

        cout << "Enter date of birth (xx xx xxxx): ";
        in >> sign.date[0] >> sign.date[1] >> sign.date[2];

        return in;
    }

};

void resize(sign*& persons, int size) {
    int newsize = (size == 0) ? 1 : size + 1;
    sign* newpersons = new sign[newsize];

    for (int i = 0; i < size; ++i)
        newpersons[i] = persons[i];

    delete[] persons;
    persons = newpersons;
    size = newsize;
}

void deleteperson(sign*& persons, int& size, int index) {
    if (index < 0 || index >= size) {
        cerr << "Error: Index out of range.\n";
        return;
    }

    for (int i = index; i < size - 1; ++i) {
        persons[i] = persons[i + 1];
    }

    sign* newpersons = new sign[size - 1];
    for (int i = 0; i < size - 1; ++i) {
        newpersons[i] = persons[i];
    }

    delete[] persons;
    persons = newpersons;
    --size;
}

void sortbydate(sign* persons, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            int year1 = persons[j].getdate()[2];
            int year2 = persons[j + 1].getdate()[2];
            int month1 = persons[j].getdate()[1];
            int month2 = persons[j + 1].getdate()[1];
            int day1 = persons[j].getdate()[0];
            int day2 = persons[j + 1].getdate()[0];

            if (year1 > year2 || (year1 == year2 && month1 > month2) ||
                (year1 == year2 && month1 == month2 && day1 > day2)) {
                sign temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = temp;
            }
        }
    }
}