# BFC - A BrainF Compiler

<img src="https://repl.it/badge/github/https12345678/BFC">
<img src="https://img.shields.io/github/downloads/https123456789/BFC/total">
<img src="https://img.shields.io/github/last-commit/https123456789/BFC">
<hr>
<img src="https://img.shields.io/github/stars/https123456789/BFC">
<img src="https://img.shields.io/github/watchers/https123456789/BFC">
<img src="https://img.shields.io/github/commit-activity/y/https123456789/BFC">
<img src="https://img.shields.io/github/contributors/https123456789/BFC?color=success">
<hr>
<img src="https://www.codefactor.io/repository/github/https123456789/BFC/badge">
<img src="https://img.shields.io/tokei/lines/github/https123456789/BFC?label=Lines%20of%20Code">
<img src="https://img.shields.io/github/repo-size/https123456789/BFC">
<hr>
<img src="https://bfc-test.https12345678.repl.co/badge.php?test=1">
<img src="https://bfc-test.https12345678.repl.co/badge.php?test=2">
<img src="https://bfc-test.https12345678.repl.co/badge.php?test=3">
<img src="https://bfc-test.https12345678.repl.co/badge.php?test=4">
<img src="https://bfc-test.https12345678.repl.co/badge.php?test=5">

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

#### `myprogram.bf`:
```brainfuck
>++++++++++[<++++++++>-]<++++.
[-]
>++++++++++[<++++++++++>-]<+.
[-]
>+++++++++++[<++++++++++>-]<+++++.
[-]
>+++++++++++[<++++++++++>-]<++++++.
[-]
```

#### Call: `./bfc myprogram.bf`

#### Result:

```
Test
```
