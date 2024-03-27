#!/bin/bash

# Directory where the XPM files are located
dir="assets/player/run"

# Iterate over the numbers 1 to 8
for i in {1..8}; do
    # Original XPM file
    original_file="$dir/run_$i.xpm"
    
    # New XPM file with _s prefix
    new_file="$dir/run_s_${i}.xpm"
    
    # Convert the original XPM file to 32x32 and save as the new file
    convert "$original_file" -resize 32x32 "$new_file"
done
