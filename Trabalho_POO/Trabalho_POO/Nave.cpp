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

void Nave::set_salas_normais()
{
	Tripulacao trip1;
	Tripulacao trip2;
	Tripulacao trip3;

	Sala s1("Propulsor",1);
	Sala s2("Sala_Maquinas",5);
	Sala s3("Suporte_Vida",6);
	Sala s4("Controlo_Escudo",7);
	Sala s5("Ponte",8);
	Sala s6("Propulsor",9);

	set_tripulantes(&trip1);
	s1.set_tripulante(trip1);

	set_tripulantes(&trip2);
	s5.set_tripulante(trip2);

	set_tripulantes(&trip3);
	s6.set_tripulante(trip3);


	salas.push_back(s1);
	salas.push_back(s2);
	salas.push_back(s3);
	salas.push_back(s4);
	salas.push_back(s5);
	salas.push_back(s6);
}


void Nave::set_tripulantes(Tripulacao *trip)// adiciona os tres primeiro tripulantes no inicio do jogo
{
	
	trip->set_nome("Membro Tripulacao");
	trip->set_vida(5);
	trip->set_respira(true);
	trip->set_operador(true);
	trip->set_reparador(1);
	trip->set_forca_combate(1);
	trip->set_combate(false);
}

void Nave::set_salas_opcionais()
{
	Tripulacao trip[6];
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
			Sala s1("Propulsor",numero_sala);
			cout << "Propulsor adicionado a nave" <<endl;
			salas.push_back(s1);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 2)
		{
			Sala s2("Beliche", numero_sala);
			cout << "Beliche adicionado a nave" << endl;
			set_tripulantes(&trip[aux]);
			s2.set_tripulante(trip[aux]);
			salas.push_back(s2);
			contador++;
			numero_sala++;
			aux++;
			system("PAUSE");
		}

		else if (sala == 3)
		{
			Sala s3("Raio_Laser", numero_sala);
			cout << "Raio laser adicionado a nave" << endl;
			salas.push_back(s3);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 4)
		{
			Sala s4("Auto_Reparador", numero_sala);
			cout << "Auto reparador adicionado a nave" << endl;
			salas.push_back(s4);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 5)
		{
			Sala s5("Sist_Seg_Interno", numero_sala);
			cout << "Sistema de seguranca interno adicionado a nave" << endl;
			salas.push_back(s5);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 6)
		{
			Sala s6("Enfermaria", numero_sala);
			cout << "Enfermaria adicionado a nave" << endl;
			salas.push_back(s6);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 7)
		{
			Sala s7("Sala_Armas", numero_sala);
			cout << "Sala de Armas adicionado a nave" << endl;
			salas.push_back(s7);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 8)
		{
			if (alojamento_cap == false)
			{
				Sala s8("Aloj_Capitao", numero_sala);
				cout << "Alojamento do Capitao adicionado a nave" << endl;
				salas.push_back(s8);
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
				Sala s9("Oficina_Robotica", numero_sala);
				cout << "Oficina robotica adicionado a nave" << endl;
				salas.push_back(s9);
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


void Nave::modificar_tripulantes(int tipo, Tripulacao *trip)
{
	if (tipo == 1)
	{
		trip->set_vida(6);
		trip->set_respira(true);
		trip->set_operador(true);
		trip->set_reparador(1);
		trip->set_combate(2);
		trip->set_exoesq(1);
	}
	else if (tipo == 2)
	{
		trip->set_vida(8);
		trip->set_combate(3);
		trip->set_exoesq(2);
	}
}


void Nave::mover_membro_tripulacao(char nome, int numero)
{
	
	Tripulacao t;
	bool verifica = false;
	int i;
	//verifica se a sala indicada existe
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i).get_numero() == numero)
		{
			verifica = true;
			break;
		}
	}

	if (verifica == true)
	{
		verifica = false;
		
		for (i = 0; i < salas.size(); i++)
		{
			//verifica em que sala existe um tripulante com este nome
			verifica = salas.at(i).verifica_tripulante(nome);
			if ( verifica == true)
			{
				for (int j = 0; j < salas.size(); j++)
				{
					if (salas.at(j).get_numero() == numero)
					{

						salas.at(j).set_tripulante(salas.at(i).get_tripulantes(nome));
						break;
					}
				}
				break;
			}
		}
		if (verifica == false)
		{
			cout << "Tripualante " << nome << " nao existe" << endl;
			system("PAUSE");
		}
	}
	
	else
	{
		cout << "Sala numero: " << numero << " nao existe" << endl;
		system("PAUSE");
	}
	
	
	
	


}

