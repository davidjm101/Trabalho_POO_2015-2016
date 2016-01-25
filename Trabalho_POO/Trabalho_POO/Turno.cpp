#include "Turno.h"
#include "Po_Cosmico.h"

Turno::Turno()
{
	turno = 1;
	conta_turno_eventos = 0;
	nave = new Nave();
	Ataque_Piratas* ata_pirata = new Ataque_Piratas();
	evento.push_back(ata_pirata);
	Ataque_Xenomorfo* ata_xeno = new Ataque_Xenomorfo();
	evento.push_back(ata_xeno);
	Chuva_Meteorito* chuva_meteorito = new Chuva_Meteorito();
	evento.push_back(chuva_meteorito);
	Po_Cosmico* po_cosmico = new Po_Cosmico();
	evento.push_back(po_cosmico);

}

Turno::~Turno()
{
}

void Turno::inicio_jogo()
{
	

	c.gotoxy(92, 8);
	cout << turno;
	nave->set_salas_normais();
	nave->set_salas_opcionais();
	nave->adiciona_tripulantes();

}

void Turno::inicio_turno()
{
	c.setScreenSize(168, 400);
	nave->dano_sala_fogo();
	nave->trata_efeito_toxicidade();
	nave->trata_efeito_regenerador();
	nave->trata_efeito_flamejante();
	nave->sala_verifica_respirar();
	nave->mover_pirata();
	nave->mover_xenomorfo();

	
	desenho.desenha_nave();
	desenho.desenha_info();
	desenho.desenha_info_nave();
	desenho.desenha_info_unidades();
	desenho.desenha_accoes();
	desenho.desenha_comando();
	nave->imprime_dados_sala();
	nave->imprime_accoes_eventos();
	nave->imprime_accoes_salas();
	nave->limpa_accoes_salas();
	c.gotoxy(104, 4);
	cout << nave->get_milhas();
	c.gotoxy(92, 6);
	cout << nave->get_escudo();
	c.gotoxy(92, 8);
	cout << turno;

}


void Turno::fase_ordem()
{
	
	string comando;
	
	string token;
	string token1;
	string aux;
	char nome;
	int num;
	
	do
	{
		

		c.gotoxy(22, 31);
		getline(cin, comando);
		stringstream stream(comando);
		stream >> token >> token1;

		if (token == "info")
		{
			
			if (token1 == "trip")
			{
				desenho.desenha_nave();
				desenho.desenha_info();
				desenho.desenha_info_nave();
				desenho.desenha_info_unidades();
				desenho.desenha_accoes();
				desenho.desenha_comando();
				c.gotoxy(104, 4);
				cout << nave->get_milhas();
				c.gotoxy(92, 6);
				cout << nave->get_escudo();
				c.gotoxy(92, 8);
				cout << turno;
				nave->imprime_dados_sala();


				nave->imprime_info_trip();	
				
			}
			if (token1 == "xeno")
			{
				desenho.desenha_nave();
				desenho.desenha_info();
				desenho.desenha_info_nave();
				desenho.desenha_info_unidades();
				desenho.desenha_accoes();
				desenho.desenha_comando();
				c.gotoxy(104, 4);
				cout << nave->get_milhas();
				c.gotoxy(92, 6);
				cout << nave->get_escudo();
				c.gotoxy(92, 8);
				cout << turno;
				nave->imprime_dados_sala();

				nave->imprime_info_xeno();
				
			}
			if (token1 == "pir")
			{
				desenho.desenha_nave();
				desenho.desenha_info();
				desenho.desenha_info_nave();
				desenho.desenha_info_unidades();
				desenho.desenha_accoes();
				desenho.desenha_comando();
				c.gotoxy(104, 4);
				cout << nave->get_milhas();
				c.gotoxy(92, 6);
				cout << nave->get_escudo();
				c.gotoxy(92, 8);
				cout << turno;
				nave->imprime_dados_sala();

				nave->imprime_info_pir();
				
			}
		}
		else if (token == "move")
		{
			
			aux = token1.substr(0, 1);
			nome = aux[0];
			aux = token1.substr(1, token1.size());
			num = stoi(aux);
			nave->mover_membro_tripulacao(nome, num);

			desenho.desenha_nave();
			desenho.desenha_info();
			desenho.desenha_info_nave();
			desenho.desenha_info_unidades();
			desenho.desenha_accoes();
			desenho.desenha_comando();
			nave->imprime_dados_sala();
		}
		else
		{
			desenho.desenha_nave();
			desenho.desenha_info();
			desenho.desenha_info_nave();
			desenho.desenha_info_unidades();
			desenho.desenha_accoes();
			desenho.desenha_comando();
			nave->imprime_dados_sala();
		}
	} while (token != "next");
}

void Turno::final_turno()
{
	nave->dano_sala_curto_circuito();
	nave->accoes_salas();
	nave->trata_efeito_mutanti_mutantis();
	nave->accoes_xenomorfos();
	nave->accoes_piratas();
	nave->accoes_tripulantes();
	nave->mover_nave();
	
}

void Turno::eventos()
{
	
	int aux;
	srand(time(NULL));
	if (turno == 1)
	{
		aux = rand() % 4;
		evento.at(aux)->accao(nave);	
	}
	conta_turno_eventos++;
	if (conta_turno_eventos == 5)
	{
		aux = rand() % 4;
		evento.at(aux)->accao(nave);
		conta_turno_eventos = 0;
	}
	turno++;

}




bool Turno::acabou_jogo()
{
	bool aux = false;
	bool destruido = false;
	if (nave->get_milhas() >= (4000 + 1000) || nave->get_sala_destruida()==true || nave->verifica_existe_tripulantes()==false)
	{
		aux = true;
	}

	return aux;
}

void Turno::imprime_acabou_jogo()
{
	system("cls");
	c.setScreenSize(25, 100);
	c.setTextColor(c.VERMELHO);
	c.gotoxy(20,2);
	cout << " _____                  _____             " << endl;
	c.gotoxy(20, 3);
	cout << "|   __|___ _____ ___   |     |_ _ ___ ___ " << endl;
	c.gotoxy(20, 4);
	cout << "|  |  | .'|     | -_|  |  |  | | | -_|  _|" << endl;
	c.gotoxy(20, 5);
	cout << "|_____|__,|_|_|_|___|  |_____| \_/|___|_|  " << endl;
	
	c.setTextColor(c.BRANCO);
	if (nave->get_milhas() >= (4000 + 1000))
	{
		c.gotoxy(30, 7);
		cout << "O jogo acabou";
		c.gotoxy(30, 8);
		cout << "Atingui a milhas necessarias!!";
	}
	else if (nave->get_sala_destruida() == true)
	{
		c.gotoxy(30, 7);
		cout << "O jogo acabou";
		c.gotoxy(30, 8);
		cout << "Uma das salas foi destruida!!";
	}
	else if (nave->verifica_existe_tripulantes() == false)
	{
		c.gotoxy(30, 7);
		cout << "O jogo acabou";
		c.gotoxy(30, 8);
		cout << "Ja nao tem tripulantes!!";
	}
	cout << endl;
	cout << endl;
	system("PAUSE");
}