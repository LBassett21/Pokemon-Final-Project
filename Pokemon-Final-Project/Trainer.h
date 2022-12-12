#pragma once
#include "Pokemon.h"
#include "PokemonData.h"

class Trainer
{
	string name;
	int num_potion;
	int num_elixir;
	int num_revive;
	Pokemon party[3];										// Array of all Pokemon in Trainer's party
	Pokemon* active_pokemon = &party[0];					// Current pokemon selected (default = 0)

	friend class User;

public:
	Trainer();
	Trainer(string in_name, int num_p, int num_e, int num_r, Pokemon& p1, Pokemon& p2, Pokemon& p3);

	string show_name();
	int show_potion();
	int show_elixir();
	int show_revive();
	Pokemon* return_active_pokemon();
	Pokemon& return_pokemon(int in_num);
	string show_pokemon(int in_num);
	string show_pokemon_type(int in_num);
	int show_pokemon_hp(int in_num);
	int show_pokemon_pp(int in_num);
	void new_pokemon(int party_member, Pokemon& pNew);
	
	// Battle methods
	void print_moves();
	void use_move(int move, Pokemon& enemy);
	void use_potion(int party_member);
	void use_elixir(int party_member);
	void use_revive(int party_member);
	
	void faint();
	virtual void switch_active_pokemon();
	

};

