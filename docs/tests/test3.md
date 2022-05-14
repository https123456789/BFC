---
title: Test 3
parent: Tests
---
# Test 3

<img src="https://bfc-test.https12345678.repl.co/badge.php?test=3">

This tests error handling by BFC (error in the input program). The errors tested by this are:

- negative memory shifting
- memory over-shifing

## Code

> **Note**: I have removed the majority of the right shift instructions `>`, becuase there are ***way*** to many of them for me to reasonably put in the docs.

```brainfuck
; Test 3 - Tests error handling

; Error no -1th memory block
<+

; Error shifted too far
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
```

## Configuration

> **Note**: This test should be run with and without the config file.

```json
{
	"warnOnNegitiveShift": true
}
```

## Expected Results

### Run without `--config` or `-c` option

```
$ ./bfc test3.bf
[bfc] InvalidMemoryShiftError: memory pointer shifted to a negative index at test3.bf:5:0
```

### Run with `--config` or `-c` option

```
$ ./bfc test3.bf --config test3.bfc
[bfc] Warning: negitive shift attempted at test3.bf:5:0. Instruction skipped.
[bfc] InvalidMemoryShiftError: memory pointer shifted beyond allocated memory at test3.bf:308:0.
```