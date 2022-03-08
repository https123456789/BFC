# BFC - A BrainF Compiler

<a href="https://replit.com/@https12345678/BFC?lite=true#replit/runOnReplit.md"><img src="https://raw.githubusercontent.com/https123456789/BFC/main/github/runOnReplit.svg"></a>

![test1](<https://bfc-test.https12345678.repl.co/badges/test1.svg>)
![test2](<https://bfc-test.https12345678.repl.co/badges/test2.svg>)
![test3](<https://bfc-test.https12345678.repl.co/badges/test3.svg>)
![test4](<https://bfc-test.https12345678.repl.co/badges/test4.svg>)
![test5](<https://bfc-test.https12345678.repl.co/badges/test5.svg>)

## Pages

- [Options](<options>)
- [Config Files](<configFiles>)

## Downloading

The latest stable version can be downloaded from [here](<>).

The latest development build can be downloaded from [here](<https://github.com/https123456789/BFC/tree/main/dist>).

#### Build Platforms

|Platform|Pre-Built|
|--------|---------|
| Linux x86 | ✅ |
| Linux arm | ❌ |
| Window x86 | ❌ |

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

Call: `./bfc myprogram.bf`

#### Result:

```
Test
```
