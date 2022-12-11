#include "Pokemon.h"
#include "PokemonData.h"

Pokemon::Pokemon() {

}

Pokemon::Pokemon(int in_name, int in_hp, int in_pp, int in_type, int move1, int move2, int move3, int move4) {
	name = in_name;
	type = in_type;
	hp = in_hp;
	pp = in_pp;

	max_hp = in_hp;
	max_pp = in_pp;
	
	moves[0] = move1;
	moves[1] = move2;
	moves[2] = move3;
	moves[3] = move4;
}

string Pokemon::show_name() {
	return poke_data.names[name];
}
int Pokemon::show_hp() {
	return hp;
}
int Pokemon::show_pp() {
	return pp;
}
int Pokemon::show_type() {
	return type;
}

int Pokemon::show_move1() {
	return moves[0];
}

int Pokemon::show_move2() {
	return moves[1];
}

int Pokemon::show_move3() {
	return moves[2];
}

int Pokemon::show_move4() {
	return moves[3];
}

