# Test 3
echo "Building test3.bf..."
echo "" > test3.bf
echo "; Test 3 - Tests error handling

; Error no -1th memory block
<+
" >> test3.bf
echo "; Error shifted too far" >> test3.bf
for i in {0..300}
do
	echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> test3.bf
done