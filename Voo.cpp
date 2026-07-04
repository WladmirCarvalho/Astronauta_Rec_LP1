#include "Voo.h"

Voo::Voo(int c) {
	codigo = c;
	estado = planejado;
	naveAssociada = nullptr;
}