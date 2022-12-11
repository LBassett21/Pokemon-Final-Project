#include "User.h"

User::User(string in_name, float in_bal, int num_pb, int num_p, int num_e, int num_r, Pokemon& p1, Pokemon& p2, Pokemon& p3) {
	name = in_name;
	balance = in_bal;

	num_pokeball = num_pb;
	num_potion = num_p;
	num_elixir = num_e;
	num_revive = num_r;

	party[0] = p1;
	party[1] = p2;
	party[2] = p3;

	active_pokemon = p1;
}

int User::show_pokeball() {
	return num_pokeball;
}

int User::show_balance() {
	return balance;
}

// TODO: Subtract from balance
// Add error checking when buying / cout stuff here to reduce main.cpp clutter
void User::buy_pokeball() {
	num_pokeball += 1;
}
void User::buy_potion() {
	num_potion += 1;
}
void User::buy_elixir() {
	num_elixir += 1;
}
void User::buy_revive() {
	num_revive += 1;
}
void User::use_pokeball() {
	num_pokeball -= 1;
}