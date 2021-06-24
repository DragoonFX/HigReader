# HiguReader
Small C program to read Higurashi scripts and turn it into a readable format.

## Introduction
This is a fork of [HigReader](https://github.com/aamador-ch-en/HigReader) created by [Abraham Amador](https://github.com/aamador-ch-en) with many improvements.

### Improvements over the original version
* Extracts strings more accurately (original version skipped some lines)
* Added support for 07th mod scripts
* Added name of the character who is currently speaking (works perfectly only for 07th mod scripts)
* Added quotation marks when a character speaks
* Added title names for chapters
* Added command line argument for getting file name
* Added a script for batch converting files
* Removed the option to convert japanese text

## Instructions
1. You can compile the program and feed it a higurashi script file or you can use the `start_conversion.sh` to batch convert the scripts of a whole arc.
1. If using the `start_conversion.sh`-
	1. First make sure you are using a linux based distro (if using windows, download and install cygwin with gcc and it should work on android(with termux) and any unix based OS)
	1. Clone this repo to your local machine and `cd` to it
	1. Make a directory named `script`
	1. Copy the scripts from <Higurashi_Arc_Name>/StreamingAssets/Scripts/ directory to the `script/` directory(the scripts should be in txt format)
	1. Then run `./start_conversion.sh`
	1. It will produce a txt file named `Higurashi_<insert_arc_name>.txt`. Now you can convert it to pdf or epub using calibre.
