// COMSC-210 | Lab 23 | Vevaan Verma
using namespace std;
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include "Goat.h"

/* FUNCTION PROTOTYPES */
int select_goat(list<Goat> trip);
void add_goat(list<Goat>& trip, string[], string[]);
void delete_goat(list<Goat>& trip);
void display_trip(list<Goat> trip);
int main_menu();
int getValidatedChoice(int min, int max);

/* CONSTANTS */
const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	srand(time(0));

	// read & populate arrays for names and colors
	ifstream fin("names.txt");
	string names[SZ_NAMES];

	int i = 0;

	while (fin >> names[i++]);

	fin.close();

	ifstream fin1("colors.txt");
	string colors[SZ_COLORS];

	i = 0;

	while (fin1 >> colors[i++]);

	fin1.close();

	list<Goat> trip; // create a list of goats
	int choice = main_menu();
	cout << endl; // blank line for formatting purposes

	while (choice != 4) { // keep looping until player quits

		switch (choice) {

		case 1: // add a goat
			add_goat(trip, names, colors);
			break;

		case 2: // delete a goat
			delete_goat(trip);
			break;

		case 3: // display goats
			display_trip(trip);
			break;

		}

		choice = main_menu(); // get the user's next choice
		cout << endl; // blank line for formatting purposes

	}

	return 0;

}

// main_menu() displays the main menu and gets the user's choice
// arguments: none
// returns: int - the user's choice
int main_menu() {

	// output main menu
	cout << "*** GOAT MANAGER 3001 ***\n"
		<< "[1] Add a goat\n"
		<< "[2] Delete a goat\n"
		<< "[3] List goats\n"
		<< "[4] Quit\n"
		<< "Choice --> ";

	return getValidatedChoice(1, 4);

}

// select_goat() displays the goats in the trip and gets the user's choice
// arguments: list<Goat> trip - the list of goats
// returns: int - the user's choice
int select_goat(list<Goat> trip) {

	int count = 1;

	for (list<Goat>::iterator iterator = trip.begin(); iterator != trip.end(); iterator++) { // iterate through the list of goats

		cout << "[" << count << "] " << (*iterator).get_name() << " (" << (*iterator).get_age() << ", " << (*iterator).get_color() << ")" << endl; // output the goat's name, age, and color
		count++; // increment the count

	}

	cout << "Select a goat: "; // prompt the user to select a goat
	return getValidatedChoice(1, trip.size()) - 1; // return the user's choice (validated to be between 1 and the size of the list) minus 1 (to get the index of the goat in the list)

}

// add_goat() adds a goat to the trip
// arguments: list<Goat> trip - the list of goats, string names[] - the array of names, string colors[] - the array of colors
// returns: none
void add_goat(list<Goat>& trip, string names[], string colors[]) {

	Goat goat(names[rand() % SZ_NAMES], rand() % MAX_AGE, colors[rand() % SZ_COLORS]); // create a goat with a random name (from the names array), random age (from 0 to MAX_AGE), and random color (from the colors array)
	trip.push_back(goat); // add the goat to the list

}

// delete_goat() deletes a goat from the trip
// arguments: list<Goat> trip - the list of goats
// returns: none
void delete_goat(list<Goat>& trip) {

	int index = select_goat(trip); // get the index of the goat to delete
	cout << endl; // blank line for formatting purposes
	list<Goat>::iterator it = trip.begin(); // create an iterator to the beginning of the list
	advance(it, index); // advance the iterator to the index of the goat to delete
	trip.erase(it); // delete the goat

}

// display_trip() outputs all the goats in the trip
// arguments: list<Goat> trip - the list of goats
// returns: none
void display_trip(list<Goat> trip) {

	cout << "*** TRIP ***\n"; // output the trip header

	for (list<Goat>::iterator iterator = trip.begin(); iterator != trip.end(); iterator++) // iterate through the list of goats
		cout << (*iterator).get_name() << " (" << (*iterator).get_age() << ", " << (*iterator).get_color() << ")" << endl; // output the goat's name, age, and color

	cout << endl; // blank line for formatting purposes

}

// getValidatedChoice() gets a validated integer choice from the user (between min and max)
// arguments: int min - the minimum value, int max - the maximum value
// returns: int - the validated integer choice
int getValidatedChoice(int min, int max) {

	int inputInt; // variable to store the input (of type int)

	while (!(cin >> inputInt) || inputInt < min || inputInt > max) { // while the input is not an integer or is not between the min and max

		cin.clear(); // clear the input stream
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input
		cout << "Invalid input. Please enter a valid integer: "; // prompt the user to enter an integer

	}

	return inputInt;

}