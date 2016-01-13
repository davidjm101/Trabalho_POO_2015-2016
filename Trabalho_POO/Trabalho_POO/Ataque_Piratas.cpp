#include "Ataque_Pirata.h"

Ataque_Piratas::Ataque_Piratas()
{
		
}

Ataque_Piratas::~Ataque_Piratas()
{

}

void Ataque_Piratas::accao(Nave *nave)
{
	int aux;
	srand(time(NULL));
	aux = rand() % 60 + 30;
	set_dano(aux);
	aux = rand() % 5 + 3;
	nave->ataque_pirata(get_dano(), aux);
}