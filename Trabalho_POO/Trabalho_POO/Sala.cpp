#include "bibliotecas.h"
#include "Sala.h"

Sala::Sala(string nome)
{
	this->nome = nome;
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

string Sala::get_nome()
{
	return nome;
}

int Sala::get_saude()
{
	return saude;
}

int Sala::get_oxigenio()
{
	return oxigenio;
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