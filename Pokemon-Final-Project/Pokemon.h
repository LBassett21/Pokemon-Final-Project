#pragma once
#include <string>

using std::string;

class Pokemon
{
	int name;
	int hp;
	int pp;
	int type;
	int moves[4];

	int max_hp;
	int max_pp;

	friend class Trainer;
	//friend class User;

public:
	Pokemon();
	Pokemon(int in_name, int in_hp, int in_pp, int type, int poke_moves[4]);

	string show_name();

	int show_hp();
	int show_pp();
	int show_type();

	int show_move1();
	int show_move2();
	int show_move3();
	int show_move4();

};

