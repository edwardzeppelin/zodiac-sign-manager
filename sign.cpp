#include "sign.h"

sign::sign() {
    name = "";
    surname = "";
    nsign = "";
    date[0] = 0;
    date[1] = 0;
    date[2] = 0;
    cout << "Default constructor called" << endl;
}

sign::sign(const string& newname, const string& newsurname, const string& newsign, int day, int month, int year) {
    name = newname;
    surname = newsurname;
    nsign = newsign;
    date[0] = day;
    date[1] = month;
    date[2] = year;
    cout << "Parametr constructor called" << endl;
}

sign::sign(const sign& other) {
    name = other.name;
    surname = other.surname;
    nsign = other.nsign;
    date[0] = other.date[0];
    date[1] = other.date[1];
    date[2] = other.date[2];
    cout << "Copy constructor called" << endl;
}

ostream& operator<<(ostream& out, const sign& sign) {
    out << "Name: " << sign.name << "\n"
        << "Surname: " << sign.surname << "\n"
        << "Sign: " << sign.nsign << "\n"
        << "Date of birth: " << sign.date[0] << "." << sign.date[1] << "." << sign.date[2] << "\n";
    return out;
}

istream& operator>>(istream& in, sign& sign) {
    cout << "Enter name: ";
    in >> sign.name;

    cout << "Enter surname: ";
    in >> sign.surname;

    cout << "Enter sign: ";
    in >> sign.nsign;

    bool validDate = false;
    while (!validDate) {
        cout << "Enter date of birth (dd mm yyyy): ";
        in >> sign.date[0] >> sign.date[1] >> sign.date[2];

        if (in.fail() || sign.date[0] < 1 || sign.date[0] > 31 || sign.date[1] < 1 || sign.date[1] > 12) {
            cout << "Invalid date. Please enter again.\n";
            in.clear();
            in.ignore(INT_MAX, '\n');
        }
        else {
            validDate = true;
        }
    }

    return in;
}


