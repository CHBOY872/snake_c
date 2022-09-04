#!/bin/sh

function reserve() {
    git checkout reserve
    git cherry-pick master
    git checkout master
}


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
    *)  
        echo "unknkown comand..."
        exit 2
        ;;
esac