# Test 5

<img src="https://bfc-test.https12345678.repl.co/badge.php?test=5">

This tests indentation. Any format of indentation should compile, from one character per line, to one line in the file.

## Code

```brainfuck
; test5.bf - Tests Indentation

; Normal Non-Indented Stuff
>++++++++++[<++++++++>-]<++++.
[-]
>++++++++++[<++++++++++>-]<+.
[-]
>+++++++++++[<++++++++++>-]<+++++.
[-]

; Indented Stuff
>
+++++++++++
[
	<
		++++++++++
	>-
]
<
++++++.
[
	-
]
```

## Expected Results

```
$ ./bfc test5.bf
Test
```