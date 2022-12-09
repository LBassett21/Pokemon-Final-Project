#pragma once
#include <string>
using std::string;

// Pokemon Define names
#define	BULBASAUR	1
#define	IVYSAUR		2
#define	VENUSAUR	3
#define	CHARMANDER	4
#define	CHARMELEON	5
#define	CHARIZARD	6
#define	SQUIRTLE	7
#define	WARTORTLE	8
#define	BLASTOISE	9
#define	PIDGEY		10
#define	PIDGEOTTO	11
#define	PIDGEOT		12
#define	RATTATA		13
#define	RATICATE	14
#define	SPEAROW		15
#define	FEAROW		16
#define	PIKACHU		17
#define	RAICHU		18
#define	VULPIX		19
#define	NINETAILS	20
#define	ODDISH		21
#define	GLOOM		22
#define	VILEPLUME	23
#define	PARAS		24
#define	PARASECT	25
#define	MEOWTH		26
#define	PERSIAN		27
#define	PSYDUCK		28
#define	GOLDUCK		29
#define	GROWLITHE	30
#define	ARCANINE	31
#define	POLIWAG		32
#define	POLIWHIRL	33
#define	POLIWRATH	34
#define	BELLSPROUT	35
#define	WEEPINBELL	36
#define	VICTREEBELL	37
#define	TENTACOOL	38
#define	TENTACRUEL	39
#define	GEODUDE		40
#define	GRAVLER		41
#define	GOLEM		42
#define	PONYTA		43
#define	RAPIDASH	44
#define	SLOWPOKE	45
#define	SLOWBRO		46
#define	MAGNEMITE	47
#define	MAGNETON	48
#define	DODUO		49
#define	DODRIO		50
#define	SEEL		51
#define	DEWGONG		52
#define	SHELLDER	53
#define	CLOYSTER	54
#define	ONIX		55
#define	KRABBY		56
#define	KINGLER		57
#define	EXEGGCUTE	58
#define	EXEGGUTOR	59
#define	CUBONE		60
#define	MAROWAK		61
#define	RYHORN		62
#define	RHYDON		63
#define	TANGELA		64
#define	HORSEA		65
#define	SEADRA		66
#define	GOLDEEN		67
#define	SEAKING		68
#define	STARYU		69
#define	STARMIE		70
#define	ELECTRABUZZ	71
#define	MAGMAR		72
#define	MAGIKARP	73
#define	GYRADOS		74
#define	LAPRAS		75
#define	DITTO		76
#define	EEVEE		77
#define	VAPOREON	78
#define	JOLTEON		79
#define	FLAREON		80
#define	OMANYTE		81
#define	OMASTAR		82
#define	KABUTO		83
#define	KABUTOPS	84
#define	SNORLAX		85

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
	int pp[14] =	 { 10, 10, 20, 20, 30, 35, 40, 50, 35, 40, 60, 50, 35, 40 };	// PP cost per move
	int type[14] = NORMAL, NORMAL, NORMAL, NORMAL, WATER, WATER, FIRE, FIRE, GRASS, GRASS, GROUND, GROUND, ELECTRIC, ELECTRIC;
} poke_moves;
