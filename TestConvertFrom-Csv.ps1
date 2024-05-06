<#
先頭行の有効な項目から列数を判断し、「-h @(...)」を生成
#>
# 有効な項目数をカウント
function getValidCount($a,$names){
$cnt = 0
$names|%{
    if ($a[0].$_ -ne "" -and $a[0].$_ -ne $null){
        $cnt++
        #write-host "$_,$cnt,$($a[0].$_)"
    }
}
$cnt
}

# 項目数カウント
function getItemCount($aa){
$names=$aa[0]|get-member|?{$_.membertype -eq 'NoteProperty'}|%{$_.name}
#"$names"
#$names.Count
(getValidCount $aa $names)
}

#$l = 15 # 

$n = 10 # 生成する列数
$a=1..20|%{
$i=$_
$st=($i*100+1)
$l=($st..($st+$n-1)) -join ","
"$l"
}

#$nn = getItemCount 
# 少し多めにカラム数を設定
$aa = $a|convertfrom-csv -h (@(1..99)|%{"** $_ **"}) #|ogv
$nn = getItemCount $aa
$nn　# 有効な項目数

# 列数を指定してView
$aa = $a|convertfrom-csv -h (@(1..$nn)|%{"** $_ **"}) #|ogv
$aa|ogv
