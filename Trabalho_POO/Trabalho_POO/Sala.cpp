#include "bibliotecas.h"
#include "Sala.h"

Sala::Sala(string nome , int numero)
{
	this->nome = nome;
	this->numero = numero;
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
/*
void Sala::retira_vida(int valor)
{
	this->vida = vida + valor;
}
*/

void Sala::set_nome(string nome)
{
	this->nome = nome;
}

void Sala::set_numero(int numero)
{
	this->numero = numero;
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


//adiciona um tripulante a sala
void Sala::set_tripulante()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Membro Tripulacao");
	trip->set_vida(5);
	trip->set_respira(true);
	trip->set_operador(true);
	trip->set_reparador(1);
	trip->set_forca_combate(1);
	trip->set_combate(false);
	tripulantes.push_back(trip);
}

//adiciona um capitao a sala
void Sala::set_capitao()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Capitão");
	trip->set_vida(6);
	trip->set_respira(true);
	trip->set_reparador(1);
	trip->set_operador(true);
	trip->set_exoesq(1);
	trip->set_forca_combate(2);
	trip->set_combate(false);
	tripulantes.push_back(trip);
}

//adiciona um robot a sala
void Sala::set_robot()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Robot - X34-ZT2");
	trip->set_vida(8);
	trip->set_respira(false);
	trip->set_reparador(0);
	trip->set_operador(false);
	trip->set_exoesq(2);
	trip->set_forca_combate(3);
	trip->set_combate(false);
	tripulantes.push_back(trip);
}

//adiciona um pirata
void Sala::set_pirata()
{
	Pirata* pirata = new Pirata();
	pirata->set_vida(4);
	pirata->set_respira(true);
	pirata->set_forca_combate_para_Inimigo(1);
	pirata->set_forca_combate_para_Sala(2);
	pirata->set_mover(15);
}

//adiciona um xenomorfo geigermorfo
void Sala::set_xenomorfo_geigermorfo()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Geigermorfo");
	xen->set_vida(4);
	xen->set_xenomorfo(3);
	xen->set_misterioso(true);
	xen->set_mover(50);
	xen->set_casulo(20);
	xen->set_exoesq(3);
}

void Sala::set_xenomorfo_casulo_geigermorfo()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Casulo de Geigermorfo");
	xen->set_vida(6);
	xen->set_xenomorfo(0);
	xen->set_exoesq(1);

}

void Sala::set_xenomorfo_blob()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Blob");
	xen->set_vida(8);
	xen->set_xenomorfo(0);
	xen->set_regenerador(2);
	xen->set_flamejante(true);
	xen->set_toxico(true);
	xen->set_reparador(6);
	xen->set_operador(true);
	xen->set_mover(15);
}

void Sala::set_xenomorfo_mxyzypykwi()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Mxyzypykwi");
	xen->set_vida(8);
	xen->set_xenomorfo(0);
	xen->set_hipnotizador(15);
	xen->set_mover(30);
	xen->set_mutatis_mutandis(10);
	xen->set_respira(true);
}



void Sala::remove_tripulante()
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_nome() == "Membro Tripulacao")
		{
			tripulantes.erase(tripulantes.begin() + i);
			break;
		}
	}
}






string Sala::get_nome()
{
	return nome;
}

int Sala::get_numero()
{
	return numero;
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




//verifica se existe algum tripulante na sala com este nome
bool Sala::verifica_tripulante(char nome)
{
	bool verifica = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == nome)
		{
			verifica = true;
		}
	}
	return verifica;
}

//obtem o tripulante da sala original para se mover para outra sala
//apagando-o da sala original
Tripulacao* Sala::obtem_tripulante(char nome)
{
	Tripulacao* t= new Tripulacao();
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == nome)
		{

			t = tripulantes.at(i);
			tripulantes.erase(tripulantes.begin()+i);
			break;
		}
	}
  return t;
}

//insere o tripulante na nova sala depois de mover
void Sala::inser_tripulante(Tripulacao* t)
{
	tripulantes.push_back(t);
}

//reparar sala
void Sala::reparar_sala()
{
	int i;
	int reparar = 0;
	for (i = 0; i < tripulantes.size(); i++)
	{
		reparar += tripulantes.at(i)->quanto_reparar();
	}
	if (integridade < 100)
	{
		integridade += reparar;
	}

}




bool Sala::verifica_sala_operada()//verifica se a sala em questao esta a ser operada
{
	bool verifica = false;
	/*for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i).get_operador()==true)
		{
			verifica = true;
		}
	}*/

	return verifica;
}



//void Sala::verifica_tripulante_respira()
//{
//
//	if (oxigenio > 0)
//	{
//
//	}
//}


//sbuscar 
void Sala::get_info_tripulantes()
{
	if (tripulantes.size() > 0)
	{
		for (int i = 0; i < tripulantes.size(); i++)
		{
			cout << tripulantes.at(i)->get_letra() << " ";
		}
	}
	
}


void Sala::atingida_meteorito(int dano)
{
	integridade -= dano;
	brecha = true;
}