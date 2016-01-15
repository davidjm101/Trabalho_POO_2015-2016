#pragma once


class Unidade {
	string nome;
	int vida;
	int tipo_unidade;
	bool respira;
	bool operador;
	int mover;
	int exoesq;
	int quanto_repara;
	bool repara;

public:
	Unidade();
	
	~Unidade();
	void set_nome(string nome);
	void set_vida(int valor);
	void set_respira(bool valor);
	void set_operador(bool valor);
	void set_mover(int valor);
	void set_exoesq(int valor);
	void set_quanto_reparar(int valor);
	void set_repara(bool aux);

	void reduz_vida(int valor);
	void acrescenta_vida(int valor);
	void altera_valor_do_dano(int valor);


	string get_nome();
	int get_vida();


	bool get_respira();
	bool get_operador();
	int get_mover();
	int get_exoesq();
	int get_quanto_reparar();
	bool get_repara();
};