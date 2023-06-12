#!/bin/bash

prefix=$1
max_size=$2

if [[ -z $prefix ]] || [[ -z $max_size ]]
then
    echo "Missing arguments"
    echo "Usage: ./main.sh <prefix> <max-size>"
else
    while [[ `find . -type f -name "$prefix*" | xargs wc -c | awk '{print $1}' | head -1` -gt "$max_size" ]] || [[ `find . -type f -name "$prefix*" | xargs wc -c | grep total | awk '{print $1}'` -gt "$max_size" ]]
    do
        max_file=`find . -type f -name "$prefix*" -printf "%s\t%p\n" | sort -n | tail -1 | awk '{print $2}'`
        rm $max_file
    done
fi
