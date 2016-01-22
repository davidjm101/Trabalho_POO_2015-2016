#include "Turno.h"
#include "Po_Cosmico.h"

Turno::Turno()
{
	turno = 1;
	conta_turno_eventos = 1;
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
	nave->dano_sala_fogo();
	nave->trata_efeito_toxicidade();
	nave->trata_efeito_regenerador();
	nave->trata_efeito_flamejante();
	nave->sala_verifica_respirar();
	nave->mover_pirata();
	/*nave->mover_xenomorfo();*/

	desenho.desenha_nave();
	desenho.desenha_info();
	desenho.desenha_info_nave();
	desenho.desenha_info_unidades();
	desenho.desenha_accoes();
	desenho.desenha_comando();
	nave->imprime_dados_sala();
	c.gotoxy(104, 4);
	cout << nave->get_milhas();
	c.gotoxy(92, 6);
	cout << nave->get_escudo();
	c.gotoxy(92, 8);
	cout << turno;
	nave->imprime_accoes_eventos();
	nave->imprime_accoes_salas();
	nave->limpa_accoes_salas();

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
		evento.at(1)->accao(nave);	
	}
	
	if (conta_turno_eventos == 5)
	{
		aux = rand() % 4;
		evento.at(3)->accao(nave);
		conta_turno_eventos = 0;
	}
	
	conta_turno_eventos++;
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