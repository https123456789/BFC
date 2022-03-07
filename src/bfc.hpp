#include <iostream>
#include <fstream>
#include <streambuf>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <string>
#include "lib/cxxopts.hpp"
#include "lib/json.hpp"

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

int versionTop = 0;
int versionL2 = 0;
int versionL3 = 1;