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

void Tripulacao::set_combate(int valor)
{
	this->combate = valor;
}

int Tripulacao::get_reparador()
{
	return reparador;
}

int Tripulacao::get_combate()
{
	return combate;
}


char Tripulacao::get_nome()
{
	return nome;
}