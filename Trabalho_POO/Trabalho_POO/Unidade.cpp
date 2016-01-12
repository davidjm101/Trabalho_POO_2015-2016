#include "bibliotecas.h"
#include "Unidade.h"


Unidade::Unidade()
{
}

Unidade::~Unidade()
{
}

void Unidade::set_nome(string nome)
{
	this->nome = nome;
}

void Unidade::set_vida(int valor)
{
	this->vida = valor;
}


void Unidade::set_respira(bool valor)
{
	this->respira = valor;
}

void Unidade::set_operador(bool valor)
{
	this->operador = valor;
}

void Unidade::set_mover(int valor)
{
	this->mover = valor;   /*/percentagem ->verificar depois*/
}

void Unidade::set_exoesq(int valor)
{
	this->exoesq = valor;
}

string Unidade::get_nome()
{
	return nome;
}
int Unidade::get_vida() 
{
	return vida;
}

int Unidade::get_mover()
{
	return mover;
}

int Unidade::get_exoesq()
{
	return exoesq;
}

bool Unidade::get_respira()
{
	return respira;
}


bool Unidade::get_operador()
{
	return operador;
}