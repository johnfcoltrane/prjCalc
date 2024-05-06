# OpenNetUseDvPath.ps11
# net-use ドライブの元のパスを開く
Param($d='z:')
$a = net use $d |?{$_ -match "リモート名"}
if ($a.count -eq 1){
    ($p0,$p)=$a -split "[ ]+"
    start $p
}
