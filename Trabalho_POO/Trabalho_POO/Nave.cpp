#include "Nave.h"
#include "Desenho.h"



Nave::Nave()
{
	milhas = 0;
	escudo = 100;
}

Nave::~Nave()
{

}

void Nave::set_escudo(int escudo)
{
	this->escudo = escudo;
}

//cria a sala obrigatorias
void Nave::set_salas_normais()
{
	
	int aux = 1;	
	salas.push_back(new Sala("Propulsor",aux));
	aux = 5;
	salas.push_back(new Sala("Sala_Maquinas", aux));
	aux++;
	salas.push_back(new Sala("Suporte_Vida", aux));
	aux++;
	salas.push_back(new Sala("Controlo_Escudo", aux));
	aux++;
	salas.push_back(new Sala("Ponte", aux));
	aux++;
	salas.push_back(new Sala("Propulsor", aux));

	
	
}


//cria sala opcionais
void Nave::set_salas_opcionais()
{
	int contador=1;
	int numero_sala = 2;
	int aux = 0;
	int sala;
	bool alojamento_cap = false;// como so pode existir um sala destas
	bool oficina_rob = false;// como so pode existir um sala destas

	do
	{
		do {
			system("cls");
			cout << "1:Propulsor Adicional" << endl;
			cout << "2:Beliche" << endl;
			cout << "3:Raio laser" << endl;
			cout << "4:Auto reparador" << endl;
			cout << "5:Sistema de seguranca interno" << endl;
			cout << "6:Enfermaria" << endl;
			cout << "7:Sala de Armas" << endl;
			cout << "8:Alojamento do Capitao" << endl;
			cout << "9:Oficina robotica" << endl;
			cout << "Indique a sala que pretende juntar a nave: ";
			cin >> sala;
		} while (sala < 1 || sala > 9);
		
		if (numero_sala == 5)
		{
			numero_sala = 10;
		}
		
		if (sala == 1)
		{
			salas.push_back(new Sala("Propulsor",numero_sala));
			cout << "Propulsor adicionado a nave" <<endl;
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 2)
		{
			salas.push_back(new Sala("Beliche", numero_sala));
			cout << "Beliche adicionado a nave" << endl;
			contador++;
			numero_sala++;
			aux++;
			system("PAUSE");
		}

		else if (sala == 3)
		{
			salas.push_back(new Sala("Raio_Laser", numero_sala));
			cout << "Raio laser adicionado a nave" << endl;
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 4)
		{
			salas.push_back(new Sala("Auto_Reparador", numero_sala));
			cout << "Auto reparador adicionado a nave" << endl;
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 5)
		{
			salas.push_back(new Sala("Sist_Seg_Interno", numero_sala));
			cout << "Sistema de seguranca interno adicionado a nave" << endl;
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 6)
		{
			salas.push_back(new Sala("Enfermaria", numero_sala));
			cout << "Enfermaria adicionado a nave" << endl;
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 7)
		{
			salas.push_back(new Sala("Sala_Armas", numero_sala));
			cout << "Sala de Armas adicionado a nave" << endl;
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 8)
		{
			if (alojamento_cap == false)
			{
				salas.push_back(new Sala("Aloj_Capitao", numero_sala));
				cout << "Alojamento do Capitao adicionado a nave" << endl;
				contador++;
				numero_sala++;
				alojamento_cap = true;
				system("PAUSE");
			}
			else
			{
				cout << "Ja possui um alojamento do capitao na nave" << endl;
				cout << "Nao pode adicionar outro alojamento do capitao a nave" << endl;
				system("PAUSE");
			}
			
		}

		else if (sala == 9)
		{
			if (oficina_rob == false)
			{

				salas.push_back(new Sala("Oficina_Robotica", numero_sala));
				cout << "Oficina robotica adicionado a nave" << endl;
				contador++;
				numero_sala++;
				oficina_rob = true;
				system("PAUSE");
			}
			else
			{
				cout << "Ja possui uma oficina robotica na nave" << endl;
				cout << "Nao pode adicionar outra oficina robotica a nave" << endl;
				system("PAUSE");
			}

		}
		
	} while (contador <=6);

}


