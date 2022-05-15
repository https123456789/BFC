echo "Build project..."
(
	cd src
	echo "Building object files (this might take a bit)..."
	clang++ -c *.cpp
	echo "Compiling object files to executable..."
	clang++ -o bfc *.o
	echo "Cleaning..."
	rm *.o
)
(
	cd testtools
	echo "Building testtools..."
	echo -e "\ttestTimer..."
	clang++ -o testTimer testTimer.cpp
)
echo "Moving..."
AR=$(arch)
mv src/bfc "dist/$OSTYPE-$AR-bfc"
echo "Copying..."
cp "dist/$OSTYPE-$AR-bfc" tests/bfc
cp testtools/testTimer tests/testTimer