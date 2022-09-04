#!/bin/sh

if [[ -z $1 ]]
then
    echo "write what to do"
    exit 1
fi

ARG=$2

case $1 in
    "commit")
        ./commit.sh $ARG
        ;;
    "build")
        ./build.sh
        ;;
    "reserve")
        ./reserve.sh
        ;;
    *)  
        echo "unknkown comand..."
        exit 2
        ;;
esac