#include "bfc.hpp"
#include "cxxopts.hpp"

int checkCompiler(int argc, char *argv[]) {
	int retval = -1;
	int clang = 1;
	int gcc = 1;
	cxxopts::Options options("BFC", "A brainF Compiler");
	options.add_options()
		("version", "version")
		("i,info", "Print info")
		("v,verbose", "verbose")
		("e,execute", "execute")
		("r,remove-executable", "remove-executable")
		("o", "Output file name", cxxopts::value<std::string>()->default_value("executable"))
		("c,config", "config", cxxopts::value<std::string>()->default_value(""));
	auto  optres = options.parse(argc, argv);
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc-compiler-test] Testing for clang...\033[0m" << std::endl;
	}
	if (OS == 0 || OS == 1) {
		clang = system("clang --version > nul 2> nul");
	} else {
		clang = system("clang --version > /dev/null 2> /dev/null");
	}
	if (clang == 0) {
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc-compiler-test] \033[32mclang present.\033[0m" << std::endl;
		}
		retval = 1;
	}
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc-compiler-test] Testing for gcc...\033[0m" << std::endl;
	}
	if (OS == 0 || OS == 1) {
		gcc = system("gcc --version > nul 2> nul");
	} else {
		gcc = system("gcc --version > /dev/null 2> /dev/null");
	}
	if (gcc == 0) {
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc-compiler-test] \033[0m\033[32mgcc present.\033[0m" << std::endl;
		}
		retval = 2;
	}
	return retval;
}