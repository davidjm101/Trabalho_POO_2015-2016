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


//adiciona um tripulante a sala
void Sala::set_tripulante()
{
	Tripulacao* trip = new Tripulacao();
	trip->set_nome("Membro Tripulacao");
	trip->set_vida(5);
	trip->set_respira(true);
	trip->set_operador(true);
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
	xen->set_misterioso(true);
	xen->set_mutatis_mutandis(0);
	xen->set_mover(50);
	xen->set_casulo(20);
	xen->set_exoesq(3);
	xen->set_repara(false);
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
	xen->set_mutatis_mutandis(0);
	xen->set_exoesq(1);
	xen->set_repara(false);
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
	xen->set_quanto_reparar(6);
	xen->set_mutatis_mutandis(0);
	xen->set_repara(true);
	xen->set_operador(true);
	xen->set_mover(15);
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
	xen->set_mover(30);
	xen->set_mutatis_mutandis(10);
	xen->set_respira(true);
	xen->set_repara(false);
	Xenomorfos.push_back(xen);
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

//verifica se o robot pode se mexer, caso a sala nao esteja em curto-circuito
bool Sala::verifica_robot_curto_circuito(char nome)
{
	bool verifica=true;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == nome)
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
bool Sala::verifica_tripulante_indeciso(char nome)
{
	bool verifica = false;
	for (int i = 0; i < tripulantes.size(); i++)
	{
		if (tripulantes.at(i)->get_letra() == nome)
		{
			verifica=tripulantes.at(i)->get_indeciso();
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



//move um pirata
void Sala::move_pirata()
{
	int aux;
	for (int i = 0; i < piratas.size(); i++)
	{
		aux = rand() % 7 + 1;
		if (aux == 1)
		{

		}
	}
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
				break;
			}
		}

		for (i = 0; i < Xenomorfos.size(); i++)
		{
			if (Xenomorfos.at(i)->get_repara() == true)
			{
				integridade += Xenomorfos.at(i)->get_quanto_reparar();
			}
			//verifica se a integridade passou dos 100 depois de reparar
			if (integridade > 100)
			{
				//repoem a 100, pois a integridade nao deve ser maior que 100 e para o ciclo
				integridade = 100;
				break;
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
			{
				tripulantes.at(i)->reduz_vida(1);
				//se o tripulante ja nao tiver vida entao e removido do vector
				if (tripulantes.at(i)->get_vida() <= 0)
				{
					tripulantes.erase(tripulantes.begin() + i);
				}
			}
				
		}
	}

	for (int i = 0; i < piratas.size(); i++)
	{
		if (piratas.at(i)->get_respira() == true)
		{
			if (oxigenio > 0)
				oxigenio = oxigenio - 1;
			else
			{
				piratas.at(i)->reduz_vida(1);
				//se o pirata ja nao tiver vida entao e removido do vector
				if (piratas.at(i)->get_vida() <= 0)
				{
					piratas.erase(piratas.begin() + i);
				}
			}
				
		}
	}

	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_respira() == true)
		{
			if (oxigenio > 0)
				oxigenio = oxigenio - 1;
			else
			{
				Xenomorfos.at(i)->reduz_vida(1);
				//se o xenomorfo ja nao tiver vida entao e removido do vector
				if (Xenomorfos.at(i)->get_vida() <= 0)
				{
					Xenomorfos.erase(Xenomorfos.begin() + i);
				}
			}
				
		}

		if (Xenomorfos.at(i)->get_flamejante() == true)  ///Instrução de verificação se o xenomorfo é flamejante
		{
			oxigenio = oxigenio - 5;	
		}

	}

}

// vai verificar as unidades que contenham toxicidade e retirar vidas aos outros que nao sao toxicos
void Sala::trata_caracteristica_toxico() 
{
	int valordetoxico;
	int i;

	for (i = 0; i < Xenomorfos.size(); i++)
	{
		valordetoxico = Xenomorfos.at(i)->get_toxico();
		
		if (valordetoxico > 0)
		{
			for (int j = 0; j < piratas.size(); j++)
			{
				piratas.at(j)->reduz_vida(valordetoxico);
				//se o pirata ja nao tiver vida entao e removido do vector
				if (piratas.at(j)->get_vida() <= 0)
				{
					piratas.erase(piratas.begin() + j);
				}
			}

			for (int z = 0; z < tripulantes.size(); z++)
			{
				tripulantes.at(z)->reduz_vida(valordetoxico);
				//se o tripulante ja nao tiver vida entao e removido do vector
				if (tripulantes.at(z)->get_vida() <= 0)
				{
					tripulantes.erase(tripulantes.begin() + z);
				}
			}
		}
	}
}

