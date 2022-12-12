#include "Trainer.h"	
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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
	active_pokemon = p1;
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
string Trainer::show_pokemon_type(int in_num) {
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

Pokemon Trainer::show_active_pokemon() {
	return active_pokemon;
}

// TODO: create methods for using moves / other menu options
void Trainer::use_potion(int party_member) {
	num_potion -= 1;
	active_pokemon.hp += 20;
}
void Trainer::use_elixir(int party_member) {
	num_elixir -= 1;
	active_pokemon.pp += 20;
}
void Trainer::use_revive(int party_member) {
	// TODO: Only allow user to revive dead Pokemon (HP <= 0) - probably in main function?
	if (party[party_member].hp > 0) {
		cout << "This Pokemon has not fainted!\n";
	}
	else if (num_revive < 0) {
		cout << "You don't have a Revive!\n";
	}
	else {
		party[party_member].hp = party[party_member].max_hp / 2;	// Restore Pokemon to half HP
		num_revive -= 1;
		cout << party[party_member].show_name() << " has been revived!\n";
	}
	
}

void Trainer::print_moves() {
	cout << "Moves:" << endl
		<< "1. " << active_pokemon.move_name[0] << " (PP: " << active_pokemon.move_pp[0] << ")\n"
		<< "2. " << active_pokemon.move_name[1] << " (PP: " << active_pokemon.move_pp[1] << ")\n"
		<< "3. " << active_pokemon.move_name[2] << " (PP: " << active_pokemon.move_pp[2] << ")\n"
		<< "4. " << active_pokemon.move_name[3] << " (PP: " << active_pokemon.move_pp[3] << ")\n";
}

void Trainer::use_move(int move, Pokemon& enemy) {
	// Check PP
	if (active_pokemon.move_pp[move] > active_pokemon.pp) {
		cout << "You don't have enough PP to use this move!\n";
	}
	else {
		cout << active_pokemon.show_name() << " used " << active_pokemon.show_move(move) << "!\n";

		if (enemy.weak_type == active_pokemon.move_type[move]) {
			enemy.hp -= 2*active_pokemon.move_dmg[move];
			cout << "It's super effective!\n";
		}
		else {
			enemy.hp -= active_pokemon.move_dmg[move];
		}
	}
}

