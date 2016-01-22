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
	this->escudo_ativado = true;
	this->valor_escudo = 0;

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






//retorna o numero de tripulantes na sala para saber se ainda existe tripulantes na sala
int Sala::get_num_tripulantes()
{
	return tripulantes.size();
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




//adiciona um tripulante a sala
void Sala::set_tripulante()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Membro Tripulacao");
	trip->set_vida(5);
	trip->set_respira(true);
	trip->set_operador(true);
	trip->set_exoesq(0);
	trip->set_quanto_reparar(1);
	trip->set_forca_combate(1);
	trip->set_combate(false);
	trip->set_repara(true);
	tripulantes.push_back(trip);
}

//adiciona um capitao a sala
void Sala::set_capitao()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Capitão");
	trip->set_vida(6);
	trip->set_respira(true);
	trip->set_quanto_reparar(1);
	trip->set_operador(true);
	trip->set_exoesq(1);
	trip->set_forca_combate(2);
	trip->set_combate(false);
	trip->set_repara(true);
	tripulantes.push_back(trip);
}

//adiciona um robot a sala
void Sala::set_robot()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Robot - X34-ZT2");
	trip->set_vida(8);
	trip->set_respira(false);
	trip->set_quanto_reparar(1);
	trip->set_operador(false);
	trip->set_exoesq(2);
	trip->set_forca_combate(3);
	trip->set_combate(false);
	trip->set_repara(false);
	tripulantes.push_back(trip);
}

//adiciona um pirata
void Sala::set_pirata()
{
	Pirata* pirata = new Pirata();
	pirata->set_vida(4);
	pirata->set_respira(true);
	pirata->set_combate(false);
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
	xen->set_regenerador(0);
	xen->set_flamejante(false);
	xen->set_toxico(false);
	xen->set_misterioso(true);
	xen->set_mutatis_mutandis(0);
	xen->set_quanto_reparar(0);
	xen->set_mover(50);
	xen->set_casulo(20);
	xen->set_exoesq(3);
	xen->set_repara(false);
	xen->set_operador(false);
	xen->set_hipnotizador(0);
	xen->set_combate(false);
	Xenomorfos.push_back(xen);
}

//adiciona um xenomorfo casulo
void Sala::set_xenomorfo_casulo_geigermorfo()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Casulo de Geigermorfo");
	xen->set_vida(6);
	xen->set_xenomorfo(0);
	xen->set_regenerador(0);
	xen->set_flamejante(false);
	xen->set_toxico(false);
	xen->set_misterioso(false);
	xen->set_quanto_reparar(0);
	xen->set_mutatis_mutandis(0);
	xen->set_repara(false);
	xen->set_operador(false);
	xen->set_exoesq(1);
	xen->set_mover(0);
	xen->set_hipnotizador(0);
	xen->set_combate(false);
	Xenomorfos.push_back(xen);

}

//adiciona um xenomorfo blob
void Sala::set_xenomorfo_blob()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Blob");
	xen->set_vida(8);
	xen->set_xenomorfo(0);
	xen->set_regenerador(2);
	xen->set_flamejante(true);
	xen->set_toxico(true);
	xen->set_misterioso(false);
	xen->set_quanto_reparar(6);
	xen->set_mutatis_mutandis(0);
	xen->set_repara(true);
	xen->set_operador(true);
	xen->set_exoesq(0);
	xen->set_mover(15);
	xen->set_hipnotizador(0);
	xen->set_combate(false);
	Xenomorfos.push_back(xen);
}

//adiciona um xenomorfo mxyzypykwi
void Sala::set_xenomorfo_mxyzypykwi()
{
	xenomorfos* xen = new xenomorfos();
	xen->set_nome("Mxyzypykwi");
	xen->set_vida(8);
	xen->set_xenomorfo(0);
	xen->set_regenerador(0);
	xen->set_hipnotizador(15);
	xen->set_flamejante(true);
	xen->set_toxico(false);
	xen->set_misterioso(false);
	xen->set_mover(30);
	xen->set_quanto_reparar(0);
	xen->set_mutatis_mutandis(10);
	xen->set_repara(false);
	xen->set_operador(false);
	xen->set_exoesq(0);
	xen->set_combate(false);
	Xenomorfos.push_back(xen);
}



//verifica se existe algum tripulante na sala com este nome
bool Sala::verifica_tripulante(char letra)
{
	bool verifica = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == letra)
		{
			verifica = true;
		}
	}
	return verifica;
}

//verifica se o robot pode se mexer, caso a sala nao esteja em curto-circuito
bool Sala::verifica_robot_curto_circuito(char letra)
{
	bool verifica=true;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == letra)
		{
			if (tripulantes.at(i)->get_nome() == "Robot - X34-ZT2")
			{
				if (curto_circuito == true)
				{
					verifica = false;
				}
			}
		}
	}
	return verifica;
}

//verifica se o tripulante esta indeciso e se vai se mover ou nao
bool Sala::verifica_tripulante_indeciso(char letra)
{
	bool indeciso = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == letra)
		{
			indeciso =tripulantes.at(i)->get_indeciso();
		}
	}
	return indeciso;
}

//obtem o tripulante da sala original para se mover para outra sala
//apagando-o da sala original
Tripulacao* Sala::obtem_tripulante(char letra)
{
	Tripulacao* t= new Tripulacao();
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == letra )
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


