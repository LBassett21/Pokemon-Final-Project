#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include "Pokemon.h"
#include "Trainer.h"
#include<windows.h> 
//#include "PokemonData.h"
//#include "Moves.h"

using std::cout;
using std::cin;
using std::setprecision;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;
using std::vector;

// Pokemon Define names
#define	BULBASAUR	0
#define	IVYSAUR		1
#define	VENUSAUR	2
#define	CHARMANDER	3
#define	CHARMELEON	4
#define	CHARIZARD	5
#define	SQUIRTLE	6
#define	WARTORTLE	7
#define	BLASTOISE	8
#define	PIDGEY		9
#define	PIDGEOTTO	10
#define	PIDGEOT		11
#define	RATTATA		12
#define	RATICATE	13
#define	SPEAROW		14
#define	FEAROW		15
#define	PIKACHU		16
#define	RAICHU		17
#define	VULPIX		18
#define	NINETAILS	19
#define	ODDISH		20
#define	GLOOM		21
#define	VILEPLUME	22
#define	PARAS		23
#define	PARASECT	24
#define	MEOWTH		25
#define	PERSIAN		26
#define	PSYDUCK		27
#define	GOLDUCK		28
#define	GROWLITHE	29
#define	ARCANINE	30
#define	POLIWAG		31
#define	POLIWHIRL	32
#define	POLIWRATH	33
#define	BELLSPROUT	34
#define	WEEPINBELL	35
#define	VICTREEBELL	36
#define	TENTACOOL	37
#define	TENTACRUEL	38
#define	GEODUDE		39
#define	GRAVLER		40
#define	GOLEM		41
#define	PONYTA		42
#define	RAPIDASH	43
#define	SLOWPOKE	44
#define	SLOWBRO		45
#define	MAGNEMITE	46
#define	MAGNETON	47
#define	DODUO		48
#define	DODRIO		49
#define	SEEL		50
#define	DEWGONG		51
#define	SHELLDER	52
#define	CLOYSTER	53
#define	ONIX		54
#define	KRABBY		55
#define	KINGLER		56
#define	EXEGGCUTE	57
#define	EXEGGUTOR	58
#define	CUBONE		59
#define	MAROWAK		60
#define	RYHORN		61
#define	RHYDON		62
#define	TANGELA		63
#define	HORSEA		64
#define	SEADRA		65
#define	GOLDEEN		66
#define	SEAKING		67
#define	STARYU		68
#define	STARMIE		69
#define	ELECTRABUZZ	70
#define	MAGMAR		71
#define	MAGIKARP	72
#define	GYRADOS		73
#define	LAPRAS		74
#define	DITTO		75
#define	EEVEE		76
#define	VAPOREON	77
#define	JOLTEON		78
#define	FLAREON		79
#define	OMANYTE		80
#define	OMASTAR		81
#define	KABUTO		82
#define	KABUTOPS	83
#define	SNORLAX		84

// Pokemon Types
#define	NORMAL		1
#define	WATER		2
#define GRASS		3
#define	GROUND		4
#define	FIRE		5
#define	ELECTRIC	6

