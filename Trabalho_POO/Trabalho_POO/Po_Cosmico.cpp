#include "Po_Cosmico.h"

Po_Cosmico::Po_Cosmico()
{
	int dano = 10;
	set_dano(dano);
}

Po_Cosmico::~Po_Cosmico()
{
}

void Po_Cosmico::accao(Nave* nave)
{
	nave->atravessa_po_cosmico(get_dano());
}

