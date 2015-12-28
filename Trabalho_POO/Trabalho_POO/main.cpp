#include "bibliotecas.h"
#include "Turno.h"

void main()
{
	int i = 0;
	Turno turno;
	turno.inicio_jogo();
	do {
		/*turno.inicio_turno();*/
		turno.fase_ordem();
		turno.final_turno();
		turno.eventos();
	} while (turno.acabou_jogo()==false);
	
}