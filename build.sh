cd src
clang++ -o bfc main.cpp
echo "Build project..."
cd ..
mv src/bfc dist/bfc
cp dist/bfc tests/bfc