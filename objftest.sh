MAIN_O_LCT=$(date -r src/main.o +%s)
MAIN_CPP_LCT=$(date -r src/main.cpp +%s)
COMPILER_O_LCT=$(date -r src/compiler.o +%s)
COMPILER_CPP_LCT=$(date -r src/compiler.cpp +%s)
if [ "$MAIN_CPP_LCT" -ge "$MAIN_O_LCT" ]; then
	exit 1
fi
if [ "$COMPILER_CPP_LCT" -ge "$COMPILER_O_LCT" ]; then
	exit 1
fi
exit 0