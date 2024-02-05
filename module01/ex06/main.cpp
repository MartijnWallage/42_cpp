#include "Harl.hpp"
#include <iostream>
#include <string>
#include <map>

int main(int argc, char *argv[]) {
    Harl 						harl;
	std::string					level;
	std::map<std::string, int>	levelMap;
	
	levelMap["DEBUG"] = 0;
	levelMap["INFO"] = 1;
	levelMap["WARNING"] = 2;
	levelMap["ERROR"] = 3;

	if (argc != 2) {
		std::cerr << "Please provide one of the four levels as an argument" << std::endl;
		return 1;
	}

	level = argv[1];
	switch (levelMap[level]) {
		case 0:
			harl.complain(level);
		case 1:
			harl.complain(level);
		case 2:
			harl.complain(level);
		case 3:
			harl.complain(level);
	}

    return 0;
}
