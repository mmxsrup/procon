read n a
read x
sum=$(echo $x | tr " " "+" | bc)
ans=$(($n*$a))
if [ $sum -eq $ans ]
	then echo "YES"
else echo "NO"
fi

#awk '{if($ans == $sum){print "NO";} else {print "YES";}}'
