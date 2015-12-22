#pragma once
#include "Sala.h"
#include "Tripulacao.h"

class Nave 
{
	vector<Sala> salas;
	

public:
	Nave();
	~Nave();
	void set_salas_normais();
	void set_tripulantes(Tripulacao *trip);
	void set_salas_opcionais();
	void modificar_tripulantes(int tipo, Tripulacao *trip);
	void le_comando();
	void mover_membro_tripulacao(char nome, int numero);
	void get_info_salas();


};