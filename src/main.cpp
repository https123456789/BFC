#include "bfc.hpp"
#include "cxxopts.hpp"
#include "json.hpp"

int main(int argc, char *argv[]) {
	// Command line options/arguments
	cxxopts::Options options("BFC", "A brainF Compiler");
	options.add_options()
		("version", "Print version")
		("i,info", "Print info")
		("v,verbose", "Verbose output")
		("e,execute", "Execute program")
		("r,remove-executable", "Remove executable")
		("o", "Output file name", cxxopts::value<std::string>()->default_value("executable"))
		("c,config", "Config", cxxopts::value<std::string>()->default_value(""));
	//options.parse_positional({"inputFile"});
	auto optres = options.parse(argc, argv);
	
	if (argc < 2) {
		std::cout << options.help() << std::endl;
		_Exit(1);
	}

	// Check for help
	if (strcmp(argv[1], "help") == 0) {
		std::cout << options.help() << std::endl;
		_Exit(1);
	}
	
	// Check for version options
	if (optres["version"].as<bool>()) {
		printVersion();
		_Exit(0);
	}

	// Check for info option
	if (optres["i"].as<bool>()) {
		printInfo();
		_Exit(0);
	}
	
	if (optres["v"].as<bool>()) {
		std::cout << "[bfc] BFC - A BrainF Compiler" << std::endl;
	}
	
	// Check for compiler
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc] Checking for compiler...\033[0m" << std::endl;
	}
	int compiler = checkCompiler(argc, argv);
	if (compiler == -1) {
		std::cerr << "\033[31m[bfc] FatalError: No compiler present.\033[0m" << std::endl;
		_Exit(1);
	}

	// Detect build platform
	if (ARCHITECTURE == 0) {
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc] Building for x86...\033[0m" << std::endl;
		}
	} else {
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc] Building for arm...\033[0m" << std::endl;
		}
	}

	// Load program
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc] Loading " << argv[1] << "...\033[0m" << std::endl;
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

	// Errors
	int errorCount = 0;
	int errorMax = 1;

	// Config
	if (optres["c"].as<std::string>() != "") {
		// Load and parse config file
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc-config] Loading config file...\033[0m" << std::endl;
		}
		std::ifstream configFile(optres["c"].as<std::string>());
		nlohmann::json configData;
		configFile >> configData;
		if(optres["v"].as<bool>()) {
			std::cout << "\r\033[34m[bfc-config] Config file loaded. Parsing...\033[0m" << std::endl;
		}
		if (configData["memoryAllocationSize"] > 0) {
			memorySize = (int)configData["memoryAllocationSize"];
			if (optres["v"].as<bool>()) {
				std::cout << "\033[34m[bfc-config] Memory Alloocation Size: " << memorySize << "\033[0m" << std::endl;
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
                            std::cerr << "\033[31m[bfc] InvalidMemoryShiftError: memory pointer shifted to a negitive index at " << argv[1] << ":" << linecount << ":" << charcount << ":\033[0m" << std::endl;
                            errorCount += 1;
                            if (errorCount >= errorMax) {
                                _Exit(3);
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
			const auto p1 = std::chrono::system_clock::now();
			const auto td = std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count();
			//std::cout << td << std::endl;
			if (optres["v"].as<bool>() && ((int) td) % 2 == 0) {
				std::cout << "\033[34m[bfc-parse] Parsing" << s << " " << curinst << " \033[0m\033[92m" << percent << "%\033[0m\r";
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
		std::cout << "\033[34m[bfc] Done parsing.     \033[0m\033[92m100%\033[0m" << std::endl;
	}
	// Exit if there are errors
	if (errorCount > 0) {
		_Exit(2);
	}

	std::ofstream exf("executable.cpp");
	exf << cp;
	exf.close();
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc] Compiling...\033[0m" << std::endl;
	}
	// Compiler
	compile(
		optres["o"].as<std::string>(),
		compiler,
		optres["v"].as<bool>()
	);
	
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc] Done Compiling.\033[0m" << std::endl;
	}
	if (optres["e"].as<bool>()) {
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc] Executing...\033[0m" << std::endl;
		}
		int res = std::system("./executable");
		std::cout << std::endl;
	}
	if (optres["v"].as<bool>()) {
		std::cout << "\033[34m[bfc] Execution complete.\033[0m" << std::endl;
	}
	int res = std::system("rm executable.cpp");
	if (optres["r"].as<bool>()) {
		if (optres["v"].as<bool>()) {
			std::cout << "\033[34m[bfc] Removing " << optres["o"].as<std::string>() << ".\033[0m" << std::endl;
		}
		res = std::system(
			(std::string("rm ") + optres["o"].as<std::string>()).c_str()
		);
	}
	return 0;
}

void printVersion(void) {
	std::cout << "BFC " << versionTop << "." << versionL2 << "." << versionL3 << std::endl;
}

void printMessage(std::string message) {
	std::cout << message << std::endl;
}