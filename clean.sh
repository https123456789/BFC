(
	cd src
	rm ./*.o
)
(
	cd dist
	ARCH=`arch`
	mv bfc "$OSTYPE-$ARCH-bfc"
)
rm tests/bfc
rm tests/testTimer
rm testtools/testTimer