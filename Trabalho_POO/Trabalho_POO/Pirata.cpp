#include "bibliotecas.h"
#include "Pirata.h"



char Pirata::aux = 'P';

Pirata::Pirata()
{
	this->letra = this->aux;
	this->aux++;
}

Pirata::~Pirata()
{

}


void Pirata::set_forca_combate_para_Inimigo(int valor)
{
	this->forca_combate_para_Inimigo = valor;
}

void Pirata::set_forca_combate_para_Sala(int valor)
{
	this->forca_combate_para_Sala = valor;
}


int Pirata::get_forca_combate_para_Inimigo()
{
	return forca_combate_para_Inimigo;
}

int Pirata::get_forca_combate_para_Sala()
{
	return forca_combate_para_Sala;
}

char Pirata::get_letra()
{
	return letra;
}


bool Pirata::verifica_move()
{
	int aux;
	bool move = false;
	aux = aux = rand() % 6 + 1;
	if (aux == 1)
	{
		move = true;
	}
	else
		move = false;
	return move;
}