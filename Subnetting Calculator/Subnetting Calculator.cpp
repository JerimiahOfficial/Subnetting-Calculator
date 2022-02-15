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
#include <iostream>

class IP {
	public:
		std::string Ip;
		std::string BinaryIp;
		std::string NetClass;
		std::string DefaultMask;
		std::string SubNetMask;
		int NumOfBits;
};

void SubnetCalculator() {
	std::cout << "Subnetting calculator" << std::endl << std::endl;
	while (true) {
		IP ip;

		std::cout << "      Enter an ip: ";
		std::getline(std::cin, ip.Ip);

		if (!Util::checkAlpha(ip.Ip) || ip.Ip.size() <= 0) {
			std::cout << "Invalid ip address, try again." << std::endl;
			continue;
		}

		std::vector<std::string>segments = Util::split(ip.Ip, ".");
		ip.BinaryIp = Util::toBinary(segments[0]) + "." + Util::toBinary(segments[1]) + "." + Util::toBinary(segments[2]) + "." + Util::toBinary(segments[3]);
		ip.NumOfBits = (int)std::count(ip.BinaryIp.begin(), ip.BinaryIp.end(), '1');

		if (std::stoi(segments[0]) <= 126) {
			ip.NetClass = "A";
			ip.DefaultMask = "255.0.0.0";
		}
		else if (std::stoi(segments[0]) <= 191) {
			ip.NetClass = "B";
			ip.DefaultMask = "255.255.0.0";
		}
		else if (std::stoi(segments[0]) <= 223) {
			ip.NetClass = "C";
			ip.DefaultMask = "255.255.255.0";
		}
		else {
			ip.NetClass = "Unknown";
			ip.DefaultMask = "Unknown";
		}

		std::cout 
			<< "Binary equivalent: "	<< ip.BinaryIp		<< std::endl
			<< "   Number of bits: "	<< ip.NumOfBits		<< std::endl
			<< "    Network Class: "	<< ip.NetClass		<< std::endl
			<< "     Default mask: "	<< ip.DefaultMask	<< std::endl
			<< std::endl;

	}
}

int main() {
	SubnetCalculator();
	return 0;
}
