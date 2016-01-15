#pragma once

#include "bibliotecas.h"

#include "Unidade.h"

class Tripulacao : public Unidade
{
	int quanto_reparar;
	int forca_combate;
	int forca_arma;
	static char aux;
	bool combate;
	char letra;
	bool indeciso;
	bool robotico;
	bool arma;

public:
	Tripulacao();
	~Tripulacao();
	void set_forca_combate(int valor);
	void set_combate(bool aux);
	void set_forca_arma(int valor);
	void set_arma(bool aux);
	int get_forca_combate();
	bool get_combate();
	char get_letra();
	

	void get_info();

	bool get_indeciso();
	void set_indeciso(int conta_numero_vezes_hipnotizado);
	void set_robotico(bool valor);
	bool get_robotico();
	int get_forca_arma();
	bool get_arma();

};
