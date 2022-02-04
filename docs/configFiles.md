# Config Files

## Options:

### `warnOnNegativeShift`

Type: `bool`

Tags:
- flag

Determines if an error or warning is thrown when a negative shift occurs. If `true`, bfc throws and warning when it encounters the negative shift **and skips the instruction**.

### `memorySize`

Type: `int`

Tags:
- runtimeSpecification

If set, bfc allocates `n` number of memory positions, where `n` is the value specified. If not specified, the defaut of 30,000 is used.