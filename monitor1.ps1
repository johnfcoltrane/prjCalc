function getList(){
    Get-Process|?{
        $_.ProcessName -match 'pwsh'
        }
}
$ws = @{}
$at_first = 1
$h=" NPM(K)    PM(M)      WS(M)     CPU(s)      Id  SI ProcessName
 ------    -----      -----     ------      --  -- -----------"
do{
    if ($at_first){
    
    }
    #$h
    "Id, WS"
    $lst = getList
    $lst|ForEach-Object{
        if ($at_first){
            $ws[$_.Id] = $_.WS
        }
        "{0},{1},{2},{3}" -f $_.Id,$_.WS,$ws[$_.Id], ($_.WS - $ws[$_.Id])
    }
    $at_first = 0
    sleep 1
    Clear-Host
}while(1)