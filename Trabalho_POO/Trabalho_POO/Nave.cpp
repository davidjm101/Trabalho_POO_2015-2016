#include "Nave.h"


Nave::Nave()
{

}

Nave::~Nave()
{

}

void Nave::set_salas_normais()
{
	Sala s1("Propulsor");
	Sala s5("Sala de maquinas");
	Sala s6("Suporte de vida");
	Sala s7("Controlo de escudo");
	Sala s8("Ponte");
	Sala s9("Propulsor");

	salas.push_back(s1);
	salas.push_back(s5);
	salas.push_back(s6);
	salas.push_back(s7);
	salas.push_back(s8);
	salas.push_back(s9);

	

	for (unsigned int i = 0; i < salas.size(); i++)
	{
		cout << salas.at(i).get_nome() << endl;
	}
}