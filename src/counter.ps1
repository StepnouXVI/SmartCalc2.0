$totalLines = 0
$excludeDirs = @('Libs') # Добавьте каталоги, которые нужно исключить
$excludeFiles = @('QCustomPlot.cpp', 'QCustomPlot.h') # Добавьте файлы, которые нужно исключить

Get-ChildItem -Recurse -Filter *.cpp  -Exclude $excludeFiles | Where-Object { 
    $excludeDirs -notcontains $_.Directory.Name 
} | ForEach-Object {
    try {
        $fileLines = (Get-Content $_.FullName -ErrorAction Stop | Measure-Object -Line).Lines
        $totalLines += $fileLines
        Write-Host "File: $($_.FullName) has $fileLines lines"
    } catch {
        Write-Host "Error reading file: $($_.FullName)"
    }
}
Write-Host "Total number of lines in .cpp files: $totalLines"

Get-ChildItem -Recurse -Filter  *.h -Exclude $excludeFiles | Where-Object { 
    $excludeDirs -notcontains $_.Directory.Name 
} | ForEach-Object {
    try {
        $fileLines = (Get-Content $_.FullName -ErrorAction Stop | Measure-Object -Line).Lines
        $totalLines += $fileLines
        Write-Host "File: $($_.FullName) has $fileLines lines"
    } catch {
        Write-Host "Error reading file: $($_.FullName)"
    }
}
Write-Host "Total number of lines in .h files: $totalLines"