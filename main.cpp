#include "sign.h"

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
		cout << "4 - Search by sign" << endl;
		cout << "5 - Exit" << endl;
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

					if (index < 1 || index > size) {
						cout << "Wrong index\n";
					}
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
						if (cnt == 0)
							cout << "No persons" << endl;
					}
				}
				break;
			case 5:
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
