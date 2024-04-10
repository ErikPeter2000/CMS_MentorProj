Get-ChildItem ".\Blender\" -Filter "*.png" -Recurse | ForEach-Object {
    git lfs track $_.Name
}

Get-ChildItem ".\Lorenz-CPP\Renders" -Filter "*.png" -Recurse | ForEach-Object {
    git lfs track $_.Name
}