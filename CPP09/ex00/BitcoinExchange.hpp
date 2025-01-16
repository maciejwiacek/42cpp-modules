#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <sstream>

class BitcoinExchange {
	private:
		std::string _dbPath;
		std::map<time_t, float> _db;
	public:
		BitcoinExchange(std::string path);
		~BitcoinExchange();

		time_t getDate(std::string dateString);
		void fillDb();
		void openFile(std::string path, std::ifstream& file);
		time_t findClosestDate(const std::string& dateString);
		float getPrice(time_t date);
};