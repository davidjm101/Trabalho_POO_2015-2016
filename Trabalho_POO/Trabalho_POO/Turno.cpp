#include "Turno.h"
#include "Po_Cosmico.h"

Turno::Turno()
{
	numero = 1;
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
	
	nave->set_salas_normais();
	nave->set_salas_opcionais();
	nave->adiciona_tripulantes();
	desenho.desenha_nave();
	desenho.desenha_info();
	desenho.desenha_milhas();
	desenho.desenha_info_tripulantes();
	desenho.desenha_info_xenomorfos();
	desenho.desenha_info_piratas();
	nave->imprime_dados_sala();
}

void Turno::inicio_turno()
{
	nave->sala_verifica_respirar();
	nave->imprime_dado_tripulante();
}


void Turno::fase_ordem()
{
	
	string comando="";
	string token;
	char nome;
	int numero;
	desenho.desenha_nave();
	desenho.desenha_info();
	desenho.desenha_milhas();
	nave->imprime_dados_sala();
	c.gotoxy(85, 4);
	cout << nave->get_milhas();
	c.gotoxy(85, 6);
	cout << nave->get_escudo();
	c.gotoxy(3, 26);

	cout << "Indique o comando: ";
	cin >> comando;
	/*cin.ignore();
	getline(cin,comando);
	if (comando.size() > 2)
	{
		token=comando.substr(5, 1);
		nome= token[0];
		nave->imprime_dado_tripulante(nome);
	}*/
		token = comando.substr(0, 1);
		nome = token[0];
		token = comando.substr(1, comando.size());
		numero = stoi(token);
		nave->mover_membro_tripulacao(nome, numero);
	
	
	desenho.desenha_nave();
	desenho.desenha_info();
	desenho.desenha_milhas();
	nave->imprime_dados_sala();
	nave->imprime_dado_tripulante();
	
	
}

void Turno::final_turno()
{
	nave->mover_nave();
	c.gotoxy(85, 4);
	cout << nave->get_milhas();
}

void Turno::eventos()
{
	
	int aux;
	srand(time(NULL));
	if (numero == 5)
	{
		/*aux = rand() % 4 + 1;*/
		evento.at(0)->accao(nave);
		nave->imprime_dados_sala();
		numero =1;	
		
	}
	numero++;
	
}




bool Turno::acabou_jogo()
{
	bool aux = false;
	bool destruido = false;
	if (nave->get_milhas() >= (4000 + 1000) || nave->get_sala_destruida()==true)
	{
		aux = true;
	}

	return aux;
}