#include "Ataque_Pirata.h"

Ataque_Piratas::Ataque_Piratas()
{
		
}

Ataque_Piratas::~Ataque_Piratas()
{

}

void Ataque_Piratas::accao()
{
	int aux;
	srand(time(NULL));
	aux = rand() % 60 + 30;
	set_dano(aux);
	aux = rand() % 5 + 3;
	//chamar uma funcao da nave e passar o dano e o aux que é o numero de piratas a criar
}