#!/bin/bash

# Directories for object files, libraries, and executables
OBJ_DIR=obj
LIB_DIR=lib
BIN_DIR=bin

# Create directories if they don't exist
mkdir -p $OBJ_DIR $LIB_DIR $BIN_DIR

# Find all .c files in specific directories recursively excluding CMakeLists.txt and cmake-build-debug directory, and print their names
c_files=$(find src test -type f -name "*.c" ! -name "CMakeLists.txt" ! -path "./cmake-build-debug/*" -print)

# Print the list of .c files
echo "Found C source files:"
echo "$c_files"

# Compile each .c file into an object file
for file in $c_files; do
    gcc -c $file -Iinclude -Wall -Wextra -pedantic -o $OBJ_DIR/$(basename ${file%.c}.o)
done

# Create the library directory if it doesn't exist
mkdir -p $LIB_DIR

# Compile the object files into a library
ar rcs $LIB_DIR/libhomelib.a $OBJ_DIR/*.o

# Compile the test program
gcc -o $BIN_DIR/test_program test/test_homelib.c -Iinclude -L$LIB_DIR -lhomelib

# Run the test program
$BIN_DIR/test_program