//adiciona os tripulantes as salas
void Nave::adiciona_tripulantes()
{
	int i;
	int conta=0;

	for (i = 0; i < salas.size(); i++)//adiciona o tripulantes as sala Propulsor e Ponte
	{
		if (salas.at(i)->get_nome() == "Propulsor" || salas.at(i)->get_nome() == "Ponte")
		{
			salas.at(i)->set_tripulante();
		}
	}

	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_nome() == "Aloj_Capitao")
		{
			salas.at(i)->set_capitao();
			conta++;
		}
		if (salas.at(i)->get_nome() == "Oficina_Robotica")
		{
			salas.at(i)->set_robot();
			conta++;
		}
		if (salas.at(i)->get_nome() == "Beliche")
		{
			salas.at(i)->set_tripulante();
		}
	}


	
}


int Nave::get_escudo()
{
	return escudo;
}

int Nave::get_milhas()
{
	return milhas;
}


//mover membro da tripulacao
void Nave::mover_membro_tripulacao(char nome, int numero)
{

	Tripulacao* t = new Tripulacao();
	bool verifica = false;
	bool robot_move;
	bool indeciso;
	int i;
	int aux;
	//verifica se a sala indicada existe
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_numero() == numero)
		{
			verifica = true;
			break;
		}
	}

	
	if (verifica == true)
	{
		for (i = 0; i < salas.size(); i++)
		{
			    //verifica que existe o tripulante indicado
				verifica = salas.at(i)->verifica_tripulante(nome);
				if (verifica == true)
				{
					//verifica se caso for robot se ele se pode mover
					robot_move = salas.at(i)->verifica_robot_curto_circuito(nome);
					if(robot_move ==true)
					{
						//vai verificar se o tripulante este indeciso
						indeciso = salas.at(i)->verifica_tripulante_indeciso(nome);
						if (indeciso == true)
						{
							aux= rand() % 2 + 1;//vai ver se o tripulante se move com uma probabilidade de 50%
							if (aux == 1)//vai mover
							{
								indeciso = false;
							}
						}
						//se retornar false, quer dizer que nao esta e entao move-se
						if (indeciso == false)
						{
							t = salas.at(i)->obtem_tripulante(nome);
							verifica = true;
							break;
						}
					}	
				}
		}
	}

	//move o tripulante caso ele exista
	if (verifica == true)
	{
		for (i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_numero() == numero)
			{
				salas.at(i)->inser_tripulante(t);
				break;
			}
		}
	}

	else
	{
		cout << "Sala ou Tripulante nao existe" << endl;
		system("PAUSE");
	}
}


