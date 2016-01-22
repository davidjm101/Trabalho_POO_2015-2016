#include "bibliotecas.h"
#include "xenomorfos.h"
#include "Sala.h"

char xenomorfos::aux = 'A';



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



//verifica se é flamejante e se for retorna o dano
int xenomorfos::get_flamejante()
{
	int dano=0;
	if (flamejante == true)
	{
		dano = 5;
	}
	return dano;
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

//regenera vida se tiver essa opcao
void xenomorfos::regenera_vida()
{
	if (regenerador > 0)
	{
		if (get_vida() < 100)
		{
			acrescenta_vida(regenerador);
		}
		if (get_vida() > 100)
		{
			set_vida(100);
		}
	}
}

bool xenomorfos::get_mutatis_mutandis()
{

	return mutatis_mutandis;
}


bool xenomorfos::verifica_move()
{
	int aux;
	bool move = false;
	if (get_nome() == "Geigermorfo")
	{
		aux = aux = rand() % 2 + 1;
		if (aux == 1)
		{
			move = true;
		}
		else
			move = false;
	}
	else if (get_nome() == "Blob")
	{
		aux = aux = rand() % 7 + 1;
		if (aux == 1)
		{
			move = true;
		}
		else
			move = false;
	}
	else if (get_nome() == "Mxyzypykwi")
	{
		aux = aux = rand() % 3 + 1;
		if (aux == 1)
		{
			move = true;
		}
		else
			move = false;
	}
	
	return move;
}


char xenomorfos::get_letra()
{
	return letra;
}