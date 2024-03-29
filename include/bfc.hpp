#include <iostream>
#include <fstream>
#include <streambuf>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <string>
//#include "cxxopts.hpp"
//#include "json.hpp"

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

#ifndef versionTop
#define versionTop "0"
#define versionL2 "0"
#define versionL3 "1"
#endif

int checkCompiler(int argc, char *argv[]);
void compile(std::string fn, int compiler, bool isVerbose);
void printVersion(void);
void printMessage(std::string message);
void printInfo(void);