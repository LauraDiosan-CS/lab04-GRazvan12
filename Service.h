#pragma once
#include "Repo.h"
#include "Cheltuiala.h"

class Service {
private:
	Repo repo;
public:
	Service();
	Service(const Repo& r);
	~Service();
	void setRepo(const Repo& r);
	void addChelt(Cheltuiala& c);
	int delChelt(Cheltuiala& c);
	void updateChelt(int id, int numar, int suma, const char* tip);
	Cheltuiala* getAll();
	int getSize();
};
