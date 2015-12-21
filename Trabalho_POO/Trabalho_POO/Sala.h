#pragma once
#include "bibliotecas.h"

class Sala {
	string nome;
	int saude;
	int oxigenio;
	int integridade;
	int dano;
	bool fogo;
	bool brecha;
	bool curto_circuito;

public:
	Sala(string nome);
	~Sala();
	void set_nome(string nome);
	void set_saude(int saude);
	void set_oxigenio(int oxigenio);
	void set_integridade(int integridade);
	void set_fogo(bool existe);
	void set_brecha(bool existe);
	void set_curto_circuito(bool existe);
	string get_nome();
	int get_saude();
	int get_oxigenio();
	int get_integridade();
	bool get_fogo();
	bool get_brecha();
	bool get_curto_circuito();





};	