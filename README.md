# BFC - A BrainF Compiler

<a href="https://replit.com/@https123456789/BFC?lite=true#replit/runOnReplit.md"><img src="https://img.shields.io/static/v1?style=for-the-badge&label=&message=Run%20on%20Replit&logo=replit"></a>
<img src="https://img.shields.io/github/downloads/https123456789/BFC/total?style=for-the-badge&label=">
<img src="https://img.shields.io/github/last-commit/https123456789/BFC?style=for-the-badge">
<hr>
<img src="https://img.shields.io/github/stars/https123456789/BFC?style=for-the-badge">
<img src="https://img.shields.io/github/watchers/https123456789/BFC?style=for-the-badge">
<img src="https://img.shields.io/github/commit-activity/y/https123456789/BFC?style=for-the-badge">
<img src="https://img.shields.io/github/contributors/https123456789/BFC?color=success&style=for-the-badge">
<hr>
<img src="https://www.codefactor.io/repository/github/https123456789/BFC/badge?style=for-the-badge">
<img src="https://img.shields.io/tokei/lines/github/https123456789/BFC?label=Lines%20of%20Code&style=for-the-badge">
<img src="https://img.shields.io/github/repo-size/https123456789/BFC?style=for-the-badge">
<hr>

![Tests Status](<https://bfc-test.https12345678.repl.co/overview.php>)

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

#### Call:
```shell
$ ./bfc myprogram.bf
$ ./executable
```

#### Result:

```
Test
```
