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

    sign();

    sign(const string& newname, const string& newsurname, const string& newsign, int day, int month, int year);

    sign(const sign& other);

    ~sign() { cout << "Deconstructor called" << endl; };

    void setname(const string& newname) { name = newname; };
    string getname() const { return name; };
    void setsurname(const string& newsurname) { surname = newsurname; };
    string getsurname() const { return surname; };
    void setsign(const string& newsign) { nsign = newsign; };
    string getsign() const { return nsign; };
    void setdate(const int& newday, const int& newmonth, const int& newyear) { date[0] = newday; date[1] = newmonth; date[2] = newyear; };
    const int* getdate() const { return date; }

    friend ostream& operator<<(ostream& out, const sign& sign);

    friend istream& operator>>(istream& in, sign& sign);

};

