#!/bin/bash

# Check if the user provided a directory as input
if [ $# -eq 0 ]; then
    echo "Usage: $0 <directory>"
    exit 1
fi

# Store the provided directory in a variable
directory="$1"

# Check if the provided directory exists
if [ ! -d "$directory" ]; then
    echo "Error: Directory '$directory' does not exist."
    exit 1
fi

# Create the "Modified" directory if it doesn't exist
modified_dir="$directory/Modified"
mkdir -p "$modified_dir"

# Find all files with a ".txt" extension recursively in the provided directory
find "$directory" -type f -name "*.txt" | while read -r file; do
    # Get the filename without the extension
    filename=$(basename "$file" .txt)
    
    # Copy the file to the "Modified" directory with the ".bak" extension
    cp "$file" "$modified_dir/$filename.bak"
done

echo "Files with '.txt' extension copied to '$modified_dir' with '.bak' extension."
