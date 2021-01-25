#include <iostream>
#include <string>
using namespace std;

int selection(string action, double input, int max);

int main() {
	char again;
	do {
		double change;
		change = selection("Insert Change", 0, 100);

		change = change / 100;
		cout << "You have inserted: " << change << endl;
		cout << endl;

		string drinks[2][5] = {
		{"Coke ", "Dr Pepper ", "Pepsi", "Sprite ", "Fanta"},
		{"Coffee ", "Tea ", "Hot Chocolate ", "Horlicks ", "Green tea "}
		};


		int Prices[2][5] = {
			{1.50 /* Coke */, 1.20 /* Dr Pepper */, 1.80 /* Pepsi */, 1.00 /*Sprite */, 1.50 /* Fanta */},
			{1.20 /* Coffee */, 1.00 /* Tea */, 1.10 /* Hot Chocolate */, 1.50 /* Horlicks */, 2.00 /* Green tea */}
		};

		while (true) {
			int hoc = selection("1.Cold drinks\n2.Hot drinks", 0, 2);
			hoc = hoc / 100;
			hoc--;
			cout << endl;

			string menu;
			if (hoc == 0) {
				menu = "1.Coke 1.50\n2.Dr Pepper 1.20\n3.Pepsi 1.80\n4.Sprite 1.00\n5.Fanta 1.50";
			}
			else {
				menu = "1.Coffee 1.20\n2.Tea 1.00\n3.Hot Chocolate 1.10\n4.Horlicks 1.50\n5.Green tea 2.00";
			}

			int which = selection(menu, 0, 5);
			which = which / 100;
			which--;

			if (change - Prices[hoc][which] < 0) {
				cout << "You do not have enough money for this drink, please select another" << endl;
			}
			else {
				change = change - Prices[hoc][which];
				cout << drinks[hoc][which] << "Vended" << endl;
				cout << "You have " << change << " pounds remaining" << endl;
				break;
			}
		}
		cout << "Would you like to buy another drink ? Y or N" << endl;
		cin >> again;
		again = toupper(again);
	} while (again == 'Y');
	return 0;
	
}

int selection(string action, double input, int max) {

	cout << action << endl;
	cin >> input;

	while (cin.fail() || input < 1 || input > max) {
		cout << "Invalid input" << endl;
		cin.clear();
		cin.ignore(1000, '\n');

		cout << action << endl;
		cin >> input;
	}

	input = input * 100;
	return input;
}