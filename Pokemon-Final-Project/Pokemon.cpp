#include "Pokemon.h"
#include "PokemonData.h"

Pokemon::Pokemon() {

}

Pokemon::Pokemon(int in_name, int in_hp, int in_pp, int in_type, int move1, int move2, int move3, int move4) {
	name = in_name;
	type = in_type;
	hp = in_hp;
	pp = in_pp;
	fainted = false;

	max_hp = in_hp;
	max_pp = in_pp;
	
	moves[0] = move1;
	moves[1] = move2;
	moves[2] = move3;
	moves[3] = move4;

	for (int i = 0; i < 4; i++) {
		move_name[i] = poke_data.move_names[moves[i]];
		move_dmg[i] = poke_data.move_damage[moves[i]];
		move_pp[i] = poke_data.move_pp[moves[i]];
		move_type[i] = poke_data.move_type[moves[i]];
	}

	// Find type weakness
	switch (type) {
	case NORMAL:
		weak_type = -1;			// Normal has no weakness or strength
		break;
	case WATER:
		weak_type = GRASS;			
		break;
	case GRASS:
		weak_type = FIRE;
		break;
	case GROUND:
		weak_type = GRASS;
		break;
	case FIRE:
		weak_type = WATER;
		break;
	case ELECTRIC:
		weak_type = GROUND;
		break;
	}
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
string Pokemon::show_type() {
	if (type == 1)
		return "NORMAL";
	else if (type == 2)
		return "WATER";
	else if (type == 3)
		return "GRASS";
	else if (type == 4)
		return "GROUND";
	else if (type == 5)
		return "FIRE";
	else 
		return "ELECTRIC";
}

string Pokemon::show_move(int move_num) {
	return move_name[move_num];
}

bool Pokemon::is_fainted() {
	return fainted;
}
