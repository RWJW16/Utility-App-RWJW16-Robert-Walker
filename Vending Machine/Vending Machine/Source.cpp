#include <iostream>
#include <string>
using namespace std;

int selection(string action, double input, int max);

int main() {

	int countH = 6;
	int countC = 6;

	string drinks[2][10] = {
		{"Coke ", "Dr Pepper ", "Pepsi ", "Sprite ", "Fanta "},
		{"Coffee ", "Tea ", "Hot Chocolate ", "Horlicks ", "Green tea "}
	};

	double Prices[2][10] = {
		{1.50 , 1.20 , 1.80 , 1.00 , 1.50 },
		{1.20 , 1.00 , 1.10 , 1.50 , 2.00 }
	};

	int stock[2][10] = {
		{5 , 4 , 0 , 7, 1 },
		{5 , 6 , 1 , 0 , 2 }
	};

	char again;
	double change = 0;
	do {
		change = selection("Insert Change", 0, 100);
		change = change / 100;

		cout << "You have inserted: " << change << endl << endl;

		
		while (true) {
			cout << "would you like a hot or cold drink?" << endl;
			int hoc = selection("1.Cold drinks\n2.Hot drinks", 0, 2);
			hoc = hoc / 100;
			hoc--;
			cout << endl;

			cout << "Please select a drink (type 12 to add a new drink to the menu)" << endl;
			string menu = " ";
			int num = 1;
			if (hoc == 0) {
				for (int i = 0; i < 10; i++) {
					menu = menu + to_string(num) + "." + drinks[hoc][i] + " " + to_string(Prices[hoc][i]) + "\n";
					num++;
				}
			}
			else {
				for (int i = 0; i < 10; i++) {
					menu = menu  + to_string(num) + "." + drinks[hoc][i] + " " + to_string(Prices[hoc][i]) + "\n";
					num++;
				}
			}

			int which = selection(menu, 0, 12);
			which = which / 100;
			which--;

			if (which == 11) {
				int count = 0;
				string item;
				double price = 0;

				switch (hoc) {
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

				cout << "\nAdding new item to selected category" << endl;

				cout << "What is the name of the item?" << endl;
				cin >> item;

				cout << "How much will it cost?" << endl;
				cin >> price;

				drinks[hoc][(count - 1)] = item;
				Prices[hoc][(count - 1)] = price;
				stock[hoc][(count - 1)] = 10;


				count++;
				switch (hoc) {
				case 0:
					countC = count;
					break;

				case 1:
					countH = count;
					break;

				default:
					cout << "Incorrect selection" << endl;
					break;

				}
				cout << endl;
			}
			else if (stock[hoc][which] == 0) {
				cout << "This drink is currently out of stock, you will be refunded " << change << endl << "Please select another drink" << endl << endl;
			}
			else if (change - Prices[hoc][which] < 0) {
				cout << "You do not have enough money for this drink, please select another" << endl;
			}
			else {
				change = change - Prices[hoc][which];
				cout << endl << drinks[hoc][which] << "Vended" << endl;
				cout << change << " pounds returned as change" << endl;
				stock[hoc][which] = stock[hoc][which] - 1;
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

