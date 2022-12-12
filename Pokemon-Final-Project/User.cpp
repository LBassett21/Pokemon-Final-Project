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

void User::buy_pokeball(int in_num) {
	num_pokeball += (1 * in_num);
	balance = balance - (200 * in_num);
}
void User::buy_potion(int in_num) {
	num_potion += (1 * in_num);
	balance = balance - (100 * in_num);
}
void User::buy_elixir(int in_num) {
	num_elixir += (1 * in_num);
	balance = balance - (150 * in_num);
}
void User::buy_revive(int in_num) {
	num_revive += (1 * in_num);
	balance = balance - (300 * in_num);
}
void User::use_pokeball() {
	num_pokeball -= 1;
}