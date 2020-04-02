#pragma once
#include "Repo.h"
#include "Cheltuiala.h"

class Service {
private:
	Repo repo;
	int contorID;
public:
	Service();
	Service(const Repo&);
	~Service();
	void setRepo(const Repo r);
	void addChelt(int numar, int suma, const char* tip);
	int delChelt(int id);
	void updateChelt(int id, int numar, int suma, const char* tip);
	Cheltuiala* getAll(int = -1);
	int getSize();
	Service& operator=(const Service& s);
};
