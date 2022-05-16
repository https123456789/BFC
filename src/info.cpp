#include "bfc.hpp"

namespace BFCInfo {
	std::string getInfo(void) {
		std::string s = "";
		s += versionTop;
		s += ".";
		s += versionL2;
		s += ".";
		s += versionL3;
		return s;
	}
	std::string getPlatform(void) {
		std::string s = "";
		if (ARCHITECTURE) {
			s += "arm ";
		} else {
			s += "x86 ";
		}
		switch (OS) {
			case 0:
			case 1:
				s += "Windows";
				break;
			case 2:
			case 3:
				s += "Unix";
				break;
			case 4:
			case 5:
				s += "Apple Mac OS";
				break;
			case 6:
				s += "Linux";
				break;
			default:
				s += "Unknown OS";
				break;
		}
		return s;
	}
}

void printInfo(void) {
	std::cout << "BFC Info:" << std::endl << "Version: " << BFCInfo::getInfo() << std::endl << "Target Platform: " << BFCInfo::getPlatform() << std::endl;
}