//funcao para mover pirata
void Sala::move_pirata(vector<Pirata*>& pir)
{

	if (piratas.size() > 0)
	{
		for (int i = 0; i< piratas.size(); i++)
		{
			if (piratas.at(i)->verifica_move() == true)
			{
			
				pir.push_back(piratas.at(i));
				piratas.erase(piratas.begin() + i);
			
			}
		}
		
	}
}

void Sala::inser_pirata(Pirata* p)
{
	piratas.push_back(p);
}

//funcao para mover xenomorfo
void Sala::move_xenomorfo(vector<xenomorfos*>& xeno)
{
	if (Xenomorfos.size() > 0)
	{
		for (int i = 0; i< Xenomorfos.size(); i++)
		{
			if (Xenomorfos.at(i)->verifica_move() == true)
			{

				xeno.push_back(Xenomorfos.at(i));
				Xenomorfos.erase(Xenomorfos.begin() + i);

			}
		}

	}
}

void Sala::inser_xenomrofo(xenomorfos* x)
{
	Xenomorfos.push_back(x);
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



//reparar sala
void Sala::reparar_sala()
{
	int i;
	if (integridade < 100)
	{
		for (i = 0; i < tripulantes.size(); i++)
		{
			if (tripulantes.at(i)->get_repara() == true && tripulantes.at(i)->get_combate() == false)
			{
				integridade += tripulantes.at(i)->get_quanto_reparar();
			}
			//verifica se a integridade passou dos 100 depois de reparar
			if (integridade > 100)
			{
				//repoem a 100, pois a integridade nao deve ser maior que 100 e para o ciclo
				integridade = 100;
			}
			if (integridade == 100)
			{
				fogo = false;
				brecha = false;
				curto_circuito = false;
			}
		}

		for (i = 0; i < Xenomorfos.size(); i++)
		{
			if (Xenomorfos.at(i)->get_repara() == true && Xenomorfos.at(i)->get_combate()==false)
			{
				integridade += Xenomorfos.at(i)->get_quanto_reparar();
			}
			//verifica se a integridade passou dos 100 depois de reparar
			if (integridade > 100)
			{
				//repoem a 100, pois a integridade nao deve ser maior que 100 e para o ciclo
				integridade = 100;
			}
			if (integridade == 100)
			{
				fogo = false;
				brecha = false;
				curto_circuito = false;
			}
		}
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

	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_operador() == true)
		{
			verifica = true;
		}
	}

	return verifica;
}




//opera o oxigenio existente na sala consoante o numero de unidades pertencentes a esta sala no momento
void Sala::trata_caracteristica_unidade_respira()
{
	string accao;
	stringstream ss;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_respira() == true)
		{
			//retira 1 de oxigenio a sala por cada tripulante na sala
			if (oxigenio > 0)
			{
				oxigenio = oxigenio - 1;
				if (oxigenio < 0)
				{
					oxigenio = 0;
				}
			}
			else
			{
				tripulantes.at(i)->reduz_vida(1);
				//se o tripulante ja nao tiver vida entao e removido do vector
				if (tripulantes.at(i)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Tripulante " << tripulantes.at(i)->get_letra() << " morreu por falta de oxigenio";
					accao = ss.str();
					accoes_trip.push_back(accao);
					ss.str(string());
					//apaga o tripulante do vector
					tripulantes.erase(tripulantes.begin() + i);
				
				}
			}
				
		}
	}

	for (int i = 0; i < piratas.size(); i++)
	{
		if (piratas.at(i)->get_respira() == true)
		{
			//retira 1 de oxigenio a sala por cada pirata na sala
			if (oxigenio > 0)
			{
				oxigenio = oxigenio - 1;
				if (oxigenio < 0)
				{
					oxigenio = 0;
				}
			}
			else
			{
				piratas.at(i)->reduz_vida(1);
				//se o pirata ja nao tiver vida entao e removido do vector
				if (piratas.at(i)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Pirata " << piratas.at(i)->get_letra() << " morreu por falta de oxigenio";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());
					//apaga o pirata do vector
					piratas.erase(piratas.begin() + i);
				
				}
			}
				
		}
	}

	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_respira() == true)
		{
			//retira 1 de oxigenio a sala por cada xenomorofo na sala
			if (oxigenio > 0)
			{
				oxigenio = oxigenio - 1;
				if (oxigenio < 0)
				{
					oxigenio = 0;
				}
			}
				
			else
			{
				Xenomorfos.at(i)->reduz_vida(1);
				//se o xenomorfo ja nao tiver vida entao e removido do vector
				if (Xenomorfos.at(i)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " morreu por falta de oxigenio";
					accao = ss.str();
					accoes_xeno.push_back(accao);
					ss.str(string());
					//apaga o xenomorfo do vector
					Xenomorfos.erase(Xenomorfos.begin() + i);
				
				}
			}
				
		}
	}

}

