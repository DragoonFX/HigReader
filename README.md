# HiguReader
Small C program to read Higurashi scripts and turn it into a readable format.

## Introduction
This is a fork of [HigReader](https://github.com/aamador-ch-en/HigReader) created by [Abraham Amador](https://github.com/aamador-ch-en) with many improvements.

### Differences from the original version
* Extracts strings more accurately (original version skipped some lines)
* Added name of the character who is currently speaking (not perfect)
* Added quotation marks when a character speaks
* Added command line argument for getting file name
* Added a script for batch converting files
* Removed the option to convert japanese text

## Instructions
1. First make sure you are using a linux based distro (if using windows, download and install cygwin with gcc)
1. Clone the repo to your local machine
1. Copy the scripts from <Higurashi_folder>/StreamingAssets/Scripts/ directory. (the scripts should be in txt format)
1. Then run `./start_conversion.sh`
1. It will produce a txt file named `Higurashi_insert_version.txt`. Now you can convert it to pdf or epub using calibre.
