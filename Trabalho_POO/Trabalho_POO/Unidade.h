#pragma once


class Unidade {
	string nome;
	int vida;
	int tipo_unidade;
	bool respira;
	bool operador;
	int mover;
	int exoesq;

public:
	Unidade();
	
	~Unidade();
	void set_nome(string nome);
	void set_vida(int valor);
	void set_respira(bool valor);
	void set_operador(bool valor);
	void set_mover(int valor);
	void set_exoesq(int valor);
	string get_nome();
	int get_vida();
	
	bool get_respira();
	bool get_operador();
	int get_mover();
	int get_exoesq();
};