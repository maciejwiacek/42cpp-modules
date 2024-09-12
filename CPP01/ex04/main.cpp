#include <iostream>
#include <fstream>
#include <sstream>

void replace(std::string str, char **av) {
	std::ofstream outfile;

	outfile.open(((std::string)av[1] + ".replace").c_str());
	if (outfile.fail()) {
		std::cout << "Something is wrong with outfile!" << std::endl;
		return;
	}
	for (int i = 0; i < (int)str.size(); i++) {
		if ((int)str.find(av[2], i) == i) {
			outfile << av[3];
		} else {
			outfile << str[i];
		}
	}
	outfile.close();
}

int main(int ac, char **av) {
	std::ifstream infile;
	std::stringstream ss;
	if (ac != 4) {
		std::cout << "Wrong input!!! Correct usage is:" << std::endl;
		std::cout << "./betterSed <filename> <word_to_replace> <new_word>" << std::endl;
		return 1;
	}
	infile.open(av[1]);
	if (infile.fail()) {
		std::cout << "Something is wrong with infile!" << std::endl;
		return 1;
	}
	ss << infile.rdbuf();
	infile.close();
	replace(ss.str(), av);
	return (0);
}