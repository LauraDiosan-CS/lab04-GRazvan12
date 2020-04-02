#include "ui.h"
#include <iostream>
#include <string.h>
#include <string>
#include <limits.h>
using namespace std;

UI::UI() {
	this->undoLista = new Service[100];
	this->l = 0;
}

UI::UI(Service& service) {
	this->undoLista = new Service[100];
	this->l = 0;
	this->service = service;
}

UI::~UI() {
	delete[] this->undoLista;
}

void UI::afisareLista(Cheltuiala* cheltuieli, int lungime) {
	for (int i = 0; i < lungime; i++)
		cout << cheltuieli[i];
}

void UI::meniuPrincipal() {
	cout << "Introduceti cifra/litera de ordine a comenzii dorite:\n";
	cout << "1. Adaugarea unei cheltuieli in lista de cheltuieli\n";
	cout << "2. Modificarea cheltuielilor din lista\n";
	cout << "3. Identificarea cheltuielilor cu anumite proprietati\n";
	cout << "4. Obtinerea unor caracteristici ale cheltuielilor\n";
	cout << "5. Filtrari\n";
	cout << "u. Undo\n";
	cout << "x. Inchidere aplicatie\n";
}

void UI::meniuAdauga() {
	cout << "Scrieti \"adauga {numar} {tip} {suma}\" pentru a adauga o cheltuiala.\n";
	cout << "Scrieti \"inapoi\" pentru a reveni la meniul principal.\n";
}

void UI::adaugaChelt(string comanda) {
	string cuvant;
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	int numar = stoi(cuvant);

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	char* tip = new char[cuvant.length() + 1];
	strcpy_s(tip, cuvant.length() + 1, cuvant.c_str());

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	int suma = stoi(cuvant);

	this->service.addChelt(numar, suma, tip);
	delete[] tip;
}

void UI::uiAdauga() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuAdauga();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);
		if (comanda.find("adauga") != string::npos) {
			this->undoLista[this->l++] = this->service;
			this->adaugaChelt(comanda);
		}
		if (comanda.find("inapoi") != string::npos) {
			continua = false;
		}
	}
}

void UI::meniuIdentifica() {
	cout << "Scrieti \"listeaza\" pentru a afisa toate cheltuielile din lista.\n";
	cout << "Scrieti \"listeaza {numar}\" pentru a afisa toate cheltuielile apartamentului cu nr {numar}.\n";
	cout << "Scrieti \"listeaza > {suma}\" pentru a afisa toate cheltuielile cu suma mai mare decat {suma}.\n";
	cout << "Scrieti \"listeaza = {suma}\" pentru a afisa toate cheltuielile cu suma egala cu {suma}.\n";
	cout << "Scrieti \"listeaza < {suma}\" pentru a afisa toate cheltuielile cu suma mai mica decat {suma}.\n";
	cout << "Scrieti \"inapoi\" pentru a reveni la meniul principal.\n";
}

void UI::listeazaCuSemn(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);

	char* op = new char[cuvant.length() + 1];
	strcpy_s(op, cuvant.length() + 1, cuvant.c_str());

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	int suma = stoi(cuvant);

	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();

	Cheltuiala* listaFiltrata = new Cheltuiala[lungime];
	int l = 0;

	switch (op[0]) {
	case'>':
		for (int i = 0; i < lungime; i++)
			if (lista[i].getSuma() > suma)
				listaFiltrata[l++] = lista[i];
		break;
	case'=':
		for (int i = 0; i < lungime; i++)
			if (lista[i].getSuma() == suma)
				listaFiltrata[l++] = lista[i];
		break;
	case'<':
		for (int i = 0; i < lungime; i++)
			if (lista[i].getSuma() < suma)
				listaFiltrata[l++] = lista[i];
		break;
	}
	if (l)
		this->afisareLista(listaFiltrata, l);
	else
		cout << "Nu sunt cheltuieli de afisat.\n";
	delete[] op;
	delete[] listaFiltrata;
}

void UI::listeazaNumarAp(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);
	int numar = stoi(cuvant);

	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();

	Cheltuiala* listaFiltrata = new Cheltuiala[lungime];
	int l = 0;

	for (int i = 0; i < lungime; i++)
		if (lista[i].getNumar() == numar)
			listaFiltrata[l++] = lista[i];
	if (l)
		this->afisareLista(listaFiltrata, l);
	else
		cout << "Nu sunt cheltuieli de afisat.\n";
	delete[] listaFiltrata;
}

