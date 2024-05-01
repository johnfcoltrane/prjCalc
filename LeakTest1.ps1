$s = "*"*1000
do{
$buf = ""
$i = 0
do{
    $buf += $s
    get-date
    sleep 1
    $i += 1
} while($i -lt 10)
$buf = ""
}while(0)

