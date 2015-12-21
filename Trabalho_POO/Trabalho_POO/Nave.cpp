#include "Nave.h"


Nave::Nave()
{

}

Nave::~Nave()
{

}

void Nave::set_salas_normais()
{
	Sala s1("Propulsor");
	Sala s5("Sala de maquinas");
	Sala s6("Suporte de vida");
	Sala s7("Controlo de escudo");
	Sala s8("Ponte");
	Sala s9("Propulsor");

	salas.push_back(s1);
	salas.push_back(s5);
	salas.push_back(s6);
	salas.push_back(s7);
	salas.push_back(s8);
	salas.push_back(s9);

	

	/*for (unsigned int i = 0; i < salas.size(); i++)
	{
		cout << salas.at(i).get_nome() << endl;
	}*/
}

void Nave::set_salas_opcionais()
{
	int contador=1;
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
		
		
		if (sala == 1)
		{
			Sala s1("Propulsor");
			cout << "Propulsor adicionado a nave";
			salas.push_back(s1);
			contador++;
			system("PAUSE");
		}

		else if (sala == 2)
		{
			Sala s2("Beliche");
			cout << "Beliche adicionado a nave";
			salas.push_back(s2);
			contador++;
			system("PAUSE");
		}

		else if (sala == 3)
		{
			Sala s3("Raio laser");
			cout << "Raio laser adicionado a nave";
			salas.push_back(s3);
			contador++;
			system("PAUSE");
		}

		else if (sala == 4)
		{
			Sala s4("Auto reparador");
			cout << "Auto reparador adicionado a nave";
			salas.push_back(s4);
			contador++;
			system("PAUSE");
		}

		else if (sala == 5)
		{
			Sala s5("Sistema de seguranca interno");
			cout << "Sistema de seguranca interno adicionado a nave";
			salas.push_back(s5);
			contador++;
			system("PAUSE");
		}

		else if (sala == 6)
		{
			Sala s6("Enfermaria");
			cout << "Enfermaria adicionado a nave";
			salas.push_back(s6);
			contador++;
			system("PAUSE");
		}

		else if (sala == 7)
		{
			Sala s7("Sala de Armas");
			cout << "Sala de Armas adicionado a nave";
			salas.push_back(s7);
			contador++;
			system("PAUSE");
		}

		else if (sala == 8)
		{
			if (alojamento_cap == false)
			{
				Sala s8("Alojamento do Capitao");
				cout << "Alojamento do Capitao adicionado a nave";
				salas.push_back(s8);
				contador++;
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
				Sala s9("Oficina Robotica");
				cout << "Oficina robotica adicionado a nave";
				salas.push_back(s9);
				contador++;
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

	system("cls");
	cout << "Salas addicionadas" << endl;
	cout << "A nave possui as seguintes salas:" << endl;
	for (unsigned int i = 0; i < salas.size(); i++)
	{
		cout <<"- " << salas.at(i).get_nome() << endl;
	}
}