void UI::listeaza(string comanda) {
	string sep = " ";
	if (comanda.find(sep) == string::npos) {
		if (this->service.getSize() == 0)
			cout << "Nu sunt cheltuieli de afisat.\n";
		else
			this->afisareLista(this->service.getAll(), this->service.getSize());
	}
	else {
		if (comanda.find(">") != string::npos || comanda.find("=") != string::npos || comanda.find("<") != string::npos)
			this->listeazaCuSemn(comanda);
		else
			this->listeazaNumarAp(comanda);
	}
}

void UI::uiIdentifica() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuIdentifica();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);
		if (comanda.find("listeaza") != string::npos) {
			this->listeaza(comanda);
		}
		else if (comanda.find("inapoi") != string::npos) {
			continua = false;
		}
		else
			cout << "Comanda invalida.\n";
	}
}

void UI::meniuModifica() {
	cout << "Scrieti \"eliminare {numar}\" pentru a elimina toate cheltuielile apartamentului cu numarul {numar}.\n";
	cout << "Scrieti \"eliminare {nr1} la {nr2}\" pentru a elimina toate cheltuielile apartamentelor\n";
	cout << "\tcu numerele de la {nr1} pana la {nr2}.\n";
	cout << "Scrieti\"eliminare {tip}\" pentru a elimina toate cheltuielile de tipul {tip}.\n";
	cout << "Scrieti\"inlocuire {numar} {tip} cu {sumaNoua}\" pentru a inlocui suma veche a cheltuielii\n";
	cout << "\tde tipul {tip} de la apartamentul cu numarul {numar} cu suma {sumaNoua}.\n";
	cout << "Scrieti \"inapoi\" pentru a reveni la meniul principal.\n";
}

void UI::eliminaNumar(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);

	int numar = stoi(cuvant);
	Cheltuiala* lista = this->service.getAll();
	int l = this->service.getSize();

	int* listaID = new int[l];
	int lungime = 0;

	for (int i = 0; i < l; i++)
		if (lista[i].getNumar() == numar)
			listaID[lungime++] = lista[i].getID();

	for (int i = 0; i < lungime; i++)
		this->service.delChelt(listaID[i]);
	delete[] listaID;
}

void UI::eliminaInterval(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);

	string cuvant = comanda.substr(0, poz);
	int nr1 = stoi(cuvant);

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	int nr2 = stoi(cuvant);

	Cheltuiala* lista = this->service.getAll();
	int l = this->service.getSize();

	int* listaID = new int[l];
	int lungime = 0;
	
	for (int i = 0; i < l; i++)
		if ((lista[i].getNumar() >= nr1) && (lista[i].getNumar() <= nr2))
			listaID[lungime++] = lista[i].getID();

	for (int i = 0; i < lungime; i++)
		this->service.delChelt(listaID[i]);
	delete[] listaID;
}

void UI::eliminaTip(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);

	char* tip = new char[cuvant.length() + 1];
	strcpy_s(tip, cuvant.length() + 1, cuvant.c_str());

	Cheltuiala* lista = this->service.getAll();
	int l = this->service.getSize();

	int* listaID = new int[l];
	int lungime = 0;

	for (int i = 0; i < l; i++)
		if (strcmp(lista[i].getTip(), tip) == 0)
			listaID[lungime++] = lista[i].getID();

	for (int i = 0; i < lungime; i++)
		this->service.delChelt(listaID[i]);
	delete[] tip;
	delete[] listaID;
}

void UI::elimina(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());
	
	if (comanda.find("la") != string::npos) {
		this->undoLista[this->l++] = this->service;
		this->eliminaInterval(comanda);
	}
	else if (comanda.find_first_of("0123456789") != string::npos) {
		this->undoLista[this->l++] = this->service;
		this->eliminaNumar(comanda);
	}
	else {
		this->undoLista[this->l++] = this->service;
		this->eliminaTip(comanda);
	}
}

