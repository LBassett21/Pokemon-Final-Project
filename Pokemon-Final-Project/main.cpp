#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include "Pokemon.h"
#include "Trainer.h"
#include "User.h"
#include <windows.h>		// what
#include "PokemonData.h"

using std::cout;
using std::cin;
using std::setprecision;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;

int generate_move(int pokemon, int move1, int move2, int move3) {
	int move;

	// Pick moves based on type
	for (int i = 0; i < sizeof(poke_data.move_type) / sizeof(poke_data.move_type[0]); i++) {
		// If move type matches pokemon type (or is normal type move), also check if not the same move as existing moves
		if ((i != move1 && i != move2 && i != move3) && ((poke_data.move_type[i] == poke_data.poke_type[pokemon]) || poke_data.move_type[i] == NORMAL)) {	
			move = i;	
			break;
		}
	}
	return move;
}

Pokemon* generate_pokemon() {
	int randPokemon = rand() % 85;			// Random Pokemon from 0-84
	int randHP = (rand() % 70) + 80;		// Random HP from 80-150 
	int randPP = (rand() % 60) + 60;		// Random PP from 60-120

	int moves[4] = {-1,-1,-1,-1};
	for (int i = 0; i < 4; i++) {
		moves[i] = generate_move(randPokemon, moves[0], moves[1], moves[2]);
	}
	Pokemon* pokemon = new Pokemon(randPokemon, randHP, randPP, poke_data.poke_type[randPokemon], moves[0], moves[1], moves[2], moves[3]);
	return pokemon;
}

// Simulate entire fight, only break when one trainer is defeated
void fightTrainer(User& user, Trainer& opponent, bool& userDefeated) {
	bool opponentDefeated = false;
	int choice = 0;
	int move_choice = 0;
	int item_choice = 0;
	int poke_choice = 0;
	
	cout << opponent.show_name() << " wants to fight!" << endl;
	cout << opponent.show_name() << " sent out " << opponent.show_active_pokemon().show_name() << "!" << endl;
	cout << "You sent out " << user.show_active_pokemon().show_name() << "!" << endl;
	do {
		cout << opponent.show_active_pokemon().show_name() << " - " << "HP: " << opponent.show_active_pokemon().show_hp() << " PP: " << opponent.show_active_pokemon().show_pp() << endl;
		cout << user.show_active_pokemon().show_name() << " - " << "HP: " << user.show_active_pokemon().show_hp() << " PP: " << user.show_active_pokemon().show_pp() << endl;

		cout << "What will you do?" << endl;
		cout << "1. Fight\n" << "2. Bag\n" << "3. Pokemon\n";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Moves:\n" << user.show_active_pokemon().show_move1() << endl << user.show_active_pokemon().show_move2()
				<< endl << user.show_active_pokemon().show_move3() << endl << user.show_active_pokemon().show_move1() << endl;
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout << "Invalid option. Try again.\n";
			break;
		}
	} while (!userDefeated && !opponentDefeated);
}

