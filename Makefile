TT = $(shell c++ -dumpmachine)
BFC = dist/$(TT)-bfc
BFC_TEST_FLAGS = -re

SRC := $(shell find src -type f -name "*.cpp")
OFILES := $(SRC:.cpp=.o)

.PHONY: all
all: detect $(BFC)
	cp $(BFC) dist/bfc

.PHONY: detect
detect:
	@echo "Detecting required dependencies..."
	@echo "C++..."
	@sh -c "c++ --version > /dev/null" 2> /dev/null || ( echo "Please install a C++ compiler."; exit 1 )
	@echo "NASM..."
	@sh -c "nasm --version > /dev/null" 2> /dev/null || ( echo "Please install NASM."; exit 1 )
	@echo "All dependencies were found."

.PHONY: test
test: $(BFC)
	@echo "Testing..."
	@echo "Extracting Compressed tests..."
	@chmod +x tests/*.sh
	@cd tests && ./buildTests.sh
	./$(BFC) tests/test1.bf BFC_TEST_FLAGS > /dev/null
	./$(BFC) tests/test2.bf BFC_TEST_FLAGS > /dev/null
	./$(BFC) tests/test3.bf BFC_TEST_FLAGS 2> /dev/null || echo -n
	./$(BFC) tests/test4.bf BFC_TEST_FLAGS 2> /dev/null || echo -n
	./$(BFC) tests/test5.bf BFC_TEST_FLAGS
	./$(BFC) tests/test6.bf BFC_TEST_FLAGS
	@echo "Cleaning up..."
	@cd tests && ./deleteTests.sh

.PHONY: clean
clean:
	rm -fr dist $(BFC) $(OFILES)

$(BFC): $(OFILES)
	mkdir -p dist
	c++ -o $@ $^

%.o: %.cpp
	c++ -o $@ -c $< -Iinclude -Ilib
