#pragma once
#include "bibliotecas.h"
#include "Tripulacao.h"
#include "xenomorfos.h"
#include "Pirata.h"

class Sala {
	string nome;
	int numero;
	int oxigenio;
	int integridade;
	int dano;
	bool fogo;
	bool brecha;
	bool curto_circuito;
	vector <Tripulacao*> tripulantes;
	vector <xenomorfos*> Xenomorfos;
	vector <Pirata*> piratas;

public:
	Sala(string nome, int numero);
	~Sala();
	void set_nome(string nome);
	void set_numero(int numero);
	void set_oxigenio(int oxigenio);
	void set_integridade(int integridade);
	void set_dano(int dano);
	void set_fogo(bool existe);
	void set_brecha(bool existe);
	void set_curto_circuito(bool existe);
	void set_tripulante();
	void set_capitao();
	void set_robot();
	void set_pirata();
	void set_xenomorfo_geigermorfo();
	void set_xenomorfo_casulo_geigermorfo();
	void set_xenomorfo_blob();
	void set_xenomorfo_mxyzypykwi();
	void remove_tripulante();
	void reparar_sala();
	
	//void retira_vida(int valor);

	string get_nome();
	int get_numero();
	int get_oxigenio();
	int get_dano();
	int get_integridade();
	bool get_fogo();
	bool get_brecha();
	bool get_curto_circuito();
	bool verifica_tripulante(char nome);
	bool verifica_sala_operada();
	Tripulacao* obtem_tripulante(char nome);
	void inser_tripulante(Tripulacao* t);
	void trata_caracteristica_unidade_respira();
	void trata_caracteristica_toxico();

	void atingida_meteorito(int dano);//num é o numero de vezes que a sala é atingida

	void invadida_piratas(int num);//num é o numero de piratas que invadem a sala
	void atacada_piratas(int dano);
	void invadida_xenomorfos();
	void atingida_po_cosmico(int dano);
	void get_letra_tripulantes();
	void get_letra_xenomorfos();
	void get_letra_piratas();
	void get_info_tripulante(char nome);

	void sala_invadida_piratas(int num);//num é o numero de piratas que invadem a sala
	void sala_atacada_piratas(int dano);
	void get_info_tripulantes();
	void trata_caracteristica_indeciso();
	void trata_caracteristica_hipnotizador(int valor);
	void trata_caracteristica_Regenerador();
	void trata_caracteristica_Misterioso();
	void trata_caracteristica_Robotico();
	void trata_caracteristica_Reparador(int valor);
	void altera_valor_do_dano(int valor);







};	