// Pokemon string names
struct {
	string names[85] = {
		"BULBASAUR", "IVYSAUR", "VENUSAUR", "CHARMANDER", "CHARMELEON",
		"CHARIZARD", "SQUIRTLE", "WARTORTLE", "BLASTOISE", "PIDGEY",
		"PIDGEOTTO", "PIDGEOT", "RATTATA", "RATICATE", "SPEAROW",
		"FEAROW", "PIKACHU", "RAICHU", "VULPIX", "NINETAILS",
		"ODDISH", "GLOOM", "VILEPLUME", "PARAS", "PARASECT",
		"MEOWTH", "PERSIAN", "PSYDUCK", "GOLDUCK", "GROWLITHE",
		"ARCANINE", "POLIWAG", "POLIWHIRL", "POLIWRATH", "BELLSPROUT",
		"WEEPINBELL", "VICTREEBELL", "TENTACOOL", "TENTACRUEL", "GEODUDE",
		"GRAVLER", "GOLEM", "PONYTA", "RAPIDASH", "SLOWPOKE",
		"SLOWBRO", "MAGNEMITE", "MAGNETON", "DODUO", "DODRIO",
		"SEEL", "DEWGONG", "SHELLDER", "CLOYSTER", "ONIX",
		"KRABBY", "KINGLER", "EXEGGCUTE", "EXEGGUTOR", "CUBONE",
		"MAROWAK", "RYHORN", "RHYDON", "TANGELA", "HORSEA",
		"SEADRA", "GOLDEEN", "SEAKING", "STARYU", "STARMIE",
		"ELECTRABUZZ", "MAGMAR", "MAGIKARP", "GYRADOS", "LAPRAS",
		"DITTO", "EEVEE", "VAPOREON", "JOLTEON", "FLAREON",
		"OMANYTE", "OMASTAR", "KABUTO", "KABUTOPS", "SNORLAX"
	};
} poke_names;

struct {
	string move_names[14] = {
		"QUICK ATTACK", "TACKLE", "MEGA KICK", "FURY ATTACK", "HYDRO PUMP", "BUBBLE BEAM", "FLAMETHROWER", "FIRE SPIN",
		"RAZOR LEAF", "VINE WHIP", "EARTHQUAKE", "DIG", "THUNDER PUNCH", "THUNDERBOLT"
	};
	int damage[14] = { 10, 10, 20, 20, 30, 35, 40, 50, 35, 40, 60, 50, 35, 40 };	// Damage per move
	int pp[14] = { 10, 10, 20, 20, 30, 35, 40, 50, 35, 40, 60, 50, 35, 40 };	// PP cost per move
	int type[14] = { NORMAL, NORMAL, NORMAL, NORMAL, WATER, WATER, FIRE, FIRE, GRASS, GRASS, GROUND, GROUND, ELECTRIC, ELECTRIC };
} poke_moves;



