#include "Desenho.h"

Desenho::Desenho()
{
	
}

Desenho::~Desenho()
{

}

void Desenho::desenha_nave()
{
	system("cls");
	set_sala1();
	set_sala2();
	set_sala3();
	set_sala4();
	set_sala5();
	set_sala6();
	set_sala7();
	set_sala8();
	set_sala9();
	set_sala10();
	set_sala11();
	set_sala12();

		
}


void Desenho::desenha_info()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(82, 18);
	cout << (char)201 << endl;

	//linha de cima
	for (i = 83; i < 115; i++)
	{
		c.gotoxy(i, 18);
		cout << (char)205 << "\n";
	}

	//canto superior direito
	c.gotoxy(115, 18);
	cout << (char)187 << endl;

	//linha esquerda
	for (i = 19; i < 30; i++)
	{
		c.gotoxy(82, i);
		cout << (char)186 << "\n";
	}

	//linha direita
	for (i = 19; i < 30; i++)
	{
		c.gotoxy(115, i);
		cout << (char)186 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(82, 30);
	cout << (char)200 << endl;

	//linha de baixo
	for (i = 83; i < 115; i++)
	{
		c.gotoxy(i, 30);
		cout << (char)205 << "\n";
	}

	//canto inferior direito
	c.gotoxy(115, 30);
	cout << (char)188 << endl;

	c.gotoxy(84, 18);
	cout << "Informacao" << endl;
}

void Desenho::desenha_milhas()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(84, 2);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 85; i < 116; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(116, 2);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 3; i < 7; i++)
	{
		c.gotoxy(84, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 7; i++)
	{
		c.gotoxy(116, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(84, 7);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 85; i < 116; i++)
	{
		c.gotoxy(i, 7);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(116, 7);
	cout << (char)217 << endl;
	

	c.gotoxy(85,3);
	cout << "Milhas Percorridas:" << endl;

}

void Desenho::set_sala1()
{
	
	int i;

	//canto superior esquerdo
	c.gotoxy(2, 2);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(20, 2);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(20, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(2, 9);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 9);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(20, 9);
	cout << (char)217 << endl;

	

}

void Desenho::set_sala2()
{
	
	int i;

	//canto superior esquerdo
	c.gotoxy(22, 2);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(40, 2);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(22, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(40, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(22, 9);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 9);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(40, 9);
	cout << (char)217 << endl;
}

void Desenho::set_sala3()
{

	int i;

	//canto superior esquerdo
	c.gotoxy(42, 2);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(60, 2);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(42, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(42, 9);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 9);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(60, 9);
	cout << (char)217 << endl;
}

void Desenho::set_sala4()
{

	int i;

	//canto superior esquerdo
	c.gotoxy(62, 2);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(80, 2);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(62, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 9; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(62, 9);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 9);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(80, 9);
	cout << (char)217 << endl;
}

void Desenho::set_sala5()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(22, 10);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(40, 10);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(22, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(40, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(22, 17);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 17);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(40, 17);
	cout << (char)217 << endl;
}

void Desenho::set_sala6()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(42, 10);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(60, 10);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(42, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(42, 17);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 17);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(60, 17);
	cout << (char)217 << endl;
}

void Desenho::set_sala7()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(62, 10);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(80, 10);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(62, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(62, 17);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 17);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(80, 17);
	cout << (char)217 << endl;
}

void Desenho::set_sala8()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(82, 10);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 83; i < 100; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(100, 10);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(82, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 11; i < 17; i++)
	{
		c.gotoxy(100, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(82, 17);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 83; i < 100; i++)
	{
		c.gotoxy(i, 17);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(100, 17);
	cout << (char)217 << endl;
}

void Desenho::set_sala9()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(2, 18);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 18);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(20, 18);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(20, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(2, 25);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 25);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(20, 25);
	cout << (char)217 << endl;
}

void Desenho::set_sala10()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(22, 18);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 18);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(40, 18);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(22, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(40, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(22, 25);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 25);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(40, 25);
	cout << (char)217 << endl;
}

void Desenho::set_sala11()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(42, 18);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 18);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(60, 18);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(42, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(42, 25);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 25);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(60, 25);
	cout << (char)217 << endl;
}

void Desenho::set_sala12()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(62, 18);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 18);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(80, 18);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(62, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 19; i < 25; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(62, 25);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 25);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(80, 25);
	cout << (char)217 << endl;
}