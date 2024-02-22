/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:21:02 by mwallage          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:03 by mwallage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	replaceStr(const std::string& source, const std::string& from, const std::string& to) {
	std::string	result;
	std::size_t	pos = 0;

	while (pos < source.length()) {
		std::size_t	found = source.find(from, pos);
		if (found != std::string::npos) {
			result += source.substr(pos, found - pos) + to;
			pos = found + from.length();
		} else {
			result += source.substr(pos);
			break ;
		}
	}

	return result;
}

int	main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Format: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return 1;
	}

	std::string	filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string	content;
	std::string	line;

	std::ifstream	fin;
	fin.open(argv[1]);
	if (!fin.is_open()) {
		std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
		return 1;
	}

	while (getline(fin, line)) {
		content += line + "\n";
	}
	fin.close();

	std::string	replacedContent = replaceStr(content, s1, s2);

	std::ofstream	fout;
	fout.open((filename + ".replace").c_str());
	if (!fout.is_open()) {
		std::cerr << "Error: could not create file '" << filename << ".replace'" << std::endl;
		return 1;
	}

	fout << replacedContent;
	fout.close();

	return 0;
}