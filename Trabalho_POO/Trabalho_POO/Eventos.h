#pragma once
#include "bibliotecas.h"

class Eventos {
	int dano;
public:
	Eventos();
	~Eventos();
	void set_dano(int dano);
	int get_dano();
	virtual void accao()=0;

};