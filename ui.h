#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	Service* undoLista;
	int l;
	void meniuPrincipal();
	void meniuAdauga();
	void meniuIdentifica();
	void meniuModifica();
	void meniuObtine();
	void meniuFiltru();
	void uiAdauga();
	void adaugaChelt(string comanda);
	void uiIdentifica();
	void afisareLista(Cheltuiala* cheltuieli, int lungime);
	void listeaza(string comanda);
	void listeazaCuSemn(string comanda);
	void listeazaNumarAp(string comanda);
	void uiModifica();
	void elimina(string comanda);
	void eliminaNumar(string comanda);
	void eliminaInterval(string comanda);
	void eliminaTip(string comanda);
	void inlocuieste(string comanda);
	void uiObtine();
	void obtineSuma(string comanda);
	void obtineMinMax(string comanda);
	void obtineSortare(string comanda);
	void uiFiltru();
	void filtreaza(string comanda);
	void filtreazaSuma(int suma);
	void filtreazaTip(const char* tip);
public:
	UI();
	~UI();
	UI(Service& service);
	void runUI();
};
