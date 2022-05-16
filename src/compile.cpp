#include "bfc.hpp"

void compile(std::string fn, int compiler, bool isVerbose) {
	int res = -1;
	std::string invoc;
	switch (compiler) {
		case 1:
			if (isVerbose) {
				std::cout << "\033[34m[bfc-compiler-internal] Using clang...\033[0m" << std::endl;
			}
			// Clang
			invoc = "clang -o ";
			invoc += fn;
			invoc += " executable.cpp";
			res = std::system(invoc.c_str());
			break;
		case 2:
			if (isVerbose) {
				std::cout << "\033[34m[bfc-compiler-internal] Using gcc...\033[0m" << std::endl;
			}
			// gcc
			invoc = "gcc -o ";
			invoc += fn;
			invoc += " executable.cpp";
			res = std::system(invoc.c_str());
			break;
		default:
			std::cerr << "\033[31m[bfc-compiler-internal] No C compiler is present on the system. BFC can't compile. Exiting...\033[0m" << std::endl;
			_Exit(1);
			break;
	}
	if (res/256 == 1) {
		std::cout << "\033[31m[bfc] An error occured during compiling.\033[0m" << std::endl;
		res = std::system("rm executable.cpp");
		_Exit(1);
	}
}