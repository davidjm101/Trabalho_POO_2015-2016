#pragma once

#include "bibliotecas.h"

#include "Unidade.h"

class Tripulacao : public Unidade
{
	int reparador;
	int combate;
	static char letra;
	char nome;

public:
	Tripulacao();
	~Tripulacao();
	void set_reparador(int valor);
	void set_combate(int valor);
	int get_reparador();
	int get_combate();
	char get_nome();

};
