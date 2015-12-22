#include "bibliotecas.h"
#include "Nave.h"
#include "Tripulacao.h"

void main()
{
	int i = 0;
	Nave nave;
	nave.set_salas_normais();
	nave.set_salas_opcionais();
	nave.get_info_salas();
	while (i < 3)
	{
		nave.le_comando();
		nave.get_info_salas();
		i++;
	}
	
	/*nave.set_tripulantes();*/
	
	



	
}