int main() {
	srand(time(0));
	int level = 1;
	int count = 3;
	int userinput;
	vector <int> pokeChoices;
	bool check = false;
	float bal = 1000;
	string username;
	string rivalname;
	int randPokemon = 0;
	int chance = 0;
	int randEnemyPokemon = 0;

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
	cout << "A world of dreams and adventures with Pokemon awaits! Lets go!\n\n";
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

		if (userinput == 1) {
			if (pokeChoices.size() > 0) {
				for (int i = 0; i < pokeChoices.size(); i++) {
					if (pokeChoices[i] == BULBASAUR) {
						cout << "Pokemon already picked!\n";
						check = true;
					}
				}
			}
			if (check == false) {
				pokeChoices.push_back(BULBASAUR);
				count = count - 1;
				cout << "Added Bulbasaur to your team!\n";
			}
			check = false;
		}
		else if (userinput == 2) {
			if (pokeChoices.size() > 0) {
				for (int i = 0; i < pokeChoices.size(); i++) {
					if (pokeChoices[i] == CHARMANDER) {
						cout << "Pokemon already picked!\n";
						check = true;
					}
				}
			}
			if (check == false) {
				pokeChoices.push_back(CHARMANDER);
				count = count - 1;
				cout << "Added Charmander to your team!\n";
			}
			check = false;
		}
		else if (userinput == 3) {
			if (pokeChoices.size() > 0) {
				for (int i = 0; i < pokeChoices.size(); i++) {
					if (pokeChoices[i] == PIKACHU) {
						cout << "Pokemon already picked!\n";
						check = true;
					}
				}
			}
			if (check == false) {
				pokeChoices.push_back(PIKACHU);
				count = count - 1;
				cout << "Added Pikachu to your team!\n";
			}
			check = false;
		}
		else if (userinput == 4) {
			if (pokeChoices.size() > 0) {
				for (int i = 0; i < pokeChoices.size(); i++) {
					if (pokeChoices[i] == SQUIRTLE) {
						cout << "Pokemon already picked!\n";
						check = true;
					}
				}
			}
			if (check == false) {
				pokeChoices.push_back(SQUIRTLE);
				count = count - 1;
				cout << "Added Squirtle to your team!\n";
			}
			check = false;
		}
		else if (userinput == 5) {
			// ADD POKEMON DESCRIPTIONS

			cout << "WIP\n";
		}
		else {
			cout << "Invalid input! Please try again!\n";
		}

		cout << "Your current pokemon are: ";
		if (pokeChoices.size() > 0) {
			for (int i = 0; i < pokeChoices.size(); i++) {
				cout << poke_names.names[pokeChoices[i]] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "None! \n";
		}

		cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n";
	} while (count > 0);

	// Will uncomment once constructors are written
	Pokemon* poke1 = new Pokemon(pokeChoices[0], 100, 150, 1, 3, 8, 9);
	Pokemon* poke2 = new Pokemon(pokeChoices[1], 100, 150, 3, 4, 5, 6);
	Pokemon* poke3 = new Pokemon(pokeChoices[2], 100, 150, 1, 2, 12, 13);
	Trainer* user = new Trainer(username, 0, 0, 0, 0, *poke1, *poke2, *poke3);

	Trainer* fighter = new Trainer("KF", 1, 1, 1, 1, *poke1, *poke2, *poke3);
	
	// Loop until user defeats all 3 trainers (or loses)
	do {
		// Play vs each trainer, increment level for each opponent defeated
		cout << "What would you like to do?\n";
		cout << "1. Go to the Mart\n";
		cout << "2. Battle other trainers\n";
		cout << "3. Catch a pokemon\n";
		cin >> userinput;

		if (userinput == 1) {
			cout << "Hi there! How can I help you?\n";
			while (1) {
				cout << "Current balance: $" << bal << "\n";
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
			cout << fighter->show_name() << " wants to fight!\n";
			randEnemyPokemon = rand() % 3 + 1;
			//cout << fighter->show_name() << " sent out " << fighter->

			// ADD WHOLE FIGHTING GAME

		}

		else if (userinput == 3) {
			if (user->show_pokeball() > 0) {
				if (level == 1) {
					randPokemon = rand() % 20 + 1;
					while (1) {
						cout << "You encountered a " << poke_names.names[randPokemon] << "!\n";
						cout << "Would you like the chance to catch it?\n";
						cout << "(You will use one Pokeball and replace one of your pokemon!)\n";
						cout << "1. Yes!\n";
						cout << "2. I'll pass\n";
						cin >> userinput;
						if (userinput == 1) {
							user->use_pokeball();
							chance = rand() % 100 + 1;
							if (chance >= 50) {
								cout << "You caught a wild " << poke_names.names[randPokemon] << "!\n";
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
				else if (level == 2) {
					randPokemon = rand() % 20 + 1;
					while (1) {
						cout << "You encountered a " << poke_names.names[randPokemon] << "!\n";
						cout << "Would you like the chance to catch it?\n";
						cout << "(You will use one Pokeball and replace one of your pokemon!)\n";
						cout << "1. Yes!\n";
						cout << "2. I'll pass\n";
						cin >> userinput;
						if (userinput == 1) {
							user->use_pokeball();
							chance = rand() % 100 + 1;
							if (chance >= 50) {
								cout << "You caught a wild " << poke_names.names[randPokemon] << "!\n";
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
				else if (level == 3) {
					randPokemon = rand() % 20 + 1;
					while (1) {
						cout << "You encountered a " << poke_names.names[randPokemon] << "!\n";
						cout << "Would you like the chance to catch it?\n";
						cout << "(You will use one Pokeball and replace one of your pokemon!)\n";
						cout << "1. Yes!\n";
						cout << "2. I'll pass\n";
						cin >> userinput;
						if (userinput == 1) {
							user->use_pokeball();
							chance = rand() % 100 + 1;
							if (chance >= 50) {
								cout << "You caught a wild " << poke_names.names[randPokemon] << "!\n";
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