// vai verificar as unidades que contenham toxicidade e retirar vidas aos outros que nao sao toxicos
void Sala::trata_caracteristica_toxico() 
{
	int valordetoxico;
	int i;
	string accao;
	stringstream ss;

	for (i = 0; i < Xenomorfos.size(); i++)
	{
		valordetoxico = Xenomorfos.at(i)->get_toxico();
		
		if (valordetoxico > 0)
		{
			for (int j = 0; j < piratas.size(); j++)
			{
				piratas.at(j)->reduz_vida(valordetoxico);

				//string usada para a impressao na parte das accoes
				ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " antigiu com toxico o pirata " << piratas.at(j)->get_letra();
				accao = ss.str();
				accoes_xeno.push_back(accao);
				ss.str(string());

				//se o pirata ja nao tiver vida entao e removido do vector
				if (piratas.at(j)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Pirata " << piratas.at(j)->get_letra() << " foi destruido pelo toxico";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());
					//remove do vector o pirata que ja nao tem vida
					piratas.erase(piratas.begin() + j);
					
				}
			}

			for (int z = 0; z < tripulantes.size(); z++)
			{
				tripulantes.at(z)->reduz_vida(valordetoxico);
				//string usada para a impressao na parte das accoes
				ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " antigiu com toxico o tripulante " << tripulantes.at(z)->get_letra();
				accao = ss.str();
				accoes_xeno.push_back(accao);
				ss.str(string());

				//se o tripulante ja nao tiver vida entao e removido do vector
				if (tripulantes.at(z)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Tripulante " << tripulantes.at(z)->get_letra() << " foi destruido pelo toxico";
					accao = ss.str();
					accoes_trip.push_back(accao);
					ss.str(string());

					//remove do vector o tripulante que ja nao tem vida
					tripulantes.erase(tripulantes.begin() + z);
					
				}
			}
		}
	}
}

//vai verificar se a unidade se regenera, se sim entao regenera vida
void Sala::trata_caracteristica_regenerador()
{
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		Xenomorfos.at(i)->regenera_vida();
	}
}

//vai verificar se existe alguma unidade com efeito de mutatis mutantis
bool Sala::trata_caracteristica_mutatis_mutantis()
{
	bool verifica=false;
	int aux;
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_mutatis_mutandis()>0)
		{
			aux = rand() % 2 + 1;// probabilidade de 10%
			if (aux == 1)
			{
				verifica = true;
			}	
		}
	}
	return verifica;

}

//vai verificar se a unidade tem caracteristica hipnotizador, e se ele vai hipnotizar alguem
void Sala::trata_caracteristica_hipnotizador()
{
	int aux;
	string accao;
	stringstream ss;
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_hipnotizador()>0)
		{
			aux = rand() % 7 + 1;//probabilidade de 15%
			if (aux == 1)
			{
				aux= rand() % tripulantes.size();
				tripulantes.at(aux)->set_indeciso(true);
				//string usada para a impressao na parte das accoes
				ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " foi hipnotizado";
				accao = ss.str();
				accoes_trip.push_back(accao);
				ss.str(string());
			}
		}
	}
}

