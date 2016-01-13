#pragma once

#include "bibliotecas.h"
#include "Unidade.h"

class xenomorfos : public Unidade
{
		int xenomorfo;
		int reparador;
		int forca_combate;
		static char aux;
		bool combate;
		char letra;
		bool misterioso;
		bool casulo;
		int regenerador;
		bool flamejante;
		int toxico;
		bool hipnotizador;
		bool mutatis_mutandis;
		

	public:
		xenomorfos();
		~xenomorfos();
		void set_xenomorfo(int valor);
		void set_reparador(int valor);
		void set_forca_combate(int valor);
		void set_misterioso(int n_turno);
		void set_casulo(int valor);
		void set_combate(bool aux);
		void set_regenerador(int valor);
		void set_flamejante(bool aux);
		void set_toxico(int valor);
		void set_hipnotizador(int valor);
		void set_mutatis_mutandis(int valor);


		int get_xenomorfo();
		bool get_mutatis_mutandis();
		bool get_hipnotizador();
		int get_toxico();
		bool get_flamejante();
		int get_regenerador();
		bool get_misterioso();
		bool get_casulo();
		int get_reparador();
		int get_forca_combate();
		bool get_combate();
		char get_letra();
};
