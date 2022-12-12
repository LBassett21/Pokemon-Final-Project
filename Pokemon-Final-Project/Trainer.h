#pragma once
#include "Pokemon.h"
#include "PokemonData.h"

class Trainer
{
	string name;
	int num_potion;
	int num_elixir;
	int num_revive;
	Pokemon party[3];						// Array of all Pokemon in Trainer's party
	Pokemon active_pokemon;					// Current pokemon selected (default = 0)

	friend class User;

public:
	Trainer();
	Trainer(string in_name, int num_p, int num_e, int num_r, Pokemon& p1, Pokemon& p2, Pokemon& p3);

	string show_name();
	int show_potion();
	int show_elixir();
	int show_revive();
<<<<<<< HEAD
	string show_pokemon(int in_num);
	int show_pokemon_type(int in_num);
	int show_pokemon_hp(int in_num);
	int show_pokemon_pp(int in_num);


	// TODO: create methods to show attributes of each Pokemon

	// TODO: create methods for using moves / other menu options
	void use_potion();
	void use_elixir();
	void use_revive(int party_member);

	void new_pokemon(int party_member, Pokemon& pNew);

=======
>>>>>>> 929d071f96a1fdabc1f1535ba669294ea48f3b93
	Pokemon show_active_pokemon();
	
	// Battle methods
	void print_moves();
	void use_move(int move, Pokemon& enemy);
	void use_potion(int party_member);
	void use_elixir(int party_member);
	void use_revive(int party_member);
	// 
	//virtual void switch_active_pokemon();
};

