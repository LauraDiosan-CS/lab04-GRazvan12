#include "Cheltuiala.h"
#include <string.h>

//Desc: creeaza un obiect de tip Cheltuiala
//In: -
//Out: o instanta a clasei Cheltuiala
Cheltuiala::Cheltuiala() {
	this->id = -1;
	this->numar = 0;
	this->suma = 0;
	this->tip = NULL;
}

//Desc: creeaza un obiect de tip Cheltuiala
//In: id, int - ID-ul cheltuielii
//	  nr, int - numarul cheltuielii
//	  suma, int - suma cheltuielii
//    tip, char* - tipul cheltuielii
//Out: o instanta a clasei Cheltuiala cu atributele nr, suma, tip
Cheltuiala::Cheltuiala(int id, int nr, int suma, const char* tip)
{
	this->id = id;
	this->numar = nr;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

//Desc: creeaza un obiect de tip Cheltuiala
//In: un obiect Cheltuiala
//Out: o instanta a clasei Cheltuiala cu atributele obiectului dat ca parametru
Cheltuiala::Cheltuiala(const Cheltuiala& c) {
	this->id = c.id;
	this->numar = c.numar;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
}

//Desc: distruge un obiect de tip Cheltuiala
//In: obiectul curent
//Out: -
Cheltuiala::~Cheltuiala() {
	if (this->tip) {
		delete[] this->tip;
		this->tip = NULL;
	}
}

//Desc: schimba id-ul unei cheltuieli
//In: o cheltuiala si un id int
//Out: cheltuiala cu id-ul schimbat
void Cheltuiala::setID(int id) {
	this->id = id;
}

//Desc: schimba numarul apartamentului unei cheltuieli
//In: o cheltuiala si un numar int
//Out: cheltuiala cu numarul apartamentului schimbat
void Cheltuiala::setNumar(int nr) {
	this->numar = nr;
}

//Desc: schimba suma unei cheltuieli
//In: o cheltuiala si un numar int
//Out: cheltuiala cu suma schimbata
void Cheltuiala::setSuma(int suma) {
	this->suma = suma;
}

//Desc: schimba tipul unei cheltuieli
//In: o cheltuiala si un sir de caractere
//Out: cheltuiala cu tipul schimnbat
void Cheltuiala::setTip(const char* tip)
{
	if (this->tip) {
		delete[] this->tip;
	}
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}

//Desc: Acceseaza id-ul apartamentului unei cheltuieli
//In: o cheltuiala
//Out: id-ul cheltuielii
int Cheltuiala::getID() {
	return this->id;
}

//Desc: Acceseaza numarul apartamentului unei cheltuieli
//In: o cheltuiala
//Out: numarul cheltuielii
int Cheltuiala::getNumar() {
	return this->numar;
}

//Desc: Acceseaza suma unei cheltuieli
//In: o cheltuiala
//Out: suma cheltuielii
int Cheltuiala::getSuma() {
	return this->suma;
}

//Desc: Acceseaza tipul unei cheltuieli
//In: o cheltuiala
//Out: tipul cheltuielii
char* Cheltuiala::getTip() {
	return this->tip;
}

//Desc: creeaza o cheltuiala noua egala cu o cheltuiala data
//In: o cheltuiala (c)
//Out: o noua cheltuiala (egala cu c)
Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {
	this->id = c.id;
	this->numar = c.numar;
	this->suma = c.suma;
	if (this->tip) {
		delete[] this->tip;
	}
	this->tip = new char[strlen(c.tip) + 1];
	strcpy_s(this->tip, strlen(c.tip) + 1, c.tip);
	return *this;
}

//Desc: compara doua cheltuieli
//In: doua cheltuieli (cheltuiala curenta si c)
//Out: true/false
bool Cheltuiala::operator==(const Cheltuiala& c) {
	return ((this->id == c.id) && (this->numar == c.numar) && (this->suma == c.suma) && (strcmp(this->tip, c.tip) == 0));
}

//Overload pentru operatorii IO

//Desc: incarca o cheltuiala dintr-un stream de intrare
//In: un stream de intrare
//Out: un obiect nou de tip Cheltuiala
istream& operator>>(istream& is, Cheltuiala& c) {
	cout << "numar = ";
	is >> c.numar;
	cout << "suma = ";
	is >> c.suma;

	if (c.tip) {
		delete[] c.tip;
	}
	c.tip = new char[20];

	cout << "tip: ";
	is >> c.tip;

	return is;
}

//Desc: salveaza o cheltuiala intr-un stream de iesire
//In: un stream de iesire si o cheltuiala
//Out: streamul de iesire incarcat cu informatia din cheltuiala
ostream& operator<<(ostream& os, Cheltuiala& c) {
	os << "ID: " << c.id << " Nr. Apartament: " << c.numar << "  Suma: " << c.suma << "  Tip: " << c.tip << '\n';

	return os;
}