//vai verificar se a alguma unidade com caracteristica flamejante, se sim tira oxigenio a sala
void Sala::trata_caracteristica_flamajenta()
{
	int dano;
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		dano=Xenomorfos.at(i)->get_flamejante();
		if (dano > 0)
		{
			oxigenio -= dano;
		}
		if (oxigenio < 0)
		{
			oxigenio = 0;
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
	aux = rand() % 3 + 1;
	//mete fogo a sala
	if (aux == 1)
	{
		if (brecha == false)//verifica se a brecha na sala, pois caso houver nao pode haver fogo
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
	aux = rand() % 3 + 1;
	/*if (aux == 1)
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
	}*/
	set_xenomorfo_mxyzypykwi();
}

//sala atingida por po cosmico
void Sala::atingida_po_cosmico(int dano)
{
	integridade -= dano;

}




//combate dentro de uma sala onde o tripulante ataca
void Sala::combate_tripulante()
{
	int i;
	int ataque;
	int aux;
	int exoesqueleto;
	bool verifica = true;
	string accao;
	stringstream ss;
	
	
		for (i = 0; i < tripulantes.size(); i++)
		{
			verifica = true;
			//vai verificar se o tripulante e robot
			if (tripulantes.at(i)->get_nome() == "Robot - X34 - ZT2")
			{
				//se for robot, ve se a sala esta em curto circuito
				if (curto_circuito == true)
				{
					//se tiver o robot nao pode atacar
					verifica = false;
					
					////string usada para a impressao na parte das accoes
					ss << "Tripulante " << tripulantes.at(i)->get_letra() << " nao pode atacar, sala curto_cir ";
					accao = ss.str();
					accoes_trip.push_back(accao);
					ss.str(string());
				}
			}
			//este verifica e por causa do robot
			if (verifica == true)
			{
				ataque = tripulantes.at(i)->get_forca_combate();//vai buscar a forca de ataque 
				

				//existe piratas e xenomorfos para atacar
				if (Xenomorfos.size() != 0 && piratas.size()!=0)
				{
					tripulantes.at(i)->set_combate(true);
					tripulantes.at(i)->set_operador(false);
					tripulantes.at(i)->set_repara(false);
					aux = rand() % 2 + 1;//gera numero entre 1 e 2
					if (aux == 1)//atacar xenomorfos
					{
						//verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
						if (tripulantes.at(i)->get_arma() == true)
						{
							ataque += tripulantes.at(i)->get_forca_arma();
						}
						aux = rand() % (Xenomorfos.size());//escolhe qual o xenomorfos a atacar

						exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
						if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
						{
							ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
							Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos


							////string usada para a impressao na parte das accoes
							ss << "Tripulante " << tripulantes.at(i)->get_letra() << " atacou xenomorfo " << Xenomorfos.at(aux)->get_letra();
							accao = ss.str();
							accoes_trip.push_back(accao);
							ss.str(string());
						}


						//se o xenomorfos ja nao tiver vida, e removido do vector
						if (Xenomorfos.at(aux)->get_vida() <= 0)
						{
							////string usada para a impressao na parte das accoes
							ss << "Xenomorfo " << Xenomorfos.at(aux)->get_letra() << " foi destruido";
							accao = ss.str();
							accoes_trip.push_back(accao);
							Xenomorfos.erase(Xenomorfos.begin()+aux);
							ss.str(string());
						}

					}
					else//atacar pirata
					{
						//verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
						if (tripulantes.at(i)->get_arma() == true)
						{
							ataque += tripulantes.at(i)->get_forca_arma();
						}
						aux = rand() % (piratas.size());//escolhe qual o pirata a atacar
						piratas.at(aux)->reduz_vida(ataque);//ataca o pirata

						////string usada para a impressao na parte das accoes
						ss << "Tripulante " << tripulantes.at(i)->get_letra() << " atacou pirata " << piratas.at(aux)->get_letra();
						accao = ss.str();
						accoes_trip.push_back(accao);
						ss.str(string());
						

						//se o pirata ja nao tiver vida, e removido do vector
						if (piratas.at(aux)->get_vida() <= 0)
						{
							////string usada para a impressao na parte das accoes
							ss << "Pirata " << piratas.at(aux)->get_letra() << " foi destruido";
							accao = ss.str();
							accoes_trip.push_back(accao);
							ss.str(string());
							piratas.erase(piratas.begin() + aux);

							
						}
					}
				}

				//existe apena piratas para atacar
				else if (Xenomorfos.size() == 0 && piratas.size() != 0)
				{
					tripulantes.at(i)->set_combate(true);
					tripulantes.at(i)->set_operador(false);
					tripulantes.at(i)->set_repara(false);
				    //verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
					if (tripulantes.at(i)->get_arma() == true)
					{
						ataque += tripulantes.at(i)->get_forca_arma();
					}
					aux = rand() % (piratas.size());//escolhe qual o pirata a atacar
					piratas.at(aux)->reduz_vida(ataque);//ataca o pirata

					////string usada para a impressao na parte das accoes
					ss << "Tripulante " << tripulantes.at(i)->get_letra() << " atacou pirata " << piratas.at(aux)->get_letra();
					accao = ss.str();
					accoes_trip.push_back(accao);
					ss.str(string());
				
					//se o pirata ja nao tiver vida, e removido do vector
					if (piratas.at(aux)->get_vida() <= 0)
					{
						//
						////string usada para a impressao na parte das accoes
						ss << "Pirata " << piratas.at(aux)->get_letra() << " foi destruido";
						accao = ss.str();
						accoes_trip.push_back(accao);
						ss.str(string());
						piratas.erase(piratas.begin() + aux);
					}
				}

				//existe apena xenomorfos para atacar
				else if (Xenomorfos.size() != 0 && piratas.size() == 0)
				{
					tripulantes.at(i)->set_combate(true);
					tripulantes.at(i)->set_operador(false);
					tripulantes.at(i)->set_repara(false);
					//verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
					if (tripulantes.at(i)->get_arma() == true)
					{
						ataque += tripulantes.at(i)->get_forca_arma();
					}
					aux = rand() % (Xenomorfos.size());//escolhe qual o xenomorfos a atacar
					exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos

						////string usada para a impressao na parte das accoes
						ss << "Tripulante " << tripulantes.at(i)->get_letra() << " atacou xenomorfo " << Xenomorfos.at(aux)->get_letra();
						accao = ss.str();
						accoes_trip.push_back(accao);
						ss.str(string());
					}
					//se o xenomorfos ja nao tiver vida, e removido do vector
					if (Xenomorfos.at(aux)->get_vida() <= 0)
					{
						//
						////string usada para a impressao na parte das accoes
						ss << "Xenomorfo " << Xenomorfos.at(aux)->get_letra() << " foi destruido";
						accao = ss.str();
						accoes_trip.push_back(accao);
						ss.str(string());
						Xenomorfos.erase(Xenomorfos.begin() + aux);
					}
				}
				if (Xenomorfos.size() == 0 && piratas.size() == 0)
				{
					tripulantes.at(i)->set_combate(false);
					tripulantes.at(i)->set_operador(true);
					tripulantes.at(i)->set_repara(true);
				}
			}	
		}
}

//combate na sala onde o xenomorfo ataca
void Sala::combate_xenomorfos()
{
	int num_trip_sala, num_xenomorfos_sala, num_piratas_sala;
	int i;
	int ataque;
	int aux;
	int exoesqueleto;
	bool verifica = true;
	string accao;
	stringstream ss;

		//tripulante ataca
		for (i = 0; i < Xenomorfos.size(); i++)
		{
			ataque = Xenomorfos.at(i)->get_xenomorfo();//vai buscar a forca de ataque
			//apenas o que tem xenomorfo maior que 0 atacam
			if(ataque > 0)
			{
				//existe piratas e tripulantes para atacar
				if (tripulantes.size() != 0 && piratas.size() != 0)
				{
					Xenomorfos.at(i)->set_operador(false);
					Xenomorfos.at(i)->set_repara(false);
					Xenomorfos.at(i)->set_combate(true);
					aux = rand() % 2 + 1;
					if (aux == 1)//ataca tripulante
					{
						aux = rand() % (tripulantes.size());//escolhe qual o tripulante a atacar
						exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do tripulante
						if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
						{
							ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
							tripulantes.at(aux)->reduz_vida(ataque);//ataca o xenomorfos

							//string usada para a impressao na parte das accoes
							ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " atacou tripulante " << tripulantes.at(aux)->get_letra();
							accao = ss.str();
							accoes_xeno.push_back(accao);
							ss.str(string());
						}
						//se o tripulante ja nao tiver vida, e removido do vector
						if (tripulantes.at(aux)->get_vida() <= 0)
						{
							//string usada para a impressao na parte das accoes
							ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " foi destruido";
							accao = ss.str();
							accoes_xeno.push_back(accao);
							ss.str(string());
							tripulantes.erase(tripulantes.begin() + aux);
							
						}
					}
					else//atacar pirata
					{
					
						aux = rand() % (piratas.size());//escolhe qual o pirata a atacar
						piratas.at(aux)->reduz_vida(ataque);//ataca o pirata

						//string usada para a impressao na parte das accoes
						ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " atacou pirata " << piratas.at(aux)->get_letra();
						accao = ss.str();
						accoes_xeno.push_back(accao);
						ss.str(string());

						//se o pirata ja nao tiver vida, e removido do vector
						if (piratas.at(aux)->get_vida() <= 0)
						{
							//string usada para a impressao na parte das accoes
							ss << "Pirata " << piratas.at(aux)->get_letra() << " foi destruido";
							accao = ss.str();
							accoes_xeno.push_back(accao);
							ss.str(string());
							piratas.erase(piratas.begin() + aux);
							
						}
					}
				}

				//existe apena piratas para atacar
				else if (tripulantes.size() == 0 && piratas.size() != 0)
				{
					Xenomorfos.at(i)->set_operador(false);
					Xenomorfos.at(i)->set_repara(false);
					Xenomorfos.at(i)->set_combate(true);
					aux = rand() % (piratas.size());//escolhe qual o pirata a atacar
					piratas.at(aux)->reduz_vida(ataque);//ataca o pirata

					//string usada para a impressao na parte das accoes
					ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " atacou pirata " << piratas.at(aux)->get_letra();
					accao = ss.str();
					ss.str(string());
					accoes_xeno.push_back(accao);
					
					
					//se o pirata ja nao tiver vida, e removido do vector
					if (piratas.at(aux)->get_vida() <= 0)
					{
						//string usada para a impressao na parte das accoes
						ss << "Pirata " << piratas.at(aux)->get_letra() << " foi destruido";
						accao = ss.str();
						accoes_xeno.push_back(accao);
						ss.str(string());
						piratas.erase(piratas.begin() + aux);
						
					}
				}

				//existe apena tripulantes para atacar
				else if (tripulantes.size() != 0 && piratas.size() == 0)
				{
					Xenomorfos.at(i)->set_operador(false);
					Xenomorfos.at(i)->set_repara(false);
					Xenomorfos.at(i)->set_combate(true);
					aux = rand() % tripulantes.size();//escolhe qual o xenomorfos a atacar
					exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						tripulantes.at(aux)->reduz_vida(ataque);//ataca o xenomorfos

						//string usada para a impressao na parte das accoes
						ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " atacou tripulante " << tripulantes.at(aux)->get_letra();
						accao = ss.str();
						ss.str(string());
						accoes_xeno.push_back(accao);
					}
					//se o xenomorfos ja nao tiver vida, e removido do vector
					if (tripulantes.at(aux)->get_vida() <= 0)
					{
						//string usada para a impressao na parte das accoes
						ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " foi destruido";
						accao = ss.str();
						accoes_xeno.push_back(accao);
						ss.str(string());
						tripulantes.erase(tripulantes.begin() + aux);
						
						
					}
				}
			}

			//vai por o reparar e operar ativo caso ja nao estejam em contato
			if (tripulantes.size() == 0 && piratas.size() == 0)
			{
				Xenomorfos.at(i)->set_operador(true);
				Xenomorfos.at(i)->set_repara(true);
				Xenomorfos.at(i)->set_combate(false);
			}
		}	
}

