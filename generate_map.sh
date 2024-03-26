#!/bin/bash

# Check if width and height were provided
if [ $# -ne 2 ]; then
  echo "Usage: $0 width height"
  exit 1
fi

# Define the size of the map
width=$1
height=$2

# Define the characters to use in the map
chars=("0" "C")

# Function to generate a random character
function rand_char {
  echo ${chars[$RANDOM % ${#chars[@]}]}
}

# Get the index for the new map file
index=3
while [ -e "map/map_$index.ber" ]
do
  index=$((index+1))
done

# Generate the map and write it to a file
for ((i=1; i<=$height; i++))
do
  for ((j=1; j<=$width; j++))
  do
    if [ $i -eq 1 ] || [ $j -eq 1 ] || [ $i -eq $height ] || [ $j -eq $width ]
    then
      printf "1"
    elif [ $i -eq 2 ] && [ $j -eq 2 ]
    then
      printf "P"
    elif [ $i -eq 3 ] && [ $j -eq 2 ]
    then
      printf "C"
    elif [ $i -eq 2 ] && [ $j -eq 3 ]
    then
      printf "C"
    elif [ $i -eq $((height-1)) ] && [ $j -eq $((width-1)) ]
    then
      printf "E"
    elif [ $((i%2)) -eq 0 ] && [ $j -ne 2 ] && [ $j -ne $((width-1)) ]
    then
      printf "1"
    else
      printf "$(rand_char)"
    fi
  done | tee -a "map/map_$index.ber"
  printf "\n" | tee -a "map/map_$index.ber"
done
