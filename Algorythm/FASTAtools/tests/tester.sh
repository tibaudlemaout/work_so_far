#!/bin/bash

read -p "Enter the path to the executable: " executable_path

read -p "Enter the integer argument: " integer_argument

read -p "Enter the path to the input file: " input_file

read -p "Enter the path to the expected result file: " expected_file

temp_file=$(mktemp)
"$executable_path" "$integer_argument" < "$input_file" > "$temp_file"

diff_result=$(diff -u "$temp_file" "$expected_file")

if [[ -z $diff_result ]]; then
  echo "Program output matches the expected result."
else
  echo "Program output does not match the expected result:"
  echo "$diff_result"
fi

rm "$temp_file"
