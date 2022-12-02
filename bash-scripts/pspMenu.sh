#!/bin/bash
#
#dmenu and watson based PSP tracker

command=$((echo start; echo stop; echo restart; echo status; echo cancel; echo edit) | dmenu)

if [ $command == "start" ]
then
    watson status | grep "No project started" || watson stop
    tag=$((echo psp; echo AnD; echo C; echo TnR; echo S) | dmenu)
    project=$(watson report | grep "procprog" | cut -d ' ' -f1 | dmenu)
    watson start $project +$tag
else
    watson $command
fi
