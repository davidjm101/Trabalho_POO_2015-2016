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
	int valor_escudo;
	bool escudo_ativado;

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

	//funcoes de criacao de unidades
	void set_tripulante();
	void set_capitao();
	void set_robot();
	void set_pirata();
	void set_xenomorfo_geigermorfo();
	void set_xenomorfo_casulo_geigermorfo();
	void set_xenomorfo_blob();
	void set_xenomorfo_mxyzypykwi();

	//vai buscar o numeros de tripulantes em cada sala necessario para saber se ainda a tripulantes
	int get_num_tripulantes();
	void remove_tripulante();

	
	//void retira_vida(int valor);

	string get_nome();
	int get_numero();
	int get_oxigenio();
	int get_dano();
	int get_integridade();
	bool get_fogo();
	bool get_brecha();
	bool get_curto_circuito();
	
	bool verifica_sala_operada();
	void reparar_sala();

	void trata_caracteristica_unidade_respira();
	void trata_caracteristica_toxico();
	void trata_caracteristica_regenerador();
	bool trata_caracteristica_mutatis_mutantis();
	void trata_caracteristica_hipnotizador();
	
	//funcoes para o movimento tripulante
	bool verifica_tripulante(char nome);
	bool verifica_robot_curto_circuito(char nome);
	bool verifica_tripulante_indeciso(char nome);
	Tripulacao* obtem_tripulante(char nome);
	void inser_tripulante(Tripulacao* t);

	//funcoes de mover xenomorfos e piratas
	void move_pirata();

	

	//funcoes dos eventos 
	void atingida_meteorito(int dano);//num é o numero de vezes que a sala é atingida
	void invadida_piratas(int num);//num é o numero de piratas que invadem a sala
	void atacada_piratas(int dano);
	void invadida_xenomorfos();
	void atingida_po_cosmico(int dano);

	//danos do fogo e curto circuito
	void dano_fogo();
	void dano_curto_circuito();
	string get_problema_fogo();
	string get_problema_brecha();
	string get_problema_curto_circuito();

	void get_letra_tripulantes();
	void get_letra_xenomorfos();
	void get_letra_piratas();
	void get_info_tripulante();

	
	void altera_valor_do_dano(int valor);
	
	//funcoes de combate
	void combate_tripulante();
	void combate_xenomorfos();
	void combate_piratas();

	//funcoes proprias das salas
	void suporte_vida();
	bool controlo_escudo();
	void sistema_seguranca_interno();
	void enfermaria();
	void sala_armas();
	void auto_reparador();






};	