#!/bin/bash

read -p "Enter path to log file: " logfilepath

if [ -e $logfilepath ];
then
    echo "$(sort $logfilepath | wc -l | awk '{print $1}') $(sort $logfilepath | cut -d '-' -f 1 | uniq -d | wc -l | awk '{print $1}') $(sort $logfilepath | wc -l | awk '{print $1}')"
else
    echo "File does not exist"
fi
