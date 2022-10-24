#!/bin/bash

cd ai_help

ls

chmod u=rwx keygen.sh

./keygen.sh

find . -type f empty -exec rm {} \;

chmod u=rwx unifier.sh
./unifier.sh

mv main.key key/
