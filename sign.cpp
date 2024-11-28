#include "sign.h"

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


