#!/bin/bash

output_name_initial="Higurashi_<insert_arc_name>_initial.txt"
output_name_final="Higurashi_<insert_arc_name>.txt"
script_dir="script"
exe_name="higureader.out"
source_name="higureader.c"

if [ -f "$output_name_final" ]
then
	echo "Removing previous $output_name_final ..."
	rm -f "$output_name_final"
	echo "Done"
fi

echo "Creating new higheader executable..."
gcc "$source_name" -o "$exe_name"
echo "Done"


echo "Creating $output_name_initial ..."
echo "Processing files-"

#executes the program with the opening script first
if [ -f "$script_dir"/*_op.txt ];
then
	./"$exe_name" "$script_dir"/*_op.txt >> "$output_name_initial"
	echo "$script_dir"/*op.txt
fi

readarray -d '' entries < <(printf '%s\0' "$script_dir"/*.txt | sort -zV)
for file in "${entries[@]}";
do
	if [[ "$file" != "$script_dir"/*_op.txt && "$file" != "$script_dir"/*vm*.txt && "$file" != "$script_dir"/flow.txt && "$file" != "$script_dir"/init.txt && "$file" != "$script_dir"/dummy.txt && "$file" != "$script_dir"/*opening.txt && "$file" != "$script_dir"/omake*.txt ]];
	then
		echo "$file"
		./"$exe_name" "$file" >> "$output_name_initial"
	fi
done

if [ -f "$output_name_initial" ]
then
	echo "$output_name_initial successfully created."
else
	echo "Error! $output_name_initial not created!"
fi

echo "Removing unwanted characters from $output_name_initial and creating $output_name_final..."
sed $'s/[^[:print:]\t]//g' "$output_name_initial" > "$output_name_final"
if [ -f "$output_name_final" ]
then
	echo "$output_name_final successfully created."
	rm -f "$output_name_initial"
else
	echo "Error! $output_name_final not created!"
fi

rm -f "$exe_name"
