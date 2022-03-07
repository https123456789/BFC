echo "Build project..."
cd src
echo "Compiling..."
clang++ -o bfc main.cpp
echo "Copying..."
cd ..
mv src/bfc dist/bfc
cp dist/bfc tests/bfc