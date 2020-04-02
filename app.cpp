#include <iostream>
#include "Teste.h"
#include "ui.h"

using namespace std;

int main()
{
	//teste();

	Service service;
	UI ui(service);

	ui.runUI();

	return 0;
}