#!/bin/sh

output_name="Higurashi_<insert_arc_name>.txt"
script_dir="script"
exe_name="higureader.out"
source_name="higureader.c"

if [ -f "$output_name" ]
then
	echo "Removing previous" "$output_name"".a.."
	rm -f "$output_name"
	echo "Done"
fi

#Renames files so that the order of the files are perfect
echo "Renaming files- "
if [ -f "$script_dir"/onik_009.txt ];
then
	echo "onik_009.txt to onik_009_00.txt"
	cp "$script_dir"/onik_009.txt "$script_dir"/onik_009_00.txt
	mv "$script_dir"/onik_009.txt "$script_dir"/onik_009.txt.backup
fi
if [ -f "$script_dir"/onik_014.txt ];
then
	echo "onik_014.txt to onik_014_00.txt"
	cp "$script_dir"/onik_014.txt "$script_dir"/onik_014_00.txt
	mv "$script_dir"/onik_014.txt "$script_dir"/onik_014.txt.backup
fi
if [ -f "$script_dir"/onik_015.txt ];
then
	echo "onik_015.txt to onik_015_00.txt"
	cp "$script_dir"/onik_015.txt "$script_dir"/onik_015_00.txt
	mv "$script_dir"/onik_015.txt "$script_dir"/onik_015.txt.backup
fi

if [ -f "$script_dir"/wata_009.txt ];
then
	echo "wata_009.txt to wata_009_00.txt"
	cp "$script_dir"/wata_009.txt "$script_dir"/wata_009_00.txt
	mv "$script_dir"/wata_009.txt "$script_dir"/wata_009.txt.backup
fi
if [ -f "$script_dir"/wata_010.txt ];
then
	echo "wata_010.txt to wata_010_00.txt"
	cp "$script_dir"/wata_010.txt "$script_dir"/wata_010_00.txt
	mv "$script_dir"/wata_010.txt "$script_dir"/wata_010.txt.backup
fi
if [ -f "$script_dir"/wata_011.txt ];
then
	echo "wata_011.txt to wata_011_00.txt"
	cp "$script_dir"/wata_011.txt "$script_dir"/wata_011_00.txt
	mv "$script_dir"/wata_011.txt "$script_dir"/wata_011.txt.backup
fi
if [ -f "$script_dir"/wata_012.txt ];
then
	echo "wata_012.txt to wata_012_00.txt"
	cp "$script_dir"/wata_012.txt "$script_dir"/wata_012_00.txt
	mv "$script_dir"/wata_012.txt "$script_dir"/wata_012.txt.backup
fi

if [ -f "$script_dir"/tata_008.txt ];
then
	echo "tata_008.txt to tata_008_00.txt"
	cp "$script_dir"/tata_008.txt "$script_dir"/tata_008_00.txt
	mv "$script_dir"/tata_008.txt "$script_dir"/tata_008.txt.backup
fi
if [ -f "$script_dir"/tata_009.txt ];
then
	echo "tata_009.txt to tata_009_00.txt"
	cp "$script_dir"/tata_009.txt "$script_dir"/tata_009_00.txt
	mv "$script_dir"/tata_009.txt "$script_dir"/tata_009.txt.backup
fi
if [ -f "$script_dir"/tata_010.txt ];
then
	echo "tata_010.txt to tata_010_00.txt"
	cp "$script_dir"/tata_010.txt "$script_dir"/tata_010_00.txt
	mv "$script_dir"/tata_010.txt "$script_dir"/tata_010.txt.backup
	fi
if [ -f "$script_dir"/tata_011.txt ];
then
	echo "tata_011.txt to tata_011_00.txt"
	cp "$script_dir"/tata_011.txt "$script_dir"/tata_011_00.txt
	mv "$script_dir"/tata_011.txt "$script_dir"/tata_011.txt.backup
fi
if [ -f "$script_dir"/tata_013.txt ];
then
	echo "tata_013.txt to tata_013_00.txt"
	cp "$script_dir"/tata_013.txt "$script_dir"/tata_013_00.txt
	mv "$script_dir"/tata_013.txt "$script_dir"/tata_013.txt.backup
fi

if [ -f "$script_dir"/hima_002.txt ];
then
	echo "hima_002.txt to hima_002_00.txt"
	cp "$script_dir"/hima_002.txt "$script_dir"/hima_002_00.txt
	mv "$script_dir"/hima_002.txt "$script_dir"/hima_002.txt.backup
fi
if [ -f "$script_dir"/hima_003.txt ];
then
	echo "hima_003.txt to hima_003_00.txt"
	cp "$script_dir"/hima_003.txt "$script_dir"/hima_003_00.txt
	mv "$script_dir"/hima_003.txt "$script_dir"/hima_003.txt.backup
fi
if [ -f "$script_dir"/hima_003_03.txt ];
then
	echo "hima_003_03.txt to hima_003_030.txt"
	cp "$script_dir"/hima_003_03.txt "$script_dir"/hima_003_030.txt
	mv "$script_dir"/hima_003_03.txt "$script_dir"/hima_003_03.txt.backup
fi


echo "Creating new higheader executable..."
gcc higureader.c -o "$exe_name"
echo "Done"


echo "Creating" "$output_name""..."
echo "Processing files-"

#executes the program with the opening script first
if [ -f "$script_dir"/*_op.txt ];
then
	./"$exe_name" "$script_dir"/*_op.txt >> "$output_name"
	echo "$script_dir"/*op.txt
fi

for file in "$script_dir"/*.txt
do
	if [ "$file" != "$script_dir"/*_op.txt ];
	then
		echo "$file"
		./"$exe_name" "$file" >> "$output_name"
	fi
done

if [ -f "$output_name" ]
then
	echo "$output_name" "successfully created."
else
	echo "Error! $output_name not created!"
fi

