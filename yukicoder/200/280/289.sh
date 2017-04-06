read s
echo $s | tr -d "[:alpha:]" | sed 's/[0-9]/&+/g'| sed 's/$/0/' | bc
#&は一致した正規表現の文字を表す