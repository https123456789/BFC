# BFC - A BrainF Compiler

<a href="https://replit.com/@https12345678/BFC?lite=true#replit/runOnReplit.md"><img src="https://raw.githubusercontent.com/https123456789/BFC/main/github/runOnReplit.svg"></a>

Tests:
<div>
	<img src="https://bfc-test.https12345678.repl.co/badges/test1.svg" alt="test1">
	<img src="https://bfc-test.https12345678.repl.co/badges/test2.svg" alt="test2">
	<img src="https://bfc-test.https12345678.repl.co/badges/test3.svg" alt="test3">
	<img src="https://bfc-test.https12345678.repl.co/badges/test4.svg" alt="test4">
</div>

## Downloading

The latest stable version can be downloaded from [here](<>).

The latest development build can be downloaded from `/dist/`.

#### Build Platforms

|Platform|Pre-Built|
|--------|---------|
| Linux x86 | :white_check_mark: |
| Linux arm | :x: |
| Window x86 | :x: |

## Usage

The compiler can be call with `./bfc [path to program]`.

### Example

#### Project Structure

```
\
	bfc
	myprogram.bf
```

#### Call: `./bfc myprogram.bf`

```
[bfc] Checking for compiler...
[bfc-compiler-test] Testing for clang++...
[bfc-compiler-test] clang++ present.
[bfc-compiler-test] Testing for clang...
[bfc-compiler-test] clang present.
[bfc-compiler-test] Testing for gcc...
[bfc-compiler-test] gcc present.
[bfc] BFC - A BrainF Compiler
[bfc] Loading myprogram.bf...
[bfc] Parsing... ] 99%
[bfc] Done parsing.
[bfc] Compiling...
[bfc] Done Compiling.
[bfc] Executing...
Test
[bfc] Execution complete.
```
