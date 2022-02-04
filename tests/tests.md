# Tests

## Build Tests

Large tests need to be built with this script because it the file were there the repositiory would be labeled as a brainF project.

The large files that will be built are:
- `test3.bf`

```
./buildTests.sh
```

## Delete Tests

Delete large test files. This script needs to be run before commiting.

```
./deleteTests.sh
```

## Tests

| File Name | Purpose |
|-----------|---------|
| test1.bf | Test Basic Functionality |
| test2.bf | Test Comments |
| test3.bf | Error Testing - Invalid memory shift |
| test4.bf | Error Testing - Unexpected literal |
| test5.bf | Tests indentation |