int main() {
	srand(time(0));
	int level = 1;
	int count = 3;
	int userinput;
	bool pickedPokemon = false;
	vector <int> pokeChoices;
	bool check = false;
	float bal = 1000; // delete this later
	string username;
	string rivalname;

	Pokemon* randPokemon;
	int chance = 0;

	bool userDefeated = false;

	cout << "My name is Professor Oak\n";
	Sleep(150);
	cout << "Some people call me the Pokemon Professor!\n";
	Sleep(150);
	cout << "This world is inhabited by creatures called Pokemon!\n";
	Sleep(150);
	cout << "Pokemon are pets. Others use them for fights.\n";
	Sleep(150);
	cout << "Myself? I study Pokemon as a professon.\n";
	Sleep(150);
	cout << "First, what is your name?\n";
	cout << "Name: ";
	cin >> username;
	cout << "Right! So your name is " << username << "!\n";
	Sleep(150);
	cout << "This is my grandson.\n";
	Sleep(150);
	cout << "He's been your rival since you've been a baby.\n";
	Sleep(150);
	cout << "...Erm, what is his name again?\n";
	cout << "Name: ";
	cin >> rivalname;
	cout << "Thats right! I remember now! His name is " << rivalname << "\n";
	Sleep(150);
	cout << username << "! Your very own Pokemon legend is about to unfold!\n";
	Sleep(150);
	cout << "A world of dreams and adventures with Pokemon awaits! Let's go!\n\n";
	Sleep(150);

	cout << "To start, pick your 3 starter Pokemon!\n";
	do {
		cout << "Please pick from the options below - (You have " << count << " picks left)\n";
		cout << "1. Bulbasaur\n";
		cout << "2. Charmander\n";
		cout << "3. Pikachu\n";
		cout << "4. Squirtle\n";
		cout << "5. Learn more about the pokemon\n";
		cin >> userinput;

		switch (userinput) {
		case 1:
			userinput = BULBASAUR;
			pickedPokemon = true;
			break;
		case 2:
			userinput = CHARMANDER;
			pickedPokemon = true;
			break;
		case 3:
			userinput = PIKACHU;
			pickedPokemon = true;
			break;
		case 4:
			userinput = SQUIRTLE;
			pickedPokemon = true;
			break;
		case 5:
			// ADD POKEMON DESCRIPTIONS
			cout << "WIP\n";
			break;
		default:
			cout << "Invalid input! Please try again!\n";
			break;
		}

		if (pickedPokemon) {
			if (pokeChoices.size() > 0) {
				for (int i = 0; i < pokeChoices.size(); i++) {
					if (pokeChoices[i] == userinput) {
						cout << "Pokemon already picked!\n";
						check = true;
					}
				}
			}
			if (check == false) {
				pokeChoices.push_back(userinput);
				count = count - 1;
				cout << "Added " << poke_data.names[userinput] << " to your team!\n";
			}
			check = false;
		}
		pickedPokemon = false;

		cout << "Your current pokemon are: ";
		if (pokeChoices.size() > 0) {
			for (int i = 0; i < pokeChoices.size(); i++) {
				cout << poke_data.names[pokeChoices[i]] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "None! \n";
		}
		cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
	} while (count > 0);

	// Initalize Pokemon & Trainers
	Pokemon* userPokemon[3];
	int moves[4] = { -1,-1,-1,-1 };

	// Create 3 user Pokemon
	for (int i = 0; i < 3; i++) {
		// Create 4 moves
		for (int j = 0; j < 4; j++) {
			moves[j] = generate_move(pokeChoices[i], moves[0], moves[1], moves[2]);
		}
		userPokemon[i] = new Pokemon(pokeChoices[i], 80, 100, pokeChoices[i], moves[0], moves[1], moves[2], moves[3]);		// All user Pokemon have 80 HP and 100 PP
		// Reset move array to -1
		for (int k = 0; k < 4; k++) {
			moves[k] = -1;
		}
	}
	User* user = new User(username, 1000, 0, 0, 0, 0, *userPokemon[0], *userPokemon[1], *userPokemon[2]);

	Pokemon* enemyPokemon[9];
	for (int i = 0; i < 9; i++) {
		enemyPokemon[i] = generate_pokemon();
	}
	Trainer* opponent1 = new Trainer("Brock", 1, 1, 1, *enemyPokemon[0], *enemyPokemon[1], *enemyPokemon[2]);
	Trainer* opponent2 = new Trainer("Misty", 2, 2, 2, *enemyPokemon[3], *enemyPokemon[4], *enemyPokemon[5]);
	Trainer* opponent3 = new Trainer(rivalname, 3, 3, 3, *enemyPokemon[6], *enemyPokemon[7], *enemyPokemon[8]);
	
	// Loop until user defeats all 3 trainers (or loses)
	do {
		// Play vs each trainer, increment level for each opponent defeated

		// Main Menu
		cout << "What would you like to do?\n";
		cout << "1. Go to the Mart\n";
		cout << "2. Battle other trainers\n";
		cout << "3. Catch a pokemon\n";
		cin >> userinput;

		// TODO: Shift balance editing over to User class
		if (userinput == 1) {
			cout << "Hi there! How can I help you?\n";
			while (1) {
				cout << "Current balance: $" << user->show_balance() << "\n";
				cout << "1. Poke Ball - $200 - Current Supply: " << user->show_pokeball() << "\n";
				cout << "2. Potion - $100 - Current Supply: " << user->show_potion() << "\n";
				cout << "3. Elixer - $150 - Current Supply: " << user->show_elixir() << "\n";
				cout << "4. Revive - $300 - Current Supply: " << user->show_revive() << "\n";
				cout << "5. Exit\n";
				cin >> userinput;
				if (userinput == 1) {
					if (bal < 200) {
						cout << "You don't have enough money!\n";
					}
					else {
						cout << "You purchased a Poke Ball\n";
						bal = bal - 200;
						user->buy_pokeball();
					}
				}
				else if (userinput == 2) {
					if (bal < 100) {
						cout << "You don't have enough money!\n";
					}
					else {
						cout << "You purchased a Potion\n";
						bal = bal - 100;
						user->buy_potion();
					}
				}
				else if (userinput == 3) {
					if (bal < 150) {
						cout << "You don't have enough money!\n";
					}
					else {
						cout << "You purchased an elixer\n";
						bal = bal - 150;
						user->buy_elixir();
					}
				}
				else if (userinput == 4) {
					if (bal < 300) {
						cout << "You don't have enough money!\n";
					}
					else {
						cout << "You purchased a revive\n";
						bal = bal - 300;
						user->buy_revive();
					}
				}
				else if (userinput == 5) {
					cout << "Thanks for swinging by!\n";
					break;
				}
				else {
					cout << "Invalid input, try again!\n";
				}
				cout << "\n";
			}
		}

		else if (userinput == 2) {
			switch (level) {
			case 1:
				fightTrainer(*user, *opponent1, userDefeated);
				break;
			case 2:
				fightTrainer(*user, *opponent2, userDefeated);
				break;
			case 3:
				fightTrainer(*user, *opponent3, userDefeated);
				break;
			}

			if (userDefeated) {
				cout << "You lost!" << endl;
				break;
			}
			else
				level++;

		}

		else if (userinput == 3) {
			if (user->show_pokeball() > 0) {
				randPokemon = generate_pokemon();
				while (1) {
					cout << "You encountered a " << randPokemon->show_name() << "!\n";
					cout << "Would you like the chance to catch it?\n";
					cout << "(You will use one Pokeball and replace one of your pokemon!)\n";
					cout << "1. Yes!\n";
					cout << "2. I'll pass\n";
					cin >> userinput;
					if (userinput == 1) {
						user->use_pokeball();
						if (level == 1)
							chance = rand() % 150 + 1;		// 66% catch rate
						else if (level == 2)
							chance = rand() % 100 + 1;		// 50% catch rate
						else if (level == 3)
							chance = rand() % 75 + 1;		// 33% catch rate
						if (chance >= 50) {
							cout << "You caught a wild " << randPokemon->show_name() << "!\n";
							// ADD FUNCTIONALITY THAT REMOVES ONE POKEMON FROM USER (USERS CHOICE) AND ADDS THIS ONE
						}
						else {
							cout << "You didn't catch it!\n";
						}
						break;
					}
					else if (userinput == 2) {
						break;
					}
					else {
						cout << "Invalid input!\n";
					}
				}
			}
			else {
				cout << "You do not have enough Pokeballs! Go to the Mart to buy more!\n";
			}
		}
		
		else {
			cout << "Invalid input! Please try again\n";
		}
		cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";

	} while (level <= 3);

	return 0;
}