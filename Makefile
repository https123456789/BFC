files := src/main.cpp src/compiler.cpp
ofiles := src/main.o src/compiler.o
.SILENT: build
build: objectFiles compile copy move buildTestTools
	@echo "Built."

compile: objectFiles $(files)
	@echo "Compiling object files to executable..."
	@clang++ -o bfc $(ofiles)

objectFiles:
	@echo "Building object files (this might take a bit)..."
	@clang++ -c $(files) -include-pch src/bfc.hpp.pch
	@ mv *.o src

buildTestTools:
	@echo "Building test tools..."
	@cd testtools; \
	clang++ -o testTimer testTimer.cpp
	@cp testtools/testTimer tests

copy:
	@cp bfc tests

move:
	@mv bfc dist

clean:
	@rm src/*.o