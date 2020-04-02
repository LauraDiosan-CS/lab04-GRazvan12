#pragma once
#include "Cheltuiala.h"

class Repo {
private:
	Cheltuiala cheltuieli[100];
	int n; // lungimea listei
public:
	Repo();
	~Repo();
	void addCheltuiala(Cheltuiala c);
	int deleteCheltuiala(int id);
	void updateCheltuiala(int id, int numar, int suma, const char* tip);
	Cheltuiala* getAll(int = -1);
	int getSize();
	Repo& operator=(const Repo& r);
};