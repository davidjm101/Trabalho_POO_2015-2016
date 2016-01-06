#pragma once

#include "bibliotecas.h"

#include "Unidade.h"

class Tripulacao : public Unidade
{
	int reparador;
	int forca_combate;
	static char letra;
	bool combate;
	char nome;

public:
	Tripulacao();
	~Tripulacao();
	void set_reparador(int valor);
	void set_forca_combate(int valor);
	void set_combate(bool aux);
	int get_reparador();
	int get_forca_combate();
	bool get_combate();
	char get_nome();
};
