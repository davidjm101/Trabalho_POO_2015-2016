#include "bibliotecas.h"
#include "Tripulacao.h"
#include "consola.h"


char Tripulacao::aux = 'a';

Tripulacao::Tripulacao()
{
	this->letra = this->aux;
	this->aux++;
	
}

Tripulacao::~Tripulacao()
{

}

void Tripulacao::set_reparador( int valor)
{
	this->reparar = valor;
}

void Tripulacao::set_forca_combate(int valor)
{
	this->forca_combate = valor;
}


void Tripulacao::set_combate(bool aux)
{
	this->combate = aux;
}


int Tripulacao::get_reparar()
{
	return reparar;
}

int Tripulacao::get_forca_combate()
{
	return forca_combate;
}


bool Tripulacao::get_combate()
{
	return combate;
}

char Tripulacao::get_letra()
{
	return  letra;
}

int Tripulacao::quanto_reparar()//retorna quanto e que o tripulante repara se nao estiver em combate
{
	if (combate == false)
	{
		return reparar;
	}
	return 0;
}

void Tripulacao::get_info()
{
	Consola c;
	c.gotoxy(85, 19);
	cout << "Nome: " << get_nome() << "Vida " << get_vida()<< endl;
	c.gotoxy(85, 20);
	cout << "Forca Combate: " << forca_combate << endl;
	system("PAUSE");
}