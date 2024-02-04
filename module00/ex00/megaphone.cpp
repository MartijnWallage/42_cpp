#include <iostream>
#include <cctype>

int	main(int argc, char* argv[]) {

	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	
		return 0;
	}

	for (int i = 1; i < argc; ++i) {
		std::string input = argv[i];

		for (char &c : input) {
			c = std::toupper(c);
		}

		std::cout << input;
	}
	std::cout << std::endl;

	return 0;
}