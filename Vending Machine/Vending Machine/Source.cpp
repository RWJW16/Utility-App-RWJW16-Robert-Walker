#include <iostream>
#include <string>
using namespace std;

int selection(string action, double input, int max, int hoc);
void newItem(int hotorcold);

string drinks[2][5] = {
		{"Coke ", "Dr Pepper ", "Pepsi", "Sprite ", "Fanta"},
		{"Coffee ", "Tea ", "Hot Chocolate ", "Horlicks ", "Green tea "}
};

int Prices[2][5] = {
	{1.50 /* Coke */, 1.20 /* Dr Pepper */, 1.80 /* Pepsi */, 1.00 /*Sprite */, 1.50 /* Fanta */},
	{1.20 /* Coffee */, 1.00 /* Tea */, 1.10 /* Hot Chocolate */, 1.50 /* Horlicks */, 2.00 /* Green tea */}
};

string menu;

int main() {

	char again;
	double change = 0;
	do {
		change = selection("Insert Change", 0, 100, 0);
		change = change / 100;

		cout << "You have inserted: " << change << endl;
		cout << endl;


		while (true) {
			int hoc = selection("1.Cold drinks\n2.Hot drinks", 0, 2, 0);
			hoc = hoc / 100;
			hoc--;
			cout << endl;

			
			if (hoc == 0) {
				menu = "1.Coke 1.50\n2.Dr Pepper 1.20\n3.Pepsi 1.80\n4.Sprite 1.00\n5.Fanta 1.50\n";
			}
			else {
				menu = "1.Coffee 1.20\n2.Tea 1.00\n3.Hot Chocolate 1.10\n4.Horlicks 1.50\n5.Green tea 2.00\n";
			}

			int which = selection(menu, 0, 5, hoc);
			which = which / 100;
			which--;

			if (which == 101) {
				cout << "New item added" << endl;
			}
			else if (change - Prices[hoc][which] < 0) {
				cout << "You do not have enough money for this drink, please select another" << endl;
			}
			else {
				change = change - Prices[hoc][which];
				cout << drinks[hoc][which] << "Vended" << endl << endl;
				cout << change << " pounds returned as change" << endl;
				break;
			}
		}
		cout << "Would you like to buy another drink ? Y or N" << endl;
		cin >> again;
		again = toupper(again);
	} while (again == 'Y');
	return 0;
}

int selection(string action, double input, int max, int hoc) {

	cout << action << endl;
	cin >> input;

	if (max == 5 && input == 79.62) {
		newItem(hoc);
	}
	else {
		while (cin.fail() || input < 1 || input > max) {
			cout << "Invalid input" << endl;
			cin.clear();
			cin.ignore(1000, '\n');

			cout << action << endl;
			cin >> input;
		}
	}

	input = input * 100;
	return input;
}

void newItem(int hotorcold) {
	int countH = 6;
	int countC = 6;
	int count = 0;
	string item;
	int price = 0;

	while (hotorcold > 1) {
		switch (hotorcold) {
			case 0:
				count = countC;
				break;

			case 1:
				count = countH;
				break;

			default:
				cout << "Incorrect selection" << endl;
				break;

		}
	}

	cout << "\nAdding new item to selected category" << endl;

	cout << "What is the name of the item?" << endl;
	cin >> item;

	cout << "How much will it cost?" << endl;
	cin >> price;

	drinks[hotorcold][(count - 1)] = item;
	Prices[hotorcold][(count - 1)] = price;

	string FItem = to_string(count) + "." + item + to_string(price) + "\n";

	menu = menu + FItem;

	count++;
	if (hotorcold == 0) {
		countC = count;
	}
	else {
		countH = count;
	}
}