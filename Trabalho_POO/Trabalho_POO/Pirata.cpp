#include "bibliotecas.h"
#include "Pirata.h"



char Pirata::letra = 'P';

Pirata::Pirata()
{
	this->nome = this->letra;
	this->letra++;
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

void Pirata::set_combate(bool aux) {

	this->combate = aux;
}

bool Pirata::get_combate()
{
	return combate;
}

char Pirata::get_nome()
{
	return nome;
}

