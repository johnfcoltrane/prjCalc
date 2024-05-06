# Substドライブの元のパスを開く
Param($d='x:')
$a=subst|?{$_ -match $d}
if ($a.count -eq 1){
    ($p0,$p1,$p)=$a -split " "
    cd $p
    start $p
}
