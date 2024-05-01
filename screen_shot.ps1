Add-Type -AssemblyName System.Windows.Forms
[Console]::WindowWidth = 50
while ($true) {
    Write-Host "Capturing screenshot at $((Get-Date).ToString('yyyy-MM-dd HH:mm:ss'))..."
    [System.Windows.Forms.SendKeys]::SendWait("{PRTSC}")
    Start-Sleep -Seconds 1
    $image = [System.Windows.Forms.Clipboard]::GetImage()
    $filename = "t:\screenshot_$((Get-Date).ToString('yyyyMMdd_HHmmss')).png"
    $image.Save($filename, [System.Drawing.Imaging.ImageFormat]::Png)
    Write-Host "Screenshot saved as $filename"
    Start-Sleep -Seconds 4
}
