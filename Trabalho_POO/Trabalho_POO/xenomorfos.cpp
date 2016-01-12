#include "bibliotecas.h"
#include "xenomorfos.h"
#include "Sala.h"

char xenomorfos::letra = 'a';



xenomorfos::xenomorfos()
{
	this->nome = this->letra;
	this->letra++;
}

xenomorfos::~xenomorfos()
{

}

void xenomorfos::set_reparador(int valor)
{
	this->reparador = valor;
}

void xenomorfos::set_forca_combate(int valor)
{
	this->forca_combate = valor;
}

void xenomorfos::set_misterioso(int n_turno) //???
{
	while (n_turno) {   ///?????
		srand(time(NULL));
		int probabilidade = rand() % 4 + 1;

		if (probabilidade == 1) {
			this->misterioso = true;
			n_turno++;
		}
		else
			this->misterioso = false;
	}
}

bool xenomorfos::get_misterioso()  /*ele aparece no final do proximo turno numa sala aleatoria
								   verificar*********************************************/
{
	return misterioso;
}

void xenomorfos::set_casulo(int valor)
{
	srand(time(NULL));
	int probabilidade = rand() % 100 + 1;

	if (probabilidade <= valor)
		this->casulo = true;
	else
		this->casulo = false;
}

bool xenomorfos::get_casulo()
{
	return casulo;

}

void xenomorfos::set_combate(bool aux)
{

	this->combate = aux;
}

bool xenomorfos::get_combate()
{
	return combate;
}


void xenomorfos::set_regenerador(int valor)
{
	//this->set_vida(++valor);
	this->regenerador = valor;
}

int xenomorfos::get_regenerador()
{
	return regenerador;
}

void xenomorfos::set_flamejante() 
{
	/*acabar*/
	
}

bool xenomorfos::get_flamejante()
{
	return flamejante;
}

void xenomorfos::set_toxico(int valor)
{


}
int xenomorfos::get_toxico()
{
	return toxico;
}

void xenomorfos::set_hipnotizador(int valor)
{

}

bool xenomorfos::get_hipnotizador()
{
	return hipnotizador;
}

void xenomorfos::set_mutatis_mutandis(int valor)
{
/*acabar*/

}

bool xenomorfos::get_mutatis_mutandis()
{

	return mutatis_mutandis;
}
