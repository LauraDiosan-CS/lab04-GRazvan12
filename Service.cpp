#include "Service.h"

//Desc: creeaza un obiect de tip Service
//In: -
//Out: o instanta a clasei Service
Service::Service()
{
	this->contorID = 0;
}

//Desc: creeaza un obiect de tip Service
//In: un obiect de tip Repo
//Out: o instanta a clasei Service cu datele din r
Service::Service(const Repo& r) {
	repo = r;
	this->contorID = 0;
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
void Service::setRepo(const Repo r) {
	this->repo = r;
}

//Desc: adauga o cheltuiala in repo
//In: numar, int - numaarul cheltuielii
//	  suma, int - suma cheltuielii
//    tip, const char* - tipul cheltuielii
//Out: -
void Service::addChelt(int numar, int suma, const char* tip) {
	this->repo.addCheltuiala(Cheltuiala(this->contorID, numar, suma, tip));
	this->contorID++;
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
//In: id, int - ID-ul chesltuielii care trebuie sterse
//Out: 1, daca obiectul a fost sters cu succes, 0 altfel
int Service::delChelt(int id) {
	return this->repo.deleteCheltuiala(id);
}

//Desc: acceseaza lista de cheltuieli unui repo
//In: un obiect de tip service
//Out: lista de cheltuieli
Cheltuiala* Service::getAll(int id) {
	return this->repo.getAll(id);
}

//Desc: acceseaza lungimea listei de cheltuieli unui repo din service
//In: un obiect de tip Service
//Out: lungimea listei de cheltuieli
int Service::getSize() {
	return this->repo.getSize();
}

Service& Service::operator=(const Service& s) {
	this->repo = s.repo;
	this->contorID = s.contorID;

	return *this;
}