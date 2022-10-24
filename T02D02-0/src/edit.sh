#!/bin/bash

logfilepath="src/files.log"
read -p "Enter path to file: " filepath
read -p "Enter search string: " search
read -p "Enter replace string: " replace

if [ -e $filepath ];
then
    if [[ $search != "" && $replace != "" ]];
    then
        filesource=$(cat $filepath)
        sed -i '' "s/$search/$replace/g" $filepath
        if [[ $filesource != $(cat $filepath) ]];
        then
            echo "$filepath - $(wc -c $filepath | awk '{print $1}') - $(stat -f '%Sm' -t '%Y-%m-%d %H:%M' $filepath) - $(shasum -a 256 $filepath | awk '{print $1}') - sha256" >> $logfilepath
        else
            echo "String not found or search and replace string are equal"
        fi
    else
        echo "Invalid input"
    fi
else
    echo "File does not exist"
fi
