#IdoHeikin.ps1
$a=(1..11)+(10..1)
#$a
function avg($a){
    return ($a|Measure-Object -Average).Average
}
class MyBuffer{
    $buf
    $max_len
    MyBuffer($n=5){
        $this.max_len = $n
        $this.buf = @()
    }
    [void]push($x){
        $n = ($this.buf).Length
        $m = $this.max_len
        if ($n -ge $m){
            $this.buf = $this.buf[1..($n-1)] + $x
        }
        else{
            $this.buf += $x
        }
    }
    [void]show(){
        Write-Host "$($this.buf)"
    }
    [float] getAvg(){
        return(avg($this.buf))
    }
}
$o = New-Object MyBuffer(5)
if(0){
    1..10|%{
    $o.show()
    $o.push($_)
    }
}
$n = $a.Length
$m = 5
#$b=($m-1)..($n-1)
$b=0..($n-1)
$o.show()
$b|ForEach-Object{
    $o.push($a[$_])    
    #$o.show()
    "{0} , {1}" -f $a[$_],$o.getAvg()
} #|Out-File -Encoding default ./temp1.csv
