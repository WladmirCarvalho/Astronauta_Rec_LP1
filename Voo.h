#ifndef VOO_H
#define VOO_H

#include <string>
#include <vector>
#include "Nave.h"

using namespace std;

enum est { planejado, emCurso, finalizadoComSucesso, finalizadoComExplosao };

class Voo {
public:
	int codigo;
	vector<string> passageiros;
	est estado;
	Nave* naveAssociada;

	Voo(int c);
};

#endif