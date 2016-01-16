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
	c.gotoxy(82, 20);
	cout << (char)201 << endl;

	//linha de cima
	for (i = 83; i < 115; i++)
	{
		c.gotoxy(i, 20);
		cout << (char)205 << "\n";
	}

	//canto superior direito
	c.gotoxy(115, 20);
	cout << (char)187 << endl;

	//linha esquerda
	for (i = 21; i < 32; i++)
	{
		c.gotoxy(82, i);
		cout << (char)186 << "\n";
	}

	//linha direita
	for (i = 21; i < 32; i++)
	{
		c.gotoxy(115, i);
		cout << (char)186 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(82, 32);
	cout << (char)200 << endl;

	//linha de baixo
	for (i = 83; i < 115; i++)
	{
		c.gotoxy(i, 32);
		cout << (char)205 << "\n";
	}

	//canto inferior direito
	c.gotoxy(115, 32);
	cout << (char)188 << endl;

	c.gotoxy(84, 20);
	cout << "Informacao" << endl;
}

void Desenho::desenha_info_nave()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(82, 2);
	cout << (char)201 << endl;

	//linha de cima
	for (i = 83; i < 116; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)205 << "\n";
	}

	//canto superior direito
	c.gotoxy(116, 2);
	cout << (char)187 << endl;

	//linha esquerda
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(82, i);
		cout << (char)186 << "\n";
	}

	//linha direita
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(116, i);
		cout << (char)186 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(82, 10);
	cout << (char)200 << endl;

	//linha de baixo
	for (i = 83; i < 116; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)205 << "\n";
	}

	//canto inferior direito
	c.gotoxy(116, 10);
	cout << (char)188 << endl;
	
	c.gotoxy(83, 2);
	cout << "Info Nave";

	c.gotoxy(84,4);
	cout << "Milhas Percorridas: " << endl;

	c.gotoxy(84, 6);
	cout << "Escudo: " << endl;

	c.gotoxy(84, 8);
	cout << "Turnos: " << endl;

}

void Desenho::desenha_info_unidades()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(118, 2);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 119; i < 165; i++)
	{
		c.gotoxy(i, 2);
		cout << (char)196 << "\n";
	}

	////canto superior direito
	c.gotoxy(165, 2);
	cout << (char)191 << endl;

	////linha esquerda
	for (i = 3; i < 17; i++)
	{
		c.gotoxy(118, i);
		cout << (char)179 << "\n";
	}

	////linha direita
	for (i = 3; i < 17; i++)
	{
		c.gotoxy(165, i);
		cout << (char)179 << "\n";
	}

	////canto inferior esquerdo
	c.gotoxy(118, 17);
	cout << (char)192 << endl;

	////linha de baixo
	for (i = 119; i < 165; i++)
	{
		c.gotoxy(i, 17);
		cout << (char)196 << "\n";
	}

	////canto inferior direito
	c.gotoxy(165, 17);
	cout << (char)217 << endl;

	c.gotoxy(120, 2);
	cout << "Unidades:";
}

void Desenho::desenha_accoes()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(118, 18);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 119; i < 165; i++)
	{
		c.gotoxy(i, 18);
		cout << (char)196 << "\n";
	}

	////canto superior direito
	c.gotoxy(165, 18);
	cout << (char)191 << endl;

	////linha esquerda
	for (i = 19; i < 40; i++)
	{
		c.gotoxy(118, i);
		cout << (char)179 << "\n";
	}

	////linha direita
	for (i = 19; i < 40; i++)
	{
		c.gotoxy(165, i);
		cout << (char)179 << "\n";
	}

	////canto inferior esquerdo
	c.gotoxy(118, 40);
	cout << (char)192 << endl;

	////linha de baixo
	for (i = 119; i < 165; i++)
	{
		c.gotoxy(i, 40);
		cout << (char)196 << "\n";
	}

	////canto inferior direito
	c.gotoxy(165, 40);
	cout << (char)217 << endl;

	c.gotoxy(120, 18);
	cout << "Accoes:";
}

void Desenho::desenha_comando()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(2, 30);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 3; i < 45; i++)
	{
		c.gotoxy(i, 30);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(45, 30);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 31; i < 32; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 31; i < 32; i++)
	{
		c.gotoxy(45, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(2, 32);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 3; i < 45; i++)
	{
		c.gotoxy(i, 32);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(45, 32);
	cout << (char)217 << endl;

	c.gotoxy(3, 31);
	cout << "Introduza comando: ";
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
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(20, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(2, 10);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(20, 10);
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
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(22, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(40, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(22, 10);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(40, 10);
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
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(42, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(42, 10);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(60, 10);
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
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(62, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 3; i < 10; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(62, 10);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 10);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(80, 10);
	cout << (char)217 << endl;
}

void Desenho::set_sala5()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(22, 11);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 11);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(40, 11);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(22, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(40, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(22, 19);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 19);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(40, 19);
	cout << (char)217 << endl;
}

void Desenho::set_sala6()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(42, 11);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 11);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(60, 11);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(42, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(42, 19);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 19);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(60, 19);
	cout << (char)217 << endl;
}

void Desenho::set_sala7()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(62, 11);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 11);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(80, 11);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(62, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(62, 19);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 19);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(80, 19);
	cout << (char)217 << endl;
}

void Desenho::set_sala8()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(82, 11);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 83; i < 100; i++)
	{
		c.gotoxy(i, 11);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(100, 11);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(82, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 12; i < 19; i++)
	{
		c.gotoxy(100, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(82, 19);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 83; i < 100; i++)
	{
		c.gotoxy(i, 19);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(100, 19);
	cout << (char)217 << endl;
}

void Desenho::set_sala9()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(2, 20);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 20);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(20, 20);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(2, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(20, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(2, 28);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 3; i < 20; i++)
	{
		c.gotoxy(i, 28);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(20, 28);
	cout << (char)217 << endl;
}

void Desenho::set_sala10()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(22, 20);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 20);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(40, 20);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(22, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(40, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(22, 28);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 23; i < 40; i++)
	{
		c.gotoxy(i, 28);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(40, 28);
	cout << (char)217 << endl;
}

void Desenho::set_sala11()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(42, 20);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 20);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(60, 20);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(42, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(60, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(42, 28);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 43; i < 60; i++)
	{
		c.gotoxy(i, 28);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(60, 28);
	cout << (char)217 << endl;
}

void Desenho::set_sala12()
{
	int i;

	//canto superior esquerdo
	c.gotoxy(62, 20);
	cout << (char)218 << endl;

	//linha de cima
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 20);
		cout << (char)196 << "\n";
	}

	//canto superior direito
	c.gotoxy(80, 20);
	cout << (char)191 << endl;

	//linha esquerda
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(62, i);
		cout << (char)179 << "\n";
	}

	//linha direita
	for (i = 21; i < 28; i++)
	{
		c.gotoxy(80, i);
		cout << (char)179 << "\n";
	}

	//canto inferior esquerdo
	c.gotoxy(62, 28);
	cout << (char)192 << endl;

	//linha de baixo
	for (i = 63; i < 80; i++)
	{
		c.gotoxy(i, 28);
		cout << (char)196 << "\n";
	}

	//canto inferior direito
	c.gotoxy(80, 28);
	cout << (char)217 << endl;
}