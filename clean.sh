cd src
rm *.o
cd ..
cd dist
ARCH=`arch`
mv bfc "$OSTYPE-$ARCH-bfc"
cd ..
rm tests/bfc
rm tests/testTimer
rm testtools/testTimer