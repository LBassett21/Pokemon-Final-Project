#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "Pokemon.h"
#include "Trainer.h"
#include "PokemonData.h"
#include "Moves.h"

using std::cout;
using std::cin;
using std::setprecision;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;

int main() {
	int level = 1;

	string username;
	cout << "Please enter your Trainer's name: ";
	cin >> username;

	// Will uncomment once constructors are written
	//Pokemon* poke1 = new Pokemon("VENUSAUR", 100, 150, 1, 3, 8, 9);
	//Pokemon* poke2 = new Pokemon("CHARIZARD", 100, 150, 3, 4, 5, 6);
	//Pokemon* poke3 = new Pokemon("PIKACHU", 100, 150, 1, 2, 12, 13);
	//Trainer* user = new Trainer(username, 3, 3, 3, poke1, poke2, poke3);

	// Loop until user defeats all 3 trainers (or loses)
	do {
		// Play vs each trainer, increment level for each opponent defeated
		


	} while (level <= 3);

	return 0;
}