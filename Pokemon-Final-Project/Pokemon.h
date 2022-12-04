#pragma once
#include <string>

using std::string;

class Pokemon
{
	//int name;
	int hp;
	int pp;
	int type;

	// Make separate class for "moves"?

public:
	Pokemon(int in_name, int in_hp, int in_pp);

	string show_name(int in_name);
	int show_hp();
	int show_pp();
	int show_type();



};

