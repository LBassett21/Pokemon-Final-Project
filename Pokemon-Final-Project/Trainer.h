#pragma once
#include "Pokemon.h"

class Trainer :
	public Pokemon
{
	string name;
	int num_potion;
	int num_elixir;
	int num_revive;
	Pokemon* party;		// Array of all Pokemon in Trainer's party

public:
	Trainer(string in_name, int num_p, int num_e, int num_r, Pokemon p1, Pokemon p2, Pokemon p3);

	string show_name();
	int show_potion();
	int show_elixir();
	int show_revive();
	// TODO: create methods to show attributes of each Pokemon

	// TODO: create methods for using moves / other menu options
	void use_potion();
	void use_elixir();
	void use_revive();
};

