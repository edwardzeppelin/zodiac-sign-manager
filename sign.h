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

    friend ostream& operator<<(ostream& out, const sign& sign);

    friend istream& operator>>(istream& in, sign& sign);

};

