#include "BitcoinExchange.hpp"

bool isProperDate(std::string &date) {
	date.erase(date.find_last_not_of(" \t\n\r\f\v") + 1);
	if (date.size() != 10) {
		std::cout << "Invalid date format: " << date << std::endl;
		return false;
	}
	return true;
}

float getAmount(std::string &line) {
	std::string amount = line.substr(line.find('|') + 1);
	amount.erase(amount.find_last_not_of(" \t\n\r\f\v") + 1);

	float amountFloat = std::stof(amount);
	if (amountFloat < 0) {
		std::cout << "Error: not a positive number.\n";
		return -1;
	} else if (amountFloat > 1000) {
		std::cout << "Error: too large a number.\n";
		return -1;
	}
	return amountFloat;
}

void processLine(std::string& line, BitcoinExchange& btc) {
	std::string date = line.substr(0, line.find('|'));
	if (!isProperDate(date)) {
		return;
	}

	time_t closestDate = btc.findClosestDate(line);
	if (closestDate == 1) {
		std::cout << "Couldn't find a date: " << date << std::endl;
		return;
	}

	float amount = getAmount(line);
	if (amount < 0 || amount > 1000) {
		return;
	}

	float price = btc.getPrice(closestDate);
	if (price == -1) {
		std::cout << "No data for this date\n";
		return;
	}

	if (amount == static_cast<int>(amount)) {
		std::cout << date << " => " << static_cast<int>(amount) << " = " << std::fixed << std::setprecision(2) << (amount * price) << " (BTC)\n";
	} else {
		std::cout << date << " => " << std::fixed << std::setprecision(2) << amount << " = " << std::fixed << std::setprecision(2) << (amount * price) << " (BTC)\n";
	}
}

void processFile(std::ifstream& file, BitcoinExchange& btc) {
	std::string line;

	getline(file, line);
	while (getline(file, line)) {
		processLine(line, btc);
	}
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage: ./btc <filepath>\n";
		return 1;
	}
	BitcoinExchange btc("data.csv");
	btc.fillDb();

	std::ifstream iFile;
	btc.openFile(av[1], iFile);
	processFile(iFile, btc);
	iFile.close();

	(void)av;
	return 0;
}