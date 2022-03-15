#include "bfc.hpp"

int checkCompiler(int argc, char *argv[]) {
	int retval = -1;
	int clang = 1;
	int gcc = 1;
	cxxopts::Options options("BFC", "A brainF Compiler");
	options.add_options()
		("version", "version")
		("v,verbose", "verbose")
		("c,config", "config", cxxopts::value<std::string>()->default_value(""));
	auto  optres = options.parse(argc, argv);
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc-compiler-test] Testing for clang..." << std::endl;
	}
	if (OS == 0 || OS == 1) {
		clang = system("clang --version > nul 2> nul");
	} else {
		clang = system("clang --version > /dev/null 2> /dev/null");
	}
	if (clang == 0) {
		if (optres["v"].as<bool>()) {
			std::cout << "[bfc-compiler-test] \033[32mclang present.\033[0m" << std::endl;
		}
		retval = 1;
	}
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc-compiler-test] Testing for gcc..." << std::endl;
	}
	if (OS == 0 || OS == 1) {
		gcc = system("gcc --version > nul 2> nul");
	} else {
		gcc = system("gcc --version > /dev/null 2> /dev/null");
	}
	if (gcc == 0) {
		if (optres["v"].as<bool>()) {
			std::cout << "[bfc-compiler-test] \033[32mgcc present.\033[0m" << std::endl;
		}
		retval = 2;
	}
	return retval;
}