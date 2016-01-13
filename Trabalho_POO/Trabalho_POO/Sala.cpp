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
	piratas.push_back(pirata);
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
	Xenomorfos.push_back(xen);
}

void Sala::set_xenomorfo_casulo_geigermorfo()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Casulo de Geigermorfo");
	xen->set_vida(6);
	xen->set_xenomorfo(0);
	xen->set_exoesq(1);
	Xenomorfos.push_back(xen);

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
	Xenomorfos.push_back(xen);
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
	Xenomorfos.push_back(xen);
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
		if (tripulantes.at(i)->get_letra() == nome )
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


//sbuscar 
void Sala::get_letra_tripulantes()
{
	if (tripulantes.size() > 0)
	{
		for (int i = 0; i < tripulantes.size(); i++)
		{
			cout << tripulantes.at(i)->get_letra() << " ";
		}
	}

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


//verifica se a sala em questao esta a ser operada
bool Sala::verifica_sala_operada()
{
	bool verifica = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_operador()==true)
		{
			verifica = true;
		}
	}

	return verifica;
}


//opera o oxigenio existente na sala consoante o numero de unidades pertencentes a esta sala no momento
void Sala::trata_caracteristica_unidade_respira()
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_respira() == true)
		{
			if (oxigenio > 0)
				oxigenio = oxigenio - 1;
			else
				tripulantes.at(i)->reduz_vida(1);
		}
	}

	for (int i = 0; i < piratas.size(); i++)
	{
		if (piratas.at(i)->get_respira() == true)
		{
			if (oxigenio > 0)
				oxigenio = oxigenio - 1;
			else
				piratas.at(i)->reduz_vida(1);
		}
	}

	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_respira() == true)
		{
			if (oxigenio > 0)
				oxigenio = oxigenio - 1;
			else
				Xenomorfos.at(i)->reduz_vida(1);
		}

		else if (Xenomorfos.at(i)->get_flamejante() == true)  ///Instrução de verificação se o xenomorfo é flamejante
		{
			oxigenio = oxigenio - 5;
			
		}

	}

}

void Sala::trata_caracteristica_toxico() /// vai verificar as unidades que contenham toxicidade e retirar vidas aos outros que nao sao toxicos
{
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (int valordetoxico = Xenomorfos.at(i)->get_toxico() > 0)
		{
			for (int i = 0; i < piratas.size(); i++)
			{
				piratas.at(i)->reduz_vida(valordetoxico);
			}

			for (int i = 0; i < tripulantes.size(); i++)
			{
				tripulantes.at(i)->reduz_vida(valordetoxico);
			}
		}
	}
}

void Sala::trata_caracteristica_hipnotizador(int valor)
{
	srand(time(NULL));
	int probabilidade = rand() % 100 + 1;

	for (int i = 0; i < Xenomorfos.size(); i++) {

		if (probabilidade <= valor)
		{
			int escolhe_unidade = rand() % tripulantes.size() + 1;

			if (tripulantes.at(escolhe_unidade)->get_indeciso() == false) {
				tripulantes.at(escolhe_unidade)->set_indeciso(0);
				Xenomorfos.at(i)->set_hipnotizador(true);

			}
			else if (tripulantes.at(escolhe_unidade)->get_indeciso() == true) {
				tripulantes.at(escolhe_unidade)->set_indeciso(1);
				Xenomorfos.at(i)->set_hipnotizador(true);
			}

		}
		Xenomorfos.at(i)->set_hipnotizador(false);
	}

}


void Sala::trata_caracteristica_Misterioso()
{
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_nome() == "Geigermorfo")
		{
			Xenomorfos.at(i)->set_misterioso(true);
		}
	}
}




void Sala::trata_caracteristica_Regenerador()
{
	/*for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_nome() = "Blob")
		{
			Xenomorfos.at(i)->altera_vida_do_Xenomorfo();
		}
	}*/

}

void Sala::trata_caracteristica_Robotico() 
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_nome() == "Robot - X34-ZT2" && this->curto_circuito == true)
		{
			tripulantes.at(i)->set_robotico(true); ///vai activar a propriedade de robotico que depois impossibilita mover
		}
	}
}



void Sala::get_letra_xenomorfos()
{
	if (Xenomorfos.size() > 0)
	{
		for (int i = 0; i < Xenomorfos.size(); i++)
		{
			cout << Xenomorfos.at(i)->get_letra() << " ";
		}
	}

}

void Sala::get_letra_piratas()
{
	if (piratas.size() > 0)
	{
		for (int i = 0; i < piratas.size(); i++)
		{
			cout << piratas.at(i)->get_letra() << " ";
		}
	}

}


