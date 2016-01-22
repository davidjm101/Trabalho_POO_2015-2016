#pragma once
#include "Sala.h"
#include "Tripulacao.h"
#include "consola.h"
#include "bibliotecas.h"

class Nave 
{
	int milhas;
	int escudo;
	int guarda_escudo;
	bool escudo_activado;
	vector<Sala*> salas;
	vector<string> accoes_eventos;
	Consola c;
	

public:
	Nave();
	~Nave();
	void set_escudo(int escudo);
	void set_salas_normais();
	void set_salas_opcionais();
	void adiciona_tripulantes();
	void mover_nave();
	void mover_membro_tripulacao(char letra, int numero);

	void mover_pirata();
	void inser_pirata_nova_sala(Pirata* p, int sala);
	void mover_xenomorfo();
	void inser_xenomorfo_nova_sala(xenomorfos* x, int sala);
	
	void sala_verifica_misterioso();

	void reparar_nave();
	
	void sala_verifica_respirar(); //vai verificar se existe algum elemento na sala que precise de respirar
	void atravessa_chuva_meteoritos(int dano, int num);//num vai ser o numero de vezes que a nave vai ser atinginda
	void ataque_pirata(int dano, int num);//num vai ser o numero de piratas que entraram na nave
	void invadida_xenomorfos();
	void atravessa_po_cosmico(int dano);
	bool verifica_ponte_operada();
	

	void trata_efeito_mutanti_mutantis();

	void imprime_dados_sala();
	

	void dano_sala_fogo();
	void dano_sala_curto_circuito();
	void accoes_salas();

	void trata_efeito_toxicidade();
	void trata_efeito_regenerador();
	void trata_efeito_flamejante();

	//accoes que ocorrem no fim do turno pelos xenomorfos, bem como o combate
	void accoes_xenomorfos();

	//accoes que ocorrem no fim do turno pelos piratas, bem como o combate
	void accoes_piratas();

	//accoes que ocorrem no fim do turno pelos tripulantes, bem como o combate
	void accoes_tripulantes();
	
	int get_escudo();
	int get_milhas();
	bool get_sala_destruida();
	bool verifica_existe_tripulantes();
	void sala_verifica_Robotico();
	void sala_verifica_Reparador();

	void imprime_accoes_salas();
	//limpa o vector das accoes das salas para que receba novas accoes em cada turno
	void limpa_accoes_salas();

	void imprime_info_trip();
	void imprime_info_xeno();
	void imprime_info_pir();

	void imprime_accoes_eventos();
	




};