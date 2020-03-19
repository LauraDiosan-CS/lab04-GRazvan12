#include "Cheltuiala.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

//constructor
Cheltuiala::Cheltuiala() {
	this->numar = 0;
	this->suma = 0;
	this->tip = NULL;
}

Cheltuiala::Cheltuiala(int nr, int suma, char* tip)
{
	this->numar = nr;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, 1 + strlen(tip), tip);
}

Cheltuiala::Cheltuiala(const Cheltuiala& c) {
	this->numar = c.numar;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

//destructor
Cheltuiala::~Cheltuiala() {
	if (this->tip) {
		delete[] this->tip;
		this->tip = NULL;
	}
}
//Desc:Acceseaza numarul unei cheltuieli
//Out:numarul cheltuielii
int Cheltuiala::getNumar() {
	return this->numar;
}

//Desc:Acceseaza suma unei cheltuieli
//Out:suma cheltuielii
int Cheltuiala::getSuma() {
	return this->suma;
}

//Desc:Acceseaza tipul unei cheltuieli
//Out:tipul cheltuielii
char* Cheltuiala::getTip() {
	return this->tip;
}

//Desc:schimba numarul unei cheltuieli
void Cheltuiala::setNumar(int nr) {
	this->numar = nr;
}

//Desc:schimba suma unei cheltuieli
void Cheltuiala::setSuma(int suma) {
	this->numar = suma;
}

//Desc:schimba tipul unei cheltuieli
void Cheltuiala::setTip(char* tip)
{
	if (this->tip) {
		delete[] this->tip;
	}
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {
	this->setNumar(c.numar);
	this->setSuma(c.suma);
	this->setTip(c.tip);
	return *this;
}

bool Cheltuiala:: operator==(const Cheltuiala& c) {
	return this->numar == c.numar && this->suma == c.suma && strcmp(this->tip, c.tip) == 0;
}
