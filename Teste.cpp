#include <assert.h>
#include <string.h>
#include "Teste.h"
#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"

//Desc: testeaza constructorii clasei Cheltuiala
void constructoriCheltuiala() {
	Cheltuiala c1; //constructor implicit
	assert((c1.getID() == -1) && (c1.getNumar() == 0) && (c1.getSuma() == 0) && (c1.getTip() == NULL));

	char* tip = new char[4];
	strcpy_s(tip, sizeof"gaz", "gaz");
	Cheltuiala c2(1, 1, 20, tip); //constructor cu parametri
	assert((c2.getID() == 1) && (c2.getNumar() == 1) && (c2.getSuma() == 20) && (strcmp(c2.getTip(), tip) == 0));

	Cheltuiala c3(c2); //constructor de copiere
	assert((c3.getID() == 1) && (c3.getNumar() == 1) && (c3.getSuma() == 20) && (strcmp(c3.getTip(), "gaz") == 0));


	//constructori pe obiecte dinamice
	Cheltuiala* pc1;
	pc1 = new Cheltuiala; //constructor implicit
	assert((pc1->getNumar() == 0) && (pc1->getSuma() == 0) && (pc1->getTip() == NULL));

	Cheltuiala* pc2 = new Cheltuiala(1, 6, 120, tip); //constructor cu parametri
	assert((pc2->getNumar() == 6) && (pc2->getSuma() == 120) && (strcmp(pc2->getTip(), tip) == 0));

	Cheltuiala* pc3 = new Cheltuiala(*pc2); //constructor de copiere
	assert((pc3->getNumar() == 6) && (pc3->getSuma() == 120) && (strcmp(pc3->getTip(), "gaz") == 0));

	if (pc1 != NULL) {
		delete pc1; //se apeleaza destructorul
		pc1 = NULL;
	}
	if (pc2 != NULL) {
		delete pc2;
		pc2 = NULL;
	}
	if (pc3 != NULL) {
		delete pc3;
		pc3 = NULL; 
	}
	delete[] tip;
}

//Desc: testeaza setterii si getterii clasei Cheltuiala
void setGetCheltuiala() {
	char* tip = new char[8];
	strcpy_s(tip, sizeof"caldura", "caldura");

	Cheltuiala c;
	c.setNumar(6);
	c.setSuma(2000);
	c.setTip(tip);
	assert((c.getNumar() == 6) && (c.getSuma() == 2000) && (strcmp(c.getTip(), "caldura") == 0));

	char* tip2 = new char[4];
	strcpy_s(tip2, sizeof"apa", "apa");

	Cheltuiala* pc = new Cheltuiala;
	pc->setNumar(2);
	pc->setSuma(1200);
	pc->setTip(tip2);
	assert((pc->getNumar() == 2) && (pc->getSuma() == 1200) && (strcmp(pc->getTip(), "apa") == 0));
	if (pc != NULL) {
		delete pc;
		pc = NULL;
	}
	delete[] tip;
	delete[] tip2;
}

//Desc: testeaza overload-ul operatorului egal asupra clasei Cheltuiala
void egalCheltuiala() {
	char* tip1 = new char[4];
	char* tip2 = new char[8];

	strcpy_s(tip1, sizeof"apa", "apa");
	strcpy_s(tip2, sizeof"caldura", "caldura");

	Cheltuiala c1(1, 1, 200, tip1);
	Cheltuiala c2(2, 2, 256, tip2);

	assert((c1.getNumar() == 1) && (c1.getSuma() == 200) && (strcmp(c1.getTip(), tip1) == 0));
	c1 = c2;
	assert((c1.getNumar() == 2) && (c1.getSuma() == 256) && (strcmp(c1.getTip(), tip2) == 0));
	delete[] tip1;
	delete[] tip2;
}

//Desc: testeaza overload-ul operatorului de egalitate asupra clasei Cheltuiala
void egalitateCheltuieli() {
	char* tip = new char[4];
	strcpy_s(tip, sizeof"gaz", "gaz");

	Cheltuiala c1(1, 1, 867, tip);
	Cheltuiala c2(c1);

	assert((c1 == c2) == true);
	delete[] tip;
}

//Desc: testeaza operatorii de intrare/iesire asupra clasei Cheltuiala
void streamCheltuiala() {
	Cheltuiala c1;
	cin >> c1;
	cout << c1;

	Cheltuiala* c2 = new Cheltuiala;
	cin >> *c2;
	cout << *c2;
}

//Desc: functie care gestioneaza testele pentru clasa Cheltuiala 
void testeCheltuiala() {
	constructoriCheltuiala();
	setGetCheltuiala();
	egalCheltuiala();
	egalitateCheltuieli();
	//streamCheltuiala();
}

//Desc: testeaza constructorul clasei Repo
void constructorRepo() {
	Repo r1; //constructor implicit
	assert(r1.getSize() == 0);
}

//Desc: testeaza getterii clasei Repo
void getRepo() {
	char* tip1 = new char[4];
	char* tip2 = new char[8];
	strcpy_s(tip1, sizeof"apa", "apa");
	strcpy_s(tip2, sizeof"caldura", "caldura");
	Cheltuiala c[2];
	c[0] = Cheltuiala(1, 1, 256, tip1);
	c[1] = Cheltuiala(2, 2, 745, tip2);

	Repo r;
	r.addCheltuiala(c[0]);
	r.addCheltuiala(c[1]);
	Cheltuiala* lista = r.getAll();
	assert((r.getSize() == 2) && (lista[0] == c[0]) && (lista[1] == c[1]));

	delete[] tip1;
	delete[] tip2;
}

