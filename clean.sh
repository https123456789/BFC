(
	cd src
	rm ./*.o
	rm ./*.tmp
)
(
	cd dist
	ARCH=$(arch)
	mv bfc "$OSTYPE-$ARCH-bfc"
)
rm tests/bfc
rm tests/testTimer
rm testtools/testTimer
(
	cd tests
	./deleteTests.sh
)