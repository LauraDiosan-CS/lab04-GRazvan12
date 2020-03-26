#pragma once
#include <iostream>

using namespace std;

class Cheltuiala {
private:
	int id; // id-ul cheltuielii
	int numar;   //numarul apartamentului
	int suma;    //suma cheltuielii
	char* tip;   //tipul cheltuielii(dintr-o lista predefinita)
public:
	Cheltuiala();
	Cheltuiala(int id, int nr, int suma, const char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	void setID(int id);
	void setNumar(int nr);
	void setSuma(int suma);
	void setTip(const char* tip);
	int getID();
	int getNumar();
	int getSuma();
	char* getTip();

	Cheltuiala& operator=(const Cheltuiala& c);
	bool operator==(const Cheltuiala& c);

	friend istream& operator>>(istream& is, Cheltuiala& c);
	friend ostream& operator<<(ostream& os, Cheltuiala& c);
};