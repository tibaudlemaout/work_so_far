#!/bin/sh
opt=$1
read v < Version
if [[ $opt == add ]]; then
	new_version=$[$v+1]
	echo $new_version > Version
fi
if [[ $v != "0" ]]; then
	if [[ $opt == rev ]]; then
		prev_version=$[$v]
		echo $prev_version > Version
	fi
fi
