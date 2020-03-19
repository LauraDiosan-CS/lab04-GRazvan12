#pragma once

class Cheltuiala {
private:
	int numar;
	int suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int nr, int suma, char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int getNumar();
	int getSuma();
	char* getTip();
	void setNumar(int nr);
	void setSuma(int suma);
	void setTip(char* tip);

	Cheltuiala& operator=(const Cheltuiala& c);
	bool operator==(const Cheltuiala& c);
};