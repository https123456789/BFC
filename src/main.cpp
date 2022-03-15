#include "bfc.hpp"

int versionTop = 0;
int versionL2 = 0;
int versionL3 = 1;

void printVersion(void);
void printMessage(std::string message);
/*
namespace BFCRuntime {
	// Memory
	int memorySize = 30000;
	int memory[30000];
	int memoryPointer = 0;

	// Warnings
	bool warnOnNegitiveShift = false;

	// Errors
	int errorCount = 0;
	int errorMax = 1;
	void initMemory(void) {
		for (int i = 0; i < memorySize; i++) {
			memory[i] = 0;
		}
	}
	int read() {
		int c;
		c = getchar();
		while(getchar()!=10) {}
		return c;
	}
}
*/
int main(int argc, char *argv[]) {
	// Command line options/arguments
	cxxopts::Options options("BFC", "A brainF Compiler");
	options.add_options()
		("version", "version")
		("v,verbose", "verbose")
		("c,config", "config", cxxopts::value<std::string>()->default_value(""));
	auto optres = options.parse(argc, argv);

	// Check for version options
	if (optres["version"].as<bool>()) {
		printVersion();
		_Exit(0);
	}

	// Check for compiler
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Checking for compiler..." << std::endl;
	}
	int compiler = checkCompiler(argc, argv);
	if (compiler == -1) {
		std::cerr << "\033[31m[bfc] FatalError: No compiler present.\033[0m" << std::endl;
		_Exit(1);
	}

	// Detect build platform
	if (ARCHITECTURE == 0) {
		if (optres["v"].as<bool>()) {
			std::cout << "[bfc] Building for x86..." << std::endl;
		}
	} else {
		if (optres["v"].as<bool>()) {
			std::cout << "[bfc] Building for arm..." << std::endl;
		}
	}

	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] BFC - A BrainF Compiler" << std::endl;
	}

	// Load program
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Loading " << argv[1] << "..." << std::endl;
	}
	std::string sourcefile = argv[1];
	std::ifstream inprogfile(argv[1]);
	if (!inprogfile.good()) {
		std::cerr << "\033[31m[bfc] Error: File '" << argv[1] << "' doesn\'t exist or can\'t be accessed.\033[0m" << std::endl;
		_Exit(2);
	}
	std::string str((std::istreambuf_iterator<char>(inprogfile)), std::istreambuf_iterator<char>());
	inprogfile.close();

	std::string s = "";
	int si = 1;
	std::string cp = "#include<stdio.h>\nint read() {int c;c=getchar();while(getchar()!=10){}return c;}\nint main(int argc, char *argv[]) {int memory[30000];for (int i = 0; i < 30000; i++) {memory[i] = 0;}int pointerindex = 0;";
	int instc = 0;
	int percent = 0;
	bool commentMode = false;
	int charcount = 0;
	int linecount = 1;
	// Memory
	int memorySize = 30000;
	int memoryPointer = 0;

	// Warnings
	bool warnOnNegitiveShift = false;

	// Errors
	int errorCount = 0;
	int errorMax = 1;

	// Config
	if (optres["c"].as<std::string>() != "") {
		// Load and parse config file
		if (optres["v"].as<bool>()) {
			std::cout << "[bfc-config] Loading config file..." << std::endl;
		}
		std::ifstream configFile(optres["c"].as<std::string>());
		nlohmann::json configData;
		configFile >> configData;
		if(optres["v"].as<bool>()) {
			std::cout << "[bfc-config] Config file loaded. Parsing..." << std::endl;
		}
		if (configData["memoryAllocationSize"] > 0) {
			memorySize = (int)configData["memoryAllocationSize"];
			if (optres["v"].as<bool>()) {
				std::cout << "[bfc-config] Memory Alloocation Size: " << memorySize << std::endl;
			}
		}
		if (configData["warnOnNegitiveShift"]) {
			warnOnNegitiveShift = configData["warnOnNegitiveShift"];
			if (optres["v"].as<bool>()) {
				std::cout << "[bfc-config] Warning on negitive shifting. (Not Recomended)" << std::endl;
			}
		}
		configFile.close();
	}

	while (1) {
		s = "";
		int i = 0;
		// Parse
		char curinst = str[instc];
		if (!commentMode) {
			switch (curinst) {
				case '+':
					{
						std::string s = "";
						s += "memory[pointerindex]";
						s += curinst;
						s += "=1;";
						cp += s;
					}
					break;
				case '-':
					{
						std::string s = "";
						s += "memory[pointerindex]";
						s += curinst;
						s += "=1;";
						cp += s;
					}
					break;
				case '.':
					{
						cp += "printf(\"%c\", char(memory[pointerindex]));";
					}
					break;
				case ',':
					cp += "memory[pointerindex]=read();";
					break;
				case '<':
					{
						memoryPointer -= 1;
						if (memoryPointer < 0) {
							if (warnOnNegitiveShift) {
								std::cout << "\033[33m[bfc] Warning: negitive shift attempted at " << argv[1] << ":" << linecount << ":" << charcount << ". Instruction skipped.\033[0m" << std::endl;
								memoryPointer += 1;
								break;
							} else {
								std::cerr << "\033[31m[bfc] InvalidMemoryShiftError: memory pointer shifted to a negitive index at " << argv[1] << ":" << linecount << ":" << charcount << ":\033[0m" << std::endl;
								errorCount += 1;
								if (errorCount >= errorMax) {
									_Exit(3);
								}
							}
						}
						cp += "pointerindex-=1;";
					}
					break;
				case '>':
					{
						memoryPointer += 1;
						if (memoryPointer > memorySize) {
							std::cerr << "\033[31m[bfc] InvalidMemoryShiftError: memory pointer shifted beyond allocated memory at " << argv[1] << ":" << linecount << ":" << charcount << ".\033[0m" << std::endl;
							errorCount += 1;
							if (errorCount >= errorMax) {
								_Exit(3);
							}
						}
						cp += "pointerindex+=1;";
					}
					break;
				case '[':
					{
						cp += "while (memory[pointerindex] != 0){";
					}
					break;
				case ']':
					{
						cp += "}";
					}
					break;
				case ';':
					{
						commentMode = true;
					}
					break;
				case '\n':
					{
						commentMode = false;
					}
					break;
				// Fall through indentation characters
				case ' ':
				case '\t':
					break;
				default:
					{
						std::cerr << "\033[31m[bfc-parse] UnexpectedLiteralError: unexpected literal '\033[0m" << curinst << "\033[31m' at " << argv[1] << ":" << linecount << ":" << charcount << ".\033[0m" << std::endl;
						errorCount += 1;
						if (errorCount >= errorMax) {
							_Exit(3);
						}
					}
					break;
			}
		}

		if (curinst == '\n') {
			linecount += 1;
			charcount = 0;
			commentMode = false;
		} else {
			charcount += 1;
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
			if (optres["v"].as<bool>()) {
				std::cout << "[bfc-parse] Parsing" << s << " " << curinst << " " << percent << "%\r";
			}
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
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Done parsing." << std::endl;
	}
	// Exit if there are errors
	if (errorCount > 0) {
		_Exit(2);
	}

	std::ofstream exf("executable.cpp");
	exf << cp;
	exf.close();
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Compiling..." << std::endl;
	}
	int res = -1;
	switch (compiler) {
		case 1:
			// Clang
			res = std::system("clang -o executable executable.cpp");
			break;
		case 2:
			// gcc
			res = std::system("gcc -o executable executable.cpp");
			break;
	}
	if (res/256 == 1) {
		std::cout << "[bfc] An error occured during compiling." << std::endl;
		res = std::system("rm executable.cpp");
		_Exit(1);
	}
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Done Compiling." << std::endl;
	}
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Executing..." << std::endl;
	}
	res = std::system("./executable");
	std::cout << std::endl;
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] Execution complete." << std::endl;
	}
	res = std::system("rm executable executable.cpp");
	return 0;
}

void printVersion(void) {
	std::cout << "[bfc] Version:" << std::endl << "BFC " << versionTop << "." << versionL2 << "." << versionL3 << std::endl;
}

void printMessage(std::string message) {
	std::cout << message << std::endl;
}