//mover pirata
void Nave::mover_pirata()
{
	vector<Pirata*> piratas;
	int i,j;
	int aux;
	int sala;
	
	for (i = 0; i < salas.size(); i++)
	{
		
		salas.at(i)->move_pirata(piratas);
		if (piratas.size() > 0)
		{
			for (j = 0; j < piratas.size(); j++)
			{
				sala = salas.at(i)->get_numero();
				switch (sala)
				{
				case 1:
					aux = aux = rand() % 2 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 2);//move para a sala com o numero 2
					}
					else
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					piratas.clear();
					break;

				case 2:
					aux = aux = rand() % 4 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 1);//move para a sala com o numero 1
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 3);//move para a sala com o numero 3
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					piratas.clear();
					break;

				case 3:
					aux = aux = rand() % 5 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 2);//move para a sala com o numero 1
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 4);//move para a sala com o numero 4
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					else if (aux == 5)
					{
						inser_pirata_nova_sala(piratas.at(j), 7);//move para a sala com o numero 7
					}
					piratas.clear();
					break;

				case 4:
					aux = aux = rand() % 4 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 3);//move para a sala com o numero 3
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 7);//move para a sala com o numero 7
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 8);//move para a sala com o numero 8
					}
					piratas.clear();
					break;

				case 5:
					aux = aux = rand() % 7 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 1);//move para a sala com o numero 1
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 2);//move para a sala com o numero 2
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 3);//move para a sala com o numero 3
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 5)
					{
						inser_pirata_nova_sala(piratas.at(j), 9);//move para a sala com o numero 9
					}
					else if (aux == 6)
					{
						inser_pirata_nova_sala(piratas.at(j), 10);//move para a sala com o numero 10
					}
					else if (aux == 7)
					{
						inser_pirata_nova_sala(piratas.at(j), 11);//move para a sala com o numero 11
					}
					piratas.clear();
					break;

				case 6:
					aux = aux = rand() % 8 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 2);//move para a sala com o numero 1
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 3);//move para a sala com o numero 3
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 4);//move para a sala com o numero 4
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 5)
					{
						inser_pirata_nova_sala(piratas.at(j), 7);//move para a sala com o numero 7
					}
					else if (aux == 6)
					{
						inser_pirata_nova_sala(piratas.at(j), 10);//move para a sala com o numero 10
					}
					else if (aux == 7)
					{
						inser_pirata_nova_sala(piratas.at(j), 11);//move para a sala com o numero 11
					}
					else if (aux == 8)
					{
						inser_pirata_nova_sala(piratas.at(j), 12);//move para a sala com o numero 12
					}
					piratas.clear();
					break;

				case 7:
					aux = aux = rand() % 6 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 3);//move para a sala com o numero 3
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 4);//move para a sala com o numero 4
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 8);//move para a sala com o numero 8
					}
					else if (aux == 5)
					{
						inser_pirata_nova_sala(piratas.at(j), 11);//move para a sala com o numero 11
					}
					else if (aux == 6)
					{
						inser_pirata_nova_sala(piratas.at(j), 12);//move para a sala com o numero 12
					}
					piratas.clear();
					break;

				case 8:
					aux = aux = rand() % 3 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 4);//move para a sala com o numero 4
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 7);//move para a sala com o numero 7
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 12);//move para a sala com o numero 12
					}
					piratas.clear();
					break;

				case 9:
					aux = aux = rand() % 2 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 10);//move para a sala com o numero 10
					}
					piratas.clear();
					break;

				case 10:
					aux = aux = rand() % 4 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 9);//move para a sala com o numero 9
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 11);//move para a sala com o numero 11
					}
					piratas.clear();
					break;

				case 11:
					aux = aux = rand() % 5 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 5);//move para a sala com o numero 5
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 7);//move para a sala com o numero 7
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 10);//move para a sala com o numero 10
					}
					else if (aux == 5)
					{
						inser_pirata_nova_sala(piratas.at(j), 12);//move para a sala com o numero 12
					}
					piratas.clear();
					break;

				case 12:
					aux = aux = rand() % 4 + 1;
					if (aux == 1)
					{
						inser_pirata_nova_sala(piratas.at(j), 6);//move para a sala com o numero 6
					}
					else if (aux == 2)
					{
						inser_pirata_nova_sala(piratas.at(j), 7);//move para a sala com o numero 7
					}
					else if (aux == 3)
					{
						inser_pirata_nova_sala(piratas.at(j), 8);//move para a sala com o numero 8
					}
					else if (aux == 4)
					{
						inser_pirata_nova_sala(piratas.at(j), 11);//move para a sala com o numero 11
					}
					piratas.clear();
					break;

				default:
					break;
				}
			}
		}
		
	}
}
//vai inserir o pirata numa nova sala
void Nave::inser_pirata_nova_sala(Pirata* p, int sala)
{
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_numero() == sala)
		{ 
			salas.at(i)->inser_pirata(p);
			break;
		}
	}
}



//mover nave
void Nave::mover_nave()
{
	int i;
	string nome;
	int integridade = 0, propulsao = 0;
	bool verifica = false;
	//verifica se a "ponte" esta a ser operada
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_nome() == "Ponte")
		{
			verifica = salas.at(i)->verifica_sala_operada();
		}
	}

	if (verifica == true)
	{	//verifica se a sala das maquinas nao tem dano
		for (i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_nome() == "Sala_Maquinas")
			{
				integridade = salas.at(i)->get_integridade();
			}
		}
	}

	if (integridade == 100)
	{
		//vai ver quantos "prupulsores" existem e obtem o poder de propulsao de cada um
		for (i = 0; i < salas.size(); i++)
		{
			/*nome = salas.at(i)->get_nome();*/
			if (salas.at(i)->get_nome() == "Propulsor" && salas.at(i)->verifica_sala_operada() == true)
			{
				propulsao += salas.at(i)->get_integridade();
			}
		}
		milhas += propulsao;
	}
}


//reparar as salas da nave
void Nave::reparar_nave()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->reparar_sala();
	}
}


//verifica se existe alguma sala que esteja destruida
bool Nave::get_sala_destruida()
{
	bool destruido = false;
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_integridade() <= 0)
		{
			destruido = true;
		}
	}
	return destruido;
}

