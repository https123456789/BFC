# Why You Shouldn't Use The `warnOnNegativeShift` Falg:

In this demonstration, we will use the `test3.bf` brainF program. First, we define the config file, `test3.bfc` (not the extension is `.bfc`).

`test3.bfc`
```json
{
	"warnOnNegativeShift": true
}
```

Next, we want to run BFC with our config file, so we will use the `-c` option ([see the docs for the `-c` option](</BFC/options>)) and pass our config file to BFC.

```
$ ./bfc test3.bf -c test3.bfc
[bfc] Warning: negitive shift attempted at test3.bf:5:0. Instruction skipped.
[bfc] InvalidMemoryShiftError: memory pointer shifted beyond allocated memory at test3.bf:308:0.
$ 
```

You will notice that instead of throwing an error, BFC simply prints a warning and continues to parse the source code. An important thing to note however, is that BFC in addition to not throwing an error, also ignores the instruction. Below is a quick example.

---

Memory:

```
[111][000][005][007][000]
  ^  
```

Next Instruction:

`<`

**Warning thrown, parsing continues...**

Memory:

```
[111][000][005][007][000]
  ^  
```

---

The result of this is that the following instructions don't match up, because an instruction was not executed. For this reason, don't disable the error, unless the negative shift is intentional.