void UI::inlocuieste(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);
	int numar = stoi(cuvant);

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	char* tip = new char[cuvant.length() + 1];
	strcpy_s(tip, cuvant.length() + 1, cuvant.c_str());

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	int sumaNoua = stoi(cuvant);

	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();
	int id = -1;
	for (int i = 0; i < lungime; i++)
		if ((lista[i].getNumar() == numar) && (strcmp(lista[i].getTip(), tip) == 0))
			id = lista[i].getID();

	if (id == -1)
		cout << "Nu exista o cheltuiala cu aceste date.\n";
	else
		this->service.updateChelt(id, numar, sumaNoua, tip);
	delete[] tip;
}

void UI::uiModifica() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuModifica();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);
		if (comanda.find("eliminare") != string::npos) {
			this->elimina(comanda);
		}
		else if (comanda.find("inlocuire") != string::npos) {
			this->undoLista[this->l++] = this->service;
			this->inlocuieste(comanda);
		}
		else if (comanda.find("inapoi") != string::npos) {
			continua = false;
		}
		else
			cout << "Comanda invalida.\n";
	}
}

void UI::meniuObtine() {
	cout << "Scrieti \"sum {tip}\" pentru a obtine suma totala a cheltuielilor de tipul {tip}.\n";
	cout << "Scrieti \"max {numar}\" pentru a obtine cea mai valoroasa cheltuiala a apartamentului cu numarul {numar}.\n";
	cout << "Scrieti \"min {numar}\" pentru a obtine cea mai putin valoroasa cheltuiala a apartamentului cu numarul {numar}.\n";
	cout << "Scrieti \"sort cresc/descresc {tip}\" pentru a obtine cheltuielile de tipul {tip} in ordinea dorita.\n";
	cout << "Scrieti \"inapoi\" pentru a reveni la meniul principal.\n";
}

void UI::obtineSuma(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());
	
	poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);
	char* tip = new char[cuvant.length() + 1];
	strcpy_s(tip, cuvant.length() + 1, cuvant.c_str());

	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();
	int suma = 0;

	for (int i = 0; i < lungime; i++)
		if (strcmp(lista[i].getTip(), tip) == 0)
			suma += lista[i].getSuma();

	cout << "Suma obtinuta este: " << suma << '\n';

	delete[] tip;
}

void UI::obtineMinMax(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);

	string cuvant = comanda.substr(0, poz);
	char* indicator = new char[cuvant.length() + 1];
	strcpy_s(indicator, cuvant.length() + 1, cuvant.c_str());

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	int numar = stoi(cuvant);

	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();
	Cheltuiala chelt;
	int suma = 0;

	if (strcmp(indicator, "max") == 0) {
		suma = INT_MIN;
		for (int i = 0; i < lungime; i++)
			if ((lista[i].getNumar() == numar) && (lista[i].getSuma() > suma)) {
				chelt = lista[i];
				suma = lista[i].getSuma();
			}
	}
	else if (strcmp(indicator, "min") == 0) {
		suma = INT_MAX;
		for (int i = 0; i < lungime; i++)
			if ((lista[i].getNumar() == numar) && (lista[i].getSuma() < suma)) {
				chelt = lista[i];
				suma = lista[i].getSuma();
			}
	}

	if (chelt.getID() == -1)
		cout << "Nu exista o cheltuiala cu aceasta proprietate.\n";
	else
		cout << chelt;

	delete[] indicator;
}

void UI::obtineSortare(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);
	char* sens = new char[cuvant.length() + 1];
	strcpy_s(sens, cuvant.length() + 1, cuvant.c_str());

	comanda.erase(0, poz + sep.length());
	poz = comanda.find(sep);
	cuvant = comanda.substr(0, poz);
	char* tip = new char[cuvant.length() + 1];
	strcpy_s(tip, cuvant.length() + 1, cuvant.c_str());

	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();

	Cheltuiala* listaFiltrata = new Cheltuiala[lungime];
	int l = 0;

	for (int i = 0; i < lungime; i++)
		if (strcmp(lista[i].getTip(), tip) == 0)
			listaFiltrata[l++] = lista[i];

	if (l == 0)
		cout << "Nu sunt cheltuieli de afisat.\n";
	else {
		if (strcmp(sens, "cresc") == 0) {
			for (int i = 0; i < l - 1; i++)
				for (int j = i + 1; j < l; j++)
					if (listaFiltrata[i].getSuma() > listaFiltrata[j].getSuma())
						swap(listaFiltrata[i], listaFiltrata[j]);
		}
		else{
			for (int i = 0; i < l - 1; i++)
				for (int j = i + 1; j < l; j++)
					if (listaFiltrata[i].getSuma() < listaFiltrata[j].getSuma())
						swap(listaFiltrata[i], listaFiltrata[j]);
		}

		this->afisareLista(listaFiltrata, l);
	}

	delete[] listaFiltrata;
	delete[] sens;
	delete[] tip;
}