//verifica se ainda existe tripulantes na sala
bool Nave::verifica_existe_tripulantes()
{
	int num=0;
	bool verifica=true;
	for (int i = 0; i < salas.size(); i++)
	{
		num+=salas.at(i)->get_num_tripulantes();
	}
	if (num == 0)
	{
		verifica = false;
	}
	return verifica;
}


//imprime os dados das sala
void Nave::imprime_dados_sala()
{
	
	int aux=1, x, y;
	Consola c;

	do {
		switch (aux)
		{
		case 1:
			x = 3;
			y = 3;
			break;

		case 2:
			x = 23;
			y = 3;
			break;

		case 3:
			x = 43;
			y = 3;
			break;

		case 4:
			x = 63;
			y = 3;
			break;

		case 5:
			x = 23;
			y = 12;
			break;

		case 6:
			x = 43;
			y = 12;
			break;

		case 7:
			x = 63;
			y = 12;
			break;

		case 8:
			x = 83;
			y = 12;
			break;

		case 9:
			x = 3;
			y = 21;
			break;

		case 10:
			x = 23;
			y = 21;
			break;

		case 11:
			x = 43;
			y = 21;
			break;

		case 12:
			x = 63;
			y = 21;
			break;
		}

		for (int i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_numero() == aux)
			{
				c.gotoxy(x, y);
				cout << aux << ":" << salas.at(i)->get_nome() << endl;
				c.gotoxy(x, y + 1);
				cout << "Integ: " << salas.at(i)->get_integridade() << endl;
				c.gotoxy(x, y + 2);
				cout << "Oxig: " << salas.at(i)->get_oxigenio() << endl;
				c.gotoxy(x, y + 3);
				cout << "Prob: " << salas.at(i)->get_problema_fogo() << " " << salas.at(i)->get_problema_brecha() << " " << salas.at(i)->get_problema_curto_circuito();
				c.gotoxy(x, y + 4);
				cout << "Trip: ";
				salas.at(i)->get_letra_tripulantes();
				c.gotoxy(x, y + 5);
				cout << "Xeno: ";
				salas.at(i)->get_letra_xenomorfos();
				c.gotoxy(x, y + 6);
				cout << "Pirat:";
				salas.at(i)->get_letra_piratas();
				cout << endl;
				break;
			}
		}
		aux++;
	} while (aux <= 12);
}





//vai verificar se existe algum elemento nas salas que precise de respirar
void Nave::sala_verifica_respirar()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->trata_caracteristica_unidade_respira();		
	}
}

//vai verifica se existe algum elemto mutanti mutantis e se vai se mudar a sala
void Nave::trata_efeito_mutanti_mutantis()
{
	bool verifica=false;
	int aux;
	for (int i = 0; i < salas.size(); i++)
	{
		verifica = salas.at(i)->trata_caracteristica_mutatis_mutantis();
		if (verifica == true)
		{
			aux = rand() % 9 + 1;
			switch (aux)
			{
				case 1:
					salas.at(i)->set_nome("Propulsor");
					break;
				case 2:
					salas.at(i)->set_nome("Beliche");
					break;
				case 3:
					salas.at(i)->set_nome("Raio_Laser");
					break;
				case 4:
					salas.at(i)->set_nome("Auto_Reparador");
					break;
				case 5:
					salas.at(i)->set_nome("Sist_Seg_Interno");
					break;
				case 6:
					salas.at(i)->set_nome("Enfermaria");
					break;
				case 7:
					salas.at(i)->set_nome("Sala_Armas");
					break;
				case 8:
					salas.at(i)->set_nome("Aloj_Capitao");
					break;
				case 9:
					salas.at(i)->set_nome("Oficina_Robotica");
					break;
				default:
					break;
			}
		}
	}
}

//verifica se existe algum elemento toxixo e se vai dar dano ao outros
void Nave::trata_efeito_toxicidade()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->trata_caracteristica_toxico();
	}
}

//verifica se existe algum elemento que se regenera e vai regenar vida caso exista
void Nave::trata_efeito_regenerador()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->trata_caracteristica_regenerador();
	}
}

//verifica se existe algum flamejante na sala e se sim vai tirar oxigenio a sala
void Nave::trata_efeito_flamejante()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->trata_caracteristica_flamajenta();
	}
	
}




