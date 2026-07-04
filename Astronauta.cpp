#include "Astronauta.h"

Astronauta::Astronauta(string c, int i, string n) {
	cpf = c;
	idade = i;
	nome = n;
	vivo = true;
	disponivel = true;
}

Comandante::Comandante(string c, int i, string n) : Astronauta(c, i, n) {}
Engenheiro::Engenheiro(string c, int i, string n) : Astronauta(c, i, n) {}
Cientista::Cientista(string c, int i, string n) : Astronauta(c, i, n) {}
Turista::Turista(string c, int i, string n) : Astronauta(c, i, n) {}