void UI::uiObtine() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuObtine();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);
		if (comanda.find("sum") != string::npos) {
			this->obtineSuma(comanda);
		}
		else if ((comanda.find("max") != string::npos) || (comanda.find("min") != string::npos)) {
			this->obtineMinMax(comanda);
		}
		else if (comanda.find("sort") != string::npos) {
			this->obtineSortare(comanda);
		}
		else if (comanda.find("inapoi") != string::npos) {
			continua = false;
		}
		else
			cout << "Comanda invalida.\n";
	}
}

void UI::meniuFiltru() {
	cout << "Scrieti \"filtru {tip}\" pentru a pastra doar cheltuielile de tipul {tip}.\n";
	cout << "Scrieti \"filtru {suma}\" pentru a pastra doar cheltuielile cu suma mai mica decat {suma}.\n";
	cout << "Scrieti \"inapoi\" pentru a reveni la meniul principal.\n";
}

void UI::filtreazaTip(const char* tip) {
	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();

	int* listaID = new int[lungime];
	int l = 0;

	for (int i = 0; i < lungime; i++)
		if (strcmp(lista[i].getTip(), tip) != 0)
			listaID[l++] = lista[i].getID();

	for (int i = 0; i < l; i++)
		this->service.delChelt(listaID[i]);

	delete[] listaID;
}

void UI::filtreazaSuma(int suma) {
	Cheltuiala* lista = this->service.getAll();
	int lungime = this->service.getSize();

	int* listaID = new int[lungime];
	int l = 0;

	for (int i = 0; i < lungime; i++)
		if (lista[i].getSuma() > suma)
			listaID[l++] = lista[i].getID();

	for (int i = 0; i < l; i++)
		this->service.delChelt(listaID[i]);

	delete[] listaID;
}

void UI::filtreaza(string comanda) {
	string sep = " ";
	size_t poz = comanda.find(sep);
	comanda.erase(0, poz + sep.length());

	poz = comanda.find(sep);
	string cuvant = comanda.substr(0, poz);

	int suma = 0;
	char* tip = new char[cuvant.length() + 1];

	if (cuvant.find_first_of("0123456789") != string::npos) {
		suma = stoi(cuvant);
		this->undoLista[this->l++] = this->service;
		this->filtreazaSuma(suma);
	}
	else {
		strcpy_s(tip, cuvant.length() + 1, cuvant.c_str());
		this->undoLista[this->l++] = this->service;
		this->filtreazaTip(tip);
	}

	delete[] tip;
}

void UI::uiFiltru() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuFiltru();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);
		if (comanda.find("filtru") != string::npos) {
			this->filtreaza(comanda);
		}
		else if (comanda.find("inapoi") != string::npos) {
			continua = false;
		}
		else
			cout << "Comanda invalida.\n";
	}
}

void UI::runUI() {
	bool continua = true;
	string comanda;
	while (continua) {
		this->meniuPrincipal();
		cout << "Introduceti comanda dorita: ";
		getline(cin, comanda);
		if (comanda.find("1") != string::npos) {
			this->uiAdauga();
		}
		else if (comanda.find("2") != string::npos) {
			this->uiModifica();
		}
		else if (comanda.find("3") != string::npos) {
			this->uiIdentifica();
		}
		else if (comanda.find("4") != string::npos) {
			this->uiObtine();
		}
		else if (comanda.find("5") != string::npos) {
			this->uiFiltru();
		}
		else if (comanda.find("u") != string::npos) {
			if (this->l != 0) {
				this->l--;
				this->service = this->undoLista[l];
			}
			else
				cout << "Lista este deja vida.\n";
		}
		else if (comanda.find("x") != string::npos) {
			cout << "Ati parasit programul.\n";
			continua = false;
		}
		else
			cout << "Comanda invalida.\n";
	}
}