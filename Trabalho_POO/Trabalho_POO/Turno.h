#pragma once
#include "bibliotecas.h"
#include "Nave.h"
#include "Desenho.h"
#include "consola.h"
#include "Eventos.h"
#include "Ataque_Pirata.h"
#include "Ataque_Xenomorfo.h"
#include "Chuva_Meteorito.h"
#include "Po_Cosmico.h"


class Turno
{
	int turno;
	int conta_turno_eventos;
	Nave* nave;
	Consola c;
	Desenho desenho;
	vector<Eventos*> evento;
public:
	Turno();
	~Turno();
	void inicio_jogo();
	void inicio_turno();
	void fase_ordem();
	void final_turno();
	void eventos();
	bool acabou_jogo();
	void imprime_acabou_jogo();

};

