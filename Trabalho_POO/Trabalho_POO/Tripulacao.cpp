#include "bibliotecas.h"
#include "Tripulacao.h"



char Tripulacao::letra = 'a';

Tripulacao::Tripulacao()
{
	this->nome = this->letra;
	this->letra++;
}

Tripulacao::~Tripulacao()
{

}

void Tripulacao::set_reparador( int valor)
{
	this->reparador = valor;
}

void Tripulacao::set_forca_combate(int valor)
{
	this->forca_combate = valor;
}


void Tripulacao::set_combate(bool aux)
{
	this->combate = aux;
}


int Tripulacao::get_reparador()
{
	return reparador;
}

int Tripulacao::get_forca_combate()
{
	return forca_combate;
}


bool Tripulacao::get_combate()
{
	return combate;
}

char Tripulacao::get_nome()
{
	return nome;
}