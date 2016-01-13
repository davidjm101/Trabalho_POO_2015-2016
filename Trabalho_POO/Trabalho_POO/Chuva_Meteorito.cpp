#include "Chuva_Meteorito.h"

Chuva_Meteorito::Chuva_Meteorito()
{
	int dano = 10;
	set_dano(dano);
}


Chuva_Meteorito::~Chuva_Meteorito()
{

}

//acontecimento da chuva de meteoritos
void Chuva_Meteorito::accao(Nave *nave)
{
	int aux;
	srand(time(NULL));
	if (nave->verifica_ponte_operada() == true)//ponte esta a ser operada, antige a nave entre 4a8 vezes
	{
		aux = rand() % 8 + 4;
		nave->atravessa_chuva_meteoritos(get_dano(), aux);
	}
	else
	{
		aux = rand() % 12 + 6;
		nave->atravessa_chuva_meteoritos(get_dano(), aux);
	}
}