#pragma once
#include "bibliotecas.h"
#include "Eventos.h"
#include "Nave.h"

class Chuva_Meteorito:public Eventos
{

public:
	Chuva_Meteorito();
	~Chuva_Meteorito();
	virtual void accao(Nave *nave);
};