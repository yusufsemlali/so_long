#!/bin/bash

# Desired size of the output images
size=$1

# Directory where the image files are located
dir="assets"

# Find all .xpm and .png files in the directory and its subdirectories
find "$dir" -type f \( -name "*.xpm" -o -name "*.png" \) | while read -r file; do
    # New file with _s prefix
    new_file="${file%.*}_s.${file##*.}"
    
    # Convert the file to the desired size and save as the new file
    convert "$file" -resize ${size}x${size} "$new_file"
done
