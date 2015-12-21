#pragma once
#include "Sala.h"

class Nave
{
	vector<Sala> salas;

public:
	Nave();
	~Nave();
	void set_salas_normais();
	void set_salas_opcionais();

};