echo "Build project..."
(
	cd src
	echo "Compiling..."
	clang++ -o bfc main.cpp
)
echo "Moving..."
mv src/bfc dist/bfc
echo "Copying..."
cp dist/bfc tests/bfc