//combate na sala onde o pirata ataca
void Sala::combate_piratas()
{
	int num_trip_sala, num_xenomorfos_sala, num_piratas_sala;
	int i;
	int ataque;
	int aux;
	int exoesqueleto;
	bool verifica = true;
	string accao;
	stringstream ss;

	for (i = 0; i < piratas.size(); i++)
	{
		//caso nao exista ninguem na sala o pirata ataca a sala
		if (tripulantes.size() == 0 && Xenomorfos.size() == 0)
		{
			ataque = piratas.at(i)->get_forca_combate_para_Sala();//vai buscar a forca de ataque para a atacar a sala
			integridade -= ataque;
			//string usada para a impressao na parte das accoes
			ss << "Pirata " << piratas.at(i)->get_letra() << " atacou sala " << numero;
			accao = ss.str();
			accoes_pir.push_back(accao);
			ss.str(string());
		}

		else
		{
			ataque = piratas.at(i)->get_forca_combate_para_Inimigo();//vai buscar a forca de ataque para atacar tripulante
			//existe tripulantes e xenomorfos para atacar
			if (tripulantes.size() != 0 && Xenomorfos.size() != 0)
			{
				piratas.at(i)->set_combate(true);
			
				aux = rand() % 2 + 1;
				if (aux == 1)//ataca tripulante
				{
					
					aux = rand() % (tripulantes.size());//escolhe qual o tripulante a atacar
					exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do tripulante
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						tripulantes.at(aux)->reduz_vida(ataque);//ataca o tripulante

						//string usada para a impressao na parte das accoes
						ss << "Pirata " << piratas.at(i)->get_letra() << " atacou tripulante " << tripulantes.at(aux)->get_letra();
						accao = ss.str();
						accoes_pir.push_back(accao);
						ss.str(string());
					}
					//se o tripulante ja nao tiver vida, e removido do vector
					if (tripulantes.at(aux)->get_vida() <= 0)
					{
						//string usada para a impressao na parte das accoes
						ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " foi destruido";
						accao = ss.str();
						accoes_pir.push_back(accao);
						ss.str(string());
						tripulantes.erase(tripulantes.begin() + aux);
					}
				}
				else//atacar xenomorfos
				{
					piratas.at(i)->set_combate(true);
					aux = rand() % (Xenomorfos.size());//escolhe qual o xenomorfo a atacar
					exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do xenomorfo
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos

					    //string usada para a impressao na parte das accoes
						ss << "Pirata " << piratas.at(i)->get_letra() << " atacou xenomorfo " << Xenomorfos.at(aux)->get_letra();
						accao = ss.str();
						accoes_pir.push_back(accao);
						ss.str(string());
					}
					//se o xenomorfo ja nao tiver vida, e removido do vector
					if (Xenomorfos.at(aux)->get_vida() <= 0)
					{
						//string usada para a impressao na parte das accoes
						ss << "Xenomorfo " << Xenomorfos.at(aux)->get_letra() << " foi destruido";
						accao = ss.str();
						accoes_pir.push_back(accao);
						ss.str(string());
						Xenomorfos.erase(Xenomorfos.begin() + aux);

					}
				}
			}

			//existe apena xenomorfos para atacar
			else if (tripulantes.size() == 0 && Xenomorfos.size() != 0)
			{
				piratas.at(i)->set_combate(true);
				aux = rand() % (Xenomorfos.size());//escolhe qual o xenomorfo a atacar
				exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
				if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do xenomorfo
				{
					ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
					Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos

					//string usada para a impressao na parte das accoes
					ss << "Pirata " << piratas.at(i)->get_letra() << " atacou xenomorfo " << Xenomorfos.at(aux)->get_letra();
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());
				}
				//se o xenomorfo ja nao tiver vida, e removido do vector
				if (Xenomorfos.at(aux)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Xenomorfo " << Xenomorfos.at(aux)->get_letra() << " foi destruido";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());
					Xenomorfos.erase(Xenomorfos.begin() + aux);
				}
			}

			//existe apena tripulantes para atacar
			else if (tripulantes.size() != 0 && Xenomorfos.size() == 0)
			{
				piratas.at(i)->set_combate(true);
				aux = rand() % (tripulantes.size());//escolhe qual o tripulante a atacar
				exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
				if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
				{
					ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
					tripulantes.at(aux)->reduz_vida(ataque);//ataca o tripulante

					//string usada para a impressao na parte das accoes
					ss << "Pirata " << piratas.at(i)->get_letra() << " atacou tripulante " << tripulantes.at(aux)->get_letra();
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());
					
				}
				//se o tripulante ja nao tiver vida, e removido do vector
				if (tripulantes.at(aux)->get_vida() <= 0)
				{
					//string usada para a impressao na parte das accoes
					ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " foi destruido";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());
					tripulantes.erase(tripulantes.begin() + aux);
				}
				
			}
			if (Xenomorfos.size() == 0 && tripulantes.size() == 0)
			{
				piratas.at(i)->set_combate(false);
			}
		}
	}
	
	
}