//vai verificar se a unidade se regenera, se sim entao regenera vida
void Sala::trata_caracteristica_regenerador()
{
	int regenera;
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		regenera = Xenomorfos.at(i)->get_regenerador();
		if (regenera>0)
		{
			Xenomorfos.at(i)->acrescenta_vida(regenera);
		}
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
			aux = rand() % 10 + 1;
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
	int num_trip;
	for (int i = 0; i < Xenomorfos.size(); i++)
	{
		if (Xenomorfos.at(i)->get_hipnotizador()>0)
		{
			aux = rand() % 7 + 1;
			if (aux == 1)
			{
				num_trip = tripulantes.size();
				aux= rand() % num_trip;
				tripulantes.at(aux)->set_indeciso(true);
			}
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


void Sala::get_info_tripulante()
{
	for (int i = 0; i < tripulantes.size(); i++)
	{
		tripulantes.at(i)->get_info();
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

//combate dentro de uma sala onde o tripulante ataca
void Sala::combate_tripulante()
{
	int num_trip_sala, num_xenomorfos_sala, num_piratas_sala;
	int i;
	int ataque;
	int aux;
	int exoesqueleto;
	bool verifica = true;

	num_trip_sala = tripulantes.size();
	num_xenomorfos_sala = Xenomorfos.size();
	num_piratas_sala = piratas.size();
	
	if (num_trip_sala != 0)
	{
		for (i = 0; i < tripulantes.size(); i++)
		{
			//indica que o tripulante nao pode nem operar nem reparar
			tripulantes.at(i)->set_combate(true);
			tripulantes.at(i)->set_operador(false);
			tripulantes.at(i)->set_repara(false);

			verifica = true;
			//vai verificar se o tripulante e robot
			if (tripulantes.at(i)->get_nome() == "Robot - X34 - ZT2")
			{
				//se for robot, ve se a sala esta em curto circuito
				if (curto_circuito == true)
				{
					//se tiver o robot nao pode atacar
					verifica = false;
				}
			}
			//este verifica e por causa do robot
			if (verifica == true)
			{
				ataque = tripulantes.at(i)->get_forca_combate();//vai buscar a forca de ataque 
				

				//existe piratas e xenomorfos para atacar
				if (num_xenomorfos_sala != 0 && num_piratas_sala != 0)
				{
					aux = rand() % 2 + 1;
					if (aux == 1)//atacar xenomorfos
					{
						//verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
						if (tripulantes.at(i)->get_arma() == true)
						{
							ataque += tripulantes.at(i)->get_forca_arma();
						}
						aux = rand() % (num_xenomorfos_sala - 1);//escolhe qual o xenomorfos a atacar
						exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
						if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
						{
							ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
							Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
						}
						//se o xenomorfos ja nao tiver vida, e removido do vector
						if (Xenomorfos.at(aux)->get_vida() <= 0)
						{
							Xenomorfos.erase(Xenomorfos.begin()+aux);
						}
					}
					else//atacar pirata
					{
						//verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
						if (tripulantes.at(i)->get_arma() == true)
						{
							ataque += tripulantes.at(i)->get_forca_arma();
						}
						aux = rand() % (num_piratas_sala - 1);//escolhe qual o pirata a atacar
						piratas.at(aux)->reduz_vida(ataque);//ataca o pirata	
						//se o pirata ja nao tiver vida, e removido do vector
						if (piratas.at(aux)->get_vida() <= 0)
						{
							piratas.erase(piratas.begin() + aux);
						}
					}
				}

				//existe apena piratas para atacar
				else if (num_xenomorfos_sala == 0 && num_piratas_sala != 0)
				{
				    //verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
					if (tripulantes.at(i)->get_arma() == true)
					{
						ataque += tripulantes.at(i)->get_forca_arma();
					}
					aux = rand() % (num_piratas_sala - 1);//escolhe qual o pirata a atacar
					piratas.at(aux)->reduz_vida(ataque);//ataca o pirata
					//se o pirata ja nao tiver vida, e removido do vector
					if (piratas.at(aux)->get_vida() <= 0)
					{
						piratas.erase(piratas.begin() + aux);
					}
				}

				//existe apena xenomorfos para atacar
				else if (num_xenomorfos_sala != 0 && num_piratas_sala == 0)
				{
					//verifica se o tripulante tem arma, e se tiver vai buscar a forca ataque da arma
					if (tripulantes.at(i)->get_arma() == true)
					{
						ataque += tripulantes.at(i)->get_forca_arma();
					}
					aux = rand() % (num_xenomorfos_sala - 1);//escolhe qual o xenomorfos a atacar
					exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
					}
					//se o xenomorfos ja nao tiver vida, e removido do vector
					if (Xenomorfos.at(aux)->get_vida() <= 0)
					{
						Xenomorfos.erase(Xenomorfos.begin() + aux);
					}
				}

				num_xenomorfos_sala = Xenomorfos.size();
				num_piratas_sala = piratas.size();
				if (num_xenomorfos_sala == 0 && num_piratas_sala == 0)
				{
					tripulantes.at(i)->set_combate(false);
					tripulantes.at(i)->set_operador(true);
					tripulantes.at(i)->set_repara(true);
				}
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

	num_trip_sala = tripulantes.size();
	num_xenomorfos_sala = Xenomorfos.size();
	num_piratas_sala = piratas.size();

	if (num_xenomorfos_sala != 0)
	{
		//tripulante ataca
		for (i = 0; i < Xenomorfos.size(); i++)
		{
			//vain indicar que o xenomorfos estao em combate e nao podem nem reparar nem operar
			Xenomorfos.at(i)->set_operador(false);
			Xenomorfos.at(i)->set_repara(false);

			ataque = Xenomorfos.at(i)->get_xenomorfo();//vai buscar a forca de ataque
			//apenas o que tem xenomorfo maior que 0 atacam
			if(ataque > 0)
			{
				//existe piratas e tripulantes para atacar
				if (num_trip_sala != 0 && num_piratas_sala != 0)
				{
					aux = rand() % 2 + 1;
					if (aux == 1)//ataca tripulante
					{
						aux = rand() % (num_trip_sala - 1);//escolhe qual o tripulante a atacar
						exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do tripulante
						if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
						{
							ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
							tripulantes.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
						}
						//se o tripulante ja nao tiver vida, e removido do vector
						if (tripulantes.at(aux)->get_vida() <= 0)
						{
							tripulantes.erase(tripulantes.begin() + aux);
						}
					}
					else//atacar pirata
					{
						aux = rand() % (num_piratas_sala - 1);//escolhe qual o pirata a atacar
						piratas.at(aux)->reduz_vida(ataque);//ataca o pirata	
															//se o pirata ja nao tiver vida, e removido do vector
						if (piratas.at(aux)->get_vida() <= 0)
						{
							piratas.erase(piratas.begin() + aux);
						}
					}
				}

				//existe apena piratas para atacar
				else if (num_trip_sala == 0 && num_piratas_sala != 0)
				{

					aux = rand() % (num_piratas_sala - 1);//escolhe qual o pirata a atacar
					piratas.at(aux)->reduz_vida(ataque);//ataca o pirata
														//se o pirata ja nao tiver vida, e removido do vector
					if (piratas.at(aux)->get_vida() <= 0)
					{
						piratas.erase(piratas.begin() + aux);
					}
				}

				//existe apena tripulantes para atacar
				else if (num_xenomorfos_sala != 0 && num_piratas_sala == 0)
				{
					aux = rand() % (num_xenomorfos_sala - 1);//escolhe qual o xenomorfos a atacar
					exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						tripulantes.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
					}
					//se o xenomorfos ja nao tiver vida, e removido do vector
					if (tripulantes.at(aux)->get_vida() <= 0)
					{
						tripulantes.erase(tripulantes.begin() + aux);
					}
				}
			}

			//vai por o reparar e operar ativo caso ja nao estejam em contato
			num_trip_sala = tripulantes.size();
			num_piratas_sala = piratas.size();
			if (num_trip_sala == 0 && num_piratas_sala == 0)
			{
				Xenomorfos.at(i)->set_operador(false);
				Xenomorfos.at(i)->set_repara(false);
			}
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

	num_trip_sala = tripulantes.size();
	num_xenomorfos_sala = Xenomorfos.size();
	num_piratas_sala = piratas.size();

	
	if (num_piratas_sala != 0)
	{
		for (i = 0; i < piratas.size(); i++)
		{
			//caso nao exista ninguem na sala o pirata ataca a sala
			if (num_trip_sala == 0 && num_xenomorfos_sala == 0)
			{
				ataque = piratas.at(i)->get_forca_combate_para_Sala();//vai buscar a forca de ataque para a atacar a sala
				integridade -= ataque;
			}

			ataque = piratas.at(i)->get_forca_combate_para_Inimigo();//vai buscar a forca de ataque para atacar tripulante

			//existe tripulantes e xenomorfos para atacar
			if (num_trip_sala != 0 && num_xenomorfos_sala != 0)
			{
				aux = rand() % 2 + 1;
				if (aux == 1)//ataca tripulante
				{
					aux = rand() % (num_trip_sala - 1);//escolhe qual o tripulante a atacar
					exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do tripulante
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						tripulantes.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
					}
					//se o tripulante ja nao tiver vida, e removido do vector
					if (tripulantes.at(aux)->get_vida() <= 0)
					{
						tripulantes.erase(tripulantes.begin() + aux);
					}
				}
				else//atacar xenomorfos
				{
					aux = rand() % (num_xenomorfos_sala - 1);//escolhe qual o xenomorfo a atacar
					exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
					if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do xenomorfo
					{
						ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
						Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
					}
					//se o xenomorfo ja nao tiver vida, e removido do vector
					if (Xenomorfos.at(aux)->get_vida() <= 0)
					{
						Xenomorfos.erase(Xenomorfos.begin() + aux);
					}
				}
			}

			//existe apena xenomorfos para atacar
			else if (num_trip_sala == 0 && num_xenomorfos_sala != 0)
			{

				aux = rand() % (num_xenomorfos_sala - 1);//escolhe qual o xenomorfo a atacar
				exoesqueleto = Xenomorfos.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
				if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do xenomorfo
				{
					ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
					Xenomorfos.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
				}
				//se o xenomorfo ja nao tiver vida, e removido do vector
				if (Xenomorfos.at(aux)->get_vida() <= 0)
				{
					Xenomorfos.erase(Xenomorfos.begin() + aux);
				}
			}

			//existe apena tripulantes para atacar
			else if (num_trip_sala != 0 && num_xenomorfos_sala == 0)
			{
				aux = rand() % (num_trip_sala - 1);//escolhe qual o xenomorfos a atacar
				exoesqueleto = tripulantes.at(aux)->get_exoesq();//vai buscar o numero de exoesqueleto do xenomorfo
				if (exoesqueleto != ataque)//se o exoesqueleto for diferente da forca de ataque do pirata
				{
					ataque -= exoesqueleto; //remove ao ataque o valor do exoesqueleto
					tripulantes.at(aux)->reduz_vida(ataque);//ataca o xenomorfos
				}
				//se o xenomorfos ja nao tiver vida, e removido do vector
				if (tripulantes.at(aux)->get_vida() <= 0)
				{
					tripulantes.erase(tripulantes.begin() + aux);
				}
			}
		}
	}
	
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


//funcao da sala de controlo de escudo
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
}

//funcao da sala sistema de seguranca interno
void Sala::sistema_seguranca_interno()
{
	int i;
	int sala;
	if (integridade == 100)
	{
		for (i = 0; i < piratas.size(); i++)
		{
			//falta verificar o parte de set combate
			piratas.at(i)->reduz_vida(1);
		}
	}
}

//funcao da sala de enfermaria
void Sala::enfermaria()
{
	if (integridade == 100)
	{
		for (int i = 0; i < tripulantes.size(); i++)
		{
			tripulantes.at(i)->acrescenta_vida(1);
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
	}
}






void Sala::altera_valor_do_dano(int valor)
{
	this->dano += valor;

}