#include "bibliotecas.h"
#include "Turno.h"
#include "consola.h"

void main()
{
	int i = 0;
	Turno turno;
	Consola c;
	int opcao;
	bool verifica = true;
	c.setScreenSize(25,100);
	c.gotoxy(20,2);
	cout << " _____              _____ _       _     " << endl;
	c.gotoxy(20, 3);
    cout << "| __  |___ _____   |  |  |_|___ _| |___ " << endl;
	c.gotoxy(20, 4);
	cout << "| __ -| -_|     |  |  |  | |   | . | . |" << endl;
	c.gotoxy(20, 5);
	cout << "|_____|___|_|_|_|    \___/|_|_|_|___|___|" << endl;
	

	do
	{
		c.gotoxy(33, 7);
		cout << "1-Iniciar jogo" << endl;
		c.gotoxy(33, 8);
		cout << "2-Sair" << endl;
		c.gotoxy(33, 9);
		cout << "Indique o que pretende fazer:" << endl;
		c.gotoxy(63, 9);
		cin >> opcao;
	} while (opcao<1 || opcao>2);
		
	if (opcao == 1)
	{
		turno.inicio_jogo();
		do {
			turno.inicio_turno();
			turno.fase_ordem();
			turno.final_turno();
			turno.eventos();


		} while (turno.acabou_jogo() == false);
		turno.imprime_acabou_jogo();
	}
	turno.imprime_acabou_jogo();
	
}