#!/bin/bash

# Directory where the PNG files are located
dir="assets"

# Find all PNG files in the directory and its subdirectories
find "$dir" -type f -name "*.png" | while read -r png_file; do
    # Replace the file extension with .xpm
    xpm_file="${png_file%.png}.xpm"
    
    # Convert the PNG file to XPM format
    convert "$png_file" "$xpm_file"
done
