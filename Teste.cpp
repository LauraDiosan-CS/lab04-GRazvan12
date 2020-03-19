#include <assert.h>
#include <string.h>
#include "Teste.h"
#include "Cheltuiala.h"
#include "Repo.h"

void teste() {
	//creez obiecte de tip Cheltuiala
	Cheltuiala cheltuieli[4];
	char* tip1 = new char[10];
	char* tip2 = new char[10];
	char* tip3 = new char[10];
	char* tip4 = new char[10];
	strcpy_s(tip1, sizeof "apa", "apa");
	Cheltuiala c1(1, 20, tip1);

	strcpy_s(tip2, sizeof "caldura", "caldura");
	Cheltuiala c2(2, 50, tip2);

	strcpy_s(tip3, sizeof "gaz", "gaz");
	Cheltuiala c3(3, 40, tip3);

	strcpy_s(tip4, sizeof "menaj", "menaj");
	Cheltuiala c4(4, 100, tip4);
	/*
	cheltuieli[0] = c1;
	cheltuieli[1] = c2;
	cheltuieli[2] = c3;
	cheltuieli[3] = c4;*/
	
	assert(c1.getNumar() == 1 && c1.getSuma() == 20);
	assert(c2.getNumar() == 2 && c2.getSuma() == 50);
	assert(c3.getNumar() == 3 && c3.getSuma() == 40);
	assert(c4.getNumar() == 4 && c4.getSuma() == 100);

	Repo ap;
	ap.addCheltuiala(c1);
	ap.addCheltuiala(c2);
	ap.addCheltuiala(c3);
	ap.addCheltuiala(c4);

	assert(ap.getSize() == 4);
}