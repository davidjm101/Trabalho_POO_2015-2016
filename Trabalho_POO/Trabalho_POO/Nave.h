#pragma once
#include "Sala.h"
#include "Tripulacao.h"

class Nave 
{
	int milhas;
	vector<Sala> salas;
	

public:
	Nave();
	~Nave();
	void set_salas_normais();
	void set_tripulantes(Tripulacao *trip);
	void set_salas_opcionais();
	void mover_nave();
	void modificar_tripulantes(int tipo, Tripulacao *trip);
	void mover_membro_tripulacao(char nome, int numero);
	int get_milhas();
	void dano_po_cosmico(int sala, int dano);
	bool get_sala_destruida();
	void reparar_nave();
	void imprime_dados_sala();


};