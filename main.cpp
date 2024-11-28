#include "sign.h"

void resize(sign*& persons, int size);

void deleteperson(sign*& persons, int& size, int index);

void sortbydate(sign* persons, int size);

int main() {

	int size = 0;
	sign* persons = new sign[size];

	int choice;

	while (true) {

		cout << "----------------------------------------------------------------------------" << endl;
		cout << "Menu:" << endl;
		cout << "1 - Show all persons" << endl;
		cout << "2 - Add person" << endl;
		cout << "3 - Delete person" << endl;
		cout << "4 - Edit person" << endl;
		cout << "5 - Search by sign" << endl;
		cout << "6 - Exit" << endl;
		cout << "Choose an action: ";

		cin >> choice;

		try {
			switch (choice) {
			case 1:
				if (size == 0) {
					cout << "No persons\n";
				}
				else {
					sortbydate(persons, size);
					for (int i = 0; i < size; ++i) {
						cout << "Person " << i + 1 << ":\n" << persons[i] << endl;
					}
				}
				break;
			case 2:
				resize(persons, size);
				cin >> persons[size];
				size++;
				break;
			case 3:
				if (size == 0) {
					cout << "No persons\n";
				}
				else {
					int index;
					cout << "Enter index of person to delete (1 to " << size << "): ";
					cin >> index;
					if (index <= 0)
						throw invalid_argument("Cant be negative");
					if (index > size)
						throw invalid_argument("Cant be more than count of persons");
					else {
						deleteperson(persons, size, index - 1);
						cout << "Person has been deleted\n";
					}
				}

				break;
			case 4:
				if (size == 0) {
					cout << "No persons\n";
				}
				else {
					int index;
					cout << "Enter index of person to edit (1 to " << size << "): ";
					cin >> index;
					if (index <= 0)
						throw invalid_argument("Cant be negative");
					if (index > size)
						throw invalid_argument("Cant be more than count of persons");
					else {
						cin >> persons[index - 1];
						cout << "Person has been edited\n";
					}
				}

				break;
			case 5:
				if (size == 0) {
					cout << "No persons\n";
				}
				else {
					string find;
					string fsign;
					cout << "Enter sign:\n";
					cin >> fsign;
					int cnt = 0;
					for (int i = 0; i < size; ++i) {
						find = persons[i].getsign();
						if (find == fsign) {
							cout << "Person " << i + 1 << ":\n" << persons[i] << endl;
							cnt++;
						}
					}
					if (cnt == 0)
						cout << "No persons for sign: " << fsign << endl;
				}
				break;
			case 6:
				cout << "Exiting..." << endl;
				return 0;
			default:
				cout << "Try again" << endl;
				break;
			}
		}
		catch (const runtime_error& e) {
			cout << "Runtime error: " << e.what() << endl;
		}
		catch (const invalid_argument& e) {
			cout << "Invalid argument: " << e.what() << endl;
		}
		catch (const exception& e) {
			cout << "Exception: " << e.what() << endl;
		}
		catch (...) {
			cout << "Unknown error occurred." << endl;
		}
	}

	return 0;
}

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
