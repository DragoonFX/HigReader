#!/bin/sh

output_name="Higurashi_<insert_chapter_name>.txt"

#echo "Renaming" 
#if [ -f *_op.txt ]
#then
#  echo "Renaming file- "
#	mv *_op.txt 1*_op.txt
#elif [ -f *_ep*.txt ]
#then
#	echo "Renaming file- "
#	mv *_ep*.txt 1*_ep*.txt
#else
#    echo "No file to rename..."
#fi

echo "Removing previous" $output_name"..."
rm -f Higurashi_insert_version.txt
echo "Done"

echo "Creating new higheader executable..."
gcc higureader.c -o higureader.out
echo "Done"

echo "Creating" $output_name"..."
for file in *.txt
do
	echo $file
	./higureader.out "$file" >> $output_name
done
echo $output_name "successfully created."

