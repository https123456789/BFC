# BFC - A BrainF Compiler

<img src="https://img.shields.io/github/downloads/https123456789/BFC/total?style=for-the-badge&label=">
<img src="https://img.shields.io/github/last-commit/https123456789/BFC?style=for-the-badge">
<hr>
<img src="https://img.shields.io/github/commit-activity/y/https123456789/BFC?style=for-the-badge">
<img src="https://img.shields.io/github/contributors/https123456789/BFC?color=success&style=for-the-badge">
<hr>
<img src="https://www.codefactor.io/repository/github/https123456789/BFC/badge?style=for-the-badge">
<img src="https://img.shields.io/github/repo-size/https123456789/BFC?style=for-the-badge">
<hr>

[![Tests Workflow Status](https://github.com/https123456789/BFC/actions/workflows/tests.yml/badge.svg)](https://github.com/https123456789/BFC/actions/workflows/tests.yml)

## Contributing

See ([/contributing](</contributing>))

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

`myprogram.bf`:
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

Call:
```shell
$ ./bfc myprogram.bf
$ ./executable
```

Result:

```
Test
```
