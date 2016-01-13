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
	int i;
	//verifica se a sala indicada existe
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i)->get_numero() == numero)
		{
			verifica = true;
			break;
		}
	}

	//verifica que existe o tripulante indicado
	if (verifica == true)
	{
		for (i = 0; i < salas.size(); i++)
		{
			verifica = salas.at(i)->verifica_tripulante(nome);
			if (verifica == true)
			{
				t = salas.at(i)->obtem_tripulante(nome);
				break;
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
		if (salas.at(i)->get_numero() == 8)
		{
			verifica = salas.at(i)->verifica_sala_operada();
		}
	}

	if (verifica == true)
	{	//verifica se a sala das maquinas nao tem dano
		for (i = 0; i < salas.size(); i++)
		{
			if (salas.at(i)->get_numero() == 5)
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
			nome = salas.at(i)->get_nome();
			if (nome == "Propulsor" && salas.at(i)->verifica_sala_operada() == true)
			{
				propulsao += salas.at(i)->get_integridade();
			}
		}
		milhas += propulsao;
	}
}


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


//imprime os dados das sala e das unidades
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
			y = 11;
			break;

		case 6:
			x = 43;
			y = 11;
			break;

		case 7:
			x = 63;
			y = 11;
			break;

		case 8:
			x = 83;
			y = 11;
			break;

		case 9:
			x = 3;
			y = 19;
			break;

		case 10:
			x = 23;
			y = 19;
			break;

		case 11:
			x = 43;
			y = 19;
			break;

		case 12:
			x = 63;
			y = 19;
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
				cout << "Prob: CC BR FG";
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


void Nave::imprime_dado_tripulante(char letra)
{
	for (int i=0; i < salas.size(); i++)
	{
		salas.at(i)->get_info_tripulante(letra);
	}
}

//void Nave::sala_verifica_respirar()//vai verificar se existe algum elemento na sala que precise de respirar
//{
//	for (int i = 0; i < salas.size(); i++)
//	{
//
//	}
//}


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

	srand(time(NULL));
	aux = rand() % 12 + 1;
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
	system("PAUSE");
}

//nave atravessa po cosmico
void Nave::atravessa_po_cosmico(int dano)
{
	int aux,aux2;

	srand(time(NULL));
	aux = rand() % 5 + 3;
	do
	{
		aux2 = rand() % 12 + 1;
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