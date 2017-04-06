read n a
read x
ans=$(($n*$a))
echo $ans;
echo $x | tr " " "+" | bc | awk '{print $ans; print $0;if($ans==$0){print "YES";} else {print "NO";}}'

#うまくいかない