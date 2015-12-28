#pragma once
#include "bibliotecas.h"
#include "Nave.h"
#include "Desenho.h"
#include "consola.h"


class Turno
{
	int numero;
	Nave nave;
	Consola c;
	Desenho desenho;
public:
	Turno();
	~Turno();
	void inicio_jogo();
	void inicio_turno();
	void fase_ordem();
	void final_turno();
	void eventos();
	void po_cosmico();
	bool acabou_jogo();

};

