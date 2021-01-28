#include <iostream>
#include <string>
using namespace std;

int selection(string action, double input, int max); //intialising selection function.

int main() {

	int countH = 6; //applies preset item count for adding new hot drinks later.
	int countC = 6; //applies preset item count for adding new hot drinks later.

	string drinks[2][10] = { //intialised array holding all item names for hot and cold drinks.
		{"Coke ", "Dr Pepper ", "Pepsi ", "Sprite ", "Fanta "}, //cold drinks.
		{"Coffee ", "Tea ", "Hot Chocolate ", "Horlicks ", "Green tea "} //hot drinks.
	};

	double Prices[2][10] = { //intialises array holding all prices for all items in order to the drinks array.
		{1.50 , 1.20 , 1.80 , 1.00 , 1.50 }, //cold drinks.
		{1.20 , 1.00 , 1.10 , 1.50 , 2.00 } //hot drinks.
	};

	int stock[2][10] = { //initialises array that keeps count of item stock, any new items added are automatically set to 10.
		{5 , 4 , 0 , 7, 1 }, //cold drinks.
		{5 , 6 , 1 , 0 , 2 } //hot drinks.
	};

	char again; //holds input for user when to determine if they want to buy another drink.
	double change = 0; //holds users change input.
	do {
		change = selection("Insert Change", 0, 100); //takes user input for change, validating any number between 1 - 100.
		change = change / 100; //the returned number is returned multiplied by 100 to help avoid any data loss when using a double.

		cout << "You have inserted: " << change << endl << endl; //tells the user how much change they've added to the system.

		
		while (true) { //maintains loop until a break appears within the code.
			cout << "would you like a hot or cold drink?" << endl; //asks for user input.
			int hoc = selection("1.Cold drinks\n2.Hot drinks", 0, 2); //gives users two options between hot and cold, validates the number.
			hoc = hoc / 100; //divides hoc by 100 to account for return.
			hoc--; //to match user input to the array position, the user input must have 1 subtracted from it.
			cout << endl; //adds a space for clarity.

			cout << "Please select a drink (type 12 to add a new drink to the menu)" << endl; //asks for user input regarding the drink they want, or if they want to add a new item.
			string menu = " "; //intialises menu variable whilst also clearing it if the program has looped.
			int num = 1; //sets number outside for loop to avoid num being reset each loop of the for.

			if (hoc == 0) { //if statement to help set up menu based on user selection. 0 = cold, 1 = hot.
				for (int i = 0; i < 10; i++) { //for loop set to 10, which is how many spaces the vending machine has for each category of drink.
					menu = menu + to_string(num) + "." + drinks[hoc][i] + " " + to_string(Prices[hoc][i]) + "\n"; //automatic system to merge arrays together into 1 string menu item.
					num++; //adds 1 to num so each item has a listed number with it.
				}
			}
			else { //if the user inputted 1 for hot drinks
				for (int i = 0; i < 10; i++) {
					menu = menu  + to_string(num) + "." + drinks[hoc][i] + " " + to_string(Prices[hoc][i]) + "\n"; //repeat of above but for hot drinks.
					num++;
				}
			}

			int which = selection(menu, 0, 12); //outputs automatically made menu limiting the user to 12 so it can only include the 10 items and the item addition function.
			which = which / 100; //divides return by 100.
			which--; //subtracts 1 to align user input with array.

			if (which == 11) { //will embedded code if user input 'which' is equal to 11 (12 - 1).
				int count = 0; //count used to help apply item number to user.
				string item; //variable to hold user input of new items name.
				double price = 0; //variable to hold price of new item.

				switch (hoc) { //uses hoc variable as a basis for the switch statement which controls which category is gaining a new item
				case 0: //if hoc = 0.
					count = countC; //count becomes equal to the count of the cold drinks.
					break;

				case 1: //if hoc = 1.
					count = countH; //count becomes equal to the count of the hot drinks
					break;

				default: //otherwise.
					cout << "Incorrect selection" << endl; //error message if hoc is incorrect as a failsafe.
					break;

				}

				cout << "\nAdding new item to selected category" << endl; //announces that the user will be able to add a new item.

				cout << "What is the name of the item?" << endl; //outputs message asking for user input.
				cin >> item; //takes name of item.

				cout << "How much will it cost?" << endl; //outputs message for user input.
				cin >> price; //takes price of item.

				drinks[hoc][(count - 1)] = item; //pushes name of the item to the corresponding array.
				Prices[hoc][(count - 1)] = price; //pushes price of the item to the corresponding array.
				stock[hoc][(count - 1)] = 10; //automatically applies 10 stock for the new item since it's new.


				count++; //increases the count.
				switch (hoc) {
				case 0:
					countC = count; //applies increased count back to countC to avoid overwriting the newly submitted item.
					break;

				case 1:
					countH = count; //applies increased count back to countC to avoid overwriting the newly submitted item.
					break;

				default:
					cout << "Incorrect selection" << endl; //failsafe.
					break;

				}
				cout << endl; //creates a space for clarity.
				//with no break in this section of code it will loop back asking the user if they want a hot or cold drink.
			}
			else if (stock[hoc][which] == 0) { //if the item selected has no stock.
				cout << "This drink is currently out of stock, you will be refunded " << change << endl << "Please select another drink" << endl << endl; //gives user a error message and refund, with no break it loops back to the start.
			}
			else if (change - Prices[hoc][which] < 0) { //if the item price exceeds the users change.
				cout << "You do not have enough money for this drink, please select another" << endl; //gives user error message, tells them to select another drink, loops back to hoc scene.
			}
			else { //if the users item has stock and enough change.
				change = change - Prices[hoc][which]; //takes price of item away from change.
				cout << endl << drinks[hoc][which] << "Vended" << endl; //tells the user what item has been vended.
				cout << change << " pounds returned as change" << endl; //tells the user what change they have left and returns it as change.
				stock[hoc][which] = stock[hoc][which] - 1; //takes 1 away from the stock of the item selection
				break; //breaks the user out of the loop.
			}
		}
		cout << "Would you like to buy another drink ? Y or N" << endl; //asks the user if they want to buy another drink.
		cin >> again; //takes user input for again.
		again = toupper(again); //changes user input to all upper case.
	} while (again == 'Y'); //using a do while the condition is checked after running the code, if the statement is matched the user will go through the whole buying process again.
	return 0; //main returns 0 and the program ends.
}

int selection(string action, double input, int max) { //holds function code for when it's called.

	cout << action << endl; //outputs whatever is applied to action when called.
	cin >> input; //takes user input.

	while (cin.fail() || input < 1 || input > max) { //while user input is incorrect, smaller than 1 or larger than whatever the max is set to at the function call.
		cout << "Invalid input" << endl; //tells user input is invalid.
		cin.clear(); //clears user input.
		cin.ignore(1000, '\n'); //ignores next 1000 characters in cache that still contain invalid data.

		cout << action << endl; //asks for user input again.
		cin >> input; //takes user input.
	}
	
	input = input * 100; //multiplies user input by 100 to avoid data loss with doubles.
	return input; //returns validated user input to main program.
}

