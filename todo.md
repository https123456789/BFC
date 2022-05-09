# BFC To Do

## In Progress
None

## Top Priority
- Speed Improvement

## Low Priority
- Convert to using assembly instead of clang++, clang, and gcc.

## Done

### 5-9-2022
- Added more options
  - Added `-e` option (makes BFC execute the binary it created)
  - Added `-r` option (makes BFC remove the binary it created)
  - Added `-o` option (specifies the name of the binary BFC creates)
- Created `testtools`
  - Created `testTimer`
- Created contributing guidelines
  - Created `.github/CONTRIBUTING.md`
  - Created `docs/contributing/CONTRIBUTING.md`
- Refactored some of `src/main.cpp`
	- Compiling the binary has its own function
- Changes to how BFC works
	- BFC will now not execute your code unless the `-e` option is present
  - BFC will not remove the executable unless the `-r` options is present

### 2-4-2022
- Negitive shifts skipped and warned

### 2-3-2022
- Add indentation support
- Config file to hold special configuration (like amount of memory allocated).
- Error Types
- Handle invalid memory shifts as error
- Add warnings
- Handle command line options

### 2-2-2022
- Handle non-existant files