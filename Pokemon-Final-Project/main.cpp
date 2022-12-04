#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

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


	// Loop until user defeats all 3 trainers (or loses)
	do {
		// Play vs each trainer, increment level for each opponent defeated



	} while (level <= 3);

	return 0;
}