//verifica se a ponte esta a ser operada por algum tripulante
bool Nave::verifica_ponte_operada() 
{
	bool verifica = false;
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_nome() == "Ponte") 
		{
			verifica=salas.at(i)->verifica_sala_operada();
		}
	}
	return verifica;
}


//nave atravessa uma nuvem de meteoritos
void Nave::atravessa_chuva_meteoritos(int dano, int num)
{
	bool verifica = false;
	int aux;
	int conta = 0,i;
	//verifica se a nave tem raio laser, e se tiver se esta a ser operado
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_nome() == "Raio_Laser")
		{
			verifica = salas.at(i)->verifica_sala_operada();
			break;
		}
	}
	
		srand(time(NULL));
		aux = rand() % 2 + 1;
		if ((aux == 1 && verifica==false) || (aux == 2 && verifica == false))//raio laser nao destroi os meteoritos
		{
			if (escudo > 0)
			{
				escudo -= (dano*num);
				c.gotoxy(85, 19);
				cout << "A nave atravessou chuva meteoritos" << endl;
				c.gotoxy(85, 20);
				cout << "o escudo da nave sofreu dano" << endl;
				system("PAUSE");
			}
			else
			{
				do {
					aux = rand() % 12 + 1;
					for (i = 0; i < salas.size(); i++)
					{
						if (salas.at(i)->get_numero() == aux)
						{
							salas.at(i)->atingida_meteorito(dano);
							conta++;
						}
					}
				} while (conta != num);
				c.gotoxy(85, 19);
				cout << "A nave atravessou chuva meteoritos" << endl;
				c.gotoxy(85, 20);
				cout << "varia salas sofreram dano" << endl;
				c.gotoxy(85, 21);
				cout << "e se encontram com brechas" << endl;
				system("PAUSE");
			}
			
		}
		else
		{
			c.gotoxy(85, 19);
			cout << "A nave atravessou chuva meteoritos" << endl;
			c.gotoxy(85, 20);
			cout << "o raio laser destrui!!!" << endl;
			c.gotoxy(85, 21);
			cout << "todos os meteoritos." << endl;
			system("PAUSE");
		}
	
}


//nave foi atacada por piratas
void Nave::ataque_pirata(int dano, int num)
{
	int dano_excesso;
	bool verifica=false;
	int i,aux;

	//verifica se a nave ainda tem escudo
	if (escudo > 0)
	{
		if ((escudo - dano) > 0)
		{
			escudo -= dano;
		}
		else
		{
			dano_excesso = dano - escudo;
			escudo = 0;
			srand(time(NULL));
			aux = rand() % 12 + 1;
			for (i = 0; i < salas.size(); i++)
			{
				if (salas.at(i)->get_numero() == aux)
				{
					salas.at(i)->atacada_piratas(dano_excesso);
					break;
				}
			}
		}
	}
	// a nave ja nao tem escudo
	else
	{
		srand(time(NULL));
		aux = rand() % 12 + 1;
		for (i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_numero() == aux)
			{
				salas.at(i)->atacada_piratas(dano);
				break;
			}
		}
	}

	//verifica que o raio laser esta operacional
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_nome() == "Raio_Laser")
		{
			verifica = salas.at(i)->verifica_sala_operada();
			break;
		}
	}
	//caso nao esteja uma sala e invadida por piratas
	if (verifica == false)
	{
		srand(time(NULL));
		aux = rand() % 12 + 1;
		for (i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_numero()==aux)
			{
				salas.at(i)->invadida_piratas(num);
				break;
			}
		}
		c.gotoxy(85, 19);
		cout << "A nave foi atacada por piratas," << endl;
		c.gotoxy(85, 20);
		cout << "recebeu dano," << endl;
		c.gotoxy(85, 21);
		cout << "a nave foi invadida" << endl;
		system("PAUSE");
	}
	else
	{
		c.gotoxy(85, 19);
		cout << "A nave foi atacada por piratas," << endl;
		c.gotoxy(85, 20);
		cout << "os piratas foram afugentados," << endl;
		c.gotoxy(85, 21);
		cout << "a nave nao foi invadida" << endl;
		system("PAUSE");
	}
}

