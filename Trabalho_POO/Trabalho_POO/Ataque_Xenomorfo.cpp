#include "Ataque_Xenomorfo.h"

Ataque_Xenomorfo::Ataque_Xenomorfo()
{

}

Ataque_Xenomorfo::~Ataque_Xenomorfo()
{

}

void Ataque_Xenomorfo::accao(Nave* nave)
{
	nave->invadida_xenomorfos();
}