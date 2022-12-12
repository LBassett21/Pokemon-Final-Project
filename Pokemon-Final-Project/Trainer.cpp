#include "Trainer.h"	

Trainer::Trainer() {

}

Trainer::Trainer(string in_name, int num_p, int num_e, int num_r, Pokemon& p1, Pokemon& p2, Pokemon& p3) {
	name = in_name;
	num_potion = num_p;
	num_elixir = num_e;
	num_revive = num_r;
	party[0] = p1;
	party[1] = p2;
	party[2] = p3;
}

string Trainer::show_name() {
	return name;
}

int Trainer::show_potion() {
	return num_potion;
}
int Trainer::show_elixir() {
	return num_elixir;
}
int Trainer::show_revive() {
	return num_revive;
}

string Trainer::show_pokemon(int in_num) {
	return party[in_num].show_name();
}
int Trainer::show_pokemon_type(int in_num) {
	return party[in_num].show_type();
}
int Trainer::show_pokemon_hp(int in_num) {
	return party[in_num].show_hp();
}
int Trainer::show_pokemon_pp(int in_num) {
	return party[in_num].show_pp();
}


void Trainer::new_pokemon(int party_member, Pokemon& pNew) {
	party[party_member] = pNew;
}

// TODO: create methods for using moves / other menu options
void Trainer::use_potion() {
	num_potion -= 1;
	active_pokemon.hp += 20;
}
void Trainer::use_elixir() {
	num_elixir -= 1;
	active_pokemon.pp += 20;
}
void Trainer::use_revive(int party_member) {
	// TODO: Only allow user to revive dead Pokemon (HP <= 0) - probably in main function?
	if (party[party_member].hp <= 0) {
		party[party_member].hp = party[party_member].max_hp / 2;	// Restore Pokemon to half HP
		num_revive -= 1;
	}
}

Pokemon Trainer::show_active_pokemon() {
	return active_pokemon;
}