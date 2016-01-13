#pragma once
#include "Sala.h"
#include "Tripulacao.h"

class Nave 
{
	int milhas;
	int escudo;
	vector<Sala*> salas;
	

public:
	Nave();
	~Nave();
	void set_escudo(int escudo);
	void set_salas_normais();
	void set_salas_opcionais();
	void adiciona_tripulantes();


	void mover_nave();
	void mover_membro_tripulacao(char nome, int numero);


	int get_escudo();
	int get_milhas();
	void dano_po_cosmico(int sala, int dano);
	bool get_sala_destruida();
	void reparar_nave();
	void imprime_dados_sala();
	void sala_verifica_respirar();//vai verificar se existe algum elemento na sala que precise de respirar
	void atravessa_chuva_meteoritos(int dano,int num);//num vai ser o numero de vezes que a nave vai ser atinginda
	bool verifica_ponte_operada();
	void set_tripulantes_capitao(Tripulacao *trip);
	void set_tripulantes_Robot(Tripulacao *trip);



};