//verifica que a sala esta em fogo e se sim cada unidade perde vida
bool Sala::dano_fogo()
{
	int aux = 2; // dano do fogo para cada unidade
	int aux2;
	bool fogo_adj=false;
	string accao;
	stringstream ss;
	if (oxigenio == 0)
	{
		fogo = false;
	}

	if (fogo == true)
	{
		for (int i = 0; i < tripulantes.size(); i++)
		{
			tripulantes.at(i)->reduz_vida(aux);
			//string usada para a impressao na parte das accoes
			ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " perdeu vida pelo fogo";
			accao = ss.str();
			accoes_trip.push_back(accao);
			ss.str(string());

			if (tripulantes.at(i)->get_vida() <= 0)//verifica se o tripulante ainda tem vida
			{
				//string usada para a impressao na parte das accoes
				ss << "Tripulante " << tripulantes.at(i)->get_letra() << " foi destruido pelo fogo";
				accao = ss.str();
				accoes_trip.push_back(accao);
				ss.str(string());

				//elimina o tripulante do vector caso ele ja nao tenha vida 
				tripulantes.erase(tripulantes.begin() + i);
			}
			
		}

		for (int i = 0; i < piratas.size(); i++)
		{
			piratas.at(i)->reduz_vida(aux);
			//string usada para a impressao na parte das accoes
			ss << "Pirata " << piratas.at(aux)->get_letra() << " perdeu vida pelo fogo";
			accao = ss.str();
			accoes_pir.push_back(accao);
			ss.str(string());

			if (piratas.at(i)->get_vida() <= 0)//verifica se o tripulante ainda tem vida
			{
				//string usada para a impressao na parte das accoes
				ss << "Pirata " << piratas.at(i)->get_letra() << " foi destruido pelo fogo";
				accao = ss.str();
				accoes_pir.push_back(accao);
				ss.str(string());

				//elimina o pirata do vector caso ele ja nao tenha vida 
				piratas.erase(piratas.begin() + i);
			}
		}

		for (int i = 0; i < Xenomorfos.size(); i++)
		{
			Xenomorfos.at(i)->reduz_vida(aux);
			//string usada para a impressao na parte das accoes
			ss << "Xenomorfo " << Xenomorfos.at(aux)->get_letra() << " perdeu vida pelo fogo";
			accao = ss.str();
			accoes_xeno.push_back(accao);
			ss.str(string());

			if (Xenomorfos.at(i)->get_vida() <= 0)//verifica se o tripulante ainda tem vida
			{
				//string usada para a impressao na parte das accoes
				ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " foi destruido pelo fogo";
				accao = ss.str();
				accoes_xeno.push_back(accao);
				ss.str(string());
				//elimina o xenemorfo do vector caso ele ja nao tenha vida 
				Xenomorfos.erase(Xenomorfos.begin() + i);
			}
		}
		aux2= rand() % 2 + 1;
		if (aux == 1)//a sala recebe 10 de dano
		{
			integridade -= dano;
			if (integridade < 0)
			{
				integridade = 0;
			}
		}
		aux2 = rand() % 20 + 1;// 5% de as salas adjacentes pegaram fogo
		if (aux == 1)
		{
			fogo_adj = true;
		}
	}
	return fogo_adj;
}

