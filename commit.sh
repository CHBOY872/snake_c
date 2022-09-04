#!/bin/sh

FILES="*.c *.h makefile *.sh"

if [[ -z $1 ]]; then
    echo "Type a message for commiting"
else

    git add $FILES

    git commit -m "$1";

fi