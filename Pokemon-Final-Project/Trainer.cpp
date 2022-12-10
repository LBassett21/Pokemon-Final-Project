#include "Trainer.h"

Trainer::Trainer() {

}

Trainer::Trainer(string in_name, int num_pb, int num_p, int num_e, int num_r, Pokemon p1, Pokemon p2, Pokemon p3) {
	name = in_name;
	num_pokeball = num_pb;
	num_potion = num_p;
	num_elixir = num_e;
	num_revive = num_r;
	party[0] = &p1;
	party[1] = &p2;
	party[2] = &p3;
}



string Trainer::show_name() {
	return name;
}
int Trainer::show_pokeball() {
	return num_pokeball;
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
// TODO: create methods to show attributes of each Pokemon

// TODO: create methods for using moves / other menu options

void Trainer::buy_pokeball() {
	num_pokeball = num_pokeball + 1;
}
void Trainer::buy_potion() {
	num_potion = num_potion + 1;
}
void Trainer::buy_elixir() {
	num_elixir = num_elixir + 1;
}
void Trainer::buy_revive() {
	num_revive = num_revive + 1;
}
void Trainer::use_pokeball() {
	num_pokeball = num_pokeball - 1;
}
void Trainer::use_potion() {
	num_potion = num_potion - 1;
}
void Trainer::use_elixir() {
	num_elixir = num_elixir - 1;
}
void Trainer::use_revive() {
	num_revive = num_revive - 1;
}