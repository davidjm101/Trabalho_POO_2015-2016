#pragma once
#include "bibliotecas.h"
#include "Eventos.h"

class Ataque_Xenomorfo:public Eventos
{

public:
	Ataque_Xenomorfo();
	~Ataque_Xenomorfo();
	virtual void accao(Nave* nave);
};