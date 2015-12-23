#pragma once
#include "bibliotecas.h"
#include "Nave.h"
#include "consola.h"

class Imprime {
	Consola c;
public:
	Imprime();
	~Imprime();
	void imprime_nave(vector<Sala> salas);
	void preenche_sala(int x,int y);
	void imprime_info();
	void set_sala1();
	void set_sala2();
	void set_sala3();
	void set_sala4();
	void set_sala5();
	void set_sala6();
	void set_sala7();
	void set_sala8();
	void set_sala9();
	void set_sala10();
	void set_sala11();
	void set_sala12();


};