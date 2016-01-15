#include "bibliotecas.h"
#include "xenomorfos.h"
#include "Sala.h"

char xenomorfos::aux = 'a';



xenomorfos::xenomorfos()
{
	this->letra = this->aux;
	this->aux++;
}

xenomorfos::~xenomorfos()
{

}

void xenomorfos::set_xenomorfo(int valor)
{

	this->xenomorfo = valor;
}
int xenomorfos::get_xenomorfo()
{
	return xenomorfo;
}


void xenomorfos::set_misterioso(bool valor) //???
{
		srand(time(NULL));
		int probabilidade = rand() % 4 + 1;

		if (probabilidade == 1) {
			this->misterioso = valor;
		}
		else
			this->misterioso = valor;
}

bool xenomorfos::get_misterioso()  /*ele aparece no final do proximo turno numa sala aleatoria
								   verificar*********************************************/
{
	return misterioso;
}

void xenomorfos::set_casulo(int valor)
{
	srand(time(NULL));
	int probabilidade = rand() % 100 + 1;

	if (probabilidade <= valor)
		this->casulo = true;
	else
		this->casulo = false;
}

bool xenomorfos::get_casulo()
{
	return casulo;

}



void xenomorfos::set_regenerador(int valor)
{
	
	this->regenerador = valor;

}
void xenomorfos::altera_vida_do_Xenomorfo()
{
	/*if(this->get_vida() <= 8)
	{
		this->set_vida += this->get_regenerador();
	
	}*/
	/*else if (this->get_vida() == 7)
	{
		this->set_vida() == 8;
	}*/
}

int xenomorfos::get_regenerador()
{
	return regenerador;
}

void xenomorfos::set_flamejante(bool aux) 
{
	this->flamejante = aux;
	
}

bool xenomorfos::get_flamejante()
{
	return flamejante;
}

void xenomorfos::set_toxico(int valor)
{
	this->toxico = valor;

}
int xenomorfos::get_toxico()
{
	return toxico;
}

void xenomorfos::set_hipnotizador(bool valor)
{
		this->hipnotizador = valor;
}

bool xenomorfos::get_hipnotizador()
{
	return hipnotizador;
}

void xenomorfos::set_mutatis_mutandis(int valor)
{
	srand(time(NULL));
	int probabilidade = rand() % 100 + 1;

	if (probabilidade <= valor)
		this->mutatis_mutandis = true;
	else
		this->mutatis_mutandis = false;

}

bool xenomorfos::get_mutatis_mutandis()
{

	return mutatis_mutandis;
}


char xenomorfos::get_letra()
{
	return letra;
}