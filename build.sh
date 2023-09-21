#!/bin/bash

# Compile C++ code 
g++ -o main /home/david/Desktop/main.cpp

if [ $? -eq 0 ]; then 
    ./main
else
    echo "Failed..."
fi