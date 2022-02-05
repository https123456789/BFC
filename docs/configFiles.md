# Config Files

Config files are a way to modify the way BFC handles your program, from setting the amount of memory available, to telling BFC how to handle errors.

## Flags:

### `warnOnNegativeShift`

Type: `bool`

Determines if an error or warning is thrown when a negative shift occurs. If `true`, bfc throws and warning when it encounters the negative shift **and skips the instruction**. It is recomemded not to use this flag. For more information see [this page](</BFC/whyYouShouldntUseThewarnOnNegativeShiftFlag>).

## Runtime Settings

### `memorySize`

Type: `int`

If set, bfc allocates `n` number of memory positions, where `n` is the value specified. If not specified, the default of 30,000 is used.