void Nave::mover_nave()
{
	int i;
	string nome;
	int integridade,propulsao=0;
	bool verifica = false;
	//verifica se a "ponte" esta a ser operada
	for (i = 0; i < salas.size(); i++)
	{
		if (salas.at(i).get_numero() == 8)
		{
			verifica = salas.at(i).verifica_sala_operada();
		}
	}

	if (verifica == true)
	{	//verifica se a sala das maquinas nao tem dano
		for (i = 0; i < salas.size(); i++)
		{
			if (salas.at(i).get_numero() == 5)
			{
				integridade = salas.at(i).get_integridade();
			}
		}
	}

	if (integridade == 100)
	{
		//vai ver quantos "prupulsores" existem e obtem o poder de propulsao de cada um
		for (i = 0; i < salas.size(); i++)
		{
			nome = salas.at(i).get_nome();
			if (nome=="Propulsor" && salas.at(i).verifica_sala_operada()==true)
			{
				propulsao += salas.at(i).get_integridade();
			}
		}
		milhas += propulsao;
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

void Nave::reparar_nave()
{
	for (int i = 0; i < salas.size(); i++)
	{
		salas.at(i).reparar_sala();
	}
}



void Nave::dano_po_cosmico(int sala, int dano)
{
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i).get_numero() == sala)
		{
			salas.at(i).set_dano(dano);
		}
	}
}

bool Nave::get_sala_destruida()
{
	bool destruido = false;
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i).get_integridade() <= 0)
		{
			destruido = true;
		}
	}
	return destruido;
}

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
			if (salas.at(i).get_numero() == aux)
			{
				c.gotoxy(x, y);
				cout << aux << ":" << salas.at(i).get_nome() << endl;
				c.gotoxy(x, y + 1);
				cout << "Integ: " << salas.at(i).get_integridade() << endl;
				c.gotoxy(x, y + 2);
				cout << "Oxig: " << salas.at(i).get_oxigenio() << endl;
				c.gotoxy(x, y + 3);
				cout << "Trip: ";
				salas.at(i).get_info_tripulantes();
				c.gotoxy(x, y + 4);
				cout << "Xeno: " << endl;
				c.gotoxy(x, y + 5);
				cout << "Pirat:" << endl;
				cout << endl;
				break;
			}
		}
		aux++;


	} while (aux <= 12);
}

//void Nave::sala_verifica_respirar()//vai verificar se existe algum elemento na sala que precise de respirar
//{
//	for (int i = 0; i < salas.size(); i++)
//	{
//
//	}
//}

bool Nave::verifica_ponte_operada()//verifica se a ponte esta a ser operada por algum tripulante
{
	bool verifica = false;
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i).get_nome == "Ponte")
		{
			verifica=salas.at(i).verifica_sala_operada();
		}
	}
	return verifica;
}

void Nave::atravessa_chuva_meteoritos(int dano, int num)
{
	bool verifica = false;
	int aux;
	int conta = 0;
	for (int i = 0; i < salas.size(); i++)
	{
		if (salas.at(i).get_nome == "Raio_Laser")
		{
			verifica = salas.at(i).verifica_sala_operada();
			break;
		}
	}
	if (verifica == true)
	{
		srand(time(NULL));
		aux = rand() % 2 + 1;
		if (aux == 1)//raio laser nao destroi os meteoritos
		{
			if (escudo > 0)
			{
				escudo -= (dano*num);
			}
			else
			{
				do {
					aux = rand() % 12 + 1;
					
				} while (conta != num);
			}
		}
	}
}