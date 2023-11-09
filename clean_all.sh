#!/bin/bash

# Find all "Makefile" files and execute "make clean" or "make fclean"



# Check if an argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 clean or fclean"
    exit 1
fi

if ["$1" != "clean" && "$1" != "fclean"]; then
    echo "Usage: $0 clean or fclean"
    exit 1
else 
	find . -type f -name Makefile -execdir make "$1" \;
fi


#Heres what each part of the command does:
#find .: This command searches for files and directories starting from the current directory (.).
#type f: This option specifies that you're interested in files.
#-name Makefile: This option looks for files named "Makefile."
#-execdir make clean \; (or -execdir make fclean \;): 
#This part executes the make clean or make fclean command in the directory where the "Makefile" is found. The \; indicates the end of the -execdir command.
