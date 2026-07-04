#ifndef NAVE_H
#define NAVE_H

#include <string>

using namespace std;

class Nave {
public:
	int codigo;
	int capacidade;
	string nome;

	Nave(int cod, int cap, string n);
};

#endif