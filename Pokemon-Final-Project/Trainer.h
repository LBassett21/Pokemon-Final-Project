#pragma once
#include "Pokemon.h"

class Trainer
{
	string name;
	int num_potion;
	int num_elixir;
	int num_revive;
	Pokemon party[3];						// Array of all Pokemon in Trainer's party
	Pokemon active_pokemon = party[0];		// Current pokemon selected (default = 0)

	friend class User;

public:
	Trainer();
	Trainer(string in_name, int num_p, int num_e, int num_r, Pokemon& p1, Pokemon& p2, Pokemon& p3);

	string show_name();
	int show_potion();
	int show_elixir();
	int show_revive();
	// TODO: create methods to show attributes of each Pokemon

	// TODO: create methods for using moves / other menu options
	void use_potion();
	void use_elixir();
	void use_revive(int party_member);

	Pokemon show_active_pokemon();
	//virtual void use_move();
	// 
	//virtual void switch_active_pokemon();
};

