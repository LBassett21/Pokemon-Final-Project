#pragma once
#include <string>

using std::string;

class Pokemon
{
	int name;
	int hp;
	int pp;
	int type;
	int weak_type;
	int strong_type;

	int moves[4];
	string move_name[4];
	int move_dmg[4];
	int move_pp[4];
	int move_type[4];

	int max_hp;
	int max_pp;

	friend class Trainer;
	//friend class User;

public:
	Pokemon();
	Pokemon(int in_name, int in_hp, int in_pp, int type, int move1, int move2, int move3, int move4);

	string show_name();

	int show_hp();
	int show_pp();
	int show_type();

	int show_move(int move_num);

};

