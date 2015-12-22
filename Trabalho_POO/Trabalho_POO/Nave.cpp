#include "Nave.h"



Nave::Nave()
{

}

Nave::~Nave()
{

}

void Nave::set_salas_normais()
{
	Tripulacao trip1;
	Tripulacao trip2;
	Tripulacao trip3;

	Sala s1("Propulsor",1);
	Sala s2("Sala de maquinas",5);
	Sala s3("Suporte de vida",6);
	Sala s4("Controlo de escudo",7);
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

	

	/*for (unsigned int i = 0; i < salas.size(); i++)
	{
		cout << salas.at(i).get_nome() << endl;
	}*/
}


void Nave::set_tripulantes(Tripulacao *trip)// adiciona os tres primeiro tripulantes no inicio do jogo
{
	
	trip->set_vida(5);
	trip->set_respira(true);
	trip->set_operador(true);
	trip->set_reparador(1);
	trip->set_combate(1);
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
			Sala s3("Raio laser", numero_sala);
			cout << "Raio laser adicionado a nave" << endl;
			salas.push_back(s3);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 4)
		{
			Sala s4("Auto reparador", numero_sala);
			cout << "Auto reparador adicionado a nave" << endl;
			salas.push_back(s4);
			contador++;
			numero_sala++;
			system("PAUSE");
		}

		else if (sala == 5)
		{
			Sala s5("Sistema de seguranca interno", numero_sala);
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
			Sala s7("Sala de Armas", numero_sala);
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
				Sala s8("Alojamento do Capitao", numero_sala);
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
				Sala s9("Oficina Robotica", numero_sala);
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

void Nave::le_comando()
{
	string comando;
	char nome;
	int numero;
	cout << "Indique o comando: ";
	cin >> comando;
	nome = comando[0];
	numero = comando[1] - '0';
	mover_membro_tripulacao(nome,numero);
}

void Nave::mover_membro_tripulacao(char nome, int numero)
{
	
	Tripulacao t;
	bool verifica = false;
	int i;
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
			verifica = salas.at(i).verifica_tripulante(nome);
			if (verifica == true)
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


void Nave::get_info_salas()
{
	system("cls");
	int aux = 1;
	do {
		for (int i = 0; i < salas.size(); i++)
		{
			if (salas.at(i).get_numero() == aux)
			{
				cout << salas.at(i).get_nome() << "   Numero:" << salas.at(i).get_numero();
				cout << "   Integridade:" << salas.at(i).get_saude() << endl;
				salas.at(i).get_info_tripulantes();
				cout << endl;
				break;
			}
		}
		aux++;
	} while (aux <= 12);
	

}