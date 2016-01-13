#pragma once
#include "bibliotecas.h"
#include "Eventos.h"

class Po_Cosmico : public Eventos{
public:
	Po_Cosmico();
	~Po_Cosmico();
	virtual void accao(Nave *nave);
};