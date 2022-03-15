files := src/main.cpp src/compiler.cpp
build: compile copy move
	echo "Built."
compile: $(files)
	clang++ -o bfc $(files)
copy:
	cp bfc tests
move:
	mv bfc dist