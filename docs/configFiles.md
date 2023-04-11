---
title: Config Files
---
# Config Files

Config files are a way to modify the way BFC handles your program, from setting the amount of memory available, to telling BFC how to handle errors.

## Runtime Settings

### `memorySize`

Type: `int`

If set, bfc allocates `n` number of memory positions, where `n` is the value specified. If not specified, the default of 30,000 is used.