// Goat.h

#ifndef GOAT_H
#define GOAT_H
#include <iostream>
using namespace std;

class Goat {
private:
	string name;
	int age;
	string color;
public:
	Goat() { name = ""; age = 0; color = ""; }
	Goat(string name) { this->name = name; age = 0; color = ""; }
	Goat(string name, int age) { this->name = name; this->age = age; color = ""; }
	Goat(string name, int age, string color) { this->name = name; this->age = age; this->color = color; }

	// setters and getters
	void set_name(string n) { name = n; };
	string get_name() const { return name; };
	void set_age(int a) { age = a; };
	int get_age() const { return age; }
	void set_color(string c) { color = c; }
	string get_color() const { return color; }

	// sorts goats by name
	bool operator<(const Goat& g) const { return name < g.name; }

};

#endif