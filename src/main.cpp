#include <iostream>
#include <fstream>
#include <streambuf>
#include <chrono>
#include <thread>
#include <string>

#ifdef __x86_64__
#define ARCHITECTURE 0
#endif

#ifdef __arm__
#define ARCHITECTURE 1
#endif

#ifdef _WIN32
#ifdef OS
#undef OS
#endif
#define OS 0
#endif

#ifdef _WIN64
#ifdef OS
#undef OS
#endif
#define OS 1
#endif

#ifdef __unix
#ifdef OS
#undef OS
#endif
#define OS 2
#endif

#ifdef __unix__
#ifdef OS
#undef OS
#endif
#define OS 3
#endif

#ifdef __APPLE__
#ifdef OS
#undef OS
#endif
#define OS 4
#endif

#ifdef __MACH__
#ifdef OS
#undef OS
#endif
#define OS 5
#endif

#ifdef __linux__
#ifdef OS
#undef OS
#endif
#define OS 6
#endif


int checkCompiler() {
	int retval = -1;
	int clangpp = 1;
	int clang = 1;
	int gcc = 1;
	std::cout << "[bfc-compiler-test] Testing for clang++..." << std::endl;
	if (OS == 0 || OS == 1) {
		clangpp = system("clang++ --version > nul 2> nul");
	} else {
		clangpp = system("clang++ --version > /dev/null 2> /dev/null");
	}
	if (clangpp == 0) {
		std::cout << "[bfc-compiler-test] clang++ present." << std::endl;
		retval = 1;
	}
	std::cout << "[bfc-compiler-test] Testing for clang..." << std::endl;
	if (OS == 0 || OS == 1) {
		clang = system("clang --version > nul 2> nul");
	} else {
		clang = system("clang --version > /dev/null 2> /dev/null");
	}
	if (clang == 0) {
		std::cout << "[bfc-compiler-test] clang present." << std::endl;
		retval = 2;
	}
	std::cout << "[bfc-compiler-test] Testing for gcc..." << std::endl;
	if (OS == 0 || OS == 1) {
		gcc = system("gcc --version > nul 2> nul");
	} else {
		gcc = system("gcc --version > /dev/null 2> /dev/null");
	}
	if (gcc == 0) {
		std::cout << "[bfc-compiler-test] gcc present." << std::endl;
		retval = 3;
	}
	return retval;
}

void parseOptions(int argc, char *argv[]) {

}

int main(int argc, char *argv[]) {
	parseOptions(argc, argv);
	if (argc < 2) {
		std::cerr << "[bfc] Invalid arguments." << std::endl;
		_Exit(1);
	}
	std::cout << "[bfc] Checking for compiler..." << std::endl;
	int compiler = checkCompiler();
	if (compiler == -1) {
		std::cerr << "[bfc] Error: No compiler present." << std::endl;
		_Exit(1);
	}
	std::cout << "[bfc] " << ARCHITECTURE << std::endl;
	std::cout << "[bfc] BFC - A BrainF Compiler" << std::endl;
	std::cout << "[bfc] Loading " << argv[1] << "..." << std::endl;
	std::ifstream inprogfile(argv[1]);
	std::string str((std::istreambuf_iterator<char>(inprogfile)), std::istreambuf_iterator<char>());
	inprogfile.close();
	std::string s = "";
	int si = 1;
	std::string cp = "#include<stdio.h>\nint read() {int c;c=getchar();while(getchar()!=10){}return c;}\nint main(int argc, char *argv[]) {int memory[30000];for (int i = 0; i < 30000; i++) {memory[i] = 0;}int pointerindex = 0;";
	int instc = 0;
	int percent = 0;
	bool commentMode = false;
	while (1) {
		s = "";
		int i = 0;
		// Parse
		char curinst = str[instc];
		switch (curinst) {
			case '+':
				if (!commentMode) {
					cp += "memory[pointerindex]+=1;";
				}
				break;
			case '-':
				if (!commentMode) {
					cp += "memory[pointerindex]-=1;";
				}
				break;
			case '.':
				if (!commentMode) {
					cp += "printf(\"%c\", char(memory[pointerindex]));";
				}
				break;
			case ',':
				if (!commentMode) {
					cp += "memory[pointerindex]=read();";
				}
				break;
			case '<':
				if (!commentMode) {
					cp += "pointerindex-=1;";
				}
				break;
			case '>':
				if (!commentMode) {
					cp += "pointerindex+=1;";
				}
				break;
			case '[':
				if (!commentMode) {
					cp += "while (memory[pointerindex] != 0){";
				}
				break;
			case ']':
				if (!commentMode) {
					cp += "}";
				}
				break;
			case ';':
				if (!commentMode) {
					commentMode = true;
				}
				break;
			case '\n':
				if (commentMode) {
					commentMode = false;
				}
				break;
			default:
				if (!commentMode) {
					std::cout << "Error: unexpected literal '" << curinst << "'." << std::endl;
					_Exit(1);
				}
				break;
		}
		instc += 1;
		while (i < 3) {
			if (si < i) {
				s += " ";
			} else {
				s += ".";
			}
			if (curinst == '\n') {
				curinst = ' ';
			}
			std::cout << "[bfc] Parsing" << s << " " << curinst << " " << percent << "%\r";
			i += 1;
		}
		if (si > 2) {
			si = 0;
		} else {
			si += 1;
		}
		std::cout.flush();
		if (instc + 1 > str.length()) {
			break;
		}
		percent = (double)(((double)instc / (double)str.length()) * 100);
	}
	cp += "}";
	std::cout << std::endl;
	std::cout << "[bfc] Done parsing." << std::endl;
	std::ofstream exf("executable.cpp");
	exf << cp;
	exf.close();
	std::cout << "[bfc] Compiling..." << std::endl;
	int res = -1;
	switch (compiler) {
		case 1:
			// Clang++
			res = std::system("clang++ -o executable executable.cpp");
			break;
		case 2:
			// Clang
			res = std::system("clang -o executable executable.cpp");
			break;
		case 3:
			// gcc
			res = std::system("gcc -o executable executable.cpp");
			break;
	}
	if (res/256 == 1) {
		std::cout << "[bfc] An error occured during compiling." << std::endl;
		res = std::system("rm executable.cpp");
		_Exit(1);
	}
	std::cout << "[bfc] Done Compiling." << std::endl;
	std::cout << "[bfc] Executing..." << std::endl;
	res = std::system("./executable");
	std::cout << std::endl << "[bfc] Execution complete." << std::endl;
	res = std::system("rm executable executable.cpp");
	return 0;
}