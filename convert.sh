#!/bin/bash

# Change directory to /test/
cd test

# Loop over each .png file in the directory
for file in *.png
do
  # Get the base name of the file (without extension)
  base_name=$(basename "$file" .png)
  
  # Convert the .png file to .xpm format
  convert "$file" "${base_name}.xpm"
done
