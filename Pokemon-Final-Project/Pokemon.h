#pragma once
#include <string>

using std::string;

class Pokemon
{
	//int name;
	int hp;
	int pp;
	int type;
	int moves[4];

public:
	Pokemon(int in_name, int in_hp, int in_pp, int move1, int move2, int move3, int move4);

	string show_name(int in_name);
	int show_hp();
	int show_pp();
	int show_type();



};

