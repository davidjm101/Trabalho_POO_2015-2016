#pragma once

#include "bibliotecas.h"
#include "Unidade.h"

class Pirata: public Unidade
{
	int reparador;
	int forca_combate_para_Inimigo;
	int forca_combate_para_Sala;
	static char letra;
	bool combate;
	char nome;

public:
	Pirata();
	~Pirata();
	void set_forca_combate_para_Inimigo(int valor);
	void set_forca_combate_para_Sala(int valor);
	void set_combate(bool aux);
	int get_forca_combate_para_Inimigo();
	int get_forca_combate_para_Sala();
	bool get_combate();
	char get_nome();
	
	
};
