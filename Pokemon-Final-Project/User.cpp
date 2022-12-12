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

void User::use_potion() {
	int userinput;
	if (num_potion == 0) {
		cout << "You do not have any Potions!\n";
	}
	else {
		cout << "What pokemon would you like to use it on?\n";
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << party[i].show_name() << "\n";
		}
		cin >> userinput;
		while (userinput != 1 && userinput != 2 && userinput != 3) {
			cout << "Invalid input! Please try again!\n";
			cin >> userinput;
		}
		cout << party[userinput - 1].show_name() << "'s Current HP: " << party[userinput - 1].show_hp() << "\n";
		if (party[userinput - 1].hp == party[userinput - 1].max_hp) {
			cout << "You are already at max HP!\n";
		}
		else {
			num_potion -= 1;
			if ((party[userinput - 1].hp + 20) > party[userinput - 1].max_hp) {
				party[userinput - 1].hp = party[userinput - 1].max_hp;
			}
			else {
				party[userinput - 1].hp += 20;
			}
			cout << party[userinput - 1].show_name() << "'s New HP: " << party[userinput - 1].show_hp() << "\n";
		}
	}
}
void User::use_elixir() {
	int userinput;
	if (num_elixir == 0) {
		cout << "You do not have any Elixirs!\n";
	}
	else {
		cout << "What pokemon would you like to use it on?\n";
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << party[i].show_name() << "\n";
		}
		cin >> userinput;
		while (userinput != 1 && userinput != 2 && userinput != 3) {
			cout << "Invalid input! Please try again!\n";
			cin >> userinput;
		}
		cout << party[userinput - 1].show_name() << "'s Current PP: " << party[userinput - 1].show_pp() << "\n";
		if (party[userinput - 1].pp == party[userinput - 1].max_pp) {
			cout << "You already have max PP!\n";
		}
		else {
			num_elixir -= 1;
			if ((party[userinput - 1].pp + 20) >= party[userinput - 1].max_pp) {
				party[userinput - 1].pp = party[userinput - 1].max_pp;
			}
			else {
				party[userinput - 1].pp += 20;
			}
			cout << party[userinput - 1].show_name() << "'s New PP is: " << party[userinput - 1].show_pp() << "\n";
		}
	}
}
void User::use_revive() {
	int userinput;
	if (num_revive < 0) {
		cout << "You don't have any Revives!\n";
	}
	else if (party[0].hp > 0 || party[1].hp > 0 || party[2].hp > 0) {
		cout << "None of your pokemon have fainted!\n";
	}
	else {
		cout << "What pokemon would you like to use it on?\n";
		for (int i = 0; i < 3; i++) {
			cout << i + 1 << ". " << party[i].show_name() << "\n";
		}
		cin >> userinput;
		while (userinput != 1 && userinput != 2 && userinput != 3) {
			cout << "Invalid input! Please try again!\n";
			cin >> userinput;
		}
		if (party[userinput - 1].hp > 0) {
			cout << "This Pokemon has not fainted!\n";
		}
		else {
			party[userinput - 1].hp = party[userinput - 1].max_hp / 2;	// Restore Pokemon to half HP
			num_revive -= 1;
			cout << party[userinput - 1].show_name() << " has been revived!\n";
		}
	}
}

void User::switch_active_pokemon() {
	int choice;
	int count = 0;
	int partyChoice[2] = { -1,-1 };

	if (party[0].is_fainted() && party[1].is_fainted() && party[2].is_fainted())
		cout << show_name() << " tried to swap Pokemon but failed!\n";
	else {
		cout << "Select a new Pokemon to swap in: \n";
		for (int i = 0; i < 3; i++) {
			if (!party[i].is_fainted() && (party[i].show_name() != active_pokemon->show_name())) {
				cout << i + 1 << ". " << party[i].show_name() << "\n";
				partyChoice[count] = i;
				count++;
			}
		}
		cin >> choice;
		while ((choice != (partyChoice[0] - 1)) && (choice != (partyChoice[1] - 1))) {
			cout << "Invalid option. Please try again.\n";
			cin >> choice;
		}

		active_pokemon = &party[choice - 1];
		cout << "Go! " << active_pokemon->show_name() << "!\n";

	}
	
}