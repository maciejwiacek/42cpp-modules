#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path): _dbPath(path) { }

BitcoinExchange::~BitcoinExchange() { }

time_t BitcoinExchange::getDate(std::string dateString) {
	tm tm = {};

	std::istringstream ss(dateString);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail()) {
		return 1;
	}
	return mktime(&tm);
}

void BitcoinExchange::openFile(const std::string path, std::ifstream& file) {
	file.open(path);
	if (!file.is_open()) {
		std::cout << "Couldn't open a " << file << std::endl;
		std::exit(1);
	}
}

// DEBUGGING

void printDb(const std::map<time_t, float>& db) {
	std::map<time_t, float>::const_iterator it;
	for (it = db.begin(); it != db.end(); ++it) {
		time_t key = it->first;
		float value = it->second;

		std::tm* timeInfo = std::localtime(&key);
		std::cout << "Date: " << std::put_time(timeInfo, "%Y-%m-%d") << "\t" << "Price: " << value << std::endl;
	}
}

time_t BitcoinExchange::findClosestDate(const std::string& dateString) {
	time_t targetDate = this->getDate(dateString);
	if (targetDate == 1) {
		return 1;
	}

	// Find first element that is not less than targetDate
	std::map<time_t, float>::const_iterator lower = this->_db.lower_bound(targetDate);

	// If this element is first item of map, return it as the closest
	if (lower == this->_db.begin()) {
		return lower->first;
		// If this element is last item of map, return the previous one
	} else if (lower == this->_db.end()) {
		return std::prev(lower)->first;
	} else {
		// If this element is in the middle of map, compare it with the previous
		std::map<time_t, float>::const_iterator prev = std::prev(lower);

		// Check absolute difference between previous and next to targetDate and choose the closest
		if (difftime(lower->first, targetDate) == 0) {
			return lower->first;
		} else {
			return prev->first;
		}
	}
}

float BitcoinExchange::getPrice(time_t date) {
	std::map<time_t, float>::const_iterator it = this->_db.find(date);
	if (it == this->_db.end()) {
		std::cerr << "No data for this date\n";
		return -1;
	}
	return it->second;
}

void BitcoinExchange::fillDb() {
	std::ifstream file;
	openFile(this->_dbPath, file);

	std::string line;
	getline(file, line);
	while(getline(file, line)) {
		if (line.empty()) break;

		std::string::size_type location = line.find(',');
		if (location == std::string::npos) {
			std::cout << "Invalid file format\n";
			break;
		}

		std::string date = line.substr(0, location);
		time_t dateFormatted = getDate(date);

		std::string price = line.substr(location + 1, line.length());
		this->_db[dateFormatted] = std::stof(price);
	}
	file.close();
//	printDb(this->_db);
}
