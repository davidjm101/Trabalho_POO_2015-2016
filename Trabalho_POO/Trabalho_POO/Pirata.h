#pragma once

#include "bibliotecas.h"
#include "Unidade.h"

class Pirata: public Unidade
{
	int reparador;
	int forca_combate_para_Inimigo;
	int forca_combate_para_Sala;
	static char aux;
	char letra;

public:
	Pirata();
	~Pirata();
	void set_forca_combate_para_Inimigo(int valor);
	void set_forca_combate_para_Sala(int valor);
	int get_forca_combate_para_Inimigo();
	int get_forca_combate_para_Sala();
	char get_letra();
	bool verifica_move();
	
	
};
