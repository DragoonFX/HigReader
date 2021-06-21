#!/bin/sh

output_name="Higurashi_insert_version.txt"

echo "Removing previous" $output_name"..."
rm -f Higurashi_insert_version.txt

echo "Creating new HigReader executable..."
gcc HiguReader.c -o HiguReader.out

echo "Creating" $output_name"..."
for file in *.txt
do
	./HiguReader.out "$file" >> Higurashi_insert_version.txt
done

echo $output_name "successfully created."