#pragma once
#include "bibliotecas.h"
#include "Nave.h"

class Eventos {
	int dano;
public:
	Eventos();
	~Eventos();
	void set_dano(int dano);
	int get_dano();
	virtual void accao(Nave *nave)=0;

};