# Test 3
echo "Building test3.bf..."
echo "" > test3.bf
echo "; Test 3 - Tests error handling

; Error no -1th memory block
<+
" >> test3.bf
echo "; Error shifted too far" >> test3.bf
for i in {0..290}
do
	echo -n -e "\r$i"
	echo ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" >> test3.bf
done
echo -e "\rBuilding test6.bf..."
touch test6.bf
echo "
; Test 6 - Tests hecka big files
" >> test6.bf
for i in {0..300}
do
	echo -n -e "\r$i / 300"
	for j in {0..100}
	do
		echo -n ">>>>>>" >> test6.bf
	done
	for j in {0..100}
	do
		echo -n "<<<<<<" >> test6.bf
	done
done

echo -en "\r         \r"