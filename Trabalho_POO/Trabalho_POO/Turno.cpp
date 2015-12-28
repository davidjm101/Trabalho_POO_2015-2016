#include "Turno.h"
#include "Po_Cosmico.h"

Turno::Turno()
{
	numero = 1;
}

Turno::~Turno()
{
}

void Turno::inicio_jogo()
{
	nave.set_salas_normais();
	nave.set_salas_opcionais();
	desenho.desenha_nave();
	desenho.desenha_info();
	desenho.desenha_milhas();
	nave.imprime_dados_sala();
}

void Turno::inicio_turno()
{

}


void Turno::fase_ordem()
{
	
	string comando;
	char nome;
	int numero;
	desenho.desenha_milhas();
	c.gotoxy(85, 4);
	cout << nave.get_milhas();
	c.gotoxy(3, 26);
	cout << "Indique o comando: ";
	cin >> comando;
	nome = comando[0];
	numero = comando[1] - '0';
	nave.mover_membro_tripulacao(nome, numero);
	
	
	
}

void Turno::final_turno()
{
	nave.reparar_nave();
	nave.mover_nave();
	desenho.desenha_milhas();
	c.gotoxy(85, 4);
	cout << nave.get_milhas();
}

void Turno::eventos()
{
	int aux;
	desenho.desenha_nave();
	desenho.desenha_info();
	nave.imprime_dados_sala();
	srand(time(NULL));
	if (numero == 5)
	{
		//gera um numero entre 1 e 4
		/*aux = rand() % 4 + 1;*/
		aux = 4;//tirar isso quanto meter os outro eventos
		switch (aux)
		{
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		//evento po cosmico
		case 4:
			po_cosmico();
			break;
		default:
			break;
		}
		numero = 0;
	}
	numero++;
}

void Turno::po_cosmico()
{

	int aux,i=1;
	Po_Cosmico po;
	srand(time(NULL));
	do {
		aux = rand() % 12 + 1;
		nave.dano_po_cosmico(aux,po.get_dano());
		i++;
	} while (i <= 3);
	c.gotoxy(85, 19);
	cout << "A nave atravessou campo" << endl;
	c.gotoxy(85, 20);
	cout << "de po cosmico!!!" << endl;
	c.gotoxy(85, 21);
	cout << "Varias salas receberam dano." << endl;
	nave.imprime_dados_sala();
	



}


bool Turno::acabou_jogo()
{
	bool aux = false;
	bool destruido = false;
	if (nave.get_milhas() >= (4000 + 1000) || nave.get_sala_destruida()==true)
	{
		aux = true;
	}

	return aux;
}