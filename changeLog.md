# Change Log

## 5-14-2022
- Moved change log into its own file.
- Added change log to docs.
- Tests workflow runs on pushes to any branch.
- Fixed `build.sh` and `clean.sh`.
- Changed style for badges.
- Tests workflow is modified to actually work.

## 5-14-2022
- The verbose output for the compiling percentage is now only after a whole second has passed.
- Created `test6.bf`
	- Test 6 tests BFC's capabilities to handle and compile large files (like really big files).
```bash
File: test6.bf
Size: 364847
Blocks: 720
IO Block: 4096
regular file
Device: 40009ch/4194460d
Inode: 643
Links: 1
Access: (0644/-rw-r--r--)
Uid: ( 1000/  runner)
Gid: ( 1000/  runner)
Access: 2022-05-14 14:18:50.472187197 +0000
Modify: 2022-05-14 14:18:57.424177747 +0000
Change: 2022-05-14 14:18:57.424177747 +0000
Birth: 2022-05-14 14:18:50.472187197 +0000
```

## 5-9-2022
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

## 2-4-2022
- Negitive shifts skipped and warned

## 2-3-2022
- Add indentation support
- Config file to hold special configuration (like amount of memory allocated).
- Error Types
- Handle invalid memory shifts as error
- Add warnings
- Handle command line options

## 2-2-2022
- Handle non-existant files