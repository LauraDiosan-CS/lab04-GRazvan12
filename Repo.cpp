#include "Repo.h"
#include <string.h>

//Desc: creeaza un obiect de tip Repo
//In: -
//Out: o instanta a clasei Repo
Repo::Repo() {
	this->n = 0;
}
/*
//Desc: creeaza un obiect de tip Repo
//In: n, int - numarul de cheltuieli
//    c - Cheltuiala*, vectorul de cheltuieli
//Out: o instanta a clasei Repo cu atributele n, c
Repo::Repo(int n, Cheltuiala* c) {
	this->n = n;
	for (int i = 0; i < n; i++)
		this->cheltuieli[i] = c[i];
}

//Desc: creeaza un obiect de tip Repo
//In: un obiect Repo
//Out: o instanta ca clasei Repo cu atributele obiectului dat ca parametru
Repo::Repo(const Repo& r) {
	this->n = r.n;
	for (int i = 0; i < r.n; i++)
		this->cheltuieli[i] = r.cheltuieli[i];
}*/

//Desc: distruge un obiect de tip Repo
//In: obiectul curent
//Out: -
Repo::~Repo() {
	this->n = 0;
}

//Desc: adauga o cheltuiala in Repo
//In: un obiect c de tip Cheltuiala
//Out: -
void Repo::addCheltuiala(Cheltuiala c) {
	this->cheltuieli[this->n++] = c;
}

//Desc:modifica suma unei cheltuieli care are acelasi numnar si tip ca si datele din parametri
//In: numar, int - numarul cheltuielii
//	  suma, int - suma cheltuielii
//	  tip , const char* - tipul cheltuielii
//Out: -
void Repo::updateCheltuiala(int id, int numar, int suma, const char* tip) {
	for (int i = 0; i < this->n; i++)
		if (this->cheltuieli[i].getID() == id) {
			this->cheltuieli[i].setNumar(numar);
			this->cheltuieli[i].setSuma(suma);
			this->cheltuieli[i].setTip(tip);
			break;
		}
}

//Desc: sterge o cheltuiala din Repo
//In: un obiect c de tip Cheltuiala
//Out: 1, daca obiectul a fost sters cu succes, 0 altfel
int Repo::deleteCheltuiala(Cheltuiala c) {
	int indice = -1;
	for (int i = 0; i < this->n; i++)
		if (this->cheltuieli[i] == c)
			indice = i;
	if (indice == -1)
		return 0;
	while (indice + 1 < this->n) {
		this->cheltuieli[indice] = this->cheltuieli[indice + 1];
		indice++;
	}
	this->n--;
	return 1;
}

//Desc: acceseaza lista de cheltuieli unui repo
//In: un obiect de tip repo
//Out: lista de cheltuieli
Cheltuiala* Repo::getAll() {
	return this->cheltuieli;
}

//Desc: acceseaza lungimea listei de cheltuieli unui repo
//In: un obiect de tip repo
//Out: lungimea listei de cheltuieli
int Repo::getSize() {
	return this->n;
}

//Desc: creeaza un obiect de tip Repo dintr-un obiect de tip Repo dat
//In: un obiect r de tip Repo
//Out: un obiect nou de tip Repo egal cu r
Repo& Repo::operator=(const Repo& r) {
	this->n = r.n;
	for (int i = 0; i < this->n; i++)
		this->cheltuieli[i] = r.cheltuieli[i];
	return *this;
}