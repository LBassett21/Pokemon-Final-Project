#include "User.h"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

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

	active_pokemon = &party[0];
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

void User::switch_active_pokemon() {
	int choice;
	int count = 0;
	int partyChoice[2] = { -1,-1 };

	cout << "Select a new Pokemon to swap in: \n";
	if (!party[0].is_fainted() || !party[1].is_fainted() || !party[2].is_fainted()) {
		for (int i = 0; i < 3; i++) {
			if (!party[i].is_fainted() && (party[i].show_name() != active_pokemon->show_name())) {
				cout << i + 1 << ". " << party[i].show_name() << "\n";
				partyChoice[count] = i;
				count++;
			}
		}
		cin >> choice;
		do {
			cout << "Invalid option. Please try again.\n";
			cin >> choice;
		} while ((choice != partyChoice[0]) && (choice != partyChoice[1]));

		active_pokemon = &party[choice - 1];
		cout << "Go! " << active_pokemon->show_name() << "!\n";
	}
	else {
		cout << "You don't have any other Pokemon to swap to!\n";
	}
	
}