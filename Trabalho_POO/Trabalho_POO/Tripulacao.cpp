#include "bibliotecas.h"
#include "Tripulacao.h"
#include "consola.h"


char Tripulacao::aux = 'a';

Tripulacao::Tripulacao()
{
	this->letra = this->aux;
	this->aux++;
	this->arma = false;
	this->forca_arma = 1;
	
}

Tripulacao::~Tripulacao()
{

}





void Tripulacao::set_forca_combate(int valor)
{
	this->forca_combate = valor;
}


void Tripulacao::set_combate(bool aux)
{
	this->combate = aux;
}

void Tripulacao::set_forca_arma(int valor)
{
	this->forca_arma = valor;
}

void Tripulacao::set_arma(bool aux)
{
	this->arma = aux;
}


void Tripulacao::set_indeciso(int conta_numero_vezes_hipnotizado)
{
		srand(time(NULL));
		int probabilidade = rand() % 100 + 1;

		if (conta_numero_vezes_hipnotizado == 0) 
		{
			if (probabilidade <= 50)
				this->indeciso = true;
			else
				this->indeciso = false;
		}
		else if (conta_numero_vezes_hipnotizado == 1)
		{
			if (probabilidade <= 75)
				this->indeciso = true;
			else
				this->indeciso = false;
		}
		else
			this->indeciso = true;
}

bool Tripulacao::get_indeciso()
{
	bool verifica = false;
	int aux;
	if (indeciso == true)
	{
		aux = rand() % 2 + 1;
		if (aux == 1)//ignora o comando de mover
		{
			verifica = true;
		}
		else
		{
			verifica = false;
		}
	}
	return verifica;
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



void Tripulacao::set_robotico(bool valor)
{
	this->robotico = valor;
}

bool Tripulacao::get_robotico() {
	return robotico;

}

int Tripulacao::get_forca_arma()
{
	return forca_arma;
}

bool Tripulacao::get_arma()
{
	return arma;
}