//verifica que a sala esta em curto_circuito e se sim cada unidade perde vida
void Sala::dano_curto_circuito()
{
	int aux;
	int dano = 0;
	string accao;
	stringstream ss;
	if (curto_circuito == true)
	{
		aux = rand() % 4 + 1;
		//saiu a probabilidade de 25% logo todas as unidades vao receber dano
		if (aux == 1)
		{
			if (tripulantes.size() > 0)//verifica se exitem alguns tripulantes na sala
			{
				dano += tripulantes.size();//se sim o dano vai se igual a size do vector
			}
			if (piratas.size() > 0)//verifica se exitem alguns piratas na sala
			{
				dano += piratas.size();//se sim o dano vai se igual a size do vector
			}
			if (Xenomorfos.size() > 0)//verifica se exitem alguns xenomorfos na sala
			{
				dano += Xenomorfos.size();//se sim o dano vai se igual a size do vector
			}


			for (int i = 0; i < tripulantes.size(); i++)
			{
				tripulantes.at(i)->reduz_vida(dano);
				//string usada para a impressao na parte das accoes
				ss << "Tripulante " << tripulantes.at(aux)->get_letra() << " perdeu vida devido ao curto_circuito";
				accao = ss.str();
				accoes_trip.push_back(accao);
				ss.str(string());

				if (tripulantes.at(i)->get_vida() <= 0)//verifica se o tripulante ainda tem vida
				{
					//string usada para a impressao na parte das accoes
					ss << "Tripulante " << tripulantes.at(i)->get_letra() << " foi destruido pelo curto_circuito";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());

					//elimina o tripulante do vector caso ele ja nao tenha vida 
					tripulantes.erase(tripulantes.begin() + i);
				}
			}

			for (int i = 0; i < piratas.size(); i++)
			{
				piratas.at(i)->reduz_vida(dano);
				//string usada para a impressao na parte das accoes
				ss << "Pirata " << piratas.at(aux)->get_letra() << " perdeu vida devido ao curto_circuito";
				accao = ss.str();
				accoes_pir.push_back(accao);
				ss.str(string());

				if (piratas.at(i)->get_vida() <= 0)//verifica se o tripulante ainda tem vida
				{
					//string usada para a impressao na parte das accoes
					ss << "Pirata " << piratas.at(i)->get_letra() << " foi destruido pelo curto_circuito";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());

					//elimina o pirata do vector caso ele ja nao tenha vida 
					piratas.erase(piratas.begin() + i);
				}
			}

			for (int i = 0; i < Xenomorfos.size(); i++)
			{
				Xenomorfos.at(i)->reduz_vida(dano);
				//string usada para a impressao na parte das accoes
				ss << "Xenomorfo " << Xenomorfos.at(aux)->get_letra() << " perdeu vida devido ao curto_circuito";
				accao = ss.str();
				accoes_xeno.push_back(accao);
				ss.str(string());

				if (Xenomorfos.at(i)->get_vida() <= 0)//verifica se o tripulante ainda tem vida
				{
					//string usada para a impressao na parte das accoes
					ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " foi destruido pelo curto_circuito";
					accao = ss.str();
					accoes_pir.push_back(accao);
					ss.str(string());

					//elimina o pirata do vector caso ele ja nao tenha vida 
					Xenomorfos.erase(Xenomorfos.begin() + i);
				}
			}
		}
	}
	

}

//retorna string FG caso a sala esteja em fogo utilizada so para impressao
string Sala::get_problema_fogo()
{
	string aux="";
	if (fogo == true)
	{
		aux = "FG";
	}
	return aux;
}

//retorna string BR caso a sala tenha brecha utilizada so para impressao
string Sala::get_problema_brecha()
{
	string aux = "";
	if (brecha == true)
	{
		aux = "BR";
	}
	return aux;
}

//retorna string CC caso a sala tenha curto_circuito utilizada so para impressao
string Sala::get_problema_curto_circuito()
{
	string aux = "";
	if (curto_circuito == true)
	{
		aux = "CC";
	}
	return aux;
}




//funcao da sala de controlo de escudo que verifica se esta intacta, ou seja nao tem dano
bool Sala::controlo_escudo()
{
	bool verifica = true;
	if (integridade < 100)
	{
		verifica = false;
	}
	else
	{
		verifica = true;
	}
		
	return verifica;
}

//funcao da sala suporte de vida
void Sala::suporte_vida()
{
	if (oxigenio < 100)
	{
		oxigenio += 2;
	}

	if (oxigenio > 100)
	{
		oxigenio = 100;
	}
}

