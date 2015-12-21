#pragma once


class Unidade {
	int vida;
	int tipo_unidade;
	bool respira;
	bool operador;
	int mover;
	int exoesq;

public:
	Unidade();
	
	~Unidade();
	void set_vida();
	void set_respira();
	void set_operador();
	void set_mover();
	void set_exoesq();
	int get_vida();
	bool get_respira();
	bool get_operador();
	int get_mover();
	int get_exoesq();
};