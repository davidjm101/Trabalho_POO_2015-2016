#pragma once
#include "Sala.h"
#include "Tripulacao.h"
#include "consola.h"

class Nave 
{
	int milhas;
	int escudo;
	vector<Sala*> salas;
	Consola c;
	

public:
	Nave();
	~Nave();
	void set_escudo(int escudo);
	void set_salas_normais();
	void set_salas_opcionais();
	void adiciona_tripulantes();
	void mover_nave();
	void mover_membro_tripulacao(char nome, int numero);
	void sala_verifica_misterioso();
	void reparar_nave();
	void imprime_dados_sala();
	void sala_verifica_respirar(); //vai verificar se existe algum elemento na sala que precise de respirar
	void atravessa_chuva_meteoritos(int dano, int num);//num vai ser o numero de vezes que a nave vai ser atinginda
	void ataque_pirata(int dano, int num);//num vai ser o numero de piratas que entraram na nave
	void sala_verifica_toxicidade();
	void sala_verifica_Regenerador();
	void dano_po_cosmico(int sala, int dano);
	
	int get_escudo();
	int get_milhas();
	bool get_sala_destruida();
	bool verifica_ponte_operada();
	void sala_verifica_Robotico();
	void sala_verifica_Reparador();
	


};