#include "Pokemon.h"
#include "PokemonData.h"

Pokemon::Pokemon(int in_name, int in_hp, int in_pp, int move1, int move2, int move3, int move4) {
	name = in_name;
	type = in_name;
	hp = in_hp;
	pp = in_pp;
}

string Pokemon::show_name(int in_name) {
	//struct poke_names a;
	//for (int i = 0; i < 84; i++) {
		//if (i == in_name) {
			//return a.names[i];
		//}
	//}
	return poke_names.names[in_name];
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


