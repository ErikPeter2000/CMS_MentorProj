Get-ChildItem -Filter "*.png" | ForEach-Object {
    git lfs track $_.Name
}