#pragma once
#include "Trainer.h"
#include "Pokemon.h"
#include <string.h>

using std::string;

class User :
    public Trainer
{
    int num_pokeball;
	float balance;

public:
	User(string in_name, float in_bal, int num_pb, int num_p, int num_e, int num_r, Pokemon& p1, Pokemon& p2, Pokemon& p3);

    int show_pokeball();
	int show_balance();

	void buy_pokeball(int in_num);
	void buy_potion(int in_num);
	void buy_elixir(int in_num);
	void buy_revive(int in_num);

	void use_pokeball();
	void use_potion();
	void use_elixir();
	void use_revive();

	void switch_active_pokemon();
};

