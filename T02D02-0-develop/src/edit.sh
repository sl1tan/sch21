#!/bin/bash


path=$1
str1=$2
str2=$3

if [ ! -f "$path" ] 
then
echo "Данного файла не существует."
kill "$$"
fi


if [ ! -r "$path" ] 
then
echo "Отказано в доступе. Файл не доступен для чтения."
kill "$$"
fi


if [ ! -w "$path" ] 
then
echo "Отказано в доступе. Файл не доступен для записи."
kill "$$"
fi 


sed -i '' "s/$str1/$str2/g" "$path"
size=$(stat -f%z $path)
date_and_time=$(date +"%Y-%m-%d %H:%M")
sha_sum=$( (shasum --a 256 $path) | (awk '{ print $1 }') )
echo "$path - $size - $date_and_time - $sha_sum - sha256" >> $PWD/files.log
