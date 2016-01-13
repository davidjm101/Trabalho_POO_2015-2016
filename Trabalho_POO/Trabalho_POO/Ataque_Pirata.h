#pragma once
#include "bibliotecas.h"
#include "Eventos.h"

class Ataque_Piratas:public Eventos
{

public:
	Ataque_Piratas();
	~Ataque_Piratas();
	virtual void accao(Nave *nave);
};