read n
read a
sum=$(echo $a : tr " " "+" | bc)
tmp=$(($n*4))
t=$(($tmp-$sum))
turu=$(($t/2))
kame=$(($n-$turu))
echo $turu
echo $kame