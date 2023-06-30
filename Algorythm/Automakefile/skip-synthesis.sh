#!/bin/sh
if [ $# -eq 0 ]; then
    echo "no args given";
    exit 84
fi
file="$1";
awk '{ print $3,"\t",$9 }' | grep -E "\b$file"