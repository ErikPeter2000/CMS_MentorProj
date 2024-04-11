Get-ChildItem ".\Code\Blender\" -Filter "*.png" -Recurse | ForEach-Object {
    git lfs track $_.Name
}

Get-ChildItem ".\Code\Lorenz-CPP\Renders" -Filter "*.png" -Recurse | ForEach-Object {
    git lfs track $_.Name
}

Get-ChildItem ".\LaTeX" -Filter "*.png" -Recurse | ForEach-Object {
    git lfs track $_.Name
}