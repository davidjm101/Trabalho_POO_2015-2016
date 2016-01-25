#pragma once

#include "bibliotecas.h"
#include "Unidade.h"

class xenomorfos : public Unidade
{
		int xenomorfo;
		static char aux;
		char letra;
		bool misterioso;
		bool casulo;
		int regenerador;
		bool flamejante;
		int toxico;
		bool hipnotizador;
		int mutatis_mutandis;
		

	public:
		xenomorfos();
		~xenomorfos();
		void set_xenomorfo(int valor);
		void set_misterioso(bool valor);
		void set_casulo(int valor);
		void set_regenerador(int valor);
		void set_flamejante(bool aux);
		void set_toxico(int valor);
		void set_hipnotizador(bool valor);
		void set_mutatis_mutandis(int valor);
		void altera_vida_do_Xenomorfo();


		void regenera_vida();
		int get_xenomorfo();
		int get_mutatis_mutandis();
		bool get_hipnotizador();
		int get_toxico();
		int get_flamejante();
		int get_regenerador();
		bool get_misterioso();
		bool get_casulo();
		char get_letra();
		bool verifica_move();

};
