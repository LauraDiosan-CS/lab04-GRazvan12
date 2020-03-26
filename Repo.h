#pragma once
#include "Cheltuiala.h"

class Repo {
private:
	Cheltuiala cheltuieli[100];
	int n;
public:
	Repo();
	~Repo();
	void addCheltuiala(Cheltuiala c);
	int deleteCheltuiala(Cheltuiala c);
	void updateCheltuiala(int id, int numar, int suma, const char* tip);
	Cheltuiala* getAll();
	int getSize();
	Repo& operator=(const Repo& r);
};