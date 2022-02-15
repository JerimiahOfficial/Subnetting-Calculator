#pragma once
#include <string>
#include <bitset>
#include <vector>

namespace Util {
	extern bool checkAlpha(std::string ip);
	extern std::string toBinary(std::string num);
	extern std::vector<std::string> split(const std::string& i_str, const std::string& i_delim);
}