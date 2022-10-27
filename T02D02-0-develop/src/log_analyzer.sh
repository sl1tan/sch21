#!/bin/bash


path=$1

if [ ! -f "$path" ]; then
    exit 1
fi

total=$(wc -l < "$path")
unique=($(awk '{print -f $1}' $path | sort -u | wc -l))
changes=($(awk '{print -f $8}' $path | sort -u | wc -l))
echo "$total $unique $changes"
