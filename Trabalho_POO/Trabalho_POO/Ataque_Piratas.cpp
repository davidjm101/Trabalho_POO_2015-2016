#include "Ataque_Pirata.h"

Ataque_Piratas::Ataque_Piratas()
{
		
}

Ataque_Piratas::~Ataque_Piratas()
{

}

void Ataque_Piratas::accao(Nave *nave)
{
	int aux,aux2;

	aux = rand() % 31 + 30;//gera numero aleatorio entre 30 e 60
	set_dano(aux);
	aux2 = rand() % 3 + 3;//gera numero aleatorio entre 3 e 5
	nave->ataque_pirata(get_dano(), aux2);
}