//nave invadida por xenomorfos
void Nave::invadida_xenomorfos()
{
	int aux;
	aux = rand() % 12 + 1;// gera numero ente 1 e 12
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_numero() == aux)
		{
			salas.at(i)->invadida_xenomorfos();
			break;
		}
	}
	c.gotoxy(85, 19);
	cout << "A nave foi atacada por" << endl;
	c.gotoxy(85, 20);
	cout << "xenomorfos, uma das salas!!!" << endl;
	c.gotoxy(85, 21);
	cout << "foi invadida." << endl;
}

//nave atravessa po cosmico
void Nave::atravessa_po_cosmico(int dano)
{
	int aux,aux2;

	
	aux = rand() % 3 + 3;//gera numero aleatorio entre 3 e 5
	do
	{
		aux2 = rand() % 12 + 1;;//gera numero aleatorio entre 1 e 12
		for (int i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_numero() == aux2)
			{
				salas.at(i)->atingida_po_cosmico(dano);
				break;
			}
		}

		aux--;
	} while (aux>0);

	c.gotoxy(85, 19);
	cout << "A nave atravessou campo" << endl;
	c.gotoxy(85, 20);
	cout << "de po cosmico, varia salas!!!" << endl;
	c.gotoxy(85, 21);
	cout << "receberam dano." << endl;
	system("PAUSE");
}

//verifica se alguma sala esta em fogo e se estiver provoca o dano
void Nave::dano_sala_fogo()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->dano_fogo();
	}
}

//verifica se alguma sala tem curto_circuito e se estiver provoca o dano
void Nave::dano_sala_curto_circuito()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->dano_curto_circuito();
	}
}




//accoes dos xenomorfos no fim do turno, bem como o ataque
void Nave::accoes_xenomorfos()
{
	

	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->trata_caracteristica_hipnotizador();
		salas.at(i)->combate_xenomorfos();
	}
}

//accoes dos piratas no fim do turno
void Nave::accoes_piratas()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->combate_piratas();
	}
}

//accoes dos piratas no fim do turno
void Nave::accoes_tripulantes()
{
	
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->combate_tripulante();
	}
	
	//for (int i = 0; i < salas.size(); i++)
	//{
	//	salas.at(i)->reparar_sala();
	//}
}