void Sala::get_info_tripulante(char nome)
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == nome)
		{
			tripulantes.at(i)->get_info();
		}
	}
}


//sala atingida por meteoritos
void Sala::atingida_meteorito(int dano)
{
	integridade -= dano;
	brecha = true;
	oxigenio = 0;
}

//sala atacada por nave pirata
void Sala::atacada_piratas(int dano)
{
	int aux;
	integridade -= dano;
	srand(time(NULL));
	aux = rand() % 3 + 1;
	//mete fogo a sala
	if (aux == 1)
	{
		if (brecha == false)//verifica se a brecha na sala, poisa caso houver nao pode haver fogo
		{
			fogo = true;
		}
		
	}
	//mete curto circuito a sala
	else if (aux == 2)
	{
		curto_circuito = true;
	}
	//mete brecha a sala
	else
	{
		brecha = true;
		oxigenio = 0;
	}
}

//sala invadida por piratas
void Sala::invadida_piratas(int num)
{
	do
	{
		set_pirata();
		num--;

	} while (num > 0);
}

//sala invadida por xenomorfos
void Sala::invadida_xenomorfos()
{
	int aux;

	srand(time(NULL));
	aux = rand() % 3 + 1;
	if (aux == 1)
	{
		set_xenomorfo_geigermorfo();
	}
	else if (aux == 2)
	{
		set_xenomorfo_blob();
	}
	else
	{
		set_xenomorfo_mxyzypykwi();
	}
}

//sala atingida por po cosmico
void Sala::atingida_po_cosmico(int dano)
{
	integridade -= dano;

}



//verifica que a sala esta em fogo e se sim cada unidade perde vida
void Sala::dano_fogo()
{
	int aux = 2;
	if (oxigenio == 0)
	{
		fogo = false;
	}

	if (fogo == true)
	{
		for (int i = 0; i < tripulantes.size(); i++)
		{
			tripulantes.at(i)->reduz_vida(aux);
		}

		for (int i = 0; i < piratas.size(); i++)
		{
			piratas.at(i)->reduz_vida(aux);
		}

		for (int i = 0; i < Xenomorfos.size(); i++)
		{
			Xenomorfos.at(i)->reduz_vida(aux);
		}
	}
}

//verifica que a sala esta em curto_circuito e se sim cada unidade perde vida
void Sala::dano_curto_circuito()
{
	int aux;
	int dano = 0;
	aux = rand() % 1 + 4;
	//saiu a probabilidade de 25% logo todas as unidades vao receber dano
	if (aux == 1)
	{
		if (tripulantes.size() > 0)//verifica se exitem alguns tripulantes na sala
		{
			dano += (tripulantes.size() + 1);//se sim o dano vai se igual a size do array + 1, pois o array comeca em 0
		}
		if (piratas.size() > 0)//verifica se exitem alguns piratas na sala
		{
			dano += (piratas.size() + 1);//se sim o dano vai se igual a size do array + 1, pois o array comeca em 0
		}
		if (Xenomorfos.size() > 0)//verifica se exitem alguns xenomorfos na sala
		{
			dano += (Xenomorfos.size() + 1);//se sim o dano vai se igual a size do array + 1, pois o array comeca em 0
		}
				
		
		for (int i = 0; i < tripulantes.size(); i++)
		{
			tripulantes.at(i)->reduz_vida(dano);
		}

		for (int i = 0; i < piratas.size(); i++)
		{
			piratas.at(i)->reduz_vida(dano);
		}

		for (int i = 0; i < Xenomorfos.size(); i++)
		{
			Xenomorfos.at(i)->reduz_vida(dano);
		}
	}

}

//retorna string FG caso a sala esteja em fogo
string Sala::get_problema_fogo()
{
	string aux="";
	if (fogo == true)
	{
		aux = "FG";
	}
	return aux;
}

//retorna string BR caso a sala tenha brecha
string Sala::get_problema_brecha()
{
	string aux = "";
	if (brecha == true)
	{
		aux = "BR";
	}
	return aux;
}

//retorna string CC caso a sala tenha curto_circuito
string Sala::get_problema_curto_circuito()
{
	string aux = "";
	if (curto_circuito == true)
	{
		aux = "CC";
	}
	return aux;
}






void Sala::trata_caracteristica_Reparador(int valor) 
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_combate() == false && this->dano < 100 && Xenomorfos.at(i)->get_nome() == "Capitão")
			this->altera_valor_do_dano(valor);

	
	}
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_combate() == false && this->dano < 100 && Xenomorfos.at(i)->get_nome()=="Blob")
			this->altera_valor_do_dano(valor);
	}


}


void Sala::altera_valor_do_dano(int valor)
{
	this->dano += valor;

}