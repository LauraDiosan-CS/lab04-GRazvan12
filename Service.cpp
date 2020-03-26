#include "Service.h"

//Desc: creeaza un obiect de tip Service
//In: -
//Out: o instanta a clasei Service
Service::Service()
{
}

//Desc: creeaza un obiect de tip Service
//In: un obiect de tip Repo
//Out: o instanta a clasei Service cu datele din r
Service::Service(const Repo& r) {
	this->repo = r;
}

//Desc: distruge un obiect de tip Service
//In: obiectul curent
//Out: -
Service::~Service()
{
}

//Desc: schimba lista din repo a unui Service
//In: un obiect de tip Repo
//Out: -
void Service::setRepo(const Repo& r) {
	this->repo = r;
}

//Desc: adauga o cheltuiala in repo
//In: un obiect c de tip cheltuiala
//Out: -
void Service::addChelt(Cheltuiala& c) {
	this->repo.addCheltuiala(c);
}

//Desc:modifica suma unei cheltuieli care are acelasi numnar si tip ca si datele din parametri
//In: numar, int - numarul cheltuielii
//	  suma, int - suma cheltuielii
//	  tip , const char* - tipul cheltuielii
//Out: -
void Service::updateChelt(int id, int numar, int suma, const char* tip) {
	this->repo.updateCheltuiala(id, numar, suma, tip);
}

//Desc: sterge o cheltuiala din repo
//In: un obiect c de tip cheltuiala
//Out: 1, daca obiectul a fost sters cu succes, 0 altfel
int Service::delChelt(Cheltuiala& c) {
	return this->repo.deleteCheltuiala(c);
}

//Desc: acceseaza lista de cheltuieli unui repo
//In: un obiect de tip service
//Out: lista de cheltuieli
Cheltuiala* Service::getAll() {
	return this->repo.getAll();
}

//Desc: acceseaza lungimea listei de cheltuieli unui repo din service
//In: un obiect de tip Service
//Out: lungimea listei de cheltuieli
int Service::getSize() {
	return this->repo.getSize();
}