//funcao da sala sistema de seguranca interno
void Sala::sistema_seguranca_interno()
{
	int i;
	int sala;
	string accao;
	stringstream ss;
	for (i = 0; i < piratas.size(); i++)
	{
		if (piratas.at(i)->get_combate() == true)
		{
			piratas.at(i)->reduz_vida(1);

			//string usada para a impressao na parte das accoes
			ss << "Pirata " << piratas.at(i)->get_letra() << " atacado seguranca interno";
			accao = ss.str();
			accoes_pir.push_back(accao);
			ss.str(string());
		}

		

		if (piratas.at(i)->get_vida() <= 0)//verifica se o pirata ainda tem vida
		{
			//string usada para a impressao na parte das accoes
			ss << "Pirata " << piratas.at(i)->get_letra() << " destruido pelo seguranca interno";
			accao = ss.str();
			accoes_pir.push_back(accao);
			ss.str(string());
			//elimina o pirata do vector caso ele ja nao tenha vida 
			piratas.erase(piratas.begin() + i);
		}
			
			
	}
	for (i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_combate() == true)
		{
			Xenomorfos.at(i)->reduz_vida(1);

			//string usada para a impressao na parte das accoes
			ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " atacado seguranca interno";
			accao = ss.str();
			accoes_xeno.push_back(accao);
			ss.str(string());
		}
		if (Xenomorfos.at(i)->get_vida() <= 0)//verifica se o xenomorfo ainda tem vida
		{
			//string usada para a impressao na parte das accoes
			ss << "Xenomorfo " << Xenomorfos.at(i)->get_letra() << " destruido pelo seguranca interno";
			accao = ss.str();
			accoes_xeno.push_back(accao);
			ss.str(string());

			//elimina o xenomorfo do vector caso ele ja nao tenha vida 
			Xenomorfos.erase(Xenomorfos.begin() + i);
		}
   }
}

//funcao da sala de enfermaria
void Sala::enfermaria()
{
	if (integridade == 100)
	{
		if (tripulantes.size() > 0)
		{
			for (int i = 0; i < tripulantes.size(); i++)
			{
				tripulantes.at(i)->acrescenta_vida(1);
			}
		}	
	}
}

//funcao da sala de armas
void Sala::sala_armas()
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		tripulantes.at(i)->set_arma(true);
	}
}

//funcao da sala auto reparador
void Sala::auto_reparador()
{
	if (integridade < 100)
	{
		integridade += 5;

		if (integridade > 100)
		{
			integridade = 100;
		}

		if (integridade == 100)
		{
			brecha = false;
			fogo = false;
			curto_circuito = false;
		}
	}
}









void Sala::imprime_accoes_trip(int *y)
{
	int i;
	for (i = 0; i < accoes_trip.size(); i++)
	{
		c.gotoxy(120, *y);
		cout << accoes_trip.at(i) << endl;
		(*y)++;
	}


}

void Sala::imprime_accoes_xeno(int *y)
{

	for (int i = 0; i < accoes_xeno.size(); i++)
	{
		c.gotoxy(120, *y);
		cout << accoes_xeno.at(i) << endl;
		(*y)++;
	}
}

void Sala::imprime_accoes_pir(int *y)
{
	
	for (int i = 0; i < accoes_pir.size(); i++)
	{
		c.gotoxy(120, *y);
		cout << accoes_pir.at(i) << endl;
		(*y)++;
	}
	
}


//limpa o vetor das strings de accoes
void Sala::limpa_accoes()
{
	accoes_trip.clear();
	accoes_xeno.clear();
	accoes_pir.clear();
}

//vai buscar os dados de cada tripulante na sala e guarda no vetor para imprimir o dados
void Sala::get_info_trip()
{
	string info;
	stringstream ss;
	for (int i = 0; i < tripulantes.size(); i++)
	{

		ss << "Nome: " << tripulantes.at(i)->get_nome() << "   Letra: " << tripulantes.at(i)->get_letra() << "   Vida: " << tripulantes.at(i)->get_vida();
		info = ss.str();
		info_uni.push_back(info);

	}
}

//funcao que obtem os dados dos xenomorfos e guarda no vetor para imprimir o dados
void Sala::get_info_xeno()
{
	string info;
	stringstream ss;
	for (int i = 0; i < Xenomorfos.size(); i++)
	{

		ss << "Nome: " << Xenomorfos.at(i)->get_nome() << "   Letra: " << Xenomorfos.at(i)->get_letra() << "   Vida: " << Xenomorfos.at(i)->get_vida();
		info = ss.str();
		info_uni.push_back(info);

	}
}

//funcao que obtem os dados dos piratas e guarda no vetor para imprimir o dados
void  Sala::get_info_pir()
{
	string info;
	stringstream ss;
	for (int i = 0; i < piratas.size(); i++)
	{

		ss << "Nome: " << piratas.at(i)->get_nome() << "   Letra: " << piratas.at(i)->get_letra() << "   Vida: " << piratas.at(i)->get_vida();
		info = ss.str();
		info_uni.push_back(info);

	}
}

//imprime os dados das unidades do vetor info_uni
void Sala::imprime_info_unidades(int *y)
{
	int  i;
	for (i = 0; i < info_uni.size(); i++)
	{
		c.gotoxy(119, *y);
		cout << info_uni.at(i) << endl;
		(*y)++;
	}
	info_uni.clear();
}




void Sala::altera_valor_do_dano(int valor)
{
	this->dano += valor;

}