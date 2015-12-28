#include "bibliotecas.h"
#include "Sala.h"

Sala::Sala(string nome , int numero)
{
	this->nome = nome;
	this->numero = numero;
	this->saude = 100;
	this->oxigenio = 100;
	this->integridade = 100;
	this->dano = 100 - integridade;
	this->fogo = false;
	this->brecha = false;
	this->curto_circuito = false;

}

Sala::~Sala()
{

}

void Sala::set_nome(string nome)
{
	this->nome = nome;
}

void Sala::set_numero(int numero)
{
	this->numero = numero;
}

void Sala::set_saude(int saude)
{
	this->saude = saude;
}

void Sala::set_oxigenio(int oxigenio)
{
	this->oxigenio = oxigenio;
}

void Sala::set_integridade(int integridade)
{
	this->integridade = integridade;
}

void Sala::set_dano(int dano)
{
	this->integridade = integridade - dano;

}

void Sala::set_fogo(bool existe)
{
	this->fogo = existe;
}


void Sala::set_brecha(bool existe)
{
	this->brecha = existe;
}

void Sala::set_curto_circuito(bool existe)
{
	this->curto_circuito = existe;
}

void Sala::set_tripulante(Tripulacao trip)
{
	tripulantes.push_back(trip);
}




string Sala::get_nome()
{
	return nome;
}


int Sala::get_numero()
{
	return numero;
}

int Sala::get_saude()
{
	return saude;
}

int Sala::get_oxigenio()
{
	return oxigenio;
}

int Sala::get_dano()
{
	return dano;
}

int Sala::get_integridade()
{
	return integridade;
}

bool Sala::get_fogo()
{
	return fogo;
}

bool Sala::get_brecha()
{
	return brecha;
}

bool Sala::get_curto_circuito()
{
	return curto_circuito;
}

bool Sala::verifica_tripulante(char nome)
{
	bool verifica = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i).get_nome() == nome)
		{
			verifica = true;
		}
	}

	return verifica;
}

bool Sala::verifica_sala_operada()
{
	bool verifica = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i).get_operador()==true)
		{
			verifica = true;
		}
	}

	return verifica;
}

Tripulacao Sala::get_tripulantes(char nome)
{
	Tripulacao t;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i).get_nome() == nome)
		{

			t = tripulantes.at(i);
			tripulantes.erase(tripulantes.begin()+i);
			
		}
	}

	

	return t;
}

int Sala::get_quanto_reparar()
{
	int repara=0;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i).get_combate() == false)
		{
			repara += tripulantes.at(i).get_reparador();
		}
	}
	return repara;
	
}

void Sala::get_info_tripulantes()
{
	if (tripulantes.size() > 0)
	{
		for (int i = 0; i < tripulantes.size(); i++)
		{
			cout <<tripulantes.at(i).get_nome() << " ";
		}
	}
	
}
