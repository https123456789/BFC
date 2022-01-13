cd src
clang++ -o bfc main.cpp
cd ..
mv src/bfc dist/bfc
cp dist/bfc tests/bfc