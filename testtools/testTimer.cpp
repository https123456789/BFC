/*

Test Timer: times the compile speed of BFC

*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <cstdint>
#include <fstream>

#ifdef _WIN32
#define PLATFORM "Windows"
#elif _WIN64
#define PLATFORM "Windows"
#elif __APPLE__ || __MACH__
#define PLATFORM "Mac OS"
#elif __linux__
#define PLATFORM "Linux"
#elif __FreeBSD__
#define PLATFORM "FreeBSD"
#elif __unix || __unix__
#define PLATFORM "Unix"
#else
#define PLATFORM "Other"
#endif

bool checkFileExists(std::string fn);

int main(int argc, char *argv[])  {
	std::cout << "Test timer" << std::endl;
	if (argc != 2) {
		std::cerr << "\033[31mError: invalid args.\033[0m" << std::endl;
		_Exit(1);
	}
	std::string fn(argv[1]);
	bool fileExists = checkFileExists(fn);
	if (!fileExists) {
		std::cerr << "\033[31mError: file does not exist.\033[0m" << std::endl;
		_Exit(1);
	}
	std::time_t startTime = std::time(nullptr);
	uint64_t startTimeMS = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count();
	// Run compiler
	std::string invoc = "./bfc ";
	invoc += fn;
	invoc += " -r";
	if (std::string("Windows").compare(PLATFORM) == 0) {
		// Windows
		invoc += " > null 2> null";
	} else {
		// Other
		invoc += " > /dev/null 2> /dev/null";
	}
	std::cout << "Running..." << std::endl;
	int syscall = system(invoc.c_str());
	// Measure time
	uint64_t endTimeMS = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
	).count();
	std::time_t endTime = std::time(nullptr);
	std::time_t tdiff = endTimeMS - startTimeMS;
	// Exit if compiler threw error
	if (syscall != 0) {
		std::cerr << "\033[31mCan't record stats, compiler threw error.\033[0m" << std::endl;
		_Exit(0);
	}
	// Localize std::cout
	std::locale cpploc{""};
	std::cout.imbue(cpploc);
	// Stats
	std::cout << "STATS:" << std::endl;
	std::cout << "\t" << ((double)tdiff / (double)1000) << " seconds" << std::endl;
	// Count chars in file
	std::ifstream file(fn);
	int count = 0;
	std::string line;
	while (getline(file, line)) {
		count += line.length();
	}
	std::cout << "\t" << count << " characters" << std::endl;
	int speed = (int) ((double)count / ((double)tdiff / (double)1000));
	std::cout << "\tParsing speed of " << speed << " characters per second" << std::endl;
	return 0;
}

bool checkFileExists(std::string fn) {
	std::string invoc = "stat ";
	invoc += fn;
	invoc += " > /dev/null 2> /dev/null";
	int syscall = std::system(invoc.c_str());
	if (syscall != 0) {
		return false;
	}
	return true;
}