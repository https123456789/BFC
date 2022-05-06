---
title: Test 4
parent: Tests
---
# Test 4

<img src="https://bfc-test.https12345678.repl.co/badge.php?test=4">

This tests error handling by BFC (error in the input program). The errors tested by this are:

- Invalid literal

## Code

```brainfuck
; test4.bf - Error Testing - Invalid Literal

>++++++++[<+++++++++>-]<++++.
[-]
>++++++++++[<++++++++++>-]<+.
[-]
; Error
?+++++++++++[<+++++++++>-]<++++.
[-]
```

## Expected Results

```
$ ./bfc test4.bf
[bfc-parse] UnexpectedLiteralError: unexpected literal '?' at test4.bf:8:0.
```