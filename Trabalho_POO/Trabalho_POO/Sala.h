#pragma once
#include "bibliotecas.h"
#include "Tripulacao.h"

class Sala {
	string nome;
	int numero;
	int saude;
	int oxigenio;
	int integridade;
	int dano;
	bool fogo;
	bool brecha;
	bool curto_circuito;
	vector <Tripulacao> tripulantes;

public:
	Sala(string nome, int numero);
	~Sala();
	void set_nome(string nome);
	void set_numero(int numero);
	void set_saude(int saude);
	void set_oxigenio(int oxigenio);
	void set_integridade(int integridade);
	void set_dano(int dano);
	void set_fogo(bool existe);
	void set_brecha(bool existe);
	void set_curto_circuito(bool existe);
	void set_tripulante(Tripulacao trip);
	//void retira_vida(int valor);

	string get_nome();
	int get_numero();
	int get_saude();
	int get_oxigenio();
	int get_dano();
	int get_integridade();
	bool get_fogo();
	bool get_brecha();
	bool get_curto_circuito();
	bool verifica_tripulante(char nome);
	bool verifica_sala_operada();
	Tripulacao get_tripulantes(char nome);

	int get_quanto_reparar();

	void get_info_tripulantes();






};	