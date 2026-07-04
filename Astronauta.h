#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>

using namespace std;

class Astronauta {
public:
	string cpf;
	string nome;
	int idade;
	bool vivo;
	bool disponivel;

	Astronauta(string c, int i, string n);
	virtual string funcao() { return "Astronauta"; }
};

class Comandante : public Astronauta {
public:
	Comandante(string c, int i, string n);
	string funcao() override { return "Comandante"; }
};

class Engenheiro : public Astronauta {
public:
	Engenheiro(string c, int i, string n);
	string funcao() override { return "Engenheiro"; }
};

class Cientista : public Astronauta {
public:
	Cientista(string c, int i, string n);
	string funcao() override { return "Cientista"; }
};

class Turista : public Astronauta {
public:
	Turista(string c, int i, string n);
	string funcao() override { return "Turista"; }
};

#endif