//Desc: testeaza functia de a adauga o cheltuiala in Repo
void addCheltuialaRepo() {
	char* tip = new char[8];
	strcpy_s(tip, sizeof"caldura", "caldura");
	Cheltuiala c(1, 6, 121, tip);

	Repo r;
	assert(r.getSize() == 0);
	r.addCheltuiala(c);
	Cheltuiala* lista = r.getAll();
	assert((r.getSize() == 1) && (lista[0] == c));

	delete[] tip;
}

//Desc: testeaza functia de a sterge o cheltuiala din Repo
void deleteCheltuialaRepo() {
	char* tip1 = new char[4];
	char* tip2 = new char[8];
	strcpy_s(tip1, sizeof"gaz", "gaz");
	strcpy_s(tip2, sizeof"caldura", "caldura");
	Cheltuiala c1(1, 1, 24, tip1);
	Cheltuiala c2(2, 2, 16, tip2);
	
	Repo r;
	r.addCheltuiala(c1);
	r.addCheltuiala(c2);
	assert(r.getSize() == 2);
	
	r.deleteCheltuiala(c1);
	Cheltuiala* lista = r.getAll();
	assert((r.getSize() == 1) && (lista[0] == c2));

	delete[] tip1;
	delete[] tip2;
}

void updateCheltuialaRepo() {
	Cheltuiala c1(1, 1, 12, "gaz");
	Cheltuiala c2(2, 2, 2000, "caldura");
	
	Repo r;
	r.addCheltuiala(c1);
	r.addCheltuiala(c2);
	r.updateCheltuiala(1, 2, 16, "caldura");

	Cheltuiala* lista = r.getAll();
	assert(lista[1].getSuma() == 16);
}

//Desc: testeaza overload-ul operatorului egal asupra clasei Repo
void egalRepo() {
	Cheltuiala c1(1, 4, 13, "apa");
	Cheltuiala c2(2, 7, 85, "gaz");
	Repo r;
	r.addCheltuiala(c1);
	r.addCheltuiala(c2);

	Repo r2;
	assert(r2.getSize() == 0);
	r2 = r;
	assert(r2.getSize() == 2);
}

//Desc: functie care gestioneaza testele pentru clasa Repo
void testeRepo() {
	constructorRepo();
	getRepo();
	addCheltuialaRepo();
	deleteCheltuialaRepo();
	//updateCheltuialaRepo();
	egalRepo();
}

//Desc: testeaza constructorii clasei Service
void constructoriService() {
	Service s; // constructor implicit

	Repo r;
	Cheltuiala c1(1, 1, 256, "gaz");
	Cheltuiala c2(2, 2, 1000, "caldura");
	r.addCheltuiala(c1);
	r.addCheltuiala(c2);

	Service s2(r); // constructor cu parametri
	Cheltuiala* lista = s2.getAll();
	assert((lista[0] == c1) && (lista[1] == c2));
}

//Desc: testeaza setterul clasei Service
void setService() {
	Cheltuiala c1(1, 1, 17, "apa");
	Cheltuiala c2(2, 2, 314, "caldura");
	Cheltuiala c3(3, 3, 4164, "gaz");
	Repo r1;
	r1.addCheltuiala(c1);
	Repo r2;
	r2.addCheltuiala(c2);
	r2.addCheltuiala(c3);

	Service s1(r1);
	assert(s1.getSize() == 1);
	s1.setRepo(r2);
	assert(s1.getSize() == 2);
}

//Desc: testeaza getterii clasei Service
void getService() {
	Cheltuiala c1(1, 1, 17, "apa");
	Cheltuiala c2(2, 2, 314, "caldura");
	Repo r1;
	r1.addCheltuiala(c1);
	r1.addCheltuiala(c2);
	
	Service s(r1);
	Cheltuiala* lista = s.getAll();
	assert((s.getSize() == 2) && (lista[0] == c1) && (lista[1] == c2));
}

//Desc: testeaza functia de a adauga o cheltuiala din Service
void addCheltService() {
	Repo r;
	Cheltuiala c1(1, 1, 27, "gaz");
	Cheltuiala c2(2, 2, 156, "caldura");
	
	Service s(r);
	assert(s.getSize() == 0);
	s.addChelt(c1);
	s.addChelt(c2);
	Cheltuiala* lista = s.getAll();
	assert((s.getSize() == 2) && (lista[0] == c1) && (lista[1] == c2));
}

//Desc: testeaza functia de update a unei cheltuieli din Service
void updateCheltService() {
	Cheltuiala c1(1, 14, 100, "apa");
	Cheltuiala c2(2, 31, 94, "electricitate");
	Repo r;
	r.addCheltuiala(c1);
	r.addCheltuiala(c2);

	Service s(r);
	s.updateChelt(1, 31, 4000, "electricitate");
	Cheltuiala c3(2, 31, 4000, "electricitate");
	Cheltuiala* lista = s.getAll();
	assert(lista[1] == c3);
}

//Desc: testeaza functia de a sterge o cheltuiala din Service
void deleteCheltService() {
	Cheltuiala c1(1, 1, 95, "gaz");
	Cheltuiala c2(2, 3, 156, "caldura");
	Repo r;
	r.addCheltuiala(c1);
	r.addCheltuiala(c2);

	Service s(r);
	assert(s.getSize() == 2);
	assert(s.delChelt(c1) == 1);
	Cheltuiala* lista = s.getAll();
	assert((s.getSize() == 1) && lista[0] == c2);
}

//Desc: functie care gestioneaza testele pentru clasa Service
void testeService() {
	constructoriService();
	setService();
	getService();
	addCheltService();
	deleteCheltService();
	//updateCheltService();
}

//Desc: functie care apeleaza functie de test pentru fiecare clasa in parte
void teste() {
	testeCheltuiala();
	testeRepo();
	testeService();
}