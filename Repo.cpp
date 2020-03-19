#include "Repo.h"
//constructor
Repo::Repo() {
	this->n = 0;
}

//destructor
Repo::~Repo() {
	this->n = 0;
}

void Repo::addCheltuiala(Cheltuiala c) {
	this->cheltuieli[this->n++] = c;
}

//Desc:Adauga o cheltuiala in Repo
//In: un obiect c de tip Cheltuiala
Cheltuiala* Repo::getAll() {
	return this->cheltuieli;
}
//Acceseaza lungimea unui repo
//Out: lungimea
int Repo::getSize() {
	return this->n;
}