//acontecimentos relativos as salas da nave
void Nave::accoes_salas()
{
	int i,j;
	int num_sala,aux;

	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_nome() == "Controlo_Escudo" && salas.at(i)->get_integridade() == 100)
		{
			//verifica se a sala nao tem dano, se retornar falso é porque tem dano
			if (salas.at(i)->controlo_escudo() == false && escudo_activado == true)
			{
				escudo_desativado = escudo;
				escudo = 0;
				escudo_activado = false;
			}
			else if (salas.at(i)->controlo_escudo() == true && escudo_activado == false)
			{
					escudo = escudo_desativado;
					escudo_activado = true;	
			}	
		}
		
		//se for a sala de sistema de segurança interno
		if (salas.at(i)->get_nome() == "Sist_Seg_Interno")
		{
			//vai ver se tem alguem inimigo na sala e vai atacar caso estajam
			salas.at(i)->sistema_seguranca_interno();
			
			//vai fazer o mesmo as salas adjacentes
			num_sala = salas.at(i)->get_numero();
			switch (num_sala)
			{
			
				case 2:
					for (j = 0; j < salas.size(); j++)
					{
						aux = salas.at(j)->get_numero();
						if (aux == 1 || aux == 3 || aux == 5 || aux == 6)
						{
							salas.at(j)->sistema_seguranca_interno();
						}
					}
					break;
				case 3:
					for (j = 0; j < salas.size(); j++)
					{
						aux = salas.at(j)->get_numero();
						if (aux == 2 || aux == 4 || aux == 5 || aux == 6 || aux == 7)
						{
							salas.at(j)->sistema_seguranca_interno();
						}
					}
					break;
				case 4:
					for (j = 0; j < salas.size(); j++)
					{
						aux = salas.at(j)->get_numero();
						if (aux == 3 || aux == 6 || aux == 7 || aux == 8)
						{
							salas.at(j)->sistema_seguranca_interno();
						}
					}
					break;
				case 10:
					for (j = 0; j < salas.size(); j++)
					{
						aux = salas.at(j)->get_numero();
						if (aux == 5 || aux == 6 || aux == 9 || aux == 11)
						{
							salas.at(j)->sistema_seguranca_interno();
						}
					}
					break;
				case 11:
					for (j = 0; j < salas.size(); j++)
					{
						aux = salas.at(j)->get_numero();
						if (aux == 5 || aux == 6 || aux == 7 || aux == 10 || aux == 12)
						{
							salas.at(j)->sistema_seguranca_interno();
						}
					}
					break;
				case 12:
					for (j = 0; j < salas.size(); j++)
					{
						aux = salas.at(j)->get_numero();
						if (aux == 6 || aux == 7 || aux == 8 || aux == 11)
						{
							salas.at(j)->sistema_seguranca_interno();
						}
					}
					break;
				default:
					break;

			}
		}

		//se for a sala de suporte de vida
		if (salas.at(i)->get_nome() == "Suporte_Vida" && salas.at(i)->get_integridade()==100)
		{
			for (j = 0; j < salas.size(); j++)
			{
				salas.at(j)->suporte_vida();
			}
		}

		//se for a sala enfermaria
		if (salas.at(i)->get_nome() == "Enfermaria" && salas.at(i)->get_integridade() == 100)
		{
				salas.at(i)->enfermaria();
		}

		// se for a sala de armas
		if (salas.at(i)->get_nome() == "Sala_Armas")
		{
			salas.at(i)->sala_armas();
		}

		//se for a sala auto reparador
		if (salas.at(i)->get_nome() == "Auto_Reparador" && salas.at(i)->get_integridade() == 100)
		{
			num_sala = salas.at(i)->get_numero();
			switch (num_sala)
			{

			case 2:
				for (j = 0; j < salas.size(); j++)
				{
					aux = salas.at(j)->get_numero();
					if (aux == 1 || aux == 3 || aux == 5 || aux == 6)
					{
						salas.at(j)->auto_reparador();
					}
				}
				break;
			case 3:
				for (j = 0; j < salas.size(); j++)
				{
					aux = salas.at(j)->get_numero();
					if (aux == 2 || aux == 4 || aux == 5 || aux == 6 || aux == 7)
					{
						salas.at(j)->auto_reparador();
					}
				}
				break;
			case 4:
				for (j = 0; j < salas.size(); j++)
				{
					aux = salas.at(j)->get_numero();
					if (aux == 3 || aux == 6 || aux == 7 || aux == 8)
					{
						salas.at(j)->auto_reparador();
					}
				}
				break;
			case 10:
				for (j = 0; j < salas.size(); j++)
				{
					aux = salas.at(j)->get_numero();
					if (aux == 5 || aux == 6 || aux == 9 || aux == 11)
					{
						salas.at(j)->auto_reparador();
					}
				}
				break;
			case 11:
				for (j = 0; j < salas.size(); j++)
				{
					aux = salas.at(j)->get_numero();
					if (aux == 5 || aux == 6 || aux == 7 || aux == 10 || aux == 12)
					{
						salas.at(j)->auto_reparador();
					}
				}
				break;
			case 12:
				for (j = 0; j < salas.size(); j++)
				{
					aux = salas.at(j)->get_numero();
					if (aux == 6 || aux == 7 || aux == 8 || aux == 11)
					{
						salas.at(j)->auto_reparador();
					}
				}
				break;
			default:
				break;

			}
		}
	}
}



//imprime as accoes em cada sala
void Nave::imprime_accoes_salas()
{

	int y = 19;
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->imprime_accoes_xeno(&y);
	}

	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->imprime_accoes_pir(&y);
	}

	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->imprime_accoes_trip(&y);
	}
}

//limpa os vector das string de accoes em cada sala
void Nave::limpa_accoes_salas()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->limpa_accoes();
	}
}




//imprime os dados dos tripulantes
void Nave::imprime_info_trip()
{
	int y = 3;
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->get_info_trip();
		salas.at(i)->imprime_info_unidades(&y);
	}
}

//imprime os dados dos xenomorfos
void Nave::imprime_info_xeno()
{
	int y = 3;
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->get_info_xeno();
		salas.at(i)->imprime_info_unidades(&y);
	}
}

//mprime os dados dos piratas
void Nave::imprime_info_pir()
{
	int y = 3;
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i)->get_info_pir();
		salas.at(i)->imprime_info_unidades(&y);
	}
}