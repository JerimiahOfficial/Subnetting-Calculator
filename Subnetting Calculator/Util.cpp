/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣄⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣴⣿⡄⠀⠀⠀⠀⠀⢀⡀
⠀⠀⠀⠀⠀⠀⠀⠀⠰⣶⣾⣿⣿⣿⣿⣿⡇⠀⢠⣷⣤⣶⣿⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣀⣿⣿⣿⣿⣿⣧⣀
⠀⠀⠀⠀⠀⠀⠀⣷⣦⣀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃
⠀⠀⠀⠀⢲⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁
⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁
⠀⠀⠀⠀⠀⠚⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⠿⠂
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⢻⣿⣿⡿⠛⠉⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠘⠋⠁⠀⠀⣧

Created by Jerimiah
https://github.com/JerimiahOfficial/
https://github.com/JerimiahOfficial/Rule34-Downloader
*/

#include "Util.h"

namespace Util {
	bool checkAlpha(std::string ip) {
		for (auto s : ip)
			if (std::isalpha(s))
				return false;

		return true;
	}

	std::string toBinary(std::string num) {
		return std::bitset<8>(std::stoi(num)).to_string();
	}

	std::vector<std::string> split(const std::string& i_str, const std::string& i_delim) {
		std::vector<std::string> result;
		size_t found = i_str.find(i_delim);
		size_t startIndex = 0;

		while (found != std::string::npos) {
			result.push_back(std::string(i_str.begin() + startIndex, i_str.begin() + found));
			startIndex = found + i_delim.size();
			found = i_str.find(i_delim, startIndex);
		}

		if (startIndex != i_str.size())
			result.push_back(std::string(i_str.begin() + startIndex